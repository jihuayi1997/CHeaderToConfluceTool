#!/bin/bash

# 同名文件与文件夹的意思是，文件名中的下划线_前面的部分相同
# 批量自动把同名文件分别放入同名文件夹中

for i in *.h;do
      # 从文件名中截取下划线_前面的部分，作为文件夹名称   
      destination_folder=${i%[.]*}
      echo $destination_folder
      if [ ! -d $destination_folder ];then
            mkdir ${destination_folder}
            echo "the folder with the name of $destination_folder has been created."
      fi 

      mv $i ./${destination_folder}/$i
      echo "$i has been moved to the same name folder of $destination_folder"

      cp Doxyfile ./${destination_folder}/Doxyfile
      cd $destination_folder
      #sed -i 's/npl-leaderboard/$destination_folder/g' Doxyfile
      doxygen
      moxygen.js -n -t C:/Users/SHS1654/Desktop/xml--md/moxygen/templates/cpp -o $destination_folder.md xml
      sed -i '/iEvtType/d' $destination_folder.md
      sed -i '/Generat/d' $destination_folder.md
      sed -i 's/__t/_t/g' $destination_folder.md
      winpty C:\\Users\\SHS1654\\Desktop\\jihuayi\\CHeaderToConfluceTool\\auto.bat $destination_folder.md $destination_folder.txt
      mkdir json
      doxybook2 -i xml -o json -j
      rm -f Doxyfile
      cd xml
      xsltproc combine.xslt index.xml >all.xml
      cd ..
      cd ..
done