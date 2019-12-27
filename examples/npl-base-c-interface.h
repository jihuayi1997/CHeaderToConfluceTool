///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \file npl-c-interface.h
///
/// \brief NPL c api export
///

#ifndef __NPL_BASE_C_INTERFACE_H__
#define __NPL_BASE_C_INTERFACE_H__

#define __NPL_C_INTERFACE__
#include "npl-macros.h"
#include "npl-defines.h"

#include "npl-app.h"
#include "npl-cais.h"

#ifdef __cplusplus
extern "C"
{
#endif
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
	NPL_API uint64_t NplGetAppId();

	///
	/// \brief get the game install directory.
	/// 
	/// \note  获取当前运行进程的安装目录。
	/// 
	NPL_API cstr_t NplGetSetupDir();

	/// 
/// \brief  set logger level (default info)
	///
	NPL_API void NplSetLogLevel(eLogLevel eLv);

	/// 
	/// \brief  获取用户Token
	/// 
	/// \return token
	///
	NPL_API cstr_t NplGetUserToken();

	///
	/// \brief  获取用户ID
	///
	/// \return 用户ID
	/// 
	NPL_API uint64_t NplGetUserId();

	///
	/// \brief 回调注册
	/// 
	/// \note  回调注册函数用于注册异步调用函数的回调。在 SDK 中异步函数会返回一个 long 类型的 Token 值（该值保证不重复），当异步函数执行完毕，
	///        SDK 会检查该Token上是否有注册回调，并进行调用。SDK 提供了一个回调函数的驱动 API NplRunCallback 需要开发者在主线程进行轮询，以保证所有开发者接触到的代码都处于同一线程中。
	/// 
	NPL_API bool RegistCallback(long iCallback, NplEventCallBack cb);

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
	NPL_API bool RegistEvent(long iEvent, NplEventCallBack cb);

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
	/// \brief 生成 NPL 应用ID
	///
	NPL_API uint64_t CreateNplAppID(uint32_t _id);

	/// 
	/// \brief 生成 NPL 用户ID
	///
	NPL_API uint64_t CreateNplUsrID(uint32_t _id);


	///
	/// \brief 设置CoreDump的注释信息
	///
	/// \param pchMsg 用户自定义信息
	///
	NPL_API void NplSetMiniDumpComment(const char *pchMsg);

	///
	/// \brief 创建minidump
	/// 
	/// \param uStructuredExceptionCode MiniDump类型, \see: https://docs.microsoft.com/en-us/windows/desktop/api/minidumpapiset/ne-minidumpapiset-_minidump_type
	/// \param pvExceptionInfo 实际的异常内容
	/// \param uBuildID 用于追溯生成dump文件的应用程序版本信息
	///
	NPL_API void NplWriteMiniDump(uint32_t uStructuredExceptionCode, void* pvExceptionInfo, uint32_t uBuildID);

	///
	/// \brief 打开商城支付界面
	///
	/// \param strTitle 商品名称
	/// \param nPrice 支付价格
	/// \param strProduct 订单
	/// \param strCustomData 自定义数据
	///
	NPL_API bool NplOpenPaymentOverlay(cstr_t strTitle, float nPrice, cstr_t strProduct, cstr_t strCustomData);

	///
	/// \brief 游戏收到 cbAppLaunchStopNotify_t 通知时，决定是否关闭游戏
	///
	/// \param isStopGame 是否关闭游戏，如果不调用此函数，SDK将终止游戏进程
	///
	NPL_API void npl_app_IsStopGameWhenLaunchStop(bool isStopGame);

	///
	/// \brief 查询当前游戏用户设置的语言
	///
	NPL_API cstr_t npl_app_GetCurrentGameLanguage();

	///
	/// \brief 查询UI界面设置的语言
	///
	NPL_API cstr_t npl_app_GetUILanguage();

	///
	/// \brief 检查当前用户是否订阅过当前应用 
	///        Checks if the active user is subscribed to the current App ID.
	///
	NPL_API bool npl_app_BIsSubscribed();

	///
	/// \brief 检查当前用户是否订阅过指定应用 
	///        Checks if the active user is subscribed to a specified AppId.
	///
	NPL_API bool npl_app_BIsSubscribedApp(uint64_t appID);

	///
	/// \brief 获取当前订阅的dlc数量
	/// \return number of DLC pieces
	///
	NPL_API int npl_app_GetDLCCount();

	///
	/// \brief 获得DLC信息
	/// \iDLC 通过npl_app_GetDLCCount()函数获得的索引
	/// \pAppID DLC的App ID
	/// \pchName DLC名称
	/// \cchNameBufferSize DLC名称最大长度
	/// \return iDLC是否在[0, npl_app_GetDLCCount())范围内
	///
	NPL_API bool npl_app_BGetDLCDataByIndex(int iDLC, uint64_t* pAppID, bool* pbAvailable, char *pchName, int cchNameBufferSize);

	///
	/// \brief 安装DLC
	/// \pAppID DLC的App ID
	///
	NPL_API void npl_app_InstallDLC(uint64_t nAppID);

	///
	/// \brief 卸载DLC
	/// \pAppID DLC的App ID
	///
	NPL_API void npl_app_UninstallDLC(uint64_t nAppID);

  ///
  /// \brief Show Overlay page
  ///
  /// \param type overlay page type
  /// \param param show parameter
  ///
  NPL_API void npl_app_ShowOverlayPage(uint32_t type, cstr_t param);

  ///
  /// \brief Hide Overlay page
  ///
  /// \param type overlay page type
  ///
  NPL_API void npl_app_HideOverlayPage(uint32_t type);

	///
	/// \brief Checks if the user owns a specific DLC and if the DLC is installed
	///
	NPL_API bool npl_app_BIsDlcInstalled(uint64_t appID);

#ifdef __cplusplus
}
#endif
#endif // !__NPL_BASE_C_INTERFACE_H__

