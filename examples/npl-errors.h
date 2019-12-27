///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \file npl-error.h
///
/// \brief NPL error codes
///
#ifndef __NPL_ERROR_H__
#define __NPL_ERROR_H__
namespace npl
{
    enum errcode
    {
        ERR_OK = 0,
		ERR_FAILED = 1,
        /// 内存分配失败
        ERR_MEMORY_ALLOC = 2000,
        /// request was abort by user
        ERR_REQUEST_ABORT = 2001,
		/// response status code is not successful
		ERR_RESPONSE_STATUS = 2002,
		/// response not data
		ERR_RESPONSE_FAILED = 2003,
		/// response parsing are error.
        ERR_RESPONSE_PARSE = 2004,
        /// response result occus error.
        ERR_RESPONSE_DATA = 2005,
		/// response paramters occus error.
        ERR_RESPONSE_PARAMS = 2006,
		/// response occus memery error.
        ERR_RESPONSE_MEMORY = 2007,
        /// cannot found token
        ERR_RESPONSE_ETOKEN = 2008,
        /// check cannot access
        ERR_RESPONSE_ECHECK = 2009,
        /// 下载文件失败
        ERR_DOWNLOAD_FAILED = 2100,
        /// 下载被取消
        ERR_DOWNLOAD_CANCEL = 2101,
        /// 下载信息丢失
        ERR_DOWNLOAD_ETOKEN = 2102,	
		/// encryptedAppTicket duplicate
		ERR_ENCRYPTEDAPPTICKET_DUPLICATE = 2200,
		/// encryptedAppTicket 60s limit
		ERR_ENCRYPTEDAPPTICKET_LIMIT = 2201,
        /// 系统内部错误
        ERR_MATCHING_SYSTEM_INVALID = 2300,
        /// 名字为空
        ERR_MATCHING_NAME_EMPTY = 2301,
        /// 重复登录
        ERR_MATCHING_REPEAT_LOGIN = 2302,
        /// 玩家未找到或玩家不在线
        ERR_MATCHING_USER_NOTFOUND = 2303,
        /// 玩家已经有大厅了
        ERR_MATCHING_USER_INLOBBYYET = 2304,
        /// 玩家还没有大厅
        ERR_MATCHING_USER_NOTINLOBBYYET = 2305,
        /// 玩家没有申请过
        ERR_MATCHING_USER_NOTAPPLY = 2306,
        /// 玩家已经申请过
        ERR_MATCHING_USER_REPEATAPPLY = 2307,
        /// 玩家没有被邀请
        ERR_MATCHING_USER_NOTBEINVITE = 2308,
        /// 玩家被重复邀请
        ERR_MATCHING_USER_REPEATINVITE = 2309,
        /// 大厅未找到 
        ERR_MATCHING_LOBBY_NOTFOUND      = 2310,
        /// 大厅权限不够
        ERR_MATCHING_LOBBY_LIMITAUTH = 2311,
        /// 大厅成员上限太小
        ERR_MATCHING_LOBBY_MEMTOOMIN = 2312,
        /// 大厅成员未找到
        ERR_MATCHING_LOBBY_MEMNOTFOUND = 2313,
        /// 不能操作自己
        ERR_MATCHING_LOBBY_OPERSELFLIMIT = 2314,
        /// 大厅已满
        ERR_MATCHING_LOBBY_FULL = 2315,
        /// 大厅拒绝申请加入
        ERR_MATCHING_LOBBY_APPLYLIMIT = 2316,
        /// 大厅申请密码错误
        ERR_MATCHING_LOBBY_APPLYPASSWORD = 2317,
        /// 大厅不允许加入
        ERR_MATCHING_LOBBY_INJOINABLE = 2318,
        /// 存储系统内部错误
		ERR_STORAGE_INTERNAL = 2400,
        /// 游戏服务器注册失败
        ERR_GAMESVR_REGISTER = 2500,
        /// 游戏服务器连接失败
        ERR_GAMESVR_CONNTIMEOUT = 2501,
        /// UGC上下文句柄丢失
		ERR_UGC_HANDLE_LOST = 2600,
        /// UGC打开文件错误
		ERR_UGC_OPEN_FILE = 2601,
        /// UGC读取文件错误
		ERR_UGC_READ_FILE = 2602,
        /// UGC获取元数据错误
		ERR_UGC_METADATA = 2603,

		/// 登录会话id错误
		ERR_VOICE_SESSION_ID = 2701,
		/// 指定的会话没被创建
		ERR_VOICE_SESSION_CREATE_FAILED = 2704,
		/// 服务器地址解析失败 
		ERR_VOICE_HOST_RESOLVE_FAILED = 2705,
		/// info解析失败
		ERR_VOICE_JOIN_INFO_RESOLVE_FAILED = 2707,

		/// 连接成功
		ERR_VOICE_CONNECT_SUC = 2800,
		/// 连接服务器失败，内部会重试，使用者可以不管
		ERR_VOICE_CONNECT_FAILED = 2801,
		/// 正常断开，包括服务器主动断开和客户端主动断开，如果是服务器主动断开，内部会自动重连
		ERR_VOICE_DISCONNECT = 2807,
		/// 客户端断线，内部会自动重连
		ERR_VOICE_CLIENT_DISCONNECT = 2808,
		/// 聊天房间不存在
		ERR_VOICE_STREAM_NOT_EXIST = 2809,
		/// 同时登录人过多，内部会重试，使用者可以不管
		ERR_VOICE_LOGIN_FULL = 2810,
		/// 服务器已满，内部会尝试其他地址，使用者可以不管
		ERR_VOICE_SERVER_FULL = 2811,
		/// 已尝试过所有地址，所有都返回full，不再尝试
		ERR_VOICE_CONNECT_SERVER_FAILED = 2812,
		/// 用户被禁止，使用者自行决定要做什么
		ERR_VOICE_USER_IS_BAN = 2813,

		//群错误码
		ERR_CHAT_TeamECountLimit		= 2921,		/// 已达到人数限制
		ERR_CHAT_TeamENAccess			= 2922,		/// 没有权限
		ERR_CHAT_TeamENotExist			= 2923,		/// 群不存在
		ERR_CHAT_TeamEMemberNotExist	= 2924,		/// 用户不在兴趣组里面
		ERR_CHAT_TeamErrType			= 2925,		/// 群类型不对
		ERR_CHAT_TeamLimit				= 2926,		/// 创建群数量限制
		ERR_CHAT_TeamUserStatusErr		= 2927,		/// 群成员状态不对
		ERR_CHAT_TeamApplySuccess		= 2928,		/// 申请成功
		ERR_CHAT_TeamAlreadyIn			= 2929,		/// 已经在群里
		ERR_CHAT_TeamInviteSuccess		= 2930,		/// 邀请成功
		ERR_CHAT_ForcePushCountLimit	= 2931,		/// 强推列表账号数量超限
		ERR_CHAT_TeamMemberLimit		= 2933,		/// 操作成功，但部分成员的群数量超限
	};

    /// 
    /// \brief  认证失败的原因枚举
    /// \see    cbGSClientDeny_t
    ///
    enum enDenyReason
    {
        /// 未知错误
        enDenyInvalid = 0,
        /// 错误的版本号
        enDenyInvalidVersion = 1,
        /// 通用错误码
        enDenyGeneric = 2,
    };
}

#endif // __NPL_ERROR_H__
