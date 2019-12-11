///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \file npl-servermatchmaking.h
///
/// \brief NPL matchmaking servers functional.
///
#ifndef _NPL_SERVERMATCHMAKING_H
#define _NPL_SERVERMATCHMAKING_H

#pragma pack(push, NPL_PACK_SIZE)
///
/// \brief  服务器详细信息
///
/// \see    GetServerDetails 
///
struct ServerDetail_t
{
	/// 应用ID
	NPL_APPID appID;
	/// 服务器ID
	NPL_SVRID serverID;
	/// 主机地址
	uint32_t ip;
	/// 主机端口
	uint16_t port;
	/// 玩家数量
	sint32_t players;
	/// 玩家最大数量
	sint32_t playersMax;
	/// 机器人数量
	sint32_t playersBot;
	/// ping time in millisecond (valid at PingServer)
	sint32_t ping;
	/// 上次游戏时间戳 (TODO)
	uint64_t lastPlayed;
	/// 是否有密码
	bool password;
	/// 版本号
	char version[NPL_SERVER_VERSION_LEN];
	/// 名字
	char name[NPL_SERVER_NAME_LEN];
	/// 地图名称
	char mapName[NPL_SERVER_MAP_NAME_LEN];
	/// desc
	char desc[NPL_SERVER_DESCRIPTION_LEN];
	/// 标签信息
	char tags[NPL_SERVER_TAGS_LEN];
	/// game dir
	char gameDir[NPL_SERVER_MOD_DIR_LEN];
};

///
/// \brief  服务器刷新通知结构
/// \see     RefreshServer
///
struct cbRefreshNotify_t
{
	enum { iEvtType = enNplServerMatchmaking + 1 };
	/// 异步请求的Token
	long itoken;
	/// 服务器ID
	NPL_SVRID serverID;
	/// 服务器所在游标
	sint32_t index;
};

/// 
/// \brief  请求服务器列表回执
///
struct cbQueryServers_t
{
	enum { iEvtType = enNplServerMatchmaking + 2 };
	/// 异步请求的Token
	long itoken;
};

class INplServerMatchmakingPingResponse
{
public:
	// Server has responded successfully and has updated data
	virtual void ServerResponded(ServerDetail_t& detail) = 0;

	// Server failed to respond to the ping request
	virtual void ServerFailedToRespond() = 0;
};

class INplServerMatchmakingPlayersResponse
{
public:
	// Got data on a new player on the server -- you'll get this callback once per player
	// on the server which you have requested player data on.
	virtual void AddPlayerToList(NPL_USRID uid, const char *pchName, int nScore, float flTimePlayed) = 0;

	// The server failed to respond to the request for player details
	virtual void PlayersFailedToRespond() = 0;

	// The server has finished responding to the player details request 
	// (ie, you won't get anymore AddPlayerToList callbacks)
	virtual void PlayersRefreshComplete() = 0;
};

class INplServerMatchmakingRulesResponse
{
public:
	// Got data on a rule on the server -- you'll get one of these per rule defined on
	// the server you are querying
	virtual void RulesResponded(const char *pchRule, const char *pchValue) = 0;

	// The server failed to respond to the request for rule details
	virtual void RulesFailedToRespond() = 0;

	// The server has finished responding to the rule details request 
	// (ie, you won't get anymore RulesResponded callbacks)
	virtual void RulesRefreshComplete() = 0;
};


#pragma pack(pop)

#ifndef __NPL_C_INTERFACE__
namespace npl
{
	///
	/// \brief server matchmaking interface
	/// 
	struct NPL_API INplServerMatchmaking
	{
	public:
		///
		/// \note   服务器列表过滤器符号
		///         括号：()，并且：&&，或者：||，大于：>，大于等于：>=，小于：<，小于等于：<=，等于：==，不等于：!=，包含：=~
		///         >， >=， <， <= 后面的值为数值类型（不带单引号）如：fieldName > 100, 不能为 fieldName > '100'
		///         =~， ==，!= 后面的值为字符串，（带单引号），如： filedName == 'war3' , 不能为 filedName == war3
		///

		///
		/// \brief  请求英特网服务器列表
		///
		/// \param  filter 服务器少选过滤器
		/// \return 异步请求的Token
		/// 
		/// \note   filter参考服务器列表过滤器符号
		/// \see    RegistCallback cbQueryServers_t
		///
		virtual long QueryInternetServers(cstr_t filter) = 0;

		///
		/// \brief  请求局域网服务器列表
		///
		/// \param  filter 服务器少选过滤器
		/// \return 异步请求的Token
		/// 
		/// \note   filter参考服务器列表过滤器符号
		/// \see    RegistCallback cbQueryServers_t
		///
		virtual long QueryLanServers(cstr_t filter) = 0;

		///
		/// \brief  请求好友服务器列表
		///
		/// \param  filter 服务器少选过滤器
		/// \return 异步请求的Token
		/// 
		/// \note   filter参考服务器列表过滤器符号
		/// \see    RegistCallback cbQueryServers_t
		///
		virtual long QueryFriendServers(cstr_t filter) = 0;

		///
		/// \brief  请求收藏的服务器列表
		///
		/// \param  filter 服务器少选过滤器
		/// \return 异步请求的Token
		/// 
		/// \note   filter参考服务器列表过滤器符号
		/// \see    RegistCallback cbQueryServers_t
		///
		virtual long QueryFavoritesServers(cstr_t filter) = 0;

		///
		/// \brief  请求历史服务器列表
		///
		/// \param  filter 服务器少选过滤器
		/// \return 异步请求的Token
		/// 
		/// \note   filter参考服务器列表过滤器符号
		/// \see    RegistCallback cbQueryServers_t
		///
		virtual long QueryHistoryServers(cstr_t filter) = 0;

		///
		/// \brief  请求观战服务器列表
		///
		/// \param  filter 服务器少选过滤器
		/// \return 异步请求的Token
		/// 
		/// \note   filter参考服务器列表过滤器符号
		/// \see    RegistCallback cbQueryServers_t
		///
		virtual long QuerySpectatorsServers(cstr_t filter) = 0;

		///
		/// \brief  取消指定Token的请求
		///
		/// \param  token 异步请求的Token
		///
		virtual void CancelQuery(long token) = 0;

		///
		/// \brief  清理指定Token的请求结果
		///
		/// \param  token 异步请求的Token
		///
		virtual void ReleaseQuery(long token) = 0;

		///
		/// \brief  获取指定请求返回的服务器数量
		///
		/// \param  token 异步请求的Token
		/// \return 服务器数量
		///
		virtual long GetServerCount(long token) = 0;

		///
		/// \brief  通过游标获取指定请求的服务器数量
		///
		/// \param  token 异步请求的Token
		/// \param  index 游标
		/// \return ServerDetail_t 服务器详细信息
		///         若失败，返回nullptr
		/// 
		/// \note   游标不应大于GetServerCount的返回结果
		///
		virtual ServerDetail_t* GetServerDetails(long token, sint32_t index) = 0;

		///
		/// \brief  刷新指定服务器
		///
		/// \param  token 异步请求的Token
		/// \param  serverID 服务器ID
		/// 
		/// \note   serverID = -1 标识刷新token对应返回的所有服务器
		/// \see    RegistCallback cbRefreshNotify_t
		///
		virtual void RefreshServer(long token, NPL_SVRID serverID) = 0;

		/// 
		/// \brief  ping server
		/// 
		/// \param  ip 目标IP
		/// \param  port 目标端口（gameServer queryPort）
		/// \param  response 回调对象（为确保安全，在这个对象置为失效前，请调用CancelServerQuery）
		///
		virtual long PingServer(uint32_t ip, uint16_t port, INplServerMatchmakingPingResponse* response) = 0;

		/// 
		/// \brief  request server player detail
		/// 
		/// \param  ip 目标IP
		/// \param  port 目标端口（gameServer queryPort）
		/// \param  response 回调对象（为确保安全，在这个对象置为失效前，请调用CancelServerQuery）
		///
		virtual long PlayerDetails(uint32_t ip, uint16_t port, INplServerMatchmakingPlayersResponse* response) = 0;

		/// 
		/// \brief  request server rules (INplGameServer::SetKeyValue)
		/// 
		/// \param  ip 目标IP
		/// \param  port 目标端口（gameServer queryPort）
		/// \param  response 回调对象（为确保安全，在这个对象置为失效前，请调用CancelServerQuery）
		///
		virtual long ServerRules(uint32_t ip, uint16_t port, INplServerMatchmakingRulesResponse* response) = 0;

		/// 
		/// \brief  取消一项未完成的单个服务器查询
		///
		/// \param  tok PingServer/PlayerDetails/ServerRules 的返回值
		///
		virtual void CancelServerQuery(long tok) = 0;
	};
};
#endif // __NPL_C_INTERFACE__
#endif // _NPL_SERVERMATCHMAKING_H
