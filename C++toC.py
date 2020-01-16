# -*- coding: utf-8 -*-
import os
from collections import Counter   #引入Counter
path="D:\workspace(py)\c++headers"
dirs=os.listdir(path)
f2 = open("npl-c-interface.h",'w',encoding='utf-8')
f3 = open("npl-c-interface.cpp", 'w', encoding='utf-8')
hhead='''///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \\file npl-c-interface.h
///
/// \\brief NPL c api export
///

#ifndef __NPL_C_INTERFACE_H__
#define __NPL_C_INTERFACE_H__

#define __NPL_C_INTERFACE__
#include <npl-base-c-interface.h>

#include "npl-user.h"
#include "npl-network.h"
#include "npl-friend.h"
#include "npl-storage.h"
#include "npl-matchmaking.h"
#include "npl-serverMatchmaking.h"
#include "npl-leaderboard.h"
#include "npl-voice.h"

#ifdef __cplusplus
extern "C"
{
#endif\n'''
chead='''#include "npl-header.h"
#include "npl-inner.h"
#include "npl-callback.h"
#include "npl.h"

#include "npl-network.h"
#include "npl-friend.h"
#include "npl-matchmaking.h"
#include "npl-storage.h"
#include "npl-sensitiveword.h"
#include "npl-serverMatchmaking.h"
#include "npl-callback.h"
#include "npl-exception.h"
#include "npl-voice.h"
#include "npl-gameServer.h"

#include "npl-c-interface.h"

#include <fstream>
#ifdef WIN32
	#include <shellapi.h>
#endif // WIN32
//
//NPL_API bool RestartAppIfNecessary(sint32_t appID)
//{
//	fstream fs;
//	fs.open(".\\npl_appid.txt");
//	if (fs.is_open())
//	{
//		sint32_t appID_t = 0;
//		fs >> appID_t;
//		if (appID_t > 0)
//		{
//			appID = appID_t;
//			return false;
//		}
//	}
//	if (appID == 0)
//	{
//		return false;
//	}
//
//	auto url = std::string("nplp://rungameid/") + std::to_string(appID);
//
//#ifdef WIN32
//	ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
//#endif // WIN32
//	return true;
//}
//\n\n'''
f2.write(hhead)
f3.write(chead)
for file in dirs:
        print(file)
        funcs=[]
        #生成域名
        space=os.path.splitext(file)[0]
        space=space.replace('-','_')
        #转换域名大写字母
        space_list=list(space)
        x2=space_list.index('_')
        x2+=1
        space_list[x2]=space_list[x2].capitalize()
        space=''.join(space_list)
        #获取文件路径名称后缀
        file=os.path.join(path,file)
        name=os.path.splitext(file)[0]
        suffix=os.path.splitext(file)[1]
        old_str = "virtual"
        new_str = "NPL_API"
        start=0
        flag="NPL_API"

        #重载函数统计
        f1 = open(file, 'r', encoding='utf-8')
        for lines in f1:
                if flag in lines:
                        start = 1
                if start == 1:
                        if old_str in lines:
                                lines = lines.replace(old_str, new_str)
                                lines = lines.replace('\t', "    ")
                                lines = lines.replace("    ", '')
                                words = lines.split(sep=' ')
                                x1 = words.index('NPL_API')
                                x1 += 2
                                y1, _, _ = words[x1].partition('(')  # y1为函数名
                                funcs.append(y1)
        b = dict(Counter(funcs))
        print("重载的函数及次数：{}".format({key: value for key, value in b.items() if value > 1}))
        f1.close()

        #生成.h
        f1 = open(file, 'r', encoding='utf-8')
        modify_times = 0  # 统计修改次数
        start=0
        #f2 = open(name+"-C"+suffix,'w',encoding='utf-8')
        for lines in f1:
                if start==1:
                        if old_str in lines:
                                lines = lines.replace(old_str,new_str)
                                lines=lines.replace('\t',"    ")
                                words=lines.split(sep=' ')
                                x1=words.index('NPL_API')
                                x1+=2
                                #print(words[x1])
                                lines=lines.replace(words[x1],space+'_'+words[x1])
                                lines=lines.replace(" = 0",'')
                                lines=lines.replace("NPL_USRID","uint64_t")
                                modify_times += 1
                        #重载则打标记
                        overflag = 0
                        for str in [key for key, value in b.items() if value > 1]:
                                if str in lines:
                                        overflag += 1
                        if overflag == 1:
                                lines =lines.replace("        ","        TODO:OVERLOAD ")
                        #把不需要的元素去掉
                        needflag=1
                        for str in ["#endif","public:",'{','}']:
                                if str in lines:
                                        needflag=0
                        # lines修改格式
                        lines=lines.replace("    ",'\t')
                        lines=lines.replace("\t\t",'\t')
                        if needflag==1:
                                f2.write(lines)
                if flag in lines:
                        start = 1
        print('生成的.h文件函数数目：',modify_times)
        f1.close()

        #生成.c
        start=0
        space2 = space.replace('-', '_')
        space2=space2.capitalize()
        f1 = open(file, 'r', encoding='utf-8')
        modify_times = 0  # 统计修改次数
        #f3 = open(name + "-C" + ".cpp", 'w', encoding='utf-8')
        for lines in f1:
                if flag in lines:
                        start=1
                if start==1:
                        if old_str in lines:
                                lines = lines.replace(old_str,new_str)
                                lines=lines.replace('\t',"    ")
                                lines=lines.replace("    ",'')
                                words=lines.split(sep=' ')
                                x1=words.index('NPL_API')
                                x1+=2
                                y1, _, _ = words[x1].partition('(')  # y1为函数名
                                _, _, y2 = lines.partition('(')
                                y3, _, _ = y2.partition(')')  # y3为待处理参数列表
                                y3 = y3.replace("const ", '')
                                y3 = y3.replace(" & ", ' ')
                                # 生成参数名字
                                paras = y3.split(sep=' ')
                                paras = paras[1::2]
                                param = ''.join(paras)
                                param = param.replace(',', ", ")
                                lines = lines.replace(words[x1], space + '_' + words[x1])
                                lines=lines.replace(" = 0;","\n{\n\treturn npl::Get"+space2+"()->"+y1+"("+param+")"+";\n}\n")
                                lines = lines.replace("NPL_USRID", "uint64_t")
                                modify_times += 1
                                overflag = 0
                                for str in [key for key, value in b.items() if value > 1]:
                                        if str in lines:
                                                overflag += 1
                                if overflag == 1:
                                        lines ="TODO:OVERLOAD "+lines
                                f3.write(lines)
        print('生成的.c文件函数数目：',modify_times)
        f1.close()
htail='''\n#ifdef __cplusplus
}
#endif
#endif // !NPL_C_INTERFACE_H__'''
f2.write(htail)
f2.close()
f3.close()