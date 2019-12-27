#ifndef __NPL_DEFINES_H__
#define __NPL_DEFINES_H__

#include "npl-macros.h"

///内存对齐大小
#define NPL_PACK_SIZE 4
/// 文件名长度
#define NPL_FILE_LEN		260
/// 路径名长度
#define NPL_PATH_LEN		260
/// 角色名长度
#define NPL_USERNAME_LEN    128
/// 好友分组ID长度
#define NPL_GROUP_ID_LEN    64
/// 好友分组名称长度
#define NPL_GROUP_NAME_LEN	128
/// 服务器名称长度
#define NPL_SERVER_NAME_LEN       64
/// 服务器主机地址长度
#define NPL_SERVER_HOST_LEN       32
/// 服务器地图名称长度
#define NPL_SERVER_MAP_NAME_LEN   32
/// 服务器Mod Dir
#define NPL_SERVER_MOD_DIR_LEN    32
/// 服务器标签长度
#define NPL_SERVER_TAGS_LEN       128
/// 服务器 description
#define NPL_SERVER_DESCRIPTION_LEN 64
/// 服务器游戏数据长度
#define NPL_SERVER_GAME_DATA_LEN  2048
/// 服务器version长度
#define NPL_SERVER_VERSION_LEN 64
/// 统计事件的API名称长度
#define NPL_STATISTICS_EVENT_NAME_LEN 128
/// 成就的API名称长度
#define NPL_ACHIEVEMENT_NAME_LEN 128
/// 成就统计事件的描述长度
#define NPL_ACHIEVEMENT_DESC_LEN 128
/// 成就达成点数url
#define NPL_ACHIEVEMENT_ICON_LEN 256
/// 成就属性长度
#define NPL_ACHIEVEMENT_ATTR_LEN 256
/// 排行榜arg名长度
#define NPL_LEADERBOARD_ARG_NAME_LEN 64
/// 查询发布内容结果最大个数
#define NPL_ENUM_PUBLISHED_FILE_MAX_RESULT 50
/// 发布内容通用查询结果最大个数
#define NPL_UGC_SEARCH_MAX_RESULT 128
/// 发布内容的title的长度
#define NPL_PUBLISHED_FILE_TITLE_NAME_LEN 256
/// 发布内容的描述的长度
#define NPL_PUBLISHED_FILE_DESCRIPTION_LEN  8192
/// 发布内容的Tag的长度
#define NPL_PUBLISHED_FILE_TAG_LEN  1025

/// 聊天消息ID长度
#define NPL_CHAT_MAX_MSG_ID_LEN 256
/// 最大文件路径长度
#define NPL_CHAT_MAX_FILE_PATH_LEN 1024
/// 最大文件扩展名长度
#define NPL_CHAT_MAX_FILE_EXT_LEN 64
/// 聊天最大消息内容长度
#define NPL_CHAT_MAX_CONTENT_LEN 5000

/// 大厅信息 max key
#define NPL_MATCHMAKING_MAX_DATA_KEY 100
/// 大厅信息 max value
#define NPL_MATCHMAKING_MAX_DATA_VALUE 256
/// 大厅信息 max total-json-length
#define NPL_MATCHMAKING_MAX_DATA_TOTAL_LENGTH 4096

/// 认证秘钥长度
const size_t NPL_ENCRYPTED_APP_TICKET_KEYLEN = 16;

/// 
/// \brief  AuthTicket句柄
///
typedef long AuthTicketHandle_t;
/// 
/// \brief  AuthTicket无效值
///
const AuthTicketHandle_t AuthTicketInvalid = 0;


///
/// \brief 共享内存事件号
/// 
enum eSharedEvent
{
	eShared_Startup = 0,
	eShared_UserToken = 1,
	eShared_User = 2,
	eShared_Shutdown = 3,
	eShared_Chat = 4,
	eShared_DlcCount = 5,
	eShared_DlcDetail = 6,
	eShared_DlcIsInstall = 7,
	eShared_DlcInstall = 8,
	eShared_DlcUninstall = 9,
};

#define NPL_MAKE_MSG_ID(module_id, msg_id) (module_id * 100 + msg_id)

enum { enNplException = 0 };
enum { enNplUser = 100 };
enum { enNplCais = 200 };
enum { enNplFriend = 300 };
enum { enNplLeaderboard = 400 };
enum { enNplMatchMaking = 500 };
enum { enNplStorage = 600 };
enum { enNplGameServer = 700 };
enum { enNplApp = 800 };
enum { enNplChat = 900 };
enum { enNplVoice = 1000 };
enum { enNetwork = 1100 };
enum { enNplHtmlSurface = 1200 };
enum { enNplServerMatchmaking = 1300 };

///
/// \brief  事件编号
///
enum eNplEvent_t
{
	eEvent_UserOnline = 1000,
	eEvent_UserOffline = 1001,

	/// matchmaking
	eEvent_MatchmakingLobbyInfoUpdate = enNplMatchMaking + 2,
	eEvent_MatchmakingUserEnterNewLobby = enNplMatchMaking + 3,
	eEvent_MatchmakingLobbyNewUserEnter = enNplMatchMaking + 4,
	eEvent_MatchmakingApplyEnterLobbyAudit = enNplMatchMaking + 5,
	eEvent_MatchmakingBeinviteEnterLobby = enNplMatchMaking + 6,
	eEvent_MatchmakingUserLeaveLobby = enNplMatchMaking + 7,
	eEvent_MatchmakingBekickout = enNplMatchMaking + 8,
	eEvent_MatchmakingKickoutLobbyMessage = enNplMatchMaking + 9,
	eEvent_MatchmakingUserInfoUpdate = enNplMatchMaking + 10,

	/// server match
	eEvent_ServerMatchRefresh = enNplServerMatchmaking + 1,

	/// friend
	eEvent_FriendMessage = enNplFriend + 4,

	/// statis
	eEvent_StatisticsTriggerEvent = enNplLeaderboard + 1,

	/// Remote Storage
	eEvent_StorageStreamWriteAbort = 1200,
	eEvent_StorageSyncFiles,

	eEvent_StoragePushFile = enNplStorage + 1,
	eEvent_StoragePullFile = enNplStorage + 2,
	eEvent_StorageStreamWriteChunk = enNplStorage + 5,
	eEvent_StorageStreamWriteClose = enNplStorage + 6,
	eEvent_StorageForgotFile = enNplStorage + 7,
};

enum eBeginAuthSessionResult
{
	/// 认证有效
	eBeginAuthSessionResult_ok,
	/// ticket 无效
	eBeginAuthSessionResult_invalidTicket,
	/// 重复认证
	eBeginAuthSessionResult_duplicateRequest,
	/// 无效的版本号
	eBeginAuthSessionResult_invalidVersion,
	/// 没有对应游戏
	eBeginAuthSessionResult_gameMismatch,
	/// ticket 失效
	eBeginAuthSessionResult_expiredTicket,
};

/// 无效的NPL_ID
#define INVALID_LAUNCHERID (-1)
#define INVALID_NPLID		NPL_ID(0)
#define ZERO_NPLID			NPL_ID(0)

enum enNPLIDType
{
	nplid_app = 0,    // appID
	nplid_usr = 1,    // userID
	nplid_svr = 2,    // serverID
	nplid_lby = 3,    // lobbyID
};

#pragma pack(push, 1)
/// 游戏ID
struct NPL_ID
{
	union
	{
		struct
		{
			uint32_t id;
			enNPLIDType type : 8;
			uint32_t instance : 8;
			uint32_t source : 16;
		} info;
		uint64_t id;
	};

	NPL_ID() : id(ZERO_NPLID)
	{
	}
	NPL_ID(uint64_t _id) : id(_id)
	{
	}
	NPL_ID(enNPLIDType type, uint32_t account)
	{
		info.id = account;
		info.type = type;
		info.instance = 0;
		info.source = 0;
	}
	NPL_ID(enNPLIDType type, sint32_t account)
	{
		info.id = account;
		info.type = type;
		info.instance = 0;
		info.source = 0;
	}

	NPL_ID& operator=(uint64_t _id)
	{
		this->id = _id;
		return *this;
	}

	operator uint64_t() const
	{
		return this->id;
	}

	/*operator int() const
	{
		return this->info.id;
	}*/

	bool operator==(const NPL_ID& _id)
	{
		return this->id == _id.id;
	}

	bool operator==(uint64_t _id)
	{
		return this->id == _id;
	}

	bool operator<(const NPL_ID& _id)
	{
		return this->id < _id.id;
	}

	bool operator<(uint64_t _id)
	{
		return this->id < _id;
	}

private:
	NPL_ID& operator=(sint32_t)
	{
		return *this;
	}
	NPL_ID& operator=(uint32_t)
	{
		return *this;
	}
};

#pragma pack(pop)

typedef NPL_ID NPL_APPID;
/// 用户ID
typedef NPL_ID NPL_USRID;
/// 游戏服务器ID
typedef NPL_ID NPL_SVRID;
/// 游戏大厅ID
typedef NPL_ID NPL_LBYID;

enum eAppSwitch
{
	/// 调试模式
	eSwitch_Debug = 0,
	/// 允许同一个APP开多个实例
	eSwitch_MoreApp = 1,
};
typedef void(*NplEventCallBack)(long err, pvoid_t params);

/// 
/// \brief  日志级别
///
enum eLogLevel
{
	/// debug
	eLogger_Debug = 0,
	/// info
	eLogger_Info,
	/// warning
	eLogger_Warning,
	/// error
	eLogger_Error,
	/// system
	eLogger_System,

	/// disable
	eLogger_Disable,
};

#endif // __NPL_DEFINES_H__
