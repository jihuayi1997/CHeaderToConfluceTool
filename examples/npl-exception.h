///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 netease China
/// All right reserved
///
/// \file npl-exception.h
///
/// \brief NPL exception functional support
///
#ifndef __NPL_EXCEPTION_H__
#define __NPL_EXCEPTION_H__
namespace npl
{
	///
	/// \brief initialize exception system
	/// 
	/// \param log_path 日志存储路径
	///
	/// \note 异常收集系统初始化，log_path为崩溃日志和转储文件存放的目录（该目录若不存在SDK会自行创建）。初始化成功后即可在系统崩溃时收集崩溃转储。
	/// 
	NPL_API bool NplExceptionInit(const char* log_path);

	///
	/// \brief set exception translate every thread
	///
	/// \note 在启动线程时，崩溃转储需进行线程的初始化。
	/// 
	NPL_API void NplExceptionInitThread();

	///
	/// \brief exception system shutdown
	///
	/// \note 进程退出时，需调用该API进行清理工作。
	/// 
	NPL_API void NplExceptionShutdown();

	///
	/// \brief write mini dump
	///
	/// \note 该API允许开发者在任何时候都可以将当前进程进行core dump。content参数在Windows下需传入一个 LPEXCEPTION_POINTERS 指针对象，该对象指向当前的exception content。
	///       若该参数为空，则 SDK 会在当前位置raise 一个 exception。file 参数也可以为 NULL，这会让该 API 使用默认的路径和文件名生成规则（Dump-%04d%02d%02d_%02d%02d%02d-%03d.dmp）生成转储文件。
	/// 
	NPL_API void NplWriteDump(const char * file, void * content);

	///
	/// \brief write mini dump
	///
	/// \note 该API允许开发者在任何时候打印当前的堆栈，并将结果添加在指定的文件中。需要说明的是，并不是所有情况下这么做都可以清楚的看到堆栈，开发者需要使用合适的参数配置编译和链接的参数。
	///       最差的情况是调用堆栈中仅包括函数的入口地址，即使这样，也可以借助MAP文件进行一些分析。
	/// 
	NPL_API void NplWriteStack(const char * file);


	///
	/// \brief 设置CoreDump的注释信息
	///
	/// \param pchMsg 用户自定义信息
	///
	NPL_API void NplSetMiniDumpComment(const char *pchMsg);

	///
	/// \brief 创建minidump的用户自定义信息
	/// 
	/// \param uStructuredExceptionCode MiniDump类型, \see: https://docs.microsoft.com/en-us/windows/desktop/api/minidumpapiset/ne-minidumpapiset-_minidump_type
	/// \param pvExceptionInfo 实际的异常内容
	/// \param uBuildID 用于追溯生成dump文件的应用程序版本信息
	///
	NPL_API void NplWriteMiniDump(uint32_t uStructuredExceptionCode, void* pvExceptionInfo, uint32_t uBuildID);
}
#endif // __NPL_EXCEPTION_H__
