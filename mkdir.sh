#!/bin/bash

# 同名文件与文件夹的意思是，文件名中的下划线_前面的部分相同

# 批量自动把同名文件分别放入同名文件夹中

# 处理的文件是后缀名为.jpg的文件

for i in *.h;do

# 从文件名中截取下划线_前面的部分，作为文件夹名称   

      destination_folder=${i%[.]*}

# 在命令行输出结果中显示文件夹名称——只是为了看看而已 ^_^   

     echo $destination_folder

# 如果已经存在这个名称的文件夹，则不再创建；

# 如果没有则创建，并创建，并在命令行输出结果中吼一声 ^_^   

      if [ ! -d $destination_folder ];then
            mkdir ${destination_folder}
            echo "the folder with the name of $destination_folder has been created."
      fi

# 移动文件到同名文件夹，并在命令行输出结果中吼一声 ^_^   

      mv $i ./${destination_folder}/$i
      echo "$i has been moved to the same name folder of $destination_folder"

      cp Doxyfile ./${destination_folder}/Doxyfile
      cd $destination_folder
      #sed -i 's/npl-leaderboard/$destination_folder/g' Doxyfile
      doxygen
      moxygen.js -n -o $destination_folder.md xml
      sed -i '/iEvtType/d' $destination_folder.md
      sed -i '/Generat/d' $destination_folder.md
      cd ..
done