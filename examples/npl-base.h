#ifndef __NPL_BASE_H__
#define __NPL_BASE_H__
#include "npl-macros.h"
#include "npl-defines.h"
#include "npl-callback.h"

#include "npl-app.h"
#include "npl-cais.h"

namespace npl
{
///
/// \brief Set the switchs for CAIS, this function must called before NplInit.
///
/// \param isAutoShowCaisTip Does need sdk show CAIS tips
/// \param isAutoExitWhenCaisEnd Does need sdk eixt process when CAIS countdown over
///
NPL_API void NplSetCaisSwitch(bool isAutoShowCaisTip, bool isAutoExitWhenCaisEnd);

///
/// \brief initialize npl library first of all.
///
/// \return ture if success, otherwise return false.
/// 
/// \note  SDK的初始化函数，除少部分 API 函数外，其他 API 都应在此函数调用成功后再使用。
/// 
NPL_API bool NplInit();

///
/// \brief termination npl library at the end.
/// 
/// \note  进程退出前需调用 NplShutdown 进行清理，否则可能出现内存泄漏等异常情况。
/// 
NPL_API void NplShutdown();

///
/// \brief  judge client is need stop
///
/// \return true is stop, otherwise return false
/// 
/// \note   
///
NPL_API bool NplIsStop();

///
/// \brief judge platform is running.
/// 
/// \note  该函数判断 NPL 平台是否已经开启。正常情况下 NPL 平台在SDK运行过程中应一直开启，否则部分功能会受到影响。
/// 
NPL_API bool NplIsRunning();

///
/// \brief get npl install path
/// 
/// \note  该函数返回平台的安装目录。在进程需要访问 NPL 的配置文件时，可通过该函数获取平台的根路径，并根据需要拼装自己的路径。
/// 
NPL_API cstr_t NplGetPlatformDir();

///
/// \brief restart platform
/// 
/// \note  该函数会重启平台，同时也会导致当前进程立即退出。
/// 
NPL_API bool NplRestart();

///
/// \brief get this application id.
/// 
/// \note  获取当前运行进程的AppId
/// 
NPL_API NPL_APPID NplGetAppId();

///
/// \brief	get this launcher id.
/// 
/// \note	获取调用游戏的Launcher ID
///
NPL_API uint32_t NplGetLauncherId();

///
/// \brief get the game install directory.
/// 
/// \note  获取当前运行进程的安装目录。
/// 
NPL_API cstr_t NplGetSetupDir();

/// 
/// \brief  set log level (default info)
///
NPL_API void NplSetLogLevel(eLogLevel eLv);

///
/// \brief 回调注册
/// 
/// \note  回调注册函数用于注册异步调用函数的回调。在 SDK 中异步函数会返回一个 long 类型的 Token 值（该值保证不重复），当异步函数执行完毕，
///        SDK 会检查该Token上是否有注册回调，并进行调用。SDK 提供了一个回调函数的驱动 API NplRunCallback 需要开发者在主线程进行轮询，以保证所有开发者接触到的代码都处于同一线程中。
/// 
NPL_API bool RegistCallback(long iCallback, INplCallback* cb);

///
/// \brief 回调注销
/// 
/// \note  回调注销函数负责从异步调用Token上删除已注册的回调函数。默认情况下，回调函数的删除并不需要开发者关心，我们有完备的机制将回调函数所分配的内存进行回收。
/// 
NPL_API void UnRegistCallback(long iCallback);

///
/// \brief 事件注册
/// 
/// \param iEvent 事件ID
/// \param cb 事件回调指针
///
/// \note  事件是由系统底层进行的通知，其产生并不依赖开发者的 API 调用。每个事件都有一个固定的事件ID与之对应，事件相应的参数由回调接口中的*params*参数给出。
/// 
NPL_API bool RegistEvent(long iEvent, INplCallback* cb);

///
/// \brief 事件注销
/// 
/// \note  在不需要事件通知的时候，可以通过调用该函数将已注册的事件响应函数进行注销。
/// 
NPL_API void UnRegistEvent(long iEvent);

///
/// \brief invoke result callback
/// 
/// \note  该函数需要在主线程中调用，用于驱动回调函数的处理逻辑。
/// 
NPL_API void NplRunCallback(double secnods);

/// 
/// \brief  gameserver
///
NPL_API bool RegistGameServerCallback(long iCallback, INplCallback* cb);

NPL_API void UnRegistGameServerCallback(long iCallback);

NPL_API bool RegistGameServerEvent(long iEvent, INplCallback* cb);

NPL_API void UnRegistGameServerEvent(long iEvent);

/// 
/// \brief 生成 NPL 应用ID
///
NPL_API NPL_APPID CreateNplAppID(uint32_t _id);

/// 
/// \brief 生成 NPL 用户ID
///
NPL_API NPL_USRID CreateNplUsrID(uint32_t _id);

/// 
/// \brief 生成 NPL 服务器ID
///
NPL_API NPL_SVRID CreateNplSvrID(uint32_t _id);

/// 
/// \brief 生成 NPL 大厅ID
///
NPL_API NPL_LBYID CreateNplLbyID(uint32_t _id);

/// 
/// \brief  获取用户Token
/// 
/// \return token
///
NPL_API cstr_t GetUserToken();

///
/// \brief  获取用户ID
///
/// \return 用户ID
/// 
NPL_API NPL_USRID GetUserId();

/// 
/// \brief 获取应用接口
///
NPL_API INplApp* GetNplApp();

}

#endif // __NPL_BASE_H__
