///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \file npl-c-interface.h
///
/// \brief NPL c api export
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
#endif
	///
	/// \brief  用户是否已登录游戏
	///
	/// \param 
	/// \return 用户是否登录
	/// 
	/// \note   
	/// \see
	///
	NPL_API bool npl_User_UserIsLogon();

	///
	/// \brief  获取用户ID
	///
	/// \param  
	/// \return 用户ID
	/// 
	/// \note   
	/// \see    
	///
	NPL_API uint64_t npl_User_GetUserId();

	///
	/// \brief  获取当前用户账号
	///
	/// \return 用户账号
	/// 
	/// \note   
	/// \see    
	///
	NPL_API cstr_t npl_User_GetUserName();

	/// 
	/// \brief  获取用户Token
	/// 
	/// \return token
	///
	NPL_API cstr_t npl_User_GetUserToken();

	///
	/// \brief  获取用户数据保存路径
	///
	/// \param  
	/// \return 用户数据保存路径
	/// 
	/// \note   
	/// \see    
	///
	NPL_API cstr_t npl_User_GetUserDirectory();

	///
	/// \brief  请求用户游戏数据
	///
	/// \param  
	/// \return 异步请求的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbUserDataReceived_t
	///
	NPL_API long npl_User_RequestUserData();

	///
	/// \brief  请求指定用户的游戏数据
	///
	/// \param  userId 用户ID
	/// \return 异步请求的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbUserDataReceived_t
	///
	NPL_API long npl_User_RequestUserDataByUserId(uint64_t userId);

	///
	/// \brief  当前用户是否存在指定游戏数据
	///
	/// \param  key 游戏数据名
	/// \return 游戏数据是否存在
	/// 
	/// \note   
	/// \see    
	///
	NPL_API bool npl_User_IsExistData(cstr_t key);

	///
	/// \brief  获取当前用户游戏数据sint64_t值
	///
	/// \param  key 游戏数据名
	/// \param  default 数据名不存在时的默认值
	/// \return 游戏数据值
	/// 
	/// \note   
	/// \see    
	///
	NPL_API sint32_t npl_User_GetDataInt32(cstr_t key, sint32_t default);

	///
	/// \brief  获取当前用户游戏数据sint64_t值
	///
	/// \param  key 游戏数据名
	/// \param  default 数据名不存在时的默认值
	/// \return 游戏数据值
	/// 
	/// \note   
	/// \see    
	///
	NPL_API sint64_t npl_User_GetDataInt64(cstr_t key, sint64_t default);

	///
	/// \brief  获取当前用户游戏数据real64_t值
	///
	/// \param  key 游戏数据名
	/// \param  default 数据名不存在时的默认值
	/// \return 游戏数据值
	/// 
	/// \note   
	/// \see    
	///
	NPL_API real64_t npl_User_GetDataReal(cstr_t key, real64_t default);

	///
	/// \brief  获取当前用户游戏数据cstr_t值
	///
	/// \param  key 游戏数据名
	/// \param  default 数据名不存在时的默认值
	/// \return 游戏数据值
	/// 
	/// \note   
	/// \see    
	///
	NPL_API cstr_t npl_User_GetDataString(cstr_t key, cstr_t default);

	///
	/// \brief  指定用户是否存在指定游戏数据
	///
	/// \param  userId 指定用户ID
	/// \param  key 游戏数据名
	/// \return 游戏数据是否存在
	/// 
	/// \note   
	/// \see    
	///
	NPL_API bool npl_User_IsUserExistData(uint64_t userId, cstr_t key);

	///
	/// \brief  获取当前用户游戏数据sint32_t值
	///
	/// \param  userId 指定用户ID
	/// \param  key 游戏数据名
	/// \param  default 数据名不存在时的默认值
	/// \return 游戏数据值
	/// 
	/// \note   
	/// \see    
	///
	NPL_API sint32_t npl_User_GetUserDataInt32(uint64_t userId, cstr_t key, sint32_t default);

	///
	/// \brief  获取当前用户游戏数据sint64_t值
	///
	/// \param  userId 指定用户ID
	/// \param  key 游戏数据名
	/// \param  default 数据名不存在时的默认值
	/// \return 游戏数据值
	/// 
	/// \note   
	/// \see    
	///
	NPL_API sint64_t npl_User_GetUserDataInt64(uint64_t userId, cstr_t key, sint64_t default);

	///
	/// \brief  获取当前用户游戏数据real64_t值
	///
	/// \param  userId 指定用户ID
	/// \param  key 游戏数据名
	/// \param  default 数据名不存在时的默认值
	/// \return 游戏数据值
	/// 
	/// \note   
	/// \see    
	///
	NPL_API real64_t npl_User_GetUserDataReal(uint64_t userId, cstr_t key, real64_t default);

	///
	/// \brief  获取当前用户游戏数据cstr_t值
	///
	/// \param  userId 指定用户ID
	/// \param  key 游戏数据名
	/// \param  default 数据名不存在时的默认值
	/// \return 游戏数据值
	/// 
	/// \note   
	/// \see    
	///
	NPL_API cstr_t npl_User_GetUserDataString(uint64_t userId, cstr_t key, cstr_t default);

	///
	/// \brief  设置当前用户的游戏数据
	///
	/// \param  key 游戏数据名
	/// \param  value 游戏数据sint32_t值
	/// \return 是否设置成功
	/// 
	/// \note   设置后，若未保存则不影响NPL服务器上的数据
	/// \see    
	///
	NPL_API bool npl_User_SetDataInt32(cstr_t key, sint32_t value);

	///
	/// \brief  设置当前用户的游戏数据
	///
	/// \param  key 游戏数据名
	/// \param  value 游戏数据sint64_t值
	/// \return 是否设置成功
	/// 
	/// \note   设置后，若未保存则不影响NPL服务器上的数据
	/// \see    
	///
	NPL_API bool npl_User_SetDataInt64(cstr_t key, sint64_t value);

	///
	/// \brief  设置当前用户的游戏数据
	///
	/// \param  key 游戏数据名
	/// \param  value 游戏数据real64_t值
	/// \return 是否设置成功
	/// 
	/// \note   设置后，若未保存则不影响NPL服务器上的数据
	/// \see    
	///
	NPL_API bool npl_User_SetDataReal(cstr_t key, real64_t value);

	///
	/// \brief  设置当前用户的游戏数据
	///
	/// \param  key 游戏数据名
	/// \param  value 游戏数据cstr_t值
	/// \return 是否设置成功
	/// 
	/// \note   设置后，若未保存则不影响NPL服务器上的数据
	/// \see    
	///
	NPL_API bool npl_User_SetDataString(cstr_t key, cstr_t value);

	///
	/// \brief  更新当前用户的均值数据
	///
	/// \param  fSessionCount 自上一次更新以来的累积值
	/// \param  fSessionSeconds 自上一次更新以来的经过的秒数
	/// \return 是否更新成功
	/// 
	/// \note   更新后，若未保存则不影响NPL服务器上的数据
	/// \see    
	///
	NPL_API bool npl_User_UpdAvgData(cstr_t key, real32_t fSessionCount, real64_t fSessionSeconds);

	///
	/// \brief  保存当前用户数据
	///
	/// \param  
	/// \return 异步请求的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbUserDataUpload_t
	///
	NPL_API long npl_User_SaveUserData();

	///
	/// \brief  清除当前用户所有数据
	///
	/// \param  
	/// \return 
	/// 
	/// \note   清除后，若未保存则不影响NPL服务器上的数据
	/// \see    
	///
	NPL_API void npl_User_ClearUserData();

	///
	/// \brief  请求全局游戏数据
	///
	/// \param  nHistoryDays 几天前的历史数据
	/// \return 异步请求的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbGlobalDataReceived_t
	///
	NPL_API long npl_User_RequestGlobalData(int nHistoryDays);

	///
	/// \brief  获取全局游戏数据sint64_t值
	///
	/// \param  key 游戏数据名
	/// \param  default 数据名不存在时的默认值
	/// \return 游戏数据值
	/// 
	/// \note   
	/// \see    
	///
	NPL_API sint64_t npl_User_SGetGlobalData(const char *key, sint64_t default);

	///
	/// \brief  获取全局游戏数据real64_t值
	///
	/// \param  key 游戏数据名
	/// \param  default 数据名不存在时的默认值
	/// \return 游戏数据值
	/// 
	/// \note   
	/// \see    
	///
	NPL_API real64_t npl_User_RGetGlobalData(const char *key, real64_t default);

	///
	/// \brief  获取全局游戏数据cstr_t值
	///
	/// \param  key 游戏数据名
	/// \param  default 数据名不存在时的默认值
	/// \return 游戏数据值
	/// 
	/// \note   
	/// \see    
	///
	NPL_API cstr_t npl_User_CGetGlobalData(const char *key, cstr_t default);

	///
	/// \brief  设置自己的昵称
	///
	/// \param  nickName 昵称
	/// \return 异步请求的Token
	/// 
	/// \note 
	/// \see   RegistCallback cbNickNameChange_t
	///
	NPL_API sint32_t npl_User_SetNickName(cstr_t nickName);

	///
	/// \brief  获取自己的昵称
	///
	/// \param  
	/// \return 自己的昵称
	/// 
	/// \note   
	/// \see    
	///
	NPL_API cstr_t npl_User_GetNickName();

	/// 
	/// \brief 生成 NPL 服务器ID
	///
	NPL_API uint64_t CreateNplSvrID(uint32_t _id);

	/// 
	/// \brief 生成 NPL 大厅ID
	///
	NPL_API uint64_t CreateNplLbyID(uint32_t _id);

	///
	/// \brief  游戏服务器初始化
	///
	/// \param  IP 将绑定的 IP 地址（应使用主机序，即 127.0.0.1 == 0x7f000001）。您可使用 INADDR_ANY 来与所有的本地 IPv4 地址绑定。
	/// \param  gamePort 进行游戏时，客户端要连接至的端口。
	/// \param  queryPort 管理服务器浏览器相关事务以及来自客户端的信息Ping 的端口。
	/// \param  flags 一个或多个 ServerFlags 的并集
	/// \param  appID 服务器所针对游戏的 AppID。
	/// \param  pchVersionString 版本字符串通常以 x.x.x.x 的形式呈现，在服务器过期时由主服务器用于进行检测（只有最新版本的服务器会被列出）。
	/// \return true-成功 false-失败    
	///
	NPL_API bool NplGameServer_Init(uint32_t IP, uint16_t gamePort, uint16_t queryPort, uint32_t flags, uint64_t appID, cstr_t pchVersionString);

	///
	/// \brief invoke result callback
	/// 
	/// \note  该函数需要在主线程中调用，用于驱动回调函数的处理逻辑。
	/// 
	NPL_API void NplGameServer_RunCallback();

	///
	/// \brief termination npl library at the end.
	/// 
	/// \note  进程退出前需调用 NplShutdown 进行清理，否则可能出现内存泄漏等异常情况。
	/// 
	NPL_API void NplGameServer_Shutdown();

	/// 
	/// \brief  解密加密的Ticket
	///
	/// \param  ticketEncrypted 用户验证的票证
	/// \param  ticketEncryptedBytes ticketEncrypted字节大小
	/// \param  ticketDecrypted 返回解密票证的缓冲区
	/// \param  ticketDecryptedBytes ticketDecrypted字节大小
	/// \param  byKey 秘钥（由NPL分配）
	/// \param  cuKey 秘钥长度
	///
	/// \return 是否解密成功 true-成功，false-失败（票证解密失败）
	///
	NPL_API bool NplEncryptedAppTicket_DecryptTicket(cbyte_t ticketEncrypted, uint32_t ticketEncryptedBytes, pbyte_t ticketDecrypted, uint32_t* ticketDecryptedBytes, const byte_t byKey[NPL_ENCRYPTED_APP_TICKET_KEYLEN], int cuKey);

	/// 
	/// \brief  用户是否拥有指定的appID
	///
	/// \param  ticketDecrypted 解密的票证
	/// \param  ticketDecryptedBytes ticketDecrypted字节大小
	/// \param  appID 用于验证的appID
	///
	/// \return 是否拥有指定appID true-拥有，false-失败（票证无效或者没有该appID）
	///
	NPL_API bool NplEncryptedAppTicket_UserOwnsAppInTicket(cbyte_t ticketDecrypted, uint32_t ticketDecryptedBytes, uint64_t appID);

	/// 
	/// \brief  获取票证里的appID
	///
	/// \param  ticketDecrypted 解密的票证
	/// \param  ticketDecryptedBytes ticketDecrypted字节大小
	///
	/// \return appID，若失败返回ZERO_NPLID
	///
	NPL_API uint64_t NplEncryptedAppTicket_GetTicketAppID(cbyte_t ticketDecrypted, uint32_t ticketDecryptedBytes);

	/// 
	/// \brief  获取票证里的UserID
	///
	/// \param  ticketDecrypted 解密的票证
	/// \param  ticketDecryptedBytes ticketDecrypted字节大小
	/// \param  pUsrID 返回用户的ID，若失败返回ZERO_NPLID
	///
	NPL_API void NplEncryptedAppTicket_GetTicketUserID(cbyte_t ticketDecrypted, uint32_t ticketDecryptedBytes, uint64_t* pUsrID);

	/// 
	/// \brief  获取票证里的时间戳
	///
	/// \param  ticketDecrypted 解密的票证
	/// \param  ticketDecryptedBytes ticketDecrypted字节大小
	///
	/// \return 票证时间戳（秒），若失败返回0
	///
	NPL_API uint64_t NplEncryptedAppTicket_GetTicketIssueTime(cbyte_t ticketDecrypted, uint32_t ticketDecryptedBytes);

	/// 
	/// \brief  获取票证里的用户数据
	///
	/// \param  ticketDecrypted 解密的票证
	/// \param  ticketDecryptedBytes ticketDecrypted字节大小
	/// \param  pcubUserData 返回用户数据大小
	///
	/// \return 返回指向用户数据的指针，若失败返回nullptr
	///
	NPL_API cbyte_t NplEncryptedAppTicket_GetUserVariableData(cbyte_t ticketDecrypted, uint32_t ticketDecryptedBytes, uint32_t* pcubUserData);

	/**
	   friend.h
	*/
	///
	/// \brief  获取自己的名字
	///
	/// \param  
	/// \return 自己的名字
	/// 
	/// \note   
	/// \see    
	///
	NPL_API cstr_t npl_Friend_GetPersonName();

	///
	/// \brief  获取当前状态
	///
	/// \param  
	/// \return 状态
	/// 
	/// \note   
	/// \see     
	///
	NPL_API enPersonStatus npl_Friend_GetPersonStatus();

	///
	/// \brief  请求好友列表
	///
	/// \param  
	/// \return 异步请求Token
	/// 
	/// \note   
	/// \see    RegistCallback cbFriendListRequest_t
	///
	NPL_API long npl_Friend_FriendListRequest();

	///
	/// \brief  获取好友数量
	///
	/// \param  
	/// \return 好友数量
	/// 
	/// \note   
	/// \see     
	///
	NPL_API long npl_Friend_GetFriendCount();

	///
	/// \brief  通过游标获取好友ID
	///
	/// \param  index 游标
	/// \return 好友ID
	/// 
	/// \note   游标不应大于GetFriendCount返回值
	/// \see    
	///
	NPL_API uint64_t npl_Friend_GetFriendByIndex(int nIndex);

	///
	/// \brief  获取好友名字
	///
	/// \param  uid 好友ID
	/// \return 名字
	/// 
	/// \note   
	/// \see    
	///
	NPL_API cstr_t npl_Friend_GetFriendName(uint64_t uid);

	///
	/// \brief  获取好友状态
	///
	/// \param  uid 好友ID
	/// \return 状态
	/// 
	/// \note   
	/// \see    
	///
	NPL_API enPersonStatus npl_Friend_GetFriendStatus(uint64_t uid);

	///
	/// \brief  获取用户好友关系
	///
	/// \param  uid 用户ID
	/// \return 关系
	/// 
	/// \note   
	/// \see    
	///
	NPL_API enRelationship npl_Friend_GetFriendRelationship(uint64_t uid);

	///
	/// \brief  获取好友分组数量
	///
	/// \param  
	/// \return 分组数量
	/// 
	/// \note   
	/// \see     
	///
	NPL_API long npl_Friend_GetGroupCount();

	///
	/// \brief  获取是否存在指定分组
	///
	/// \param  groupName 分组名称
	/// \return 是否存在该分组
	/// 
	/// \note   
	/// \see     
	///
	NPL_API bool npl_Friend_HasGroup(cstr_t groupName);

	///
	/// \brief  通过游标获取分组ID
	///
	/// \param  index 游标
	/// \return 分组ID
	/// 
	/// \note   游标不应大于GetFriendGroupCount返回值
	/// \see     
	///
	NPL_API cstr_t npl_Friend_GetGroupId(int index);

	///
	/// \brief  通过游标获取分组名称
	///
	/// \param  index 游标
	/// \return 分组名称
	/// 
	/// \note   游标不应大于GetFriendGroupCount返回值
	/// \see    
	///
	NPL_API cstr_t npl_Friend_GetGroupNameByIndex(int index);

	///
	/// \brief  通过分组ID获取分组名称
	///
	/// \param  gid 分组ID
	/// \return 分组名称
	/// 
	/// \note   
	/// \see     
	///
	NPL_API cstr_t npl_Friend_GetGroupNameByGid(cstr_t gid);

	///
	/// \brief  获取指定好友所在分组ID
	///
	/// \param  uid 好友ID
	/// \return 分组ID
	/// 
	/// \note   
	/// \see    
	///
	NPL_API cstr_t npl_Friend_GetFriendGroupId(uint64_t uid);

	///
	/// \brief  获取指定好友所在分组名称
	///
	/// \param  uid 好友ID
	/// \return 分组名称
	/// 
	/// \note   
	/// \see    
	///
	NPL_API cstr_t npl_Friend_GetFriendGroupName(uint64_t uid);

	///
	/// \brief  获取指定分组好友数量
	///
	/// \param  gid 分组ID
	/// \return 好友数量
	/// 
	/// \note   
	/// \see    
	///
	NPL_API long npl_Friend_GetGroupMembersCount(cstr_t gid);

	///
	/// \brief  获取指定分组好友用户ID列表
	///
	/// \param  gid 分组ID
	/// \param  membersOut 接收用户ID列表指针
	/// \param  membersCount 接收用户ID列表个数
	/// \return 写入的用户ID个数
	/// 
	/// \note   
	/// \see    
	///
	NPL_API long npl_Friend_GetGroupMembersList(cstr_t gid, uint64_t membersOut[], long membersCount);

	///
	/// \brief  是否与指定用户是好友关系
	///
	/// \param  uid 用户ID
	/// \return 是否是好友
	/// 
	/// \note   
	/// \see    
	///
	NPL_API bool npl_Friend_HasFriend(uint64_t uid);

	///
	/// \brief  邀请指定用户成为好友
	///
	/// \param  uid 用户ID
	/// \return 异步调用的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbFriendRelationResult_t
	///
	NPL_API long npl_Friend_InviteFriend(uint64_t uid);

	///
	/// \brief  接受好友邀请
	///
	/// \param  uid 用户ID
	/// \return 异步调用的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbFriendRelationResult_t
	///
	NPL_API long npl_Friend_AcceptFriend(uint64_t uid);

	///
	/// \brief  拒绝好友邀请
	///
	/// \param  uid 用户ID
	/// \return 异步调用的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbFriendRelationResult_t
	///
	NPL_API long npl_Friend_RefuseFriend(uint64_t uid);

	///
	/// \brief  忽略指定的好友消息
	///
	/// \param  uid 用户ID
	/// \param  cancel true - 取消忽略状态，false - 增加忽略状态
	/// \return 异步调用的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbFriendRelationResult_t
	///
	NPL_API long npl_Friend_IgnoreFriend(uint64_t uid, bool cancel);

	///
	/// \brief  将指定好友加入黑名单
	///
	/// \param  uid 用户ID
	/// \param  cancel true - 取消拉黑状态，false - 增加拉黑状态
	/// \return 异步调用的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbFriendRelationResult_t
	///
	NPL_API long npl_Friend_BlockFriend(uint64_t uid, bool cancel);

	///
	/// \brief  将指定好友删除
	///
	/// \param  uid 用户ID
	/// \return 异步调用的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbFriendRelationResult_t
	///
	NPL_API long npl_Friend_DeleteFriend(uint64_t uid);

	///
	/// \brief  设置好友分组
	///
	/// \param  uid 用户ID
	/// \param  groupName 分组名称
	/// \return 异步调用的Token
	/// 
	/// \note   设置好友分组可以将好友移动到指定的组中，若该组名不存在就会创建一个新组，并将好友移入。在调用完成时，系统会调用注册在Token上的回调，并传入cbFriendSetGroupResult_t结构参数
	/// \see    RegistCallback cbFriendSetGroupResult_t
	///
	NPL_API long npl_Friend_SetFriendGroup(uint64_t uid, cstr_t groupName);

	///
	/// \brief  删除好友分组
	///
	/// \param  groupName 分组名称
	/// \return 异步调用的Token
	/// 
	/// \note   删除好友分组可以删除一个没有好友的分组，若这个分组有好友在，则会删除失败。在调用完成时，系统会调用注册在Token上的回调，并传入cbFriendDelGroupResult_t结构参数
	/// \see    RegistCallback cbFriendDelGroupResult_t
	///
	NPL_API long npl_Friend_DeleteFriendGroup(cstr_t groupName);

	///
	/// \brief  发送聊天消息
	///
	/// \param  uid 用户ID
	/// \param  message 要发送的聊天内容
	/// \return 异步调用的Token
	/// 
	/// \note   暂不支持
	/// \see     
	///
	NPL_API bool npl_Friend_SendChatMessage(uint64_t uid, cstr_t message);

	///
	/// \brief  发送房间消息
	///
	/// \param  roomId 房间ID
	/// \param  message 要发送的聊天内容
	/// \return 异步调用的Token
	/// 
	/// \note   暂不支持
	/// \see     
	///
	NPL_API bool npl_Friend_SendRoomMessage(cstr_t roomId, cstr_t message);

	///
	/// \brief  查看好友是否在游戏中，并返回相应信息
	///
	/// \param  uid 好友的用户ID
	/// \param  pInfo 返回正在游玩的相关信息
	/// \return 是否在游戏中
	/// 
	/// \note 
	/// \see     
	///
	NPL_API bool npl_Friend_GetFriendGamePlayed(uint64_t uid, FriendGameInfo_t* pInfo);

	///
	/// \brief  设置当前用户完整状态
	///
	/// \param  key 数据键值
	/// \param  value 数据值
	/// \return 是否成功
	/// 
	/// \note 
	/// \see     
	///
	NPL_API bool npl_Friend_SetRichPresence(cstr_t key, cstr_t value);

	///
	/// \brief  获取指定好友的完整状态值
	///
	/// \param uid 用户ID
	/// \param key 完整状态键值
	/// \return  完整状态值
	/// 
	/// \note 
	/// \see     
	///
	NPL_API cstr_t npl_Friend_GetFriendRichPresence(uint64_t uid, cstr_t key);

	///
	/// \brief  获取指定用户上设定的完整状态键数量
	///
	/// \param uid 用户ID
	/// \return  完整状态数量
	/// 
	/// \note 
	/// \see     
	///
	NPL_API sint32_t npl_Friend_GetFriendRichPresenceKeyCount(uint64_t uid);

	///
	/// \brief  按索引获取指定用户上设定的完整状态键值
	///
	/// \param uid 用户ID
	/// \param idx 索引值
	/// \return  完整状态键值
	/// 
	/// \note idx 取值在 0 和 GetFriendRichPresenceKeyCount 之间
	/// \see     
	///
	NPL_API cstr_t npl_Friend_GetFriendRichPresenceKeyByIndex(uint64_t uid, sint32_t idx);

	///
	/// \brief  清除当前用户完整状态
	///
	/// \param
	/// \return
	/// 
	/// \note 
	/// \see     
	///
	NPL_API void npl_Friend_ClearRichPresence();

	///
	/// \brief  请求指定用户的完整状态
	///
	/// \param  uid 用户ID
	/// \return
	/// 
	/// \note 
	/// \see    RegistCallback cbFriendRichPresenceUpdate_t
	///
	NPL_API void npl_Friend_RequestFriendRichPresence(uint64_t uid);

	///
	/// \brief  检查指定用户是否在相应的来源中
	///
	/// \param  uid 用户ID
	/// \param  sourceID 来源ID
	/// \return 是否在sourceID指定的来源中
	/// 
	/// \note 
	/// \see     
	///
	NPL_API bool npl_Friend_IsUserInSource(uint64_t uid, uint64_t sourceID);

	///
	/// \brief  为指定用户获取中型（64*64 像素）头像的句柄
	///
	/// \param  uid 用户ID
	/// \return 图片句柄
	/// 
	/// \note 
	/// \see     
	///
	NPL_API sint32_t npl_Friend_GetMediumFriendAvatar(uint64_t uid);

	///
	/// \brief  请求指定用户的昵称及头像（可选）
	///
	/// \param  uid 用户ID
	/// \param  bReqNameOnly 是否只需要名字
	/// \return 如果本地没有缓存在返回true并下载对应数据完成后产生回调，否则返回false且可以马上取缓存的数据
	/// 
	/// \note 如果选择需要头像则会下载头像，可能会更费时。
	/// \see   RegistCallback cbRequestUserInformation_t
	///
	NPL_API bool npl_Friend_RequestUserInformation(uint64_t uid, bool bReqNameOnly);

	///
	/// \brief  设置指定用户为一起游玩过的
	///
	/// \param  uid 用户ID
	/// \return 
	/// 
	/// \note 
	/// \see     
	///
	NPL_API void npl_Friend_SetPlayedWith(uint64_t uid);

	///
	/// \brief 设置是否接受好友的消息
	///
	/// \param bInterceptEnabled 是否接收好友的消息
	/// 
	/// \see RegistEvent cbGameConnectedFriendChatMsg_t
	///
	NPL_API void npl_Friend_SetListenForFriendsMessages(bool bInterceptEnabled);

	///
	/// \brief 回复好友消息
	///
	/// \param friendID 好友id
	/// \param msgContent 消息内容
	///
	/// \return 消息id
	///
	NPL_API cstr_t npl_Friend_ReplyToFriendMessage(NPL_USRID friendID, cstr_t msgContent);

	///
	/// \brief 查询好友消息
	///
	/// \param friendID 好友id
	/// \param msgId 消息id
	/// \param[out] ppMsg 返回的消息内容
	///
	/// \note 此函数只能在 cbGameConnectedFriendChatMsg_t 回调中调用
	///
	NPL_API int npl_Friend_GetFriendMessage(NPL_USRID friendID, cstr_t msgId, void *pvData, int cubData, enChatMessageType *peChatEntryType);

	///
	/// \brief 向聊天群发送文本消息
	///
	/// \param teamId 接收群id
	/// \param content 文本内容
	///
	/// \see RegistEvent cbChatSendMsg_t
	///
	/// \return string 消息ID
	///
	NPL_API cstr_t npl_Friend_ReplyToTeamMessage(cstr_t teamId, cstr_t content);

	///
	/// \brief 向好友发送语音消息
	///
	/// \param senderId 发送者id
	/// \param audioResId 音频资源唯一ID
	///
	/// \see RegistEvent cbChatSendMsg_t
	/// 
	/// \return string 消息ID
	///
	NPL_API cstr_t npl_Friend_ReplyToFriendAudioMessage(NPL_USRID recverId, cstr_t audioResId);

	///
	/// \brief 聊天群发送语音消息
	///
	/// \param teamId 发送者id
	/// \param audioResId 音频资源唯一ID
	///
	/// \see RegistEvent cbChatSendMsg_t
	/// 
	/// \return string 消息ID
	///
	NPL_API cstr_t npl_Friend_ReplyToTeamAudioMessage(cstr_t teamId, cstr_t audioResId);

	///
	/// \brief 开始录音
	///
	/// \see RegistEvent cbChatStartCapture_t
	/// 
	/// \return string 声音资源ID
	///
	NPL_API cstr_t npl_Friend_StartAudioMessageCapture();

	///
	/// \brief 结束录音
	///
	/// \see RegistEvent cbChatStopCapture_t
	/// 
	NPL_API void npl_Friend_StopAudioMessageCapture();

	///
	/// \brief 取消录制语音
	/// 
	/// \param audioResId 声音资源id
	///
	NPL_API void npl_Friend_CancelAudioMessageCapture(cstr_t audioResId);

	///
	/// \brief 播放录音
	///
	/// \param file_path 文件路径
	///
	NPL_API void npl_Friend_PlayAudioMessage(cstr_t filePath);

	///
	/// \brief 停止播放
	///
	NPL_API void npl_Friend_StopAudioMessage();

	///
	/// \brief 创建群聊
	///
	/// \param teamName 群名称
	/// \param maxCount 群成员最大数量
	/// \param members 创建群时的成员
	/// \param memberCount members数值大小
	/// 
	/// \see RegistEvent cbChatTeamEventInfo_t
	/// 
	/// \note 群创建者，不能退群，只能解散群。其他人不能解散群只能退群。群主负责解散群
	///
	NPL_API void npl_Friend_CreateChatTeam(cstr_t teamName, uint32_t maxCount, NPL_USRID* members, sint32_t memberCount);

	///
	/// \brief 群聊邀请他人
	///
	/// \param teamId 群id
	/// \param members 被邀请人（可多人）
	/// \param memberCount members数值大小
	///
	/// \see RegistEvent cbChatTeamEventInfo_t
	/// 
	NPL_API void npl_Friend_ChatTeamInvite(cstr_t teamId, NPL_USRID* members, sint32_t memberCount);

	///
	/// \brief 解散群聊
	///
	/// \param teamId 群id
	///
	/// \see RegistEvent cbChatTeamEventInfo_t
	/// 
	NPL_API void npl_Friend_ChatTeamDismiss(cstr_t teamID);

	///
	/// \brief 离开群
	///
	/// \param teamId 群id
	///
	/// \see RegistEvent cbChatTeamEventInfo_t
	/// 
	NPL_API void npl_Friend_ChatTeamLeave(cstr_t teamID);

  ///
  /// \brief 查询单个群信息
  ///
  /// \param teamId 群聊id
  ///
  /// \see RegistEvent cbChatTeamEventInfo_t
  ///
  NPL_API void npl_Friend_QueryChatTeam(cstr_t teamId);

	///
	/// \brief 查询群所有成员信息
	///
	/// \param teamId 群聊id
	///
	/// \see RegistEvent cbChatTeamAllMembersInfo_t
	/// 
	NPL_API void npl_Friend_QueryChatTeamAllMembers(cstr_t teamId);

	///
	/// \brief 查询单个群成员信息
	///
	/// \param teamId 群聊id
	/// \param memberId 成员id
	///
	/// \see RegistEvent cbNplChatTeamMemberInfo_t
	///
	NPL_API void npl_Friend_QueryChatTeamMember(cstr_t teamId, NPL_USRID memberId);

	///
	/// \brief 查询当前用户创建的全部群
	///
	/// \see RegistEvent cbChatQueryAllCreatedTeams_T
	///
	NPL_API void npl_Friend_QueryAllCreatedChatTeams();

	///
	/// \brief 查询消息日志
	///
	/// \param id				查询id，对方的account id。 
	/// \param limit_count		本次查询的消息条数上限(最多100条)
	/// \param fromTime			开始时间
	/// \param endTime			结束时间
	///
	/// \see RegistEvent cbChatQueryMsgLog_t
	///
	NPL_API void npl_Friend_QueryFriendChatMessageLog(const NPL_USRID id, sint32_t limitCount, uint64_t fromTime, uint64_t endTime);

	///
	/// \brief 查询消息日志
	///
	/// \param id				群组id。 
	/// \param limit_count		本次查询的消息条数上限(最多100条)
	/// \param fromTime			开始时间
	/// \param endTime			结束时间
	///
	/// \see RegistEvent cbChatQueryMsgLog_t
	///
	NPL_API void npl_Friend_QueryTeamChatMessageLog(const cstr_t teamId, sint32_t limitCount, uint64_t fromTime, uint64_t endTime);

	/**
	matchmaking.h
	*/
	///
	/// \brief  创建大厅请求
	///
	/// \param  strLobbyName 大厅名称
	/// \param  dwMemberMax  成员上限
	/// \param  blInvisible  是否隐藏
	/// \param  enType       大厅类型
	/// \param  strPassword  大厅密码
	/// \return 异步请求的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbMatchmakingRequestResult_t
	///
	NPL_API long npl_Matchmaking_CreateLobby(cstr_t strLobbyName, uint32_t dwMemberMax, bool blInvisible, enLobbyType enType, cstr_t strPassword);

	///
	/// \brief  添加一个字符串类型的大厅搜索过滤器
	///
	/// \param  strKey        过滤器名
	/// \param  strValueMatch 过滤器值
	/// \param  oper          过滤器符号
	/// \return 是否添加成功
	///
	NPL_API bool npl_Matchmaking_AddRequestLobbyListStringFilter(cstr_t strKey, cstr_t strValueMatch, enFilterOperator oper);

	///
	/// \brief  添加一个数值类型的大厅搜索过滤器
	///
	/// \param  strKey        过滤器名
	/// \param  nValueMatch   过滤器值
	/// \param  oper          过滤器符号
	/// \return 是否添加成功
	///
	NPL_API bool npl_Matchmaking_AddRequestLobbyListNumericalFilter(cstr_t strKey, int nValueMatch, enFilterOperator oper);

	///
	/// \brief  添加一个剩余空位数量的大厅搜索过滤器
	///
	/// \param  nSlotsAvailable 最小剩余空位数
	/// \return 是否添加成功
	///
	NPL_API bool npl_Matchmaking_AddRequestLobbyListSlotsAvailable(int nSlotsAvailable);

	///
	/// \brief  添加一个距离的大厅搜索过滤器
	///
	/// \param  eLobbyDistanceFilter 过滤器枚举
	/// \return 是否添加成功
	///
	NPL_API bool npl_Matchmaking_AddRequestLobbyListDistanceFilter(enLobbyDistanceFilter eLobbyDistanceFilter);

	///
	/// \brief  添加一个近值类型的大厅搜索过滤器
	///
	/// \param  strKey        过滤器名
	/// \param  nValueToBeCloseTo   过滤器值
	/// \return 是否添加成功
	/// 
	/// \note   近过滤器实际上不会过滤掉值，它们只会影响结果的排序方式。您可以指定多个近似滤波器，第一个近滤波器影响最大，最后一个近滤波器影响最小。
	///
	NPL_API bool npl_Matchmaking_AddRequestLobbyListNearValueFilter(cstr_t strKey, sint32_t nValueToBeCloseTo);

	///
	/// \brief  请求大厅列表
	///
	/// \param  
	/// \return 异步请求的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbMatchmakingLobbyMatchList_t
	///
	NPL_API long npl_Matchmaking_RequestLobbyList();

	///
	/// \brief  获取查找到的大厅数量
	///
	/// \param  
	/// \return 大厅数量
	///
	NPL_API uint32_t npl_Matchmaking_GetLobbyCount();

	///
	/// \brief  通过游标获取大厅ID
	///
	/// \param  index 游标，不应大于GetLobbyCount返回的结果
	/// \return 大厅ID，0表示获取失败
	///
	NPL_API uint64_t npl_Matchmaking_GetLobbyByIndex(uint32_t index);

	///
	/// \brief  设置大厅数据
	///
	/// \param  lobbyID 大厅ID
	/// \param  key   大厅数据名
	/// \param  value 大厅数据值(字符串类型)
	/// \return 是否设置成功
	/// 
	/// \note   设置用户应是大厅创建者
	/// \see    设置后，若未提交大厅数据则不会影响NPL服务器上的数据
	///
	NPL_API bool npl_Matchmaking_SetLobbyStrData(uint64_t lobbyID, cstr_t key, cstr_t value);

	///
	/// \brief  设置大厅数据
	///
	/// \param  lobbyID 大厅ID
	/// \param  key   大厅数据名
	/// \param  value 大厅数据值(数值类型)
	/// \return 是否设置成功
	/// 
	/// \note   设置用户应是大厅创建者
	/// \see    设置后，若未提交大厅数据则不会影响NPL服务器上的数据
	///
	NPL_API bool npl_Matchmaking_SetLobbyNumericData(uint64_t lobbyID, cstr_t key, double value);

	///
	/// \brief  删除大厅指定数据
	///
	/// \param  lobbyID 大厅ID
	/// \param  key   大厅数据名
	/// \return 是否删除成功
	/// 
	/// \note   删除用户应是大厅创建者
	/// \see    设置后，若未提交大厅数据则不会影响NPL服务器上的数据 
	///
	NPL_API bool npl_Matchmaking_DelLobbyData(uint64_t lobbyID, cstr_t key);

	///
	/// \brief  提交大厅数据
	///
	/// \param  lobbyID 大厅ID
	/// \return 异步请求的Token
	/// 
	/// \note   提交用户应是大厅创建者
	/// \see    RegistCallback cbMatchmakingRequestResult_t
	///
	NPL_API long npl_Matchmaking_CommitLobbyData(uint64_t lobbyID);

	///
	/// \brief  设置大厅配置数据
	///
	/// \param  lobbyID 大厅ID
	/// \param  strLobbyName 大厅名称
	/// \param  dwMemberMax  成员上限
	/// \param  blInvisible  是否隐藏
	/// \param  enType       大厅类型
	/// \param  strPassword  大厅密码
	/// \return 异步回调的Token
	/// 
	/// \note   设置用户应是大厅创建者
	/// \see    RegistCallback cbMatchmakingRequestResult_t
	///
	NPL_API long npl_Matchmaking_SetLobbyConfig(uint64_t lobbyID, cstr_t strLobbyName, uint32_t dwMemberMax, bool blInvisible, enLobbyType enType, cstr_t strPassword);

	///
	/// \brief  设置大厅游戏服务器
	///
	/// \param  lobbyID 大厅ID
	/// \param  dwIP     IP值
	/// \param  wPort    端口值
	/// \param  dwServer 游戏服务器ID
	/// \return 异步回调的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbMatchmakingRequestResult_t
	///
	NPL_API long npl_Matchmaking_SetLobbyGameServer(uint64_t lobbyID, uint32_t dwIP, uint16_t wPort, uint32_t dwServer);

	///
	/// \brief  获取指定大厅数据(字符串)
	///
	/// \param  lobbyID 大厅ID
	/// \param  key       数据名
	/// \return 数据值
	///
	NPL_API cstr_t npl_Matchmaking_GetLobbyStrData(uint64_t lobbyID, cstr_t key);

	///
	/// \brief  获取指定大厅数据(数值)
	///
	/// \param  lobbyID 大厅ID
	/// \param  key       数据名
	/// \param  value     数据值
	/// \param  是否存在
	///
	NPL_API bool npl_Matchmaking_GetLobbyNumericData(uint64_t lobbyID, cstr_t key, double& value);

	/// 
	/// \brief  获取指定大厅元数据数量(字符串类型&数值类型)
	///
	/// \param  lobbyID 大厅ID
	/// \return 数据数量
	///
	NPL_API uint32_t npl_Matchmaking_GetLobbyDataCount(uint64_t lobbyID);

	/// 
	/// \brief  通过索引检查指定大厅数据是否是数值类型
	///
	/// \param  lobbyID 大厅ID
	/// \param  index 索引值，应小于GetLobbyDataCount返回值，[0, GetLobbyDataCount返回值)
	/// \return True:数值类型 false:字符串类型或者查找失败
	///
	NPL_API bool npl_Matchmaking_CheckLobbyDataIsNumericByIndex(uint64_t lobbyID, uint32_t index);

	/// 
	/// \brief  通过索引获取指定大厅数据(字符串类型)
	///
	/// \param  lobbyID 大厅ID
	/// \param  index 索引值，应小于GetLobbyDataCount返回值，[0, GetLobbyDataCount返回值)
	/// \param  pchKey 返回大厅元数据键
	/// \param  cchKeyBufferSize pchKey缓冲区长度，最大255
	/// \param  pchValue 返回大厅元数据值
	/// \param  cchValueBufferSize pchValue缓冲区长度，最大8192
	///
	NPL_API bool npl_Matchmaking_GetLobbyStrDataByIndex(uint64_t lobbyID, uint32_t index, char* pchKey, int cchKeyBufferSize, char* pchValue, int cchValueBufferSize);

	/// 
	/// \brief  通过索引获取指定大厅数据(数值类型)
	///
	/// \param  lobbyID 大厅ID
	/// \param  index 索引值，应小于GetLobbyDataCount返回值，[0, GetLobbyDataCount返回值)
	/// \param  pchKey 返回大厅元数据键
	/// \param  cchKeyBufferSize pchKey缓冲区长度，最大255
	/// \param  value 返回大厅元数据值
	///
	NPL_API bool npl_Matchmaking_GetLobbyNumericDataByIndex(uint64_t lobbyID, uint32_t index, char* pchKey, int cchKeyBufferSize, double* value);

	///
	/// \brief  获取指定大厅配置数据
	///
	/// \param  lobbyID       大厅ID
	/// \param  strLobbyName    大厅名称参数返回
	/// \param  dwLobbyNameSize 大厅名称参数返回长度
	/// \param  dwMemberMax     大厅成员上限参数返回
	/// \param  dwMemberCnt     大厅成员数量参数返回
	/// \param  enType          大厅类型参数返回
	/// \param  hasPassword     大厅是否有密码参数返回
	/// \return 是否获取成功
	///
	NPL_API bool npl_Matchmaking_GetLobbyConfig(uint64_t lobbyID, pstr_t strLobbyName, size_t dwLobbyNameSize, uint32_t& dwMemberMax, uint32_t& dwMemberCnt, enLobbyType& enType, bool& hasPassword);

	/// 
	/// \brief  设置大厅类型
	///
	/// \param  lobbyID 大厅ID
	/// \param  enType 大厅类型
	/// \return bool 是否设置成功
	///
	/// \note   设置自己拥有的大厅类型
	///
	NPL_API bool npl_Matchmaking_SetLobbyType(uint64_t lobbyID, enLobbyType enType);

	/// 
	/// \brief  是否有大厅密码
	///
	/// \param  lobbyID 大厅ID
	/// \return bool true:有大厅密码，false:没有密码或者大厅未找到
	///
	NPL_API bool npl_Matchmaking_HasLobbyPassword(uint64_t lobbyID);

	///
	/// \brief  设置大厅指定成员数据(字符串类型)
	///
	/// \param  lobbyID 大厅ID
	/// \param  uid 成员ID
	/// \param  key 数据名
	/// \param  value 数据值
	/// \return 是否设置成功
	/// 
	/// \note   用户应是大厅创建者
	/// \see    设置后，若未提交大厅数据则不会影响NPL服务器上的数据
	///
	NPL_API bool npl_Matchmaking_SetLobbyMemberStrData(uint64_t lobbyID, uint64_t uid, cstr_t key, cstr_t value);

	///
	/// \brief  设置大厅指定成员数据(数值类型)
	///
	/// \param  lobbyID 大厅ID
	/// \param  uid 成员ID
	/// \param  key 数据名
	/// \param  value 数据值
	/// \return 是否设置成功
	/// 
	/// \note   用户应是大厅创建者
	/// \see    设置后，若未提交大厅数据则不会影响NPL服务器上的数据
	///
	NPL_API bool npl_Matchmaking_SetLobbyMemberNumericData(uint64_t lobbyID, uint64_t uid, cstr_t key, double value);

	///
	/// \brief  删除大厅指定成员数据
	///
	/// \param  lobbyID 大厅ID
	/// \param  uid 成员ID
	/// \param  key 数据名
	/// \return 是否删除成功
	/// 
	/// \note   用户应是大厅创建者
	/// \see    删除后，若未提交大厅数据则不会影响NPL服务器上的数据
	///
	NPL_API bool npl_Matchmaking_DelLobbyUserData(uint64_t lobbyID, uint64_t uid, cstr_t key);

	///
	/// \brief  提交大厅成员数据变更
	///
	/// \param  lobbyID 大厅ID
	/// \param  uid 成员ID
	/// \return 异步请求的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbMatchmakingRequestResult_t
	///
	NPL_API long npl_Matchmaking_CommitLobbyUserData(uint64_t lobbyID, uint64_t uid);

	///
	/// \brief  获取指定大厅成员数量
	///
	/// \param  lobbyID 大厅ID
	/// \return 成员数量
	///
	NPL_API uint32_t npl_Matchmaking_GetLobbyMemberCount(uint64_t lobbyID);

	///
	/// \brief  游标获取指定大厅成员ID
	///
	/// \param  lobbyID 大厅ID
	/// \param  index 游标
	/// \return 成员ID
	/// 
	/// \note   游标值不应大于GetLobbyMemberCount返回值
	/// \see    
	///
	NPL_API uint64_t npl_Matchmaking_GetLobbyMemberByIndex(uint64_t lobbyID, uint32_t index);

	///
	/// \brief  获取指定大厅成员名字
	///
	/// \param  lobbyID 大厅ID
	/// \param  uid 成员ID
	/// \return 成员名字
	///
	NPL_API cstr_t npl_Matchmaking_GetLobbyMemberName(uint64_t lobbyID, uint64_t uid);

	///
	/// \brief  获取指定大厅成员数据(字符串类型)
	///
	/// \param  lobbyID 大厅ID
	/// \param  uid 成员ID
	/// \param  key 数据名
	/// \return 数据值
	///
	NPL_API cstr_t npl_Matchmaking_GetLobbyMemberStrData(uint64_t lobbyID, uint64_t uid, cstr_t key);

	///
	/// \brief  获取指定大厅成员数据(数值类型)
	///
	/// \param  lobbyID 大厅ID
	/// \param  uid 成员ID
	/// \param  key 数据名
	/// \param  value 数值类型值
	/// \return 是否取到
	///
	NPL_API bool npl_Matchmaking_GetLobbyMemberNumericData(uint64_t lobbyID, uint64_t npl_id, cstr_t key, double& value);

	///
	/// \brief  申请加入指定大厅
	///
	/// \param  lobbyID 大厅ID
	/// \param  strPassword 大厅密码
	/// \return 请求是否成功
	///
	NPL_API bool npl_Matchmaking_ApplyEnterLobby(uint64_t lobbyID, cstr_t strPassword);

	///
	/// \brief  审批指定用户加入大厅的申请
	///
	/// \param  lobbyID 大厅ID
	/// \param  uid 用户ID
	/// \param  agree 是否同意加入大厅
	/// \return 审批是否成功
	///
	NPL_API bool npl_Matchmaking_ApplyEnterLobbyAudit(uint64_t lobbyID, uint64_t uid, bool agree);

	///
	/// \brief  邀请指定用户加入大厅
	///
	/// \param  lobbyID 大厅ID
	/// \param  uid 用户ID
	/// \return 邀请是否成功
	///
	NPL_API bool npl_Matchmaking_InviteEnterLobby(uint64_t lobbyID, uint64_t uid);

	///
	/// \brief  回应邀请加入大厅的事件
	///
	/// \param  lobbyID 大厅ID
	/// \param  agree 是否同意加入大厅
	/// \return 回应是否成功
	///
	NPL_API bool npl_Matchmaking_InviteRespond(uint64_t lobbyID, bool agree);

	///
	/// \brief  离开大厅
	///
	/// \param  lobbyID 大厅ID
	///
	NPL_API void npl_Matchmaking_LeaveLobby(uint64_t lobbyID);

	///
	/// \brief  请指定成员离开大厅
	///
	/// \param  lobbyID 大厅ID
	/// \param  uid 成员ID
	/// \return 是否成功
	///
	NPL_API bool npl_Matchmaking_KickoutMemberLobby(uint64_t lobbyID, uint64_t uid);

	///
	/// \brief  获取指定大厅成员数量限制
	///
	/// \param  lobbyID 大厅ID
	/// \return 成员数量限制
	///
	NPL_API uint32_t npl_Matchmaking_GetLobbyMemberLimit(uint64_t lobbyID);

	///
	/// \brief  移交大厅创建者职位给指定成员
	///
	/// \param  lobbyID 大厅ID
	/// \param  uid 成员ID
	/// \return 异步请求的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbMatchmakingRequestResult_t
	///
	NPL_API long npl_Matchmaking_SetLobbyOwner(uint64_t lobbyID, uint64_t uid);

	///
	/// \brief  获取大厅游戏服务器信息
	///
	/// \param  lobbyID 大厅ID
	/// \param  *dwIP     IP值
	/// \param  *wPort    端口值
	/// \param  *server 游戏服务器ID
	/// \return true-成功，false-失败
	///
	NPL_API bool npl_Matchmaking_GetLobbyGameServer(uint64_t lobbyID, uint32_t* dwIP, uint16_t* wPort, uint64_t* dwServer);

	///
	/// \brief  获取大厅拥有者ID
	///
	/// \param  lobbyID 大厅ID
	/// \return 拥有者ID
	/// 
	NPL_API uint64_t npl_Matchmaking_GetLobbyOwner(uint64_t lobbyID);

	///
	/// \brief  设置大厅最大成员数量
	///
	/// \param  lobbyID 大厅ID
	/// \param  dwMemberMax 允许的最大玩家人数
	/// \return true-成功 false-您不是大厅所有者
	///
	NPL_API bool npl_Matchmaking_SetLobbyMemberLimit(uint64_t lobbyID, uint32_t dwMemberMax);

	///
	/// \brief  请求指定大厅信息
	///
	/// \param  lobbyID 大厅ID
	/// \return 异步请求的Token
	/// 
	/// \note   
	/// \see    cbMatchmakingRequestLobbyData_t
	///
	NPL_API bool npl_Matchmaking_RequestLobbyData(uint64_t lobbyID);

	///
	/// \brief  发送大厅聊天消息
	///
	/// \param  lobbyID 大厅ID
	/// \param  pData 消息缓冲区
	/// \param  nData 消息的长度
	/// \return true-成功 false-失败
	/// 
	NPL_API bool npl_Matchmaking_SendLobbyChatMsg(uint64_t lobbyID, cvoid_t pData, sint32_t nData);

	/*
	p2p.h

	*/
	///
	/// \brief  判断是否与指定用户处于链接状态
	///
	/// \param  uid 用户ID
	/// \return 是否处于链接状态
	/// 
	/// \note   
	/// \see    
	///
	NPL_API bool npl_P2P_IsConnected(uint64_t  uid);

	///
	/// \brief  请求创建P2P
	///
	/// \param  uid 用户ID
	/// \param  enType Nat类型
	/// \param  virtualPort 虚拟端口号
	/// \param  serverIP 服务器IP
	/// \param  serverPort 服务器端口
	/// \return 是否创建成功
	/// 
	/// \note   虚拟端口号一般可用gameID
	/// \see    
	///
	NPL_API bool  npl_P2P_CreateP2P(uint16_t virtualPort, uint16_t maxConnect);

	///
	/// \brief  请求链接指定用户
	///
	/// \param  uid 用户ID
	/// \param  timeout 超时时间（毫秒）
	/// \return 是否链接成功
	/// 
	/// \note   
	/// \see    
	///
	NPL_API bool  npl_P2P_ConnectP2P(uint64_t targetUserID, uint32_t timeout);

	///
	/// \brief  同意指定用户的链接请求
	///
	/// \param  uid 用户ID
	/// \return 是否成功
	/// 
	/// \note   
	/// \see    
	///
	NPL_API bool npl_P2P_AcceptP2PSession(uint64_t targetUserID);

	///
	/// \brief  发送信息给指定用户
	///
	/// \param  uid 用户ID
	/// \param  data 信息
	/// \param  size 信息长度
	/// \param  enPoly 发送策略
	/// \return 是否发送成功
	///
	NPL_API bool  npl_P2P_SendP2PData(uint64_t targetUserID, pvoid_t data, uint32_t size, enP2PSendPoly enPoly);


	///
	/// \brief  检查是否有可读取的消息
	///
	/// \param  msgSize 返回可读取的消息长度
	/// \return true-有 false-没有
	///
	NPL_API bool npl_P2P_IsP2PPacketAvailable(uint32_t* msgSize);

	///
	/// \brief  接收用户的信息
	///
	/// \param  uid 返回用户ID
	/// \param  dest 数据缓冲
	/// \param  size 数据缓冲长度
	/// \param  length 读取的数据长度
	/// \return 是否接收到消息
	///
	NPL_API bool  npl_P2P_RecvP2PData(uint64_t * targetUserID, pvoid_t dest, uint32_t size, uint32_t* length);

	///
	/// \brief  关闭与指定用户的链接
	///
	/// \param  uid 用户ID
	/// \return 是否关闭成功
	///
	NPL_API bool  npl_P2P_CloseP2PSession(uint64_t targetUserID);

	///
	/// \brief  获取与指定用户通讯统计信息
	///
	/// \param  uid 用户ID
	/// \param  pStatistics 统计信息对象
	/// \return 
	///
	NPL_API bool  npl_P2P_GetP2PSessionStatistics(uint64_t targetUserID, P2PSessionStatistics_t* session);

	///
	/// \brief  关闭P2P
	///
	NPL_API void  npl_P2P_CloseP2P();

	/*
	 sensitive.h
	*/
	///
	/// \brief  检查指定内容是否包含敏感屏蔽字
	///
	/// \param  data 检查内容
	/// \return 是否包含屏蔽字
	/// 
	/// \note   检查内容应是utf8编码
	/// \see     
	///
	NPL_API bool  npl_SensitiveWord_Censor_utf8(cstr_t data);


	///
	/// \brief  检查指定内容是否包含敏感屏蔽字
	///
	/// \param  data 检查内容
	/// \return 是否包含屏蔽字
	/// 
	/// \note   检查内容应是系统当前多字节编码；如果系统是gbk编码，检查内容也应是gbk编码
	/// \see     
	///
	NPL_API bool  npl_SensitiveWord_Censor_mbs(cstr_t data);

	///
	/// \brief  检查并替换指定内容中的屏蔽字到缓冲区
	///
	/// \param  data 检查内容
	/// \param  out 替换返回的缓冲区
	/// \param  out_size 替换返回的缓冲区大小
	/// \return 是否包含屏蔽字
	/// 
	/// \note   检查内容应是系统当前多字节编码；如果系统是gbk编码，检查内容也应是gbk编码
	/// \see    
	///
	NPL_API bool  npl_SensitiveWord_Censor_utf8_ps(cstr_t data, pstr_t out_data, size_t out_size);

	///
	/// \brief  检查并替换指定内容中的屏蔽字到缓冲区
	///
	/// \param  data 检查内容
	/// \param  out 替换返回的缓冲区
	/// \param  out_size 替换返回的缓冲区大小
	/// \return 是否包含屏蔽字
	/// 
	/// \note   检查内容应是系统当前多字节编码；如果系统是gbk编码，检查内容也应是gbk编码
	/// \see    
	///
	NPL_API bool  npl_SensitiveWord_Censor_mbs_ps(cstr_t data, pstr_t out_data, size_t out_size);

	/**
	servermathing.h

	*/
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
	NPL_API long  npl_ServerMatchmaking_QueryInternetServers(cstr_t filter);

	///
	/// \brief  请求局域网服务器列表
	///
	/// \param  filter 服务器少选过滤器
	/// \return 异步请求的Token
	/// 
	/// \note   filter参考服务器列表过滤器符号
	/// \see    RegistCallback cbQueryServers_t
	///
	NPL_API long  npl_ServerMatchmaking_QueryLanServers(cstr_t filter);

	///
	/// \brief  请求好友服务器列表
	///
	/// \param  filter 服务器少选过滤器
	/// \return 异步请求的Token
	/// 
	/// \note   filter参考服务器列表过滤器符号
	/// \see    RegistCallback cbQueryServers_t
	///
	NPL_API long  npl_ServerMatchmaking_QueryFriendServers(cstr_t filter);

	///
	/// \brief  请求收藏的服务器列表
	///
	/// \param  filter 服务器少选过滤器
	/// \return 异步请求的Token
	/// 
	/// \note   filter参考服务器列表过滤器符号
	/// \see    RegistCallback cbQueryServers_t
	///
	NPL_API long  npl_ServerMatchmaking_QueryFavoritesServers(cstr_t filter);

	///
	/// \brief  请求历史服务器列表
	///
	/// \param  filter 服务器少选过滤器
	/// \return 异步请求的Token
	/// 
	/// \note   filter参考服务器列表过滤器符号
	/// \see    RegistCallback cbQueryServers_t
	///
	NPL_API long  npl_ServerMatchmaking_QueryHistoryServers(cstr_t filter);

	///
	/// \brief  请求观战服务器列表
	///
	/// \param  filter 服务器少选过滤器
	/// \return 异步请求的Token
	/// 
	/// \note   filter参考服务器列表过滤器符号
	/// \see    RegistCallback cbQueryServers_t
	///
	NPL_API long  npl_ServerMatchmaking_QuerySpectatorsServers(cstr_t filter);

	///
	/// \brief  取消指定Token的请求
	///
	/// \param  token 异步请求的Token
	///
	NPL_API void npl_ServerMatchmaking_CancelQuery(long token);

	///
	/// \brief  取消指定Token的请求
	///
	/// \param  token 异步请求的Token
	///
	NPL_API void  npl_ServerMatchmaking_ReleaseQuery(long token);

	///
	/// \brief  获取指定请求返回的服务器数量
	///
	/// \param  token 异步请求的Token
	/// \return 服务器数量
	///
	NPL_API long  npl_ServerMatchmaking_GetServerCount(long token);

	///
	/// \brief  通过游标获取指定请求的服务器数量
	///
	/// \param  token 异步请求的Token
	/// \param  index 游标
	/// \return 
	/// 
	/// \note   游标不应大于GetServerCount的返回结果
	/// \see    
	///
	NPL_API ServerDetail_t*  npl_ServerMatchmaking_GetServerDetails(long token, sint32_t index);

	///
	/// \brief  刷新指定服务器
	///
	/// \param  token 异步请求的Token
	/// \param  serverID 服务器ID
	/// \return 
	/// 
	/// \note   serverID = -1 标识刷新token对应返回的所有服务器
	/// \see    RegistCallback cbRefreshNotify_t
	///
	NPL_API void  npl_ServerMatchmaking_RefreshServer(long token, uint64_t serverID);

	
	/// 
	/// \brief  ping server
	/// 
	/// \param  ip 目标IP
	/// \param  port 目标端口（gameServer queryPort）
	/// \param  response 回调对象（为确保安全，在这个对象置为失效前，请调用CancelServerQuery）
	///
	NPL_API long npl_ServerMatchmaking_PingServer(uint32_t ip, uint16_t port,
		void(*ServerResponded_ptr)(ServerDetail_t&),
		void(*ServerFailedToRespond_ptr)());

	/// 
	/// \brief  request server player detail
	/// 
	/// \param  ip 目标IP
	/// \param  port 目标端口（gameServer queryPort）
	/// \param  response 回调对象（为确保安全，在这个对象置为失效前，请调用CancelServerQuery）
	///
	NPL_API long npl_ServerMatchmaking_PlayerDetails(uint32_t ip, uint16_t port,
		void(*AddPlayerToList_ptr)(NPL_USRID, const char *, int, float),
		void(*PlayersFailedToRespond_ptr)(),
		void(*PlayersRefreshComplete_ptr)());

	/// 
	/// \brief  request server rules (INplGameServer::SetKeyValue)
	/// 
	/// \param  ip 目标IP
	/// \param  port 目标端口（gameServer queryPort）
	/// \param  response 回调对象（为确保安全，在这个对象置为失效前，请调用CancelServerQuery）
	///
	NPL_API long npl_ServerMatchmaking_ServerRules(uint32_t ip, uint16_t port,
		void(*RulesResponded_ptr)(const char*, const char*),
		void(*RulesFailedToRespond_ptr)(),
		void(*RulesRefreshComplete_ptr)());

	/// 
	/// \brief  取消一项未完成的单个服务器查询
	///
	/// \param  tok PingServer/PlayerDetails/ServerRules 的返回值
	///
	NPL_API void npl_ServerMatchmaking_CancelServerQuery(long tok);

	/**
	  npl-storage.h
	*/

	/// 
	NPL_API bool npl_Storage_IsFileExist(cstr_t pFileName);

	///
	/// \brief 获取文件大小
	///
	NPL_API sint64_t npl_Storage_GetFileSize(cstr_t pFileName);

	///
	/// \brief 获取文件最后修改时间
	///
	/// \return 最后一次修改时间（秒为单位）
	NPL_API uint64_t npl_Storage_GetFileTime(cstr_t pFileName);

	///
	/// \brief 写文件到本地
	///
	NPL_API sint32_t npl_Storage_WriteFile(cstr_t pFileName, cvoid_t pData, sint32_t nSize);

	///
	/// \brief 从本地读文件
	///
	NPL_API sint32_t npl_Storage_ReadFile(cstr_t pFileName, pvoid_t pData, sint32_t nSize);

	///
	/// \brief 异步写文件
	///
	NPL_API long npl_Storage_WriteFileAsync(cstr_t pFileName, cvoid_t pData, size_t nSize);

	///
	/// \brief 异步读文件
	///
	NPL_API long npl_Storage_ReadFileAsync(cstr_t pFileName, size_t nOffset, size_t nSize);

	///
	/// \brief 异步读文件完成
	///
	NPL_API long npl_Storage_ReadFileAsyncComplate(long nToken, pvoid_t pData, size_t nSize);

	///
	/// \brief 删除本地文件
	///
	NPL_API bool npl_Storage_RemoveFile(cstr_t pFileName);

	///
	/// \brief 删除远程文件
	/// 
	NPL_API bool npl_Storage_ForgotFile(cstr_t pFileName);

	///
	/// \brief 打开文件流
	///
	NPL_API StreamFileHandle_t npl_Storage_StreamFileOpen(cstr_t pFileName);

	///
	/// \brief 写数据到流
	///
	NPL_API bool npl_Storage_StreamFileWrite(StreamFileHandle_t hFile, cvoid_t pData, size_t nSize);

	///
	/// \brief 关闭流文件
	///
	NPL_API bool npl_Storage_StreamFileClose(StreamFileHandle_t hFile);

	///
	/// \brief 取消流文件上传
	///
	NPL_API bool npl_Storage_StreamFileAbort(StreamFileHandle_t hFile);

	///
	/// \brief 同步文件
	///
	NPL_API void npl_Storage_SyncFiles();

	///
	/// \brief 获取文件数量
	///
	NPL_API long npl_Storage_GetFileCount();

	///
	/// \brief 获取文件详细信息
	///
	/// \return callback token
	NPL_API bool npl_Storage_GetFileInfo(int nIndex, FileInfo_t *pInfo);

	///
	/// \brief 共享文件
	///
	/// \param	pFileName	共享的文件名
	/// \param	
	///
	/// \return 异步操作句柄
	/// 
	/// \see   RegistCallback cbFileShareResult_t
	///
	NPL_API long npl_Storage_FileShare(cstr_t pFileName);

	///
	/// \brief 获取云端存储使用情况
	///
	NPL_API bool npl_Storage_GetCloudSpace(uint64_t *nUsed, uint64_t *nTotal);

	///
	/// \brief 检查云存储是否开通
	///
	NPL_API bool npl_Storage_IsCloudStorageEnable();

	///
	/// \brief 检查云存储是否被游戏使用
	///
	NPL_API bool npl_Storage_IsCloudStorageUsed();

	///
	/// \brief 设置云存储游戏使用权限
	///
	NPL_API bool npl_Storage_DoCloudStorageUsed(bool bEnable);

	/// 
	/// \brief 下载用户生成内容
	///
	NPL_API long npl_Storage_UGCDownload(UGCHandle_t hContent, int nPriority);

	/// 
	/// \brief 下载用户生成内容到指定未知
	///
	NPL_API long npl_Storage_UGCDownloadTo(UGCHandle_t hContent, int nPriority, cstr_t pLocation);

	/// 
	/// \brief 获取下载信息
	/// 
	NPL_API bool npl_Storage_UGCGetDownloadInfo(UGCHandle_t hContent, sint64_t *nTotalDL, sint64_t *nSpeedDL, sint64_t *nTotalBytes);

	/// 
	/// \brief 获取UGC描述信息
	///
	NPL_API bool npl_Storage_UGCGetDetails(UGCHandle_t hContent, UGCInfomation_t *pDetails);

	/// 
	/// \brief 读取UGC文件
	///
	NPL_API sint32_t npl_Storage_UGCRead(UGCHandle_t hContent, uint32_t nOffset, pvoid_t pData, size_t nSize);

	/// 
	/// \brief 获取UGC缓存的文件数量
	///
	NPL_API sint32_t npl_Storage_UGCGetCachedCount();

	/// 
	/// \brief 获取UGC缓存的文件句柄
	///
	NPL_API UGCHandle_t npl_Storage_UGCGetHandle(sint32_t nCachedIndex);

	/// 
	/// \brief  查询搜索发布列表
	/// \param  condition 查询条件 
	///                   nickName:!=:xyz-minVersion:=:v1.0.0-maxPlayers:>=:100
	///                   每个查询条件"-"分割，目前支持 = < > <= >= in notin !=
	/// \param  pageSize  每页数量，从1开始
	/// \param  pageNumber 第几页，从1开始
	///
	/// \return 异步调用句柄
	/// \note   该函数会启动搜索符合查询条件的UGC列表
	/// \see    RegistCallback cbUGCSearchResult_t
	///
	NPL_API long npl_Storage_SearchUGC(cstr_t condition, sint32_t pageSize, sint32_t pageNumber);

	///
	/// \brief	创建发布内容
	///
	/// \param	pFile		发布的主文件
	/// \param	pPreviewFile	发布的预览文件
	/// \param	gameId		支持的dlc
	/// \param	pTitle		标题
	/// \param	pDescription		描述
	/// \param	pTags		标签
	/// \param	nMediaType	媒体类型
	/// \param	enVisiblity	可见(被搜索)类型
	///
	/// \return 异步调用句柄
	/// \note	
	/// \see RegistCallback cbUGCCreatePublish_t
	NPL_API long npl_Storage_UGCCreatePublish(cstr_t pFile, cstr_t pPreviewFile, uint64_t gameId, cstr_t pTitle, cstr_t pDescription, cstr_t pTags, int nMediaType, enPublishedFileVisibility enVisiblity);

	///
	/// \brief 请求更新发布内容
	///
	/// \param	nPublishedFileId	要更新的发布内容的句柄
	///
	/// \return	更新句柄
	///
	/// \note	
	/// \see	
	/// 
	NPL_API UGCUpdateHandle_t npl_Storage_UGCCreatePublishedUpdateRequest(PublishedFileId_t  nPublishedFileId);

	///
	/// \brief 更新发布文件
	///
	/// \param	updateHandle	更新句柄
	/// \param	pFile		发布的文件路径
	///
	/// \return	更新是否成功
	///
	/// \note	该调用仅更新本地UGC设置，需通过UGCUpdatePublishedCommit提交到服务器。
	/// \see	UGCUpdatePublishedCommit
	/// 
	NPL_API bool npl_Storage_UGCUpdatePublishedFile(UGCUpdateHandle_t updateHandle, cstr_t pFile);

	///
	/// \brief 更新发布文件的预览文件
	///
	/// \param	updateHandle	更新句柄
	/// \param	pPreview	发布的预览文件路径
	///
	/// \return	更新是否成功
	///
	/// \note	该调用仅更新本地UGC设置，需通过UGCUpdatePublishedCommit提交到服务器。
	/// \see	UGCUpdatePublishedCommit
	/// 
	NPL_API bool npl_Storage_UGCUpdatePublishedPreview(UGCUpdateHandle_t updateHandle, cstr_t pPreview);

	///
	/// \brief 更新发布文件的显示名
	///
	/// \param	updateHandle	更新句柄
	/// \param	pTitle		发布的UGC标题，标题用于列表中的显示
	///
	/// \return	更新是否成功
	///
	/// \note	该调用仅更新本地UGC设置，需通过UGCUpdatePublishedCommit提交到服务器。
	/// \see	UGCUpdatePublishedCommit
	/// 
	NPL_API bool npl_Storage_UGCUpdatePublishedTitle(UGCUpdateHandle_t updateHandle, cstr_t pTitle);

	///
	/// \brief	更新发布文件的描述
	///
	/// \param	updateHandle	更新句柄
	/// \param	pDescription 发布的UGC描述，描述用于详情页中的显示
	///
	/// \return	更新是否成功
	///
	/// \note	该调用仅更新本地UGC设置，需通过UGCUpdatePublishedCommit提交到服务器。
	/// \see	UGCUpdatePublishedCommit
	/// 
	NPL_API bool npl_Storage_UGCUpdatePublishedDescription(UGCUpdateHandle_t updateHandle, cstr_t pDescription);

	///
	/// \brief 更新发布文件的标签
	///
	/// \param	updateHandle	更新句柄
	/// \param	pTags		使用‘，’隔开的字符串，用于UGC查找时的搜索条件
	///
	/// \return	更新是否成功
	///
	/// \note	该调用仅更新本地UGC设置，需通过UGCUpdatePublishedCommit提交到服务器。
	/// \see	UGCUpdatePublishedCommit
	/// 
	NPL_API bool npl_Storage_UGCUpdatePublishedTags(UGCUpdateHandle_t updateHandle, cstr_t pTags);

	///
	/// \brief 更新发布文件的版本
	///
	/// \param	updateHandle	更新句柄
	/// \param	targetVersion	制作UGC内容的版本
	/// \param	minVersion		运行UGC内容的最小版本号
	///
	/// \return	更新是否成功
	///
	/// \note	该调用仅更新本地UGC设置，需通过UGCUpdatePublishedCommit提交到服务器。
	/// \see	UGCUpdatePublishedCommit
	///
	NPL_API bool npl_Storage_UGCUpdatePublishedVersion(UGCUpdateHandle_t updateHandle, cstr_t targetVersion, cstr_t minVersion);

	///
	/// \brief 更新发布文件的元数据
	///
	/// \param	updateHandle	更新句柄
	/// \param	pJsonString	该Json字符串必须为{ "key_1" = val_1, ... "key_n" = val_n }的格式，数据用于UGC内容搜索条件。
	///
	/// \return	更新是否成功
	///
	/// \note	该调用仅更新本地UGC设置，需通过UGCUpdatePublishedCommit提交到服务器。
	/// \see	UGCUpdatePublishedCommit
	/// 
	NPL_API bool npl_Storage_UGCUpdatePublishedData(UGCUpdateHandle_t updateHandle, cstr_t pJsonString);

	///
	/// \brief 更新发布文件是否可被搜索
	///
	/// \param	updateHandle	更新句柄
	/// \param	enVisibility	可被搜索类型。
	///
	/// \return	更新是否成功
	///
	/// \note	该调用仅更新本地UGC设置，需通过UGCUpdatePublishedCommit提交到服务器。
	/// \see	UGCUpdatePublishedCommit
	/// 
	NPL_API bool UGCUpdatePublishedVisibility(UGCUpdateHandle_t updateHandle, enPublishedFileVisibility enVisibility);

	///
	/// \brief 提交更新
	///
	/// \param	updateHandle	更新句柄
	///
	/// \return	异步操作句柄，可通过RegistCallback注册回调函数，系统会在操作完成后调用。
	/// 
	NPL_API long npl_Storage_UGCUpdatePublishedCommit(UGCUpdateHandle_t updateHandle);

	///
	/// \brief 获取发布进度
	///
	/// \param	token	调用UGCCreatePublish返回的token值
	/// \param	nTotalDL	已上传字节数
	/// \param	nSpeedDL	平均上传速度（Bytes/S）
	/// \param	nTotalBytes 总上传字节数
	///
	/// \return	调用是否成功
	/// 
	NPL_API bool npl_Storage_GetUGCPublishProgress(long token, sint64_t *nTotalUL, sint64_t *nSpeedUL, sint64_t *nTotalBytes);

	///
	/// \brief 获取更新发布进度
	///
	/// \param	updateHandle	更新句柄
	/// \param	nTotalDL	已上传字节数
	/// \param	nSpeedDL	平均上传速度（Bytes/S）
	/// \param	nTotalBytes 总上传字节数
	///
	/// \return	调用是否成功
	/// 
	NPL_API bool npl_Storage_GetUGCPublishedUpdateProgress(UGCUpdateHandle_t updateHandle, sint64_t *nTotalUL, sint64_t *nSpeedUL, sint64_t *nTotalBytes);

	///
	/// \brief 删除句柄对应的已发布内容
	///
	/// \param	nPublishedFileId	已发布内容的句柄
	///
	/// \return	异步操作句柄
	/// 
	/// \note 
	/// \see   RegistCallback cbUGCDeleteResult_t
	///	
	NPL_API bool npl_Storage_DelUGCPublished(PublishedFileId_t nPublishedFileId);

	///
	/// \brief 枚举用户发布过的内容
	///
	/// \param	当前索引
	///
	/// \return	异步操作句柄
	/// 
	/// \note 
	/// \see   RegistCallback cbEnumerateUserPublishedFilesResult_t
	///	
	NPL_API long npl_Storage_EnumerateUserPublishedFiles(uint32_t nStartIndex);

	///
	/// \brief 获取发布内容详细信息
	///
	/// \param nPublishedFileId	发布句柄
	/// \param bRefresh	是否刷新本地缓存
	///
	/// \return 异步操作句柄
	/// 
	/// \note bRefresh	true从服务器获取最新并刷新本地缓存，false直接从本地缓存取
	/// \see   RegistCallback cbPublishedFileDetailsResult_t
	///
	NPL_API long npl_Storage_GetPublishedFileDetails(PublishedFileId_t nPublishedFileId, bool bRefresh);

	///
	/// \brief 订阅发布的内容
	///
	/// \param nPublishedFileId	 发布的文件的句柄
	///
	/// \return 异步操作句柄
	/// 
	/// \note 
	/// \see   RegistCallback cbSubscribePublishedFileResult_t
	///
	NPL_API long npl_Storage_SubscribePublishedFile(PublishedFileId_t nPublishedFileId);

	///
	/// \brief 取消订阅发布的内容
	///
	/// \param nPublishedFileId	 发布内容的句柄
	///
	/// \return 异步操作句柄
	/// 
	/// \note 
	/// \see   RegistCallback cbUnsubscribePublishedFileResult_t
	///
	NPL_API long npl_Storage_UnsubscribePublishedFile(PublishedFileId_t nPublishedFileId);

	///
	/// \brief 枚举用户订阅过的内容
	///
	/// \param	当前索引
	///
	/// \return	异步操作句柄
	/// 
	/// \note 
	/// \see   RegistCallback cbEnumerateUserSubscribedFilesResult_t
	///	
	NPL_API long npl_Storage_EnumerateUserSubscribedFiles(uint32_t nStartIndex);

	/*
	排行榜 leaderboard
	*/

	///
	/// \brief  事件触发上报
	///
	/// \param  evt 统计事件的API名称
	/// \param  parameter 上报的数据
	/// \return 请求是否成功 true-成功 false-失败
	///
	/// \note 
	/// \see   RegistCallback cbTriggerEvent_t
	///
	NPL_API bool npl_Leaderboard_TriggerEvent(cstr_t evt, real64_t parameter);

	///
	/// \brief  获取事件信息 
	///
	/// \param  evt 统计事件的API名称
	/// \return 异步请求的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbStatisticsGetEventInfo_t
	///
	NPL_API long npl_Leaderboard_GetStatisticsEventInfo(cstr_t evt);

	///
	/// \brief  获取事件统计项数量
	///
	/// \return 事件统计项数量
	///
	NPL_API sint32_t npl_Leaderboard_GetStatisticsEventParamCount();

	///
	/// \brief  通过游标获取事件统计项
	///
	/// \param  index 游标，不应大于GetStatisticsEventParamCount返回值
	/// \param  *param 返回事件统计项
	/// \return true-成功，需要满足GetStatisticsEventParamCount返回值大于0，并且index在[0, GetStatisEventParamCount返回值)区间；否则false-失败
	///
	NPL_API bool npl_Leaderboard_GetStatisticsEventParam(sint32_t index, StatisticsEventInfoParam_t* param);

	///
	/// \brief  获取自己周围排行榜数据
	///
	/// \param  name 排行榜API名称
	/// \return 异步请求的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbFindLeaderboard_t
	///
	NPL_API long npl_Leaderboard_FindLeaderboard(cstr_t name);

	///
	/// \brief  下载指定排行榜指定类型数据
	///
	/// \param  name 排行榜API名称
	/// \param  enKind 排行榜类型
	/// \param  nRangeStart 范围起始值，最小从0开始
	/// \param  nRangeEnd 范围结束值，传入为0时表示不指定结束值
	/// \return 异步请求的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbDownloadLeaderboardEntries_t
	///
	NPL_API long npl_Leaderboard_DownloadLeaderboardEntries(cstr_t name, enLeaderboardKind enKind, sint32_t nRangeStart, sint32_t nRangeEnd);

	///
	/// \brief  获取指定用户排行榜数据
	///
	/// \param  name 排行榜API名称
	/// \param  user 用户ID
	/// \return 异步请求的Token
	/// 
	/// \note   
	/// \see    RegistCallback cbDownloadLeaderboardEntriesForUsers_t
	///
	NPL_API long npl_Leaderboard_DownloadLeaderboardEntriesForUsers(cstr_t name, uint64_t users[], sint32_t userCount);

	/// 
	/// \brief  获取排行榜数据总数
	///
	/// \param  hLeaderboard 句柄
	/// \return 总数
	///
	NPL_API uint32_t npl_Leaderboard_GetTotalCount(NplLeaderboardHandle_t hLeaderboard);

	///
	/// \brief  获取排行榜展示名称
	///
	/// \param  hLeaderboard 句柄
	/// \return 展示名称
	///
	NPL_API cstr_t npl_Leaderboard_GetShowName(NplLeaderboardHandle_t hLeaderboard);

	///
	/// \brief  获取排行榜重置时间戳
	///
	/// \param  hLeaderboard 句柄
	/// \return 重置时间戳（秒）
	///
	NPL_API uint64_t npl_Leaderboard_GetResetTimestamp(NplLeaderboardHandle_t hLeaderboard);

	///
	/// \brief  获取排行榜刷新时间戳
	///
	/// \param  hLeaderboard 句柄
	/// \return 刷新时间戳（秒）
	///
	NPL_API uint64_t npl_Leaderboard_GetRefreshTimestamp(NplLeaderboardHandle_t hLeaderboard);

	///
	/// \brief  获取排行榜参数值排序方式枚举值
	///
	/// \param  hLeaderboard 句柄
	/// \return 排行榜参数值排序方式枚举值
	///
	NPL_API enLeaderboardArgSort npl_Leaderboard_GetLeaderboardSortMethod(NplLeaderboardHandle_t hLeaderboard);

	///
	/// \brief  获取排行榜参数值格式化枚举值
	///
	/// \param  hLeaderboard 句柄
	/// \return 排行榜参数值格式化枚举值
	///
	NPL_API enLeaderboardArgFmt npl_Leaderboard_GetLeaderboardDisplayType(NplLeaderboardHandle_t hLeaderboard);

	///
	/// \brief  获取排行榜排名数量
	///
	/// \param  hLeaderboard 句柄
	/// \return 排名数量
	///
	NPL_API sint32_t npl_Leaderboard_GetEntryCount(NplLeaderboardHandle_t hLeaderboard);

	///
	/// \brief  获取排行榜排名
	///
	/// \param  hLeaderboard 句柄
	/// \param  index 游标，不应大于GetEntryCount返回值
	/// \param  info 返回具体信息结构
	/// \return 排名
	///
	NPL_API bool npl_Leaderboard_GetEntryInfo(NplLeaderboardHandle_t hLeaderboard, sint32_t index, LeaderboardEntryInfo_t* info);

	///
	/// \brief  获取排行榜附加数据数量
	///
	/// \param  hLeaderboard 句柄
	/// \param  index 游标，不应大于GetEntryCount返回值
	/// \return 附加数据数量 -1:error
	///
	NPL_API sint32_t npl_Leaderboard_GetExtraCount(NplLeaderboardHandle_t hLeaderboard, sint32_t index);

	///
	/// \brief  获取数值类型附加数据
	///
	/// \param  hLeaderboard 句柄
	/// \param  index 游标，不应大于GetEntryCount返回值
	/// \param  extraIndex 游标，不应大于GetExtraCount返回值
	/// \param  *extra 返回数值类型值
	/// \return true-成功 false-失败
	///
	NPL_API bool npl_Leaderboard_GetExtra(NplLeaderboardHandle_t hLeaderboard, sint32_t index, sint32_t extraIndex, real64_t* extra);

	///
	/// \brief  获取字符串类型附加数据
	///
	/// \param  hLeaderboard 句柄
	/// \param  index 游标，不应大于GetEntryCount返回值
	/// \param  extraIndex 游标，不应大于GetExtraCount返回值
	/// \param  *extra 返回字符串类型值
	/// \param  extraSize 字符串值长度
	/// \return true-成功 false-失败
	///
	NPL_API bool npl_Leaderboard_GetExtraStr(NplLeaderboardHandle_t hLeaderboard, sint32_t index, sint32_t extraIndex, pstr_t extra, size_t extraSize);

	///
	/// \brief  设置数值类型附加数据
	///
	/// \param  hLeaderboard 句柄
	/// \param  extraPos 位置游标，范围[0, 20]
	/// \param  value 值
	/// \return true-成功 false-失败
	///
	NPL_API bool npl_Leaderboard_SetNumericalExtra(NplLeaderboardHandle_t hLeaderboard, sint32_t extraPos, real64_t value);

	///
	/// \brief  设置字符串类型附加数据
	///
	/// \param  hLeaderboard 句柄
	/// \param  extraPos 位置游标，范围[0, 20]
	/// \param  value 值
	/// \return true-成功 false-失败
	///
	NPL_API bool npl_Leaderboard_SetStringExtra(NplLeaderboardHandle_t hLeaderboard, sint32_t extraPos, cstr_t value);

	///
	/// \brief  提交附加数据设置
	///
	/// \param  hLeaderboard 句柄
	/// \return 异步请求的Token
	/// 
	/// \see    RegistCallback cbLeaderboadCommitExtra_t
	///
	NPL_API long npl_Leaderboard_CommitExtra(NplLeaderboardHandle_t hLeaderboard);

	///
	/// \brief  把UGC内容绑到排行榜
	///
	/// \param  hLeaderboard 排行榜句柄
	/// \param  hUGC UGC句柄
	/// \return 异步请求的Token
	/// 
	/// \see    RegistCallback cbLeaderboardUGCSet_t
	///
	NPL_API long npl_Leaderboard_AttachLeaderboardUGC(NplLeaderboardHandle_t hLeaderboard, UGCHandle_t hUGC);

	/*
	成就 Achievement
	*/

	//////////////////////////////////////////////////////////////////////////
	///
	/// \brief  获取成就列表
	///
	/// \param  
	/// \return 异步请求的Token
	/// \see    cbAchievementListRefreshed_t
	///
	NPL_API long npl_Achievement_RefreshAchievementList();

	///
	/// \brief  获取指定用户成就列表
	///
	/// \param  userID 用户ID
	/// \return 异步请求的Token
	/// \see    cbAchievementListRefreshed_t
	///
	NPL_API long npl_Achievement_RefreshAchievementListByUserID(uint64_t userID);

	///
	/// \brief  获取成就详细信息
	///
	/// \param  achName 成就API名称
	/// \return 异步请求的Token
	/// \see    cbAchievementRefreshed_t
	///
	NPL_API long npl_Achievement_RefreshAchievementInfo(cstr_t achName);

	///
	/// \brief  获取指定用户成就详细信息
	///
	/// \param  userID 用户ID
	/// \param  achName 成就API名称
	/// \return 异步请求的Token
	/// \see    cbAchievementRefreshed_t
	///	
	NPL_API long npl_Achievement_RefreshAchievementInfoByUserID(uint64_t userID, cstr_t achName);

	///
	/// \brief  清理指定成就状态
	///
	/// \param  achName 成就API名称
	/// \return true-请求已发出 
	///
	NPL_API bool npl_Achievement_ClearAchievement(cstr_t achName);

	///
	/// \brief  获取成就是否已经解锁
	///
	/// \param  achName 成就API名称
	/// \param  pbAchieved 是否已解锁成就
	/// \return true-成功 false-失败
	///
	NPL_API bool npl_Achievement_GetAchievement(cstr_t achName, bool* pbAchieved);

	///
	/// \brief  获取指定用户成就是否已经解锁
	///
	/// \param  userID 用户ID
	/// \param  achName 成就API名称
	/// \param  pbAchieved 是否已解锁成就
	/// \return true-成功 false-失败
	///
	NPL_API bool npl_Achievement_GetUserAchievement(uint64_t userID, cstr_t achName, bool* pbAchieved);

	///
	/// \brief  获取成就是否已经解锁和解锁时间
	///
	/// \param  achName 成就API名称
	/// \param  pbAchieved 是否已解锁成就
	/// \param  unlockTime 解锁时间（s）
	/// \return true-成功 false-失败
	///
	NPL_API bool npl_Achievement_GetAchievementAndUnlockTime(cstr_t achName, bool* pbAchieved, uint32_t* unlockTime);

	///
	/// \brief  获取指定用户成就是否已经解锁和解锁时间
	///
	/// \param  userID 用户ID
	/// \param  achName 成就API名称
	/// \param  pbAchieved 是否已解锁成就
	/// \param  unlockTime 解锁时间（s）
	/// \return true-成功 false-失败
	///
	NPL_API bool npl_Achievement_GetUserAchievementAndUnlockTime(uint64_t userID, cstr_t achName, bool* pbAchieved, uint32_t* unlockTime);

	///
	/// \brief  获取成就图标
	///
	/// \param  achName 成就API名称
	/// \param  icon 返回ICON接收缓冲
	/// \param  iconLen 接收缓冲长度
	/// \return true-成功 false-失败
	///
	NPL_API bool npl_Achievement_GetAchievementIcon(cstr_t achName, sint32_t* icon);

	///
	/// \brief  获取成就自定义属性值
	///
	/// \param  achName 成就API名称
	/// \param  key 键名称(name/desc/attr)
	/// \return 值
	///
	NPL_API cstr_t npl_Achievement_GetAchievementDisplayAttribute(cstr_t achName, cstr_t key);

	///
	/// \brief  标注成就进度
	///
	/// \param  achName 成就API名称
	/// \param  nCurProgress 当前进度
	/// \param  nMaxProgress 解锁所需进度
	/// \return true-成功 false-失败
	///
	NPL_API bool npl_Achievement_IndicateAchievementProgress(cstr_t achName, uint32_t nCurProgress, uint32_t nMaxProgress);

	///
	/// \brief  通过成就ID获取成就信息
	///
	/// \param  achName 成就API名称
	/// \param  *info 返回成就信息
	/// \return true-成功 false-失败
	///
	NPL_API bool npl_Achievement_GetAchievementDetailInfo(cstr_t achName, AchievementInfo_t* info);

	///
	/// \brief  获取成就列表请求返回的成就数量
	///
	/// \param  
	/// \return 成就数量
	///
	NPL_API sint32_t npl_Achievement_GetNumAchievements();

	///
	/// \brief  通过游标获取成就名称
	///
	/// \param  index 游标,不应大于GetNumAchievements返回值
	/// \return 成就API名称
	///
	NPL_API cstr_t npl_Achievement_GetAchievementName(sint32_t index);

	///
	/// \brief  通过游标获取成就信息
	///
	/// \param  index 游标,不应大于GetNumAchievements返回值
	/// \param  *info 返回成就信息
	/// \return true-成功，需满足GetNumAchievements返回值大于0，并且index在[0,GetNumAchievements返回值)区间；否则返回false-失败
	///
	NPL_API bool npl_Achievement_GetAchievementDetailInfoByIndex(sint32_t index, AchievementInfo_t* info);

	///
	/// \brief  通过成就ID获取成就事件数量
	///
	/// \param  achName 成就API名称
	/// \return 事件数量 -1:未找到
	/// 
	NPL_API sint32_t npl_Achievement_GetNumAchievementEvents(cstr_t achName);

	///
	/// \brief  通过事件游标获取相应成就的事件信息
	///
	/// \param  achName 成就API名称
	/// \param  index 事件游标，不应大于GetNumAchievementEvents返回值
	/// \param  *info 返回成就事件信息
	/// \return true-成功 false-失败
	///
	NPL_API bool npl_Achievement_GetAchievementEventInfo(cstr_t achName, sint32_t index, AchievementEvent_t* info);

	///
	/// \brief  设置成就状态
	///
	/// \param  achName 成就API名称
	/// \param  enStat 状态
	/// \return true-成功 false-失败
	///
	NPL_API bool npl_Achievement_SetAchievementStat(cstr_t achName, enAchievementStat enStat);

	///
	/// \brief  设置成就属性
	///
	/// \param  achName 成就API名称
	/// \param  attr 自定义的属性
	/// \return true-成功 false-失败
	///
	NPL_API bool npl_Achievement_SetAchievementAttr(cstr_t achName, cstr_t attr);

	///
	/// \brief  获取成就属性
	///
	/// \param  achName 成就API名称
	/// \return 自定义的属性
	///
	NPL_API cstr_t npl_Achievement_GetAchievementAttr(cstr_t achName);

	/*
	gameServer client
	*/
	///
	/// \brief  初始化游戏服务器链接
	///
	/// \param  pAuthBlob 接收认证信息的缓冲区
	/// \param  cbMaxAuthBlob 接收认证信息的缓冲区长度（尽量长的定义该缓冲区，认证信息可能有1024字节）
	/// \param  gameServerID 请求链接的gameServerID
	/// \param  unIPServer 请求链接的gameServer IP
	/// \param  usPortServer 请求链接的gameServer Port
	/// \param  bSecure 是否使用安全链接
	/// \return 认证信息的长度，
	///         0-失败，获取认证信息失败，或者无法通过P2P方式链接gameServerID
	/// 
	/// \note   注意：链接实际使用P2P转发方式，并不是和unIPServer & usPortServer链接，发送消息请使用INplP2P::SendP2PData
	///
	NPL_API int npl_User_InitiateGameConnection(pvoid_t pAuthBlob, int cbMaxAuthBlob, uint64_t gameServerID, uint32_t unIPServer, uint16_t usPortServer, bool bSecure);

	///
	/// \brief  获取认证Ticket
	///
	/// \param  pTicket 接收认证信息的缓冲区
	/// \param  cbMaxTicket 接收认证信息的缓冲区长度（尽量长的定义该缓冲区，认证信息可能有1024字节）
	/// \param  pcbTicket 认证信息的长度
	/// \return 认证信息句柄
	///
	NPL_API AuthTicketHandle_t npl_User_GetAuthSessionTicket(pvoid_t pTicket, int cbMaxTicket, uint32_t *pcbTicket);

	/// 
	/// \brief  销毁认证Ticket
	/// \param  hAuthTicket ticket句柄
	///
	NPL_API void npl_User_CancelAuthTicket(AuthTicketHandle_t hAuthTicket);

	///
	/// \brief  通知游戏服务器断开链接
	///
	/// \param  unIPServer 服务器IP
	/// \param  usPortServer 服务器Port
	/// 
	/// \note   注意：实际断开的链接是对应InitiateGameConnection链接成功的gameServerID的P2P链接
	///
	NPL_API void npl_User_TerminateGameConnection(uint32_t unIPServer, uint16_t usPortServer);

	/// 
	/// \brief  请求加密数据票证
	///
	/// \param  pDataToInclude 放入票证里的数据
	/// \param  cbDataToInclude 放到票证里的数据字节长度
	/// \return 请求句柄
	///
	/// \see    cbEncryptedAppTicketResponse_t
	///
	NPL_API long npl_User_RequestEncryptedAppTicket(cvoid_t pDataToInclude, int cbDataToInclude);

	/// 
	/// \brief  获取加密数据票证
	///
	/// \param  pTicket 加密的数据票证将拷贝到这个缓冲区
	/// \param  cbMaxTicket pTicket缓冲区的大小
	/// \param  pcbTicket 返回拷贝到pTicket的字节
	///
	/// \return true-成功
	///         false-失败：pcbTicket is null, pTicket is null, pTicket too small, was no ticket available
	///
	NPL_API bool npl_User_GetEncryptedAppTicket(pvoid_t pTicket, int cbMaxTicket, uint32_t* pcbTicket);

	/*
	gameServer
	*/
	///
	/// \brief  init gameserver
	///
	/// \param  IP 将绑定的 IP 地址（应使用主机序，即 127.0.0.1 == 0x7f000001）。您可使用 INADDR_ANY 来与所有的本地 IPv4 地址绑定。
	/// \param  gamePort 进行游戏时，客户端要连接至的端口。
	/// \param  queryPort 管理服务器浏览器相关事务以及来自客户端的信息Ping 的端口。
	/// \param  flags 一个或多个 ServerFlags 的并集
	/// \param  appID 服务器所针对游戏的 AppID。
	/// \param  pchVersionString 版本字符串通常以 x.x.x.x 的形式呈现，在服务器过期时由主服务器用于进行检测（只有最新版本的服务器会被列出）。
	/// \return true-成功 false-失败
	/// 
	/// \note   
	///
	NPL_API bool npl_GameServer_InitGameServer(uint32_t IP, uint16_t gamePort, uint16_t queryPort, uint32_t flags, uint64_t appID, cstr_t pchVersionString);

	///
	/// \brief  设置服务器名称
	///
	/// \param  pszServerName 服务器名称
	///
	/// \note   必要设置，LogOn之前
	/// 
	NPL_API void npl_GameServer_SetServerName(cstr_t pszServerName);

	///
	/// \brief  设置要报告给服务器浏览器的地图名称
	///
	/// \param  pszMapName 地图名称
	///
	/// \note   必要设置，LogOn之前
	/// 
	NPL_API void npl_GameServer_SetMapName(cstr_t pszMapName);

	///
	/// \brief  设置此服务器一次最多可容纳的玩家人数
	///
	/// \param  cPlayersMax 玩家人数
	///
	/// \note   必要设置，LogOn之前
	/// 
	NPL_API void npl_GameServer_SetMaxPlayerCount(int cPlayersMax);

	///
	/// \brief  设置游戏服务器中机器人或 AI 玩家的数量。默认值为零
	///
	/// \param  cBotplayers 服务器中机器人或 AI 玩家的数量
	///
	NPL_API void npl_GameServer_SetServerBotPlayerCount(int cBotplayers);

	///
	/// \brief  设置服务器观战端口
	///
	/// \param  spectatorPort 观战端口
	///
	NPL_API void npl_GameServer_SetSpectatorPort(uint16_t spectatorPort);

	///
	/// \brief  设置准备注册的服务器描述
	///
	/// \param  value 描述
	///
	NPL_API void npl_GameServer_SetServerDescription(cstr_t value);

	///
	/// \brief  设置准备注册的服务器密码
	///
	/// \param  value 密码
	///
	NPL_API void npl_GameServer_SetPasswordProtected(bool bPasswordProtected);

	///
	/// \brief  设置准备注册的服务器标记信息
	///
	/// \param  value 标记信息
	/// 
	/// \note   tags长度NPL_SERVER_TAGS_LEN
	///
	NPL_API void npl_GameServer_SetServerTags(cstr_t value);

	///
	/// \brief  设置准备注册的服务器游戏数据信息
	///
	/// \param  value 游戏数据
	/// 
	/// \note   gameData长度NPL_SERVER_GAME_DATA_LEN
	///
	NPL_API void npl_GameServer_SetServerGameData(cstr_t value);

	///
	/// \brief  设置准备注册的服务器服务区域
	///
	/// \param  value 服务器服务区域
	///
	NPL_API void npl_GameServer_SetServerRegion(cstr_t value);

	///
	/// \brief  登录
	///  
	/// \note   将会链接Npl服务器，并注册InitGameServer初始化的服务器信息
	///         
	///         如果链接注册成功将会有cbNplServersConnected_t的通知
	///         注册失败将会有cbNplServerConnectFailure_t的通知
	///
	NPL_API void npl_GameServer_LogOnAnonymous();

	///
	/// \brief  取得服务器的公网IP
	///
	/// \return IP的主机序，如果无法判定 IP，返回 0
	///
	NPL_API uint32_t npl_GameServer_GetPublicIP();

	///
	/// \brief  检查游戏服务器是否已登录
	///
	/// \return 如果游戏服务器已登录，为 true，否则为 false。
	///
	NPL_API bool npl_GameServer_BLoggedOn();

	///
	/// \brief  断开与NPL服务器的链接
	///
	NPL_API void npl_GameServer_LogOff();

	//         /// TODO: 
	//         NPL_API bool BeUpdateUserData();
	// 
	//         /// TODO:
	//         NPL_API bool BeSucure();
	// 
	//         /// TODO:
	//         NPL_API uint64_t CreateUnauthenticatedUserConnection();
	
	/// 
	/// \brief  增加/更新 键值对
	///
	NPL_API void npl_GameServer_SetKeyValue(cstr_t ptrKey, cstr_t ptrValue);

	/// 
	/// \brief  清空所有键值
	///
	NPL_API void npl_GameServer_ClearAllKeyValues();

	/// 
	/// \brief  设置观战服务器名
	///
	/// \param  ptrName 观战服务器名称
	/// \note   该数据可以通过ServerRules查询，Key值为 _SpectatorServerName
	///
	NPL_API void npl_GameServer_SetSpectatorServerName(cstr_t ptrName);

	/// 
	/// \brief  更新已经连接到服务器的玩家数据
	///
	/// \param  uid 玩家ID
	/// \param  userName 玩家名字
	/// \param  score 玩家分数
	/// \return true: 成功 false: 失败（uid 对应用户并没有连接到当前服务器 BeginAuthSession/SendUserConnectAndAuthenticate）
	///
	NPL_API bool npl_GameServer_BUpdateUserData(uint64_t uid, cstr_t userName, sint32_t score);

	///
	/// \brief  获取认证Ticket
	///
	/// \param  pTicket 接收认证信息的缓冲区
	/// \param  cbMaxTicket 接收认证信息的缓冲区长度（尽量长的定义该缓冲区，认证信息可能有1024字节）
	/// \param  pcbTicket 认证信息的长度
	/// \return 认证信息句柄
	///
	NPL_API AuthTicketHandle_t npl_GameServer_GetAuthSessionTicket(pvoid_t pTicket, sint32_t cbMaxTicket, uint32_t* pcbTicket);

	/// 
	/// \brief  取消认证票据
	/// \param  hAuthTicket 认证票据句柄
	///
	/// \see    GetAuthSessionTicket
	///
	NPL_API void npl_GameServer_CancelAuthTicket(AuthTicketHandle_t hAuthTicket);

	/// 
	/// \brief  认证nplid相关的票据
	/// \param  pAuthTicket 票据 （GetAuthSessionTicket 获得的票据）
	/// \param  cbAuthTicket 票据长度
	/// \param  nplid 票据来源者NPL ID
	/// \return 认证结果枚举
	///
	NPL_API eBeginAuthSessionResult npl_GameServer_BeginAuthSession(cvoid_t pAuthTicket, int cbAuthTicket, uint64_t nplid);

	/// 
	/// \brief  结束票据认证
	/// \param  nplid 票据来源者NPL ID
	///
	NPL_API void npl_GameServer_EndAuthSession(uint64_t nplid);

	///
	/// \brief  发送认证玩家
	///
	/// \param  unIPClient 游戏客户端IP
	/// \param  pAuthBlob  认证信息
	/// \param  unAuthBlobSize 认证信息长度
	/// \param  pUserID  认证玩家的ID（不可为空）
	/// \return true-执行成功，会有cbGSClientApprove_t或者cbGSClientDeny_t的事件通知
	///         false-执行失败
	/// 
	/// \note   
	/// \see    cbGSClientApprove_t / cbGSClientDeny_t
	///
	NPL_API bool npl_GameServer_SendUserConnectAndAuthenticate(uint32_t unIPClient, cvoid_t pAuthBlob, uint32_t unAuthBlobSize, uint64_t* pUserID);

	///
	/// \brief  发送玩家断开连接
	///
	/// \param  userID 玩家ID
	///
	NPL_API void npl_GameServer_SendUserDisconnect(uint64_t userID);

	/// 
	/// \brief 心跳
	/// 
	/// \param  bActive false-关闭 true-开启
	///
	NPL_API void npl_GameServer_EnableHeartbeats(bool bActive);

	///
	/// \brief  获取服务器ID
	///
	/// \param  
	/// \return 服务器ID
	///
	NPL_API uint64_t npl_GameServer_GetNplServerID();

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
	NPL_API bool npl_GameServer_HandleIncomingPacket(cstr_t pData, int cbData, uint32_t srcIP, uint16_t srcPort);

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
	NPL_API int npl_GameServer_GetNextOutgoingPacket(pvoid_t* pOut, int cbMaxOut, uint32_t* pNetAdr, uint16_t* pNetPort);

	///
	/// \brief  获取图片尺寸
	///
	/// \param  iImage 图片句柄
	/// \param  puWidth 返回图片宽度
	/// \param  puHeight 返回图片高度
	/// \return true-成功 false-失败(如果未找到iImage对应的图片)
	/// 
	/// \note   
	///
	NPL_API bool npl_utils_GetImageSize(sint32_t iImage, uint32_t* puWidth, uint32_t* puHeight);

	///
	/// \brief  获取图片字节
	///
	/// \param  iImage 图片句柄
	/// \param  pubDest 接收图片字节的缓冲
	/// \param  nDestBufferSize pubDest缓冲的总大小
	/// \return true-成功 false-失败(如果未找到iImage对应的图片，或者获取图片RGBA字节失败)
	/// 
	/// \note   pubDest大小不应小于GetImageSize得到的 puWidth * puHeight * 4
	///
	NPL_API bool npl_utils_GetImageRGBA(sint32_t iImage, uint8_t* pubDest, int nDestBufferSize);


	NPL_API cstr_t npl_utils_GetIPCountry();

	///
	/// \brief 释放线程局部存储对象
	///
	NPL_API void NplReleaseCurrentThreadMemory();

	///
	/// \brief 创建实时会话
	///
	/// \param channelType 自定义的通道类型，比如"team", "clan", "friends"...
	/// \param sessionName 自定义的会话名称
	/// 
	/// \note 由channelType和sessionName可确定一个会话房间，同一房间内的session可以互相通话
	///
	NPL_API void NplVoiceCreateSession(cstr_t channelType, cstr_t sessionName);

	///
	/// \brief 销毁的会话
	///
	/// \param sessionId 会话id
	///
	NPL_API void NplVoiceDestroySession(sint32_t sessionId);

	///
	/// \brief 登录会话
	///
	/// \note 说明：一个session可以反复login/logout。另外app切到后台时，建议logout断开，节省流量；
	///
	/// \param sessionId 会话id
	///
	NPL_API void NplVoiceLoginSession(sint32_t sessionId);

	///
	/// \brief 退出会话
	///
	/// \param sessionId 会话id
	///
	NPL_API void NplVoiceLogoutSession(sint32_t sessionId);

	///
	/// \brief 开始录音
	///
	/// \param sessionId 会话id
	///
	NPL_API void NplVoiceStartCapture(sint32_t sessionId);

	///
	/// \brief 停止录音
	///
	/// \param sessionId 会话id
	///
	NPL_API void NplVoiceStopCapture(sint32_t sessionId);

	///
	/// \brief 测试mic
	///
	/// \param sessionId 会话id
	///
	/// \return bool, true 正在试麦, false 没有在试麦
	///
	NPL_API void NplVoiceTestMic(sint32_t sessionId, bool start);

	///
	/// \brief 增加录音音量
	///
	/// \param sessionId 会话id
	///
	/// \return int, 当前录音音量
	///
	NPL_API void NplVoiceSetRecordVol(sint32_t recordVol);

	///
	/// \brief 设置软件播放音量
	///
	/// \param sessionId 会话id
	/// \param percent 0表示0%，100表示100%，150表示150%
	///
	/// \return int 软件音量，不会影响系统音量，不会影响其他软件的音量。0表示0%，100表示100%，150表示150%
	///
	NPL_API void NplVoiceSetPlaybackVol(sint32_t sessionId, uint32_t percent);

	///
	/// \brief 屏蔽发声
	///
	/// \param sessionId 会话id
	/// \param userId 需要屏蔽的用户id
	/// \param isIgnore 是否屏蔽, true 屏蔽 false 取消屏蔽
	///
	NPL_API void NplVoiceIgnoreVoice(sint32_t sessionId, NPL_USRID userId, bool isIgnore);

	///
	/// \brief 静音
	///
	/// \param sessionId 会话id
	/// \param isMute 是否静音
	///
	NPL_API void NplVoiceMutePlayback(sint32_t sessionId, bool isMute);


	///
	/// \brief 获取正在说话人的列表
	///
	/// \param sessionId 会话id
	///
	/// \see RegistEvent cbVoiceSpeakingList_t
	///
	NPL_API void NplVoiceGetSpeakingList(sint32_t sessionId);

	///
	/// \brief Must call init when starting use of the interface
	///
	NPL_API bool npl_htmlsurface_Init();

	///
	/// \brief Must call shutdown when ending use of the interface
	///
	NPL_API bool npl_htmlsurface_Shutdown();

	///
	/// \brief Create a browser object for display of a html page.
	///
	/// \param pchUserAgent The user agent string is a substring to be added to the general 
	///                     user agent string so you can identify your client on web servers.
	/// \param pchUserCSS a CSS style sheet to every displayed page, 
	///					  leave null if you do not require this functionality.
	/// \see RegistEvent cbHTML_BrowserReady_t
	///
	NPL_API void npl_htmlsurface_CreateBrowser(const char *pchUserAgent, const char *pchUserCSS);

	///
	/// \brief Call this when you are done with a html surface, this lets us free the resources being used by it
	///
	/// \param unBrowserHandle  Browser identifier
	///
	NPL_API void npl_htmlsurface_RemoveBrowser(HHTMLBrowser unBrowserHandle);

	///
	/// \brief Navigate to this URL
	///
	/// \param unBrowserHandle Browser identifier
	/// \param pchURL the vist net path
	/// \param pchPostData post data
	///
	/// \see RegistEvent HTML_StartRequest_t
	///
	NPL_API void npl_htmlsurface_LoadURL(HHTMLBrowser unBrowserHandle, const char *pchURL, const char *pchPostData);

	///
	/// \brief Tells the surface the size in pixels to display the surface
	///
	/// \param unBrowserHandle Browser identifier
	/// \param unWidth
	/// \param unHeight
	///
	NPL_API void npl_htmlsurface_SetSize(HHTMLBrowser unBrowserHandle, uint32_t unWidth, uint32_t unHeight);

	///
	/// \brief Stop the load of the current html page
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_StopLoad(HHTMLBrowser unBrowserHandle);

	///
	/// \brief Reload (most likely from local cache) the current page
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_Reload(HHTMLBrowser unBrowserHandle);

	///
	/// \brief navigate back in the page history
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_GoBack(HHTMLBrowser unBrowserHandle);

	///
	/// \brief navigate forward in the page history
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_GoForward(HHTMLBrowser unBrowserHandle);

	///
	/// \brief add this header to any url requests from this browser
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_AddHeader(HHTMLBrowser unBrowserHandle, const char *pchKey, const char *pchValue);

	///
	/// \brief run this javascript script in the currently loaded page
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_ExecuteJavascript(HHTMLBrowser unBrowserHandle, const char *pchScript);

	///
	/// \brief Mouse click commands
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_MouseUp(HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton);
	NPL_API void npl_htmlsurface_MouseDown(HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton);
	NPL_API void npl_htmlsurface_MouseDoubleClick(HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton);

	///
	/// \brief Mouse movement commands
	///
	/// \param unBrowserHandle Browser identifier
	/// \param x Mouse position of x
	/// \param y Mouse position of Y
	///
	NPL_API void npl_htmlsurface_MouseMove(HHTMLBrowser unBrowserHandle, int x, int y);

	///
	/// \brief Mouse wheel commands
	///
	/// \param unBrowserHandle Browser identifier
	/// \param nDelta pixels of scroll
	///
	NPL_API void npl_htmlsurface_MouseWheel(HHTMLBrowser unBrowserHandle, sint32_t nDelta);

	///
	/// \brief Keybroad commands
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_KeyDown(HHTMLBrowser unBrowserHandle, uint32_t nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers);
	NPL_API void npl_htmlsurface_KeyUp(HHTMLBrowser unBrowserHandle, uint32_t nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers);
	NPL_API void npl_htmlsurface_KeyChar(HHTMLBrowser unBrowserHandle, uint32_t cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers);

	///
	/// \brief programmatically scroll this many pixels on the page
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_SetHorizontalScroll(HHTMLBrowser unBrowserHandle, uint32_t nAbsolutePixelScroll);
	NPL_API void npl_htmlsurface_SetVerticalScroll(HHTMLBrowser unBrowserHandle, uint32_t nAbsolutePixelScroll);

	///
	/// \brief tell the html control if it has key focus currently, controls showing the I-beam cursor in text controls amongst other things
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_SetKeyFocus(HHTMLBrowser unBrowserHandle, bool bHasKeyFocus);

	///
	/// \brief open the current pages html code in the local editor of choice, used for debugging
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_ViewSource(HHTMLBrowser unBrowserHandle);

	///
	/// \brief copy the currently selected text on the html page to the local clipboard
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_CopyToClipboard(HHTMLBrowser unBrowserHandle);

	///
	/// \brief paste from the local clipboard to the current html page
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_PasteFromClipboard(HHTMLBrowser unBrowserHandle);

	///
	/// \brief find this string in the browser, if bCurrentlyInFind is true then instead cycle to the next matching element
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_Find(HHTMLBrowser unBrowserHandle, const char *pchSearchStr, bool bCurrentlyInFind, bool bReverse);

	///
	/// \brief cancel a currently running find
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_StopFind(HHTMLBrowser unBrowserHandle);

	///
	/// \brief return details about the link at position x,y on the current page
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_GetLinkAtPosition(HHTMLBrowser unBrowserHandle, int x, int y);

	///
	/// \brief set a webcookie for the hostname in question
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_SetCookie(const char *pchHostname, const char *pchKey, const char *pchValue, const char *pchPath = "/", float nExpires = 0.0f, bool bSecure = false, bool bHTTPOnly = false);

	///
	/// \brief Zoom the current page by flZoom ( from 0.0 to 2.0, so to zoom to 120% use 1.2 ), 
	///        zooming around point X,Y in the page (use 0,0 if you don't care)
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_SetPageScaleFactor(HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY);


	///
	/// \brief Enable/disable low-resource background mode, where javascript and repaint timers are throttled, resources are
	///        more aggressively purged from memory, and audio/video elements are paused. When background mode is enabled,
	///	       all HTML5 video and audio objects will execute ".pause()" and gain the property "._steam_background_paused = 1".
	///	       When background mode is disabled, any video or audio objects with that property will resume with ".play()".
	///
	/// \param unBrowserHandle Browser identifier
	/// \param bBackgroundMode does use background mode
	///
	NPL_API void npl_htmlsurface_SetBackgroundMode(HHTMLBrowser unBrowserHandle, bool bBackgroundMode);

	///
	///  \brief  You MUST call this in response to a HTML_StartRequest_t callback
	///	         Set bAllowed to true to allow this navigation, false to cancel it and stay 
	///	         on the current page. You can use this feature to limit the valid pages
	///	         allowed in your HTML surface.
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_AllowStartRequest(HHTMLBrowser unBrowserHandle, bool bAllowed);

	///
	/// \brief You MUST call this in response to a HTML_JSAlert_t or HTML_JSConfirm_t callback
	///        Set bResult to true for the OK option of a confirm, use false otherwise
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_JSDialogResponse(HHTMLBrowser unBrowserHandle, bool bResult);

	///
	/// \brief You MUST call this in response to a HTML_FileOpenDialog_t callback
	///
	/// \param unBrowserHandle Browser identifier
	///
	NPL_API void npl_htmlsurface_FileLoadDialogResponse(HHTMLBrowser unBrowserHandle, const char **pchSelectedFiles);

#ifdef __cplusplus
}
#endif
#endif // !NPL_C_INTERFACE_H__

