///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \file npl-friend.h
///
/// \brief NPL friend functional
///
#ifndef __NPL_FRIEND_H__
#define __NPL_FRIEND_H__

///
/// \brief  好友关系
///
enum enRelationship
{
	/// nothing relationship
	eRelationship_Noen,
	/// I was invite the query player
	eRelationship_Invite,
	/// My invite was refused by query player.
	eRelationship_Refuse,
	/// query player invite me.
	eRelationship_BeInvite,
	/// query player is friend with me.
	eRelationship_Friend,
	/// I was ignore the player all message.
	eRelationship_Ignore,
	/// query player was friend befor, but it was dorped me to block list.
	eRelationship_Block,
	/// I was delete friend
	eRelationship_Delete,
};

///
/// \brief  好友通知消息枚举
///
enum enFriendMessageType
{
	/// 被邀请
	eType_BeInvite,
	/// 接收邀请
	eType_Agree,
	/// 拒绝邀请
	eType_Refuse,
	/// 删除好友
	eType_Delete,
    /// 状态更新
    eType_Status,
};

/// 
/// \brief  用户状态、信息变更枚举
///
enum enPersonaChange
{
	/// 昵称变更
	enPersonaChange_NickName = 0x0001,
	/// 状态变更（待完善）
	enPersonaChange_Status = 0x0002,
	/// 上线
	enPersonaChange_ComeOnline = 0x0004,
	/// 离线
	enPersonaChange_GoneOffline = 0x0008,
	/// 开始游戏
	enPersonaChange_GamePlayed = 0x0010,
	/// 游戏服务器变更
	enPersonaChange_GameServer = 0x0020,
	/// avata
	enPersonaChange_Avata = 0x0040,
	/// 加入源
	enPersonaChange_JoinedSource = 0x0080,
	/// 离开源
	enPersonaChange_leftSource = 0x0100,
	/// 好友关系（待完善）
	enPersonaChange_RelationshipChanged = 0x0200,
	/// 完整状态变更
	enPersonaChange_RichPresence = 0x0400,
};

///
/// \brief	角色状态枚举值
///
enum enPersonStatus
{
	/// 离线
	eStatus_Offline,
	/// 在线
	eStatus_Online,
	/// 忙碌
	eStatus_Busy,
	/// 离开
	eStatus_Away,
	/// 长时间离开
	eStatus_Sleep,
	/// 游戏中
	eStatus_Play,
	/// 浏览商店
	eStatus_Trade,
};

///
/// \brief	聊天消息内容类型
///
enum enChatMessageType
{
	enChatText = 0,                // 文本
	enChatAudio = 2,               // 语音
	enChatSystemNotify = 5,        // 系统通知
};

///
/// \brief	聊天消息内容类型
///
enum TeamEventType
{
  eChatTeamQuery = -1,         /// 查询群
  eChatTeamInvite = 0,         /// 邀请加入
  eChatTeamLeave = 2,          /// 退出群
  eChatTeamDismiss = 4,        /// 解散群
  eChatLocalCreateTeam = 2000, /// 创建群
};

#pragma pack(push, NPL_PACK_SIZE)

///
/// \brief  好友关系变更请求回调结构
/// 
struct cbFriendRelationResult_t
{
	enum {iEvtType = enNplFriend + 1};
	/// 好友ID
	NPL_USRID uid;
	/// 当前与好友的关系
	enRelationship relation;
};

///
/// \brief  好友分组变更请求回调结构
///
struct cbFriendSetGroupResult_t
{
	enum { iEvtType = enNplFriend + 2 };
	/// 好友ID
	NPL_USRID uid;
	/// 分组ID
	char gid[NPL_GROUP_ID_LEN];
	/// 分组名称
	char groupName[NPL_GROUP_NAME_LEN];
};

///
/// \brief  好友分组删除请求回调的结构
///
struct cbFriendDelGroupResult_t
{
	enum { iEvtType = enNplFriend + 3 };
	/// 分组ID
	char gid[NPL_GROUP_ID_LEN];
};

///
/// \brief  好友请求等通知的结构
///
struct cbFriendMessageNotify_t
{
	enum { iEvtType = enNplFriend + 4 };
	/// 好友ID
	NPL_USRID uid;
	/// 好友名称
	char name[NPL_USERNAME_LEN];
	/// 通知类型
	enFriendMessageType type;
};

/// 
/// \brief  好友请求回执
///
struct cbFriendListRequest_t
{
	enum { iEvtType = enNplFriend + 5 };
};

/// 
/// \brief  请求指定用户信息回执
///
struct cbRequestUserInformation_t
{
	enum { iEvtType = enNplFriend + 6 };
	/// 用户ID
	NPL_USRID uid;
};

/// 
/// \brief  用户完整状态信息更新通知
///
struct cbFriendRichPresenceUpdate_t
{
	enum { iEvtType = enNplFriend + 7 };
	/// 用户ID
	NPL_USRID uid;
};

/// 
/// \brief  通知好友状态变更
///
struct cbPersonaStateChange_t
{
	enum { iEvtType = enNplFriend + 8 };
	/// 用户ID
	NPL_USRID uid;
	/// 变更标识
	uint32_t changeFlags;
};

///
/// \brief  好友是否在游戏中   
///
struct FriendGameInfo_t
{
	/// 正在游玩的游戏ID
	NPL_APPID appid;
	/// 正在游玩的服务器IP
	uint32_t gameIP;
	/// 正在游玩的服务器端口
	uint16_t gamePort;
	/// 正在游玩的服务器的查询端口
	uint16_t queryPort;
	/// 好友所在的大厅ID
	NPL_LBYID lobbyID;
};

///
/// \brief 从好友接收到一条消息
///
struct cbGameConnectedFriendChatMsg_t
{
	enum { iEvtType = enNplFriend + 9 };

	/// 发送消息的用户id
	NPL_USRID sendId;
	/// 消息id
	char msgId[NPL_CHAT_MAX_MSG_ID_LEN];
};


///
/// \brief 开始录音回调
///
struct cbChatStartCapture_t
{
	enum { iEvtType = enNplChat + 21 };

	sint32_t isSuc;    // 是否成功
};


///
/// \brief 结束录音回调
///
struct cbChatStopCapture_t
{
	enum { iEvtType = enNplChat + 22 };

	char resId[NPL_CHAT_MAX_MSG_ID_LEN];			// 录音资源id
	char filePath[NPL_CHAT_MAX_FILE_PATH_LEN];		// 文件路径
	char fileExt[NPL_CHAT_MAX_FILE_EXT_LEN];		// 文件扩展名
	sint32_t audioDuration;							// 声音时长

};

///
/// \brief 发送消息回调
///
struct cbChatSendMsg_t
{
	enum { iEvtType = enNplChat + 23 };

	char msgId[NPL_CHAT_MAX_MSG_ID_LEN];            /// 消息id
	sint64_t timeTag;								/// 创建时间
};

struct NplChatTeamProperty
{
	sint32_t reserved;							/// 保留字段
};

///
/// \brief 群聊事件信息回调
///
struct cbChatTeamEventInfo_t
{
	enum { iEvtType = enNplChat + 25 };

	char teamId[NPL_CHAT_MAX_MSG_ID_LEN];       /// 群ID
	char teamName[NPL_USERNAME_LEN];		    /// 群名称
	NPL_USRID creator;							/// 创建者
	sint32_t eventType;                         /// 事件类型 \see enum TeamEventType
	sint64_t createTime;                        /// 创建时间
	sint32_t memberCount;                       /// 群全部成员数量
	sint32_t maxMemberCount;                    /// 群最大成员数量
	NplChatTeamProperty property;               /// 群属性
	uint32_t relatedMemberCount;                /// 相关成员数量
	NPL_USRID*relatedMembers;                   /// 相关成员ID信息
};

///
/// \brief 查询自己创建的全部聊天群
///
struct cbChatQueryAllCreatedTeams_t
{
	enum { iEvtType = enNplChat + 27 };

	uint32_t teamCount;
	char** teamIds;
};

///
/// \brief 群聊成员信息
///
struct cbNplChatTeamMemberInfo_t
{
	enum { iEvtType = enNplChat + 28 };

	char teamId[NPL_CHAT_MAX_MSG_ID_LEN];       /// 群ID
	char nickName[NPL_USERNAME_LEN];			/// 用户昵称
	char avatarUrl[NPL_CHAT_MAX_FILE_PATH_LEN]; /// 用户头像

	NPL_USRID userId;							/// 用户id
	sint64_t joinTime;							/// 加入群时间
	uint32_t isMute;                            /// 是否被禁言
	uint32_t sex;								/// 性别0：男 1：女 2： 未知
};

///
/// \brief 群聊全部成员信息
///
struct cbChatTeamAllMembersInfo_t
{
	enum { iEvtType = enNplChat + 29 };

	char teamId[NPL_CHAT_MAX_MSG_ID_LEN];       /// 群ID
	uint32_t memberCount;						/// 相关成员数量
	cbNplChatTeamMemberInfo_t* members;			/// 成员信息
};


///
/// \brief 接收消息回调
///
struct cbChatReceiveMsg_t
{
	enum { iEvtType = enNplChat + 24 };

	sint32_t sessionType;						/// 0, 个人 1, 群
	sint32_t msgType;							/// 0, 文本  2，声音  5,系统通知
	sint32_t status;                            /// 0, 默认 1, 收到消息(未读) 2,收到消息(已读) 3,已删 4,发送中 5,发送失败 6,已发送
	sint64_t timeTag;							/// 创建时间

	char msgId[NPL_CHAT_MAX_MSG_ID_LEN];        /// 消息id
	NPL_USRID sender;							/// 发送者账号ID
	char senderNick[NPL_CHAT_MAX_MSG_ID_LEN];	/// 发送者昵称
	NPL_USRID recvUserId;						/// 接受者ID(用户)
	char recvTeamId[NPL_CHAT_MAX_MSG_ID_LEN];	/// 接受者ID(队伍)
	char content[NPL_CHAT_MAX_CONTENT_LEN];		/// 发送内容
	char resPath[NPL_CHAT_MAX_FILE_PATH_LEN];   /// 声音或其他资源路径
};

///
/// \brief 查询聊天日志
///
struct cbChatQueryMsgLog_t
{
	enum { iEvtType = enNplChat + 30 };
	uint32_t msgType;							/// 查询类型， 0: p2p 1:team
	NPL_USRID userId;							/// 用户id
	char teamId[NPL_CHAT_MAX_MSG_ID_LEN];		/// 群ID
	uint32_t msgCount;
	cbChatReceiveMsg_t* msgs;					/// 聊天日志信息
};

///
/// \brief 查询聊天日志
///
struct cbChatQueryTeamMsgLog_t
{
	enum { iEvtType = enNplChat + 31 };
	char teamId[NPL_CHAT_MAX_MSG_ID_LEN];			/// 群ID
	uint32_t msgCount;
	cbChatReceiveMsg_t* msgs;					/// 聊天日志信息
};

#pragma pack(pop)

#ifndef __NPL_C_INTERFACE__
namespace npl
{
    ///
    /// \brief friend interface
    /// 
	struct NPL_API INplFriend
    {
    public:
        ///
        /// \brief  获取自己的名字
        ///
        /// \param  
        /// \return 自己的名字
        /// 
        /// \note   
        /// \see    
        ///
		virtual cstr_t GetPersonName() = 0;

        ///
        /// \brief  获取当前状态
        ///
        /// \param  
        /// \return 状态
        /// 
        /// \note   
        /// \see     
        ///
		virtual enPersonStatus GetPersonStatus() = 0;

        ///
        /// \brief  请求好友列表
        ///
        /// \param  
        /// \return 异步请求Token
        /// 
        /// \note   
        /// \see    RegistCallback cbFriendListRequest_t
        ///
		virtual long FriendListRequest() = 0;

        ///
        /// \brief  获取好友数量
        ///
        /// \param  
        /// \return 好友数量
        /// 
        /// \note   
        /// \see     
        ///
		virtual long GetFriendCount() = 0;

        ///
        /// \brief  通过游标获取好友ID
        ///
        /// \param  index 游标
        /// \return 好友ID
        /// 
        /// \note   游标不应大于GetFriendCount返回值
        /// \see    
        ///
        virtual NPL_USRID GetFriendByIndex(int index) = 0;

        ///
        /// \brief  获取好友名字
        ///
        /// \param  uid 好友ID
        /// \return 名字
        /// 
        /// \note   
        /// \see    
        ///
		virtual cstr_t GetFriendName(const NPL_USRID &uid) = 0;

        ///
        /// \brief  获取好友状态
        ///
        /// \param  uid 好友ID
        /// \return 状态
        /// 
        /// \note   
        /// \see    
        ///
		virtual enPersonStatus GetFriendStatus(const NPL_USRID &uid) = 0;

        ///
        /// \brief  获取用户好友关系
        ///
        /// \param  uid 用户ID
        /// \return 关系
        /// 
        /// \note   
        /// \see    
        ///
		virtual enRelationship GetFriendRelationship(const NPL_USRID &uid) = 0;

        ///
        /// \brief  获取好友分组数量
        ///
        /// \param  
        /// \return 分组数量
        /// 
        /// \note   
        /// \see     
        ///
		virtual long GetGroupCount() = 0;

        ///
        /// \brief  获取是否存在指定分组
        ///
        /// \param  groupName 分组名称
        /// \return 是否存在该分组
        /// 
        /// \note   
        /// \see     
        ///
		virtual bool HasGroup(cstr_t groupName) = 0;

        ///
        /// \brief  通过游标获取分组ID
        ///
        /// \param  index 游标
        /// \return 分组ID
        /// 
        /// \note   游标不应大于GetFriendGroupCount返回值
        /// \see     
        ///
		virtual cstr_t GetGroupId(int index) = 0;

        ///
        /// \brief  通过游标获取分组名称
        ///
        /// \param  index 游标
        /// \return 分组名称
        /// 
        /// \note   游标不应大于GetFriendGroupCount返回值
        /// \see    
        ///
		virtual cstr_t GetGroupName(int index) = 0;

        ///
        /// \brief  通过分组ID获取分组名称
        ///
        /// \param  gid 分组ID
        /// \return 分组名称
        /// 
        /// \note   
        /// \see     
        ///
		virtual cstr_t GetGroupName(cstr_t gid) = 0;

        ///
        /// \brief  获取指定好友所在分组ID
        ///
        /// \param  uid 好友ID
        /// \return 分组ID
        /// 
        /// \note   
        /// \see    
        ///
        virtual cstr_t GetFriendGroupId(const NPL_USRID &uid) = 0;

        ///
        /// \brief  获取指定好友所在分组名称
        ///
        /// \param  uid 好友ID
        /// \return 分组名称
        /// 
        /// \note   
        /// \see    
        ///
		virtual cstr_t GetFriendGroupName(const NPL_USRID &uid) = 0;
        
        ///
        /// \brief  获取指定分组好友数量
        ///
        /// \param  gid 分组ID
        /// \return 好友数量
        /// 
        /// \note   
        /// \see    
        ///
		virtual long GetGroupMembersCount(cstr_t gid) = 0;

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
		virtual long GetGroupMembersList(cstr_t gid, NPL_USRID* membersOut, long membersCount) = 0;

        ///
        /// \brief  是否与指定用户是好友关系
        ///
        /// \param  uid 用户ID
        /// \return 是否是好友
        /// 
        /// \note   
        /// \see    
        ///
		virtual bool HasFriend(const NPL_USRID &uid) = 0;

        ///
        /// \brief  邀请指定用户成为好友
        ///
        /// \param  uid 用户ID
        /// \return 异步调用的Token
        /// 
        /// \note   
        /// \see    RegistCallback cbFriendRelationResult_t
        ///
        virtual long InviteFriend(const NPL_USRID &uid) = 0;

        ///
        /// \brief  接受好友邀请
        ///
        /// \param  uid 用户ID
        /// \return 异步调用的Token
        /// 
        /// \note   
        /// \see    RegistCallback cbFriendRelationResult_t
        ///
        virtual long AcceptFriend(const NPL_USRID &uid) = 0;

        ///
        /// \brief  拒绝好友邀请
        ///
        /// \param  uid 用户ID
        /// \return 异步调用的Token
        /// 
        /// \note   
        /// \see    RegistCallback cbFriendRelationResult_t
        ///
        virtual long RefuseFriend(const NPL_USRID &uid) = 0;

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
        virtual long IgnoreFriend(const NPL_USRID &uid, bool cancel) = 0;

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
        virtual long BlockFriend(const NPL_USRID &uid, bool cancel) = 0;

        ///
        /// \brief  将指定好友删除
        ///
        /// \param  uid 用户ID
        /// \return 异步调用的Token
        /// 
        /// \note   
        /// \see    RegistCallback cbFriendRelationResult_t
        ///
        virtual long DeleteFriend(const NPL_USRID &uid) = 0;
        
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
        virtual long SetFriendGroup(const NPL_USRID &uid, cstr_t groupName) = 0;

        ///
        /// \brief  删除好友分组
        ///
        /// \param  groupName 分组名称
        /// \return 异步调用的Token
        /// 
        /// \note   删除好友分组可以删除一个没有好友的分组，若这个分组有好友在，则会删除失败。在调用完成时，系统会调用注册在Token上的回调，并传入cbFriendDelGroupResult_t结构参数
        /// \see    RegistCallback cbFriendDelGroupResult_t
        ///
        virtual long DeleteFriendGroup(cstr_t groupName) = 0;

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
        virtual bool SendChatMessage(const NPL_USRID &uid, cstr_t message) = 0;

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
		virtual bool SendRoomMessage(cstr_t roomId, cstr_t message) = 0;

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
		virtual bool GetFriendGamePlayed(const NPL_USRID &uid, FriendGameInfo_t* pInfo) = 0;

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
		virtual bool SetRichPresence(cstr_t key, cstr_t value) = 0;

		///
		/// \brief  清除当前用户完整状态
		///
		/// \param
		/// \return
		/// 
		/// \note 
		/// \see     
		///
		virtual void ClearRichPresence() = 0;

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
		virtual cstr_t GetFriendRichPresence(const NPL_USRID &uid, cstr_t key) = 0;

		///
		/// \brief  获取指定用户上设定的完整状态键数量
		///
		/// \param uid 用户ID
		/// \return  完整状态数量
		/// 
		/// \note 
		/// \see     
		///
		virtual sint32_t GetFriendRichPresenceKeyCount(const NPL_USRID &uid) = 0;

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
		virtual cstr_t GetFriendRichPresenceKeyByIndex(const NPL_USRID &uid, sint32_t idx) = 0;

		///
		/// \brief  请求指定用户的完整状态
		///
		/// \param  uid 用户ID
		/// \return 异步调用的Token
		/// 
		/// \note 
		/// \see    RegistCallback cbFriendRichPresenceUpdate_t
		///
		virtual long RequestFriendRichPresence(const NPL_USRID &uid) = 0;

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
		virtual bool IsUserInSource(const NPL_USRID &uid, uint64_t sourceID) = 0;

		///
		/// \brief  为指定用户获取中型（64*64 像素）头像的句柄
		///
		/// \param  uid 用户ID
		/// \return 图片句柄
		/// 
		/// \note 
		/// \see     
		///
		virtual sint32_t GetMediumFriendAvatar(const NPL_USRID &uid) = 0;

		///
        /// \brief  请求指定用户的昵称及头像（可选）
        ///
        /// \param  uid 用户ID
		/// \param  bReqNameOnly 是否只需要名字
        /// \return 如果本地没有缓存在返回异步回调的token并下载对应数据完成后产生回调，否则返回-1且可以马上取缓存的数据
        /// 
        /// \note 如果选择需要头像则会下载头像，可能会更费时。
        /// \see   RegistCallback cbRequestUserInformation_t
        ///
		virtual long RequestUserInformation(const NPL_USRID &uid, bool bReqNameOnly) = 0;

		///
        /// \brief  设置指定用户为一起游玩过的
        ///
        /// \param  uid 用户ID
        /// \return 
        /// 
        /// \note 
        /// \see     
        ///
		virtual void SetPlayedWith(const NPL_USRID &uid) = 0;

		///
		/// \brief 设置是否接受好友的消息
		///
		/// \param bInterceptEnabled 是否接收好友的消息
		/// 
		/// \see RegistEvent cbGameConnectedFriendChatMsg_t
		///
		virtual void SetListenForFriendsMessages(bool bInterceptEnabled) = 0;

		///
		/// \brief 回复好友消息
		///
		/// \param friendID 好友id
		/// \param msgContent 消息内容
		///
		/// \return cstr_t 消息id
		///
		virtual cstr_t ReplyToFriendMessage(NPL_USRID friendID, cstr_t msgContent) = 0;

		///
		/// \brief 查询好友消息
		///
		/// \param friendID 好友id
		/// \param msgId 消息id
		/// \param[in, out] pvData 返回的消息内容
		/// \param cubData pvData字节长度
		/// \param[out] peChatEntryType 消息类型
		///
		/// \note 此函数只能在 cbGameConnectedFriendChatMsg_t 回调中调用
		///
		/// \return pvData 拷贝的字节数
		///
		virtual int GetFriendMessage(NPL_USRID friendID, cstr_t msgId, void *pvData, int cubData, enChatMessageType *peChatEntryType) = 0;

		///
		/// \brief 向聊天群发送文本消息
		///
		/// \param teamId 接收群id
		/// \param content 文本内容
		///
		/// \see RegistEvent cbChatSendMsg_t
		///
		/// \return cstr_t 消息ID
		///
		virtual cstr_t ReplyToTeamMessage(cstr_t teamId, cstr_t content) = 0;

		///
		/// \brief 向好友发送语音消息
		///
		/// \param recverId 接收者id
		/// \param audioResId 音频资源唯一ID
		///
		/// \see RegistEvent cbChatSendMsg_t
		/// 
		/// \return cstr_t 消息ID
		///
		virtual cstr_t ReplyToFriendAudioMessage(NPL_USRID recverId, cstr_t audioResId) = 0;

		///
		/// \brief 聊天群发送语音消息
		///
		/// \param teamId 接收群id
		/// \param audioResId 音频资源唯一ID
		///
		/// \see RegistEvent cbChatSendMsg_t
		/// 
		/// \return cstr_t 消息ID
		///
		virtual cstr_t ReplyToTeamAudioMessage(cstr_t teamId, cstr_t audioResId) = 0;

		///
		/// \brief 开始录音
		///
		/// \see RegistEvent cbChatStartCapture_t
		/// 
		/// \return string 声音资源ID
		///
		virtual cstr_t StartAudioMessageCapture() = 0;

		///
		/// \brief 结束录音
		///
		/// \see RegistEvent cbChatStopCapture_t
		/// 
		virtual void StopAudioMessageCapture() = 0;

		///
		/// \brief 取消录制语音
		/// 
		/// \param audioResId 声音资源id
		///
		virtual void CancelAudioMessageCapture(cstr_t audioResId) = 0;

		///
		/// \brief 播放录音
		///
		/// \param file_path 文件路径
		///
		virtual void PlayAudioMessage(cstr_t file_path) = 0;

		///
		/// \brief 停止播放
		///
		virtual void StopAudioMessage() = 0;

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
		virtual void CreateChatTeam(cstr_t teamName, uint32_t maxCount, const NPL_USRID* members, sint32_t memberCount) = 0;

		///
		/// \brief 群聊邀请他人
		///
		/// \param teamId 群id
		/// \param members 被邀请人（可多人）
		/// \param memberCount members数值大小
		///
		/// \see RegistEvent cbChatTeamEventInfo_t
		/// 
		virtual void ChatTeamInvite(cstr_t teamId, const NPL_USRID* members, sint32_t memberCount) = 0;

		///
		/// \brief 解散群聊
		///
		/// \param teamId 群id
		///
		/// \see RegistEvent cbChatTeamEventInfo_t
		/// 
		virtual void ChatTeamDismiss(cstr_t teamID) = 0;

		///
		/// \brief 离开群
		///
		/// \param teamId 群id
		///
		/// \see RegistEvent cbChatTeamEventInfo_t
		/// 
		virtual void ChatTeamLeave(cstr_t teamID) = 0;

		///
		/// \brief 查询群所有成员信息
		///
		/// \param teamId 群聊id
		///
		/// \see RegistEvent cbChatTeamAllMembersInfo_t
		/// 
		virtual void QueryChatTeamAllMembers(cstr_t teamId) = 0;

    ///
    /// \brief 查询单个群信息
    ///
    /// \param teamId 群聊id
    ///
    /// \see RegistEvent cbChatTeamEventInfo_t
    ///
    virtual void QueryChatTeam(cstr_t teamId) = 0;

		///
		/// \brief 查询单个群成员信息
		///
		/// \param teamId 群聊id
		/// \param memberId 成员id
		///
		/// \see RegistEvent cbNplChatTeamMemberInfo_t
		///
		virtual void QueryChatTeamMember(cstr_t teamId, NPL_USRID memberId) = 0;

		///
		/// \brief 查询当前用户创建的全部群
		///
		/// \see RegistEvent cbChatQueryAllCreatedTeams_T
		///
		virtual void QueryAllCreatedChatTeams() = 0;

		///
		/// \brief 查询消息日志
		///
		/// \param id				查询id，对方的account id或者群组tid。 
		/// \param limit_count		本次查询的消息条数上限(最多100条)
		/// \param fromTime			开始时间
		/// \param endTime			结束时间
		///
		/// \see RegistEvent cbChatQueryMsgLog_t
		///
		virtual void QueryFriendChatMessageLog(const NPL_USRID id, sint32_t limitCount, uint64_t fromTime, uint64_t endTime) = 0;

		///
		/// \brief 查询消息日志
		///
		/// \param id				查询id，对方的account id或者群组tid。 
		/// \param limit_count		本次查询的消息条数上限(最多100条)
		/// \param fromTime			开始时间
		/// \param endTime			结束时间
		///
		/// \see RegistEvent cbChatQueryMsgLog_t
		///
		virtual void QueryTeamChatMessageLog(cstr_t id, sint32_t limitCount, uint64_t fromTime, uint64_t endTime) = 0;
	};
}
#endif // __NPL_C_INTERFACE__
#endif // __NPL_FRIEND_H__
