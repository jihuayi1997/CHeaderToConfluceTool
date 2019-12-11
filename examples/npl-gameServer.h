///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \file npl-gameServer.h
///
/// \brief NPL game server functional
///
#ifndef _NPL_GAMESERVER_H
#define _NPL_GAMESERVER_H

/// 
/// \brief  游戏服务器标记
///
enum eGameServerFlag
{
	/// none
	eGameServerFlag_none = 0x00,
	/// server has users playing
	eGameServerFlag_active = 0x01,
	/// server wants to be secure
	eGameServerFlag_secure = 0x02,
	/// server is dedicated
	eGameServerFlag_dedicated = 0x04,
	/// linux build
	eGameServerFlag_linux = 0x08,
	/// password protected
	eGameServerFlag_passworded = 0x10,
	/// server shouldn't list on master server and
	eGameServerFlag_private = 0x20,
};

#pragma pack(push, NPL_PACK_SIZE)

/// 
/// \brief  玩家认证通过
///
struct cbGSClientApprove_t
{
	enum { iEvtType = enNplGameServer + 1 };
	/// 玩家ID
	NPL_USRID userID;
};

/// 
/// \brief  玩家认证失败
///
struct cbGSClientDeny_t
{
	enum { iEvtType = enNplGameServer + 2 };
	/// 玩家ID
	NPL_USRID userID;
	npl::enDenyReason enDeny;
};

/// 
/// \brief  玩家结束了认证
///
/// \note   client CancelAuthTicket/TerminateGameConnection
///
struct cbGSClientKick_t
{
	enum { iEvtType = enNplGameServer + 3 };
	/// source NPL_ID (userID or gameServerID who GetAuthSessionTicket or client user InitiateGameConnection)
	NPL_ID srcID;
	/// target NPL_ID (userID or gameServerID which BeginAuthTicket/SendUserConnectAndAuthenticate)
	NPL_ID dstID;
	npl::enDenyReason enDeny;
};

#pragma pack(pop)

#ifndef __NPL_C_INTERFACE__
namespace npl
{
	struct NPL_API INplGameServer
	{
	public:
		///
		/// \brief  init gameserver
		///
		/// \param  IP 将绑定的 IP 地址（应使用主机序，即 127.0.0.1 == 0x7f000001）。您可使用 INADDR_ANY 来与所有的本地 IPv4 地址绑定。
		/// \param  gamePort 进行游戏时，客户端要连接至的端口。
		/// \param  queryPort 管理服务器浏览器相关事务以及来自客户端的信息Ping 的端口。(0 使用socket-shared-mode)
		/// \param  flags 一个或多个 ServerFlags 的并集
		/// \param  appID 服务器所针对游戏的 AppID。
		/// \param  pchVersionString 版本字符串通常以 x.x.x.x 的形式呈现，在服务器过期时由主服务器用于进行检测（只有最新版本的服务器会被列出）。
		/// \return true-成功 false-失败
		/// 
		/// \note   
		///
		virtual bool InitGameServer(uint32_t IP, uint16_t gamePort, uint16_t queryPort, uint32_t flags, const NPL_APPID& appID, cstr_t pchVersionString) = 0;

		///
		/// \brief  设置服务器名称
		///
		/// \param  pszServerName 服务器名称
		///
		/// \note   必要设置，LogOn之前
		/// 
		virtual void SetServerName(cstr_t pszServerName) = 0;

		///
		/// \brief  设置要报告给服务器浏览器的地图名称
		///
		/// \param  pszMapName 地图名称
		///
		/// \note   必要设置，LogOn之前
		/// 
		virtual void SetMapName(cstr_t pszMapName) = 0;

		///
		/// \brief  设置此服务器一次最多可容纳的玩家人数
		///
		/// \param  cPlayersMax 玩家人数
		///
		/// \note   必要设置，LogOn之前
		/// 
		virtual void SetMaxPlayerCount(int cPlayersMax) = 0;

		///
		/// \brief  设置游戏服务器中机器人或 AI 玩家的数量。默认值为零
		///
		/// \param  cBotplayers 服务器中机器人或 AI 玩家的数量
		///
		virtual void SetServerBotPlayerCount(int cBotplayers) = 0;

		///
		/// \brief  设置服务器观战端口
		///
		/// \param  spectatorPort 观战端口
		///
		virtual void SetSpectatorPort(uint16_t spectatorPort) = 0;

		///
		/// \brief  设置准备注册的服务器描述
		///
		/// \param  value 描述
		///
		virtual void SetServerDescription(cstr_t value) = 0;

		/// 
		/// \brief  设置mod dir
		///
		/// \param  value 值
		///
		virtual void SetServerModDir(cstr_t value) = 0;

		///
		/// \brief  设置准备注册的服务器密码
		///
		/// \param  bPasswordProtected 密码
		///
		virtual void SetPasswordProtected(bool bPasswordProtected) = 0;

		///
		/// \brief  设置准备注册的服务器标记信息
		///
		/// \param  value 标记信息
		/// 
		/// \note   tags长度NPL_SERVER_TAGS_LEN
		///
		virtual void SetServerTags(cstr_t value) = 0;

		///
		/// \brief  设置准备注册的服务器游戏数据信息
		///
		/// \param  value 游戏数据
		/// 
		/// \note   gameData长度NPL_SERVER_GAME_DATA_LEN
		///
		virtual void SetServerGameData(cstr_t value) = 0;

		///
		/// \brief  设置准备注册的服务器服务区域
		///
		/// \param  value 服务器服务区域
		///
		virtual void SetServerRegion(cstr_t value) = 0;

		///
		/// \brief  设置游戏产品标识符
		///
		/// \param  value 产品标识符
		///
		virtual void SetServerProduct(cstr_t value) = 0;

		///
		/// \brief  登录
		///  
		/// \note   将会链接Npl服务器，并注册InitGameServer初始化的服务器信息
		///         
		///         如果链接注册成功将会有cbNplServersConnected_t的通知
		///         注册失败将会有cbNplServerConnectFailure_t的通知
		///
		virtual void LogOnAnonymous() = 0;

		///
		/// \brief  取得服务器的公网IP
		///
		/// \return IP的主机序，如果无法判定 IP，返回 0
		///
		virtual uint32_t GetPublicIP() = 0;

		///
		/// \brief  检查游戏服务器是否已登录
		///
		/// \return 如果游戏服务器已登录，为 true，否则为 false。
		///
		virtual bool BLoggedOn() = 0;

		///
		/// \brief  断开与NPL服务器的链接
		///
		virtual void LogOff() = 0;

		//         /// TODO:
		//         virtual bool BeSucure() = 0;
		// 
		//         /// TODO:
		//         virtual NPL_USRID CreateUnauthenticatedUserConnection() = 0;

		/// 
		/// \brief  增加/更新 键值对
		///
		virtual void SetKeyValue(cstr_t ptrKey, cstr_t ptrValue) = 0;

		/// 
		/// \brief  清空所有键值
		///
		virtual void ClearAllKeyValues() = 0;

		/// 
		/// \brief  设置观战服务器名
		///
		/// \param  ptrName 观战服务器名称
		/// \note   该数据可以通过ServerRules查询，Key值为 _SpectatorServerName
		///
		virtual void SetSpectatorServerName(cstr_t ptrName) = 0;

		/// 
		/// \brief  更新已经连接到服务器的玩家数据
		///
		/// \param  uid 玩家ID
		/// \param  userName 玩家名字
		/// \param  score 玩家分数
		/// \return true: 成功 false: 失败（uid 对应用户并没有连接到当前服务器 BeginAuthSession/SendUserConnectAndAuthenticate）
		///
		virtual bool BUpdateUserData(const NPL_USRID& uid, cstr_t userName, sint32_t score) = 0;

		///
		/// \brief  获取认证Ticket
		///
		/// \param  pTicket 接收认证信息的缓冲区
		/// \param  cbMaxTicket 接收认证信息的缓冲区长度（尽量长的定义该缓冲区，认证信息可能有1024字节）
		/// \param  pcbTicket 认证信息的长度
		/// \return 认证信息句柄
		///
		virtual AuthTicketHandle_t GetAuthSessionTicket(pvoid_t pTicket, sint32_t cbMaxTicket, uint32_t* pcbTicket) = 0;

		/// 
		/// \brief  取消认证票据
		/// \param  hAuthTicket 认证票据句柄
		///
		/// \see    GetAuthSessionTicket
		///
		virtual void CancelAuthTicket(AuthTicketHandle_t hAuthTicket) = 0;

		/// 
		/// \brief  认证nplid相关的票据
		/// \param  pAuthTicket 票据 （GetAuthSessionTicket 获得的票据）
		/// \param  cbAuthTicket 票据长度
		/// \param  nplid 票据来源者NPL ID
		/// \return 认证结果枚举
		///
		virtual eBeginAuthSessionResult BeginAuthSession(cvoid_t pAuthTicket, int cbAuthTicket, const NPL_ID& nplid) = 0;

		/// 
		/// \brief  结束票据认证
		/// \param  nplid 票据来源者NPL ID
		///
		virtual void EndAuthSession(const NPL_ID& nplid) = 0;

		///
		/// \brief  发送认证玩家
		///
		/// \param  unIPClient 游戏客户端IP
		/// \param  pAuthBlob  认证信息 （InitiateGameConnection 获得的票据）
		/// \param  unAuthBlobSize 认证信息长度
		/// \param  pUserID  认证玩家的ID（不可为空）
		/// \return true-执行成功，会有cbGSClientApprove_t或者cbGSClientDeny_t的事件通知
		///         false-执行失败
		/// 
		/// \note   
		/// \see    cbGSClientApprove_t / cbGSClientDeny_t
		///
		virtual bool SendUserConnectAndAuthenticate(uint32_t unIPClient, cvoid_t pAuthBlob, uint32_t unAuthBlobSize, NPL_USRID* pUserID) = 0;

		///
		/// \brief  发送玩家断开连接
		///
		/// \param  userID 玩家ID
		///
		virtual void SendUserDisconnect(const NPL_USRID& userID) = 0;

		/// 
		/// \brief 心跳
		/// 
		/// \param  bActive false-关闭 true-开启
		///
		virtual void EnableHeartbeats(bool bActive) = 0;

		/// 
		/// \brief 主动发送一次心跳
		///
		virtual void ForceHeartbeats() = 0;

		///
		/// \brief  获取服务器ID
		///
		/// \return 服务器ID
		///
		virtual NPL_SVRID GetNplServerID() = 0;

		/// 
		/// \brief  在socket-shared-mode模式下处理master-server数据包。
		/// 
		/// \param  pData 传入的数据包
		/// \param  cbData 传入数据包的长度
		/// \param  srcIP 来源IP
		/// \param  srcPort 来源port
		/// \return true: 成功 false: 失败（错误的包）
		///
		/// \note   udp package(PingServer/PlayerDetails/ServerRules) package start with 0xFFFFFFFF 
		///         if it return true, you should call GetNextOutgoingPacket
		///
		virtual bool HandleIncomingPacket(cstr_t pData, int cbData, uint32_t srcIP, uint16_t srcPort) = 0;

		/// 
		/// \brief  在socket-shared-mode模式下获得HandleIncomingPacket回执数据包
		///
		/// \param  pOut 接收数据包的缓冲 （maybe 500 byte）
		/// \param  cbMaxOut 接收数据包缓冲的大小
		/// \param  pNetAdr 接收目标IP
		/// \param  pNetPort 接收目标端口
		/// \return 实际数据包的长度
		///
		/// \note   should send out on UDP 
		///
		virtual int GetNextOutgoingPacket(pvoid_t* pOut, int cbMaxOut, uint32_t* pNetAdr, uint16_t* pNetPort) = 0;
	};
};
#endif __NPL_C_INTERFACE__

#endif _NPL_GAMESERVER_H
