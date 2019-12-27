///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \file npl-app.h
///
/// \brief NPL Application Functional
///

#ifndef __NPL_APP_H__
#define __NPL_APP_H__

#pragma pack(push, NPL_PACK_SIZE)

///
/// \brief 内嵌UI窗口类型
///
enum enOverlayWindowType
{
	enOverlayWindowPay = 1,      /// 支付窗口
};
///
/// \brief 安装进度回调信息
///
struct cbAppInstallPercent_t
{
	enum { iEvtType = enNplApp + 1 };
	/// 正在安装的应用ID
	NPL_APPID appId;
	/// 安装进度百分比, 范围[0 - 100]
	float percent;
	/// 安装错误码 0: 成功  1: 失败
	uint32_t errcode;
};

///
/// \brief 卸载进度回调信息
///
struct cbAppUninstallPercent_t
{
	enum { iEvtType = enNplApp + 2 };
	/// 正在卸载的应用ID
	NPL_APPID appID;
	/// 卸载进度百分比, 范围[0 - 100]
	float percent;
	/// 卸载错误码 0: 成功  1: 失败
	uint32_t errcode;
};

///
/// \brief 平台异常关闭通知，如果游戏未调用IsStopGameWhenLaunchStop函数，SDK将结束进程
///
struct cbAppLaunchStopNotify_t
{
	enum { iEvtType = enNplApp + 3 };
	/// 错误码 0: 异常关闭
	uint32_t errcode;
};

///
/// \brief 窗口被打开
///
struct cbAppOverlayWindowOpened_t
{
	enum { iEvtType = enNplApp + 4 };

	uint32_t windowType;					/// \see enum OverlayWindowType
};

///
/// \brief 窗口被关闭
///
struct cbAppOverlayWindowClosed_t
{
	enum { iEvtType = enNplApp + 5 };

	uint32_t windowType;
};

#pragma pack(pop)

#ifndef __NPL_C_INTERFACE__
namespace npl
{
///
/// \brief 应用程序相关接口
///
struct NPL_API INplApp
{
	///
	/// \brief 检查当前用户是否订阅过当前应用 
	///        Checks if the active user is subscribed to the current App ID.
	///
	/// \return 已经订阅返回true, 否则false
	///
	virtual bool IsSubscribed() = 0;
	///
	/// \brief 检查当前用户是否订阅过指定应用 
	///        Checks if the active user is subscribed to a specified AppId.
	///
	/// \param appId 应用程序ID
	///
	/// \return 已经订阅返回true, 否则false
	///
	virtual bool IsSubscribedApp(const NPL_APPID & appId) = 0;

	///
	/// \brief 获得DLC数量
	///
	/// \return 返回所有已经购买DLC数量
	///
	virtual int GetDLCCount() = 0;

	///
	/// \brief 查询DLC信息(未实现)
	///
	virtual bool BGetDLCDataByIndex(int iDLC, NPL_APPID* pAppID, bool* pbAvailable, char *pchName, int cchNameBufferSize) = 0;

	///
	/// \brief 检查DLC是否已经安装
	///
	/// \param gameID DLC ID
	///
	/// \return 已经安装返回true, 否则false
	///
	virtual bool IsInstalled(const NPL_APPID & gameId) = 0;

	///
	/// \brief 安装DLC
	///
	/// \param gameID DLC ID
	///
	/// \see 安装进度回调函数参数, 参见: cbAppInstallPercent_t
	///
	virtual void Install(const NPL_APPID & gameId) = 0;

	///
	/// \brief 卸载DLC
	///
	/// \param gameID DLC ID
	///
	/// \see 卸载进度回调函数参数, 参见: cbAppUninstallPercent_t
	///
	virtual void Uninstall(const NPL_APPID & gameId) = 0;

	///
	/// \brief 查询当前游戏用户设置的语言
	///
	/// \return 返回国家区域码, 默认 "zh-CN"
	///
	virtual cstr_t GetCurrentGameLanguage() = 0;

	///
	/// \brief 查询UI界面的语言
	///
	/// \return 返回国家区域码, 默认 "zh-CN"
	///
	virtual cstr_t GetUILanguage() = 0;

	///
	/// \brief 游戏收到 cbAppLaunchStopNotify_t 通知时，决定是否关闭游戏
	///
	/// \param isStopGame 是否关闭游戏，如果不调用此函数，SDK将终止游戏进程
	///
	virtual void IsStopGameWhenLaunchStop(bool isStopGame) = 0;

	///
	/// \brief 打开商城支付界面
	///
	/// \param strTitle 商品名称
	/// \param nPrice 支付价格
	/// \param strProduct 订单
	/// \param strCustomData 自定义数据
	///
	virtual bool OpenPaymentOverlay(cstr_t strTitle, float nPrice, cstr_t strProduct, cstr_t strCustomData) = 0;

  ///
  /// \brief Show Overlay page
  ///
  /// \param type overlay page type
  /// \param param show parameter
  ///
  virtual void ShowOverlayPage(enOverlayWindowType type, cstr_t param) = 0;

  ///
  /// \brief Hide Overlay page
  ///
  /// \param type overlay page type
  ///
  virtual void HideOverlayPage(enOverlayWindowType type) = 0;
};
}
#endif // __NPL_C_INTERFACE__
#endif // __NPL_APP_H__
