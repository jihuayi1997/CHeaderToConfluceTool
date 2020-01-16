///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \file npl-matchmaking.h
///
/// \brief NPL lobby matchmaking functional
///
#ifndef _NPL_MATCHMAKING_H
#define _NPL_MATCHMAKING_H
#pragma once

///
/// \brief  大厅类型
///
enum enLobbyType
{
	/// public: auto enter
	eLobbyType_public = 0,
	/// protect: manager/creator audit enter
	eLobbyType_protect = 1,
	/// private: mamager/creator invite enter
	eLobbyType_private = 2,
	/// locked: not allow apply enter & invite enter
	eLobbyType_locked = 3,
};

///
/// \brief  大厅匹配过滤器符号
///
enum enFilterOperator
{
	eFilterOperator_unknow = 0,
	/// 0b0001 ==
	eFilterOperator_equal = 1,
	/// 0b0010 >
	eFilterOperator_morethan = 2,
	/// 0b0011 >=
	eFilterOperator_moreorequal = 3,
	/// 0b0100 <
	eFilterOperator_lessthan = 4,
	/// 0b0101 <=
	eFilterOperator_lessorequal = 5,
	/// 0b0110 <>
	eFilterOperator_unequal = 6,
	/// 0b0111 <>
	eFilterOperator_unequal2 = 7,
};

///
/// \brief  大厅匹配距离过滤器枚举
///
enum enLobbyDistanceFilter
{
	/// 同一地区的 city
	enLobbyDistanceFilter_close = 0,
	/// 同一地区/附近地区 subvision
	enLobbyDistanceFilter_default = 1,
	/// 同一地区/附近地区/远地区 contry
	enLobbyDistanceFilter_far = 2,
	/// 同一地区/附近地区/远地区/更远地区 continent
	enLobbyDistanceFilter_farther = 3,
	/// 全局
	enLobbyDistanceFilter_worldWide = 4,
};

#pragma pack(push, NPL_PACK_SIZE)

///
/// \brief  异步请求回执结构
///
struct cbMatchmakingRequestResult_t
{
	enum { iEvtType = enNplMatchMaking + 1 };
	/// 大厅ID
	NPL_LBYID lobbyID;
};

///
/// \brief  大厅信息更新通知结构
///
struct cbMatchmakingLobbyInfoNotify_t
{
	enum { iEvtType = enNplMatchMaking + 2 };
	/// 大厅ID
	NPL_LBYID lobbyID;
};

///
/// \brief  加入新大厅通知结构
///
struct cbMatchmakingNewLobbyNotify_t
{
	enum { iEvtType = enNplMatchMaking + 3 };
	/// 大厅ID
	NPL_LBYID lobbyID;
};

///
/// \brief  大厅加入新成员通知结构
///
struct cbMatchmakingLobbyNewUserNotify_t
{
	enum { iEvtType = enNplMatchMaking + 4 };
	/// 大厅ID
	NPL_LBYID lobbyID;
	/// 用户ID
	NPL_USRID uid;
};

///
/// \brief  用户请求加入大厅通知结构
///
struct cbMatchmakingLobbyUserApplyEnterNotify_t
{
	enum { iEvtType = enNplMatchMaking + 5 };
	/// 大厅ID
	NPL_LBYID lobbyID;
	/// 用户ID
	NPL_USRID uid;
};

///
/// \brief  被邀请加入大厅通知结构
///
struct cbMatchmakingUserBeinviteEnterNotify_t
{
	enum { iEvtType = enNplMatchMaking + 6 };
	/// 邀请者大厅ID
	NPL_LBYID lobbyID;
	/// 邀请者用户ID
	NPL_USRID uid;
};

///
/// \brief  成员离开大厅通知结构
///
struct cbMatchmakingLobbyUserLeaveNotify_t
{
	enum { iEvtType = enNplMatchMaking + 7 };
	/// 大厅ID
	NPL_LBYID lobbyID;
	/// 离开的成员ID
	NPL_USRID uid;
};

///
/// \brief  被请出大厅通知结构
///
struct cbMatchmakingUserBekickoutNotify_t
{
	enum { iEvtType = enNplMatchMaking + 8 };
	/// 大厅ID
	NPL_LBYID lobbyID;
	/// 请出者用户ID
	NPL_USRID uid;
};

///
/// \brief  成员被请出大厅通知结构
///
struct cbMatchmakingLobbyUserBekickoutNotify_t
{
	enum { iEvtType = enNplMatchMaking + 9 };
	/// 大厅ID
	NPL_LBYID lobbyID;
	/// 请出者用户ID
	NPL_USRID operID;
	/// 被请出者用户ID
	NPL_USRID uid;
};

///
/// \brief  成员信息更新通知结构
///
struct cbMatchmakingLobbyUserInfoUpdateNotify_t
{
	enum { iEvtType = enNplMatchMaking + 10 };
	/// 大厅ID
	NPL_LBYID lobbyID;
	/// 成员ID
	NPL_USRID uid;
};

/// 
/// \brief  请求大厅列表的返回结构
///
struct cbMatchmakingLobbyMatchList_t
{
	enum { iEvtType = enNplMatchMaking + 11 };
	/// 符合搜索条件的大厅数量
	uint32_t lobbiesMatching;
};

/// 
/// \brief  大厅聊天消息通知
///
struct cbLobbyChatMsg_t
{
	enum { iEvtType = enNplMatchMaking + 12 };

	/// 大厅ID
	NPL_LBYID lobbyID;
	/// 发送者账号ID
	NPL_USRID sender;
	/// 内容
	char content[NPL_CHAT_MAX_CONTENT_LEN];
	/// 内容长度
	uint32_t content_length;
};

/// 
/// \brief  离开大厅消息通知
///
struct cbMatchmakingLeaveLobby_t
{
	enum { iEvtType = enNplMatchMaking + 13 };

	/// 大厅ID
	NPL_LBYID lobbyID;
};

///
/// \brief  大厅查询结果
///
struct cbMatchmakingRequestLobbyData_t
{
	enum { iEvtType = enNplMatchMaking + 14 };
	/// 大厅ID
	NPL_LBYID lobbyID;
};

/// 
/// \brief  用户请求加入大厅被拒绝的通知结构
///
struct cbMatchmakingLobbyUserApplyRefusedNotify_t
{
	enum { iEvtType = enNplMatchMaking + 15 };
	/// 大厅ID
	NPL_LBYID lobbyID;
	/// 用户ID
	NPL_USRID uid;
};

/// 
/// \brief  邀请他人加入大厅，被拒绝的通知结构
///
struct  cbMatchmakingUserInviteRefusedNotify_t
{
	enum { iEvtType = enNplMatchMaking + 16 };
	/// 大厅ID
	NPL_LBYID lobbyID;
	/// 用户ID
	NPL_USRID uid;
};

/// 
/// \brief  大厅拥有者（creator）变更通知
///
struct cbMatchmakingOwnerChange_t
{
	enum { iEvtType = enNplMatchMaking + 17 };
	/// 大厅ID
	NPL_LBYID lobbyID;
	/// 新的拥有者ID
	NPL_USRID owner;
};

/// 
/// \brief  大厅操作枚举
///
enum eMatchmakingOper
{
	/// 申请加入
	eMatchmaking_applyEnter,
	/// 审批加入申请
	eMatchmaking_applyEnterAudit,
	/// 邀请加入
	eMatchmaking_inviteEnter,
	/// 被邀请应答
	eMatchmaking_inviteRespond,
	/// 离开大厅
	eMatchmaking_leave,
	/// 踢人
	eMatchmaking_kickout,
	/// 发送聊天消息
	eMatchmaking_sendChat,
};

/// 
/// \brief  大厅操作通知
///
struct cbMatchmakingOperResult_t
{
	enum { iEvtType = enNplMatchMaking + 18 };
	/// 操作类型
	eMatchmakingOper oper;
	/// 大厅ID
	NPL_LBYID lobbyID;
	/// 被操作者(oper == eMatchmaking_applyEnterAudit || eMatchmaking_inviteEnter || eMatchmaking_kickout)
	NPL_USRID uid;
};

#pragma pack(pop)

#ifndef __NPL_C_INTERFACE__
namespace npl
{
	///
	/// \brief lobby matchmaking interface
	/// 
	struct NPL_API INplMatchmaking
	{
	public:
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
		virtual long CreateLobby(cstr_t strLobbyName, uint32_t dwMemberMax, bool blInvisible, enLobbyType enType, cstr_t strPassword) = 0;

		///
		/// \brief  添加一个字符串类型的大厅搜索过滤器
		///
		/// \param  strKey        过滤器名
		/// \param  strValueMatch 过滤器值
		/// \param  oper          过滤器符号
		/// \return 是否添加成功
		///
		virtual bool AddRequestLobbyListStringFilter(cstr_t strKey, cstr_t strValueMatch, enFilterOperator oper) = 0;

		///
		/// \brief  添加一个数值类型的大厅搜索过滤器
		///
		/// \param  strKey        过滤器名
		/// \param  nValueMatch   过滤器值
		/// \param  oper          过滤器符号
		/// \return 是否添加成功
		///
		virtual bool AddRequestLobbyListNumericalFilter(cstr_t strKey, int nValueMatch, enFilterOperator oper) = 0;

		///
		/// \brief  添加一个剩余空位数量的大厅搜索过滤器
		///
		/// \param  nSlotsAvailable 最小剩余空位数
		/// \return 是否添加成功
		///
		virtual bool AddRequestLobbyListSlotsAvailable(int nSlotsAvailable) = 0;

		///
		/// \brief  添加一个距离的大厅搜索过滤器
		///
		/// \param  eLobbyDistanceFilter 过滤器枚举
		/// \return 是否添加成功
		///
		virtual bool AddRequestLobbyListDistanceFilter(enLobbyDistanceFilter eLobbyDistanceFilter) = 0;

		///
		/// \brief  添加一个近值类型的大厅搜索过滤器
		///
		/// \param  strKey        过滤器名
		/// \param  nValueToBeCloseTo   过滤器值
		/// \return 是否添加成功
		/// 
		/// \note   近过滤器实际上不会过滤掉值，它们只会影响结果的排序方式。您可以指定多个近似滤波器，第一个近滤波器影响最大，最后一个近滤波器影响最小。
		///
		virtual bool AddRequestLobbyListNearValueFilter(cstr_t strKey, sint32_t nValueToBeCloseTo) = 0;

		///
		/// \brief  请求大厅列表
		///
		/// \param  
		/// \return 异步请求的Token
		/// 
		/// \note   
		/// \see    RegistCallback cbMatchmakingLobbyMatchList_t
		///
		virtual long RequestLobbyList() = 0;

		///
		/// \brief  获取查找到的大厅数量
		///
		/// \param  
		/// \return 大厅数量
		///
		virtual uint32_t GetLobbyCount() = 0;

		///
		/// \brief  通过游标获取大厅ID
		///
		/// \param  index 游标，不应大于GetLobbyCount返回的结果
		/// \return 大厅ID，0表示获取失败
		///
		virtual NPL_LBYID GetLobbyByIndex(uint32_t index) = 0;

		///
		/// \brief  设置大厅数据
		///
		/// \param  lobbyID 大厅ID
		/// \param  key   大厅数据名  (0, NPL_MATCHMAKING_MAX_DATA_KEY)
		/// \param  value 大厅数据值(字符串类型) (0, NPL_MATCHMAKING_MAX_DATA_VALUE)
		/// \return 是否设置成功
		/// 
		/// \note   设置用户应是大厅创建者
		/// \see    设置后，若未提交大厅数据则不会影响NPL服务器上的数据
		///
		virtual bool SetLobbyData(const NPL_LBYID& lobbyID, cstr_t key, cstr_t value) = 0;

		///
		/// \brief  设置大厅数据
		///
		/// \param  lobbyID 大厅ID
		/// \param  key   大厅数据名  (0, NPL_MATCHMAKING_MAX_DATA_KEY)
		/// \param  value 大厅数据值(数值类型)
		/// \return 是否设置成功
		/// 
		/// \note   设置用户应是大厅创建者
		/// \see    设置后，若未提交大厅数据则不会影响NPL服务器上的数据
		///
		virtual bool SetLobbyData(const NPL_LBYID& lobbyID, cstr_t key, double value) = 0;

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
		virtual bool DelLobbyData(const NPL_LBYID& lobbyID, cstr_t key) = 0;

		///
		/// \brief  提交大厅数据
		///
		/// \param  lobbyID 大厅ID
		/// \return 异步请求的Token
		/// 
		/// \note   提交用户应是大厅创建者, all-of lobby-data to json length 应小于 NPL_MATCHMAKING_MAX_DATA_TOTAL_LENGTH
		/// \see    RegistCallback cbMatchmakingRequestResult_t
		///
		virtual long CommitLobbyData(const NPL_LBYID& lobbyID) = 0;

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
		virtual long SetLobbyConfig(const NPL_LBYID& lobbyID, cstr_t strLobbyName, uint32_t dwMemberMax, bool blInvisible, enLobbyType enType, cstr_t strPassword) = 0;

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
		virtual long SetLobbyGameServer(const NPL_LBYID& lobbyID, uint32_t dwIP, uint16_t wPort, uint32_t dwServer) = 0;

		///
		/// \brief  获取指定大厅数据(字符串)
		///
		/// \param  lobbyID 大厅ID
		/// \param  key       数据名
		/// \return 数据值
		///
		virtual cstr_t GetLobbyData(const NPL_LBYID& lobbyID, cstr_t key) = 0;

		///
		/// \brief  获取指定大厅数据(数值)
		///
		/// \param  lobbyID 大厅ID
		/// \param  key       数据名
		/// \param  value     数据值
		/// \param  是否存在
		///
		virtual bool GetLobbyData(const NPL_LBYID& lobbyID, cstr_t key, double& value) = 0;

		/// 
		/// \brief  获取指定大厅元数据数量(字符串类型&数值类型)
		///
		/// \param  lobbyID 大厅ID
		/// \return 数据数量
		///
		virtual uint32_t GetLobbyDataCount(const NPL_LBYID& lobbyID) = 0;

		/// 
		/// \brief  通过索引检查指定大厅数据是否是数值类型
		///
		/// \param  lobbyID 大厅ID
		/// \param  index 索引值，应小于GetLobbyDataCount返回值，[0, GetLobbyDataCount返回值)
		/// \return True:数值类型 false:字符串类型或者查找失败
		///
		virtual bool CheckLobbyDataIsNumericByIndex(const NPL_LBYID& lobbyID, uint32_t index) = 0;

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
		virtual bool GetLobbyDataByIndex(const NPL_LBYID& lobbyID, uint32_t index, char* pchKey, int cchKeyBufferSize, char* pchValue, int cchValueBufferSize) = 0;

		/// 
		/// \brief  通过索引获取指定大厅数据(数值类型)
		///
		/// \param  lobbyID 大厅ID
		/// \param  index 索引值，应小于GetLobbyDataCount返回值，[0, GetLobbyDataCount返回值)
		/// \param  pchKey 返回大厅元数据键
		/// \param  cchKeyBufferSize pchKey缓冲区长度，最大255
		/// \param  value 返回大厅元数据值
		///
		virtual bool GetLobbyDataByIndex(const NPL_LBYID& lobbyID, uint32_t index, char* pchKey, int cchKeyBufferSize, double* value) = 0;

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
		virtual bool GetLobbyConfig(const NPL_LBYID& lobbyID, pstr_t strLobbyName, size_t dwLobbyNameSize, uint32_t& dwMemberMax, uint32_t& dwMemberCnt, enLobbyType& enType, bool& hasPassword) = 0;

		/// 
		/// \brief  设置大厅类型
		///
		/// \param  lobbyID 大厅ID
		/// \param  enType 大厅类型
		/// \return bool 是否设置成功
		///
		/// \note   设置自己拥有的大厅类型
		///
		virtual bool SetLobbyType(const NPL_LBYID& lobbyID, enLobbyType enType) = 0;

		/// 
		/// \brief  是否有大厅密码
		///
		/// \param  lobbyID 大厅ID
		/// \return bool true:有大厅密码，false:没有密码或者大厅未找到
		///
		virtual bool HasLobbyPassword(const NPL_LBYID& lobbyID) = 0;

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
		virtual bool SetLobbyMemberData(const NPL_LBYID& lobbyID, const NPL_USRID &uid, cstr_t key, cstr_t value) = 0;

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
		virtual bool SetLobbyMemberData(const NPL_LBYID& lobbyID, const NPL_USRID &uid, cstr_t key, double value) = 0;

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
		virtual bool DelLobbyUserData(const NPL_LBYID& lobbyID, const NPL_USRID &uid, cstr_t key) = 0;

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
		virtual long CommitLobbyUserData(const NPL_LBYID& lobbyID, const NPL_USRID &uid) = 0;

		///
		/// \brief  获取指定大厅成员数量
		///
		/// \param  lobbyID 大厅ID
		/// \return 成员数量
		///
		virtual uint32_t GetLobbyMemberCount(const NPL_LBYID& lobbyID) = 0;

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
		virtual NPL_USRID GetLobbyMemberByIndex(const NPL_LBYID& lobbyID, uint32_t index) = 0;

		///
		/// \brief  获取指定大厅成员名字
		///
		/// \param  lobbyID 大厅ID
		/// \param  uid 成员ID
		/// \return 成员名字
		///
		virtual cstr_t GetLobbyMemberName(const NPL_LBYID& lobbyID, const NPL_USRID &uid) = 0;

		///
		/// \brief  获取指定大厅成员数据(字符串类型)
		///
		/// \param  lobbyID 大厅ID
		/// \param  uid 成员ID
		/// \param  key 数据名
		/// \return 数据值
		///
		virtual cstr_t GetLobbyMemberData(const NPL_LBYID& lobbyID, const NPL_USRID &uid, cstr_t key) = 0;

		///
		/// \brief  获取指定大厅成员数据(数值类型)
		///
		/// \param  lobbyID 大厅ID
		/// \param  uid 成员ID
		/// \param  key 数据名
		/// \param  value 数值类型值
		/// \return 是否取到
		///
		virtual bool GetLobbyMemberData(const NPL_LBYID& lobbyID, const NPL_USRID &uid, cstr_t key, double& value) = 0;

		///
		/// \brief  申请加入指定大厅
		///
		/// \param  lobbyID 大厅ID
		/// \param  strPassword 大厅密码
		/// \return 请求是否成功
		///
		virtual bool ApplyEnterLobby(const NPL_LBYID& lobbyID, cstr_t strPassword) = 0;

		///
		/// \brief  审批指定用户加入大厅的申请
		///
		/// \param  lobbyID 大厅ID
		/// \param  uid 用户ID
		/// \param  agree 是否同意加入大厅
		/// \return 审批是否成功
		///
		virtual bool ApplyEnterLobbyAudit(const NPL_LBYID& lobbyID, const NPL_USRID &uid, bool agree) = 0;

		///
		/// \brief  邀请指定用户加入大厅
		///
		/// \param  lobbyID 大厅ID
		/// \param  uid 用户ID
		/// \return 邀请是否成功
		///
		virtual bool InviteEnterLobby(const NPL_LBYID& lobbyID, const NPL_USRID &uid) = 0;

		///
		/// \brief  回应邀请加入大厅的事件
		///
		/// \param  lobbyID 大厅ID
		/// \param  agree 是否同意加入大厅
		/// \return 回应是否成功
		///
		virtual bool InviteRespond(const NPL_LBYID& lobbyID, bool agree) = 0;

		///
		/// \brief  离开大厅
		///
		/// \param  lobbyID 大厅ID
		///
		virtual void LeaveLobby(const NPL_LBYID& lobbyID) = 0;

		///
		/// \brief  请指定成员离开大厅
		///
		/// \param  lobbyID 大厅ID
		/// \param  uid 成员ID
		/// \return 是否成功
		///
		virtual bool KickoutMemberLobby(const NPL_LBYID& lobbyID, const NPL_USRID &uid) = 0;

		///
		/// \brief  获取指定大厅成员数量限制
		///
		/// \param  lobbyID 大厅ID
		/// \return 成员数量限制
		///
		virtual uint32_t GetLobbyMemberLimit(const NPL_LBYID& lobbyID) = 0;

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
		virtual long SetLobbyOwner(const NPL_LBYID& lobbyID, const NPL_USRID &uid) = 0;

		///
		/// \brief  获取大厅游戏服务器信息
		///
		/// \param  lobbyID 大厅ID
		/// \param  *dwIP     IP值
		/// \param  *wPort    端口值
		/// \param  *server 游戏服务器ID
		/// \return true-成功，false-失败
		///
		virtual bool GetLobbyGameServer(const NPL_LBYID& lobbyID, uint32_t* dwIP, uint16_t* wPort, NPL_SVRID* server) = 0;

		///
		/// \brief  获取大厅拥有者ID
		///
		/// \param  lobbyID 大厅ID
		/// \return 拥有者ID
		/// 
		virtual NPL_USRID GetLobbyOwner(const NPL_LBYID& lobbyID) = 0;

		///
		/// \brief  设置大厅最大成员数量
		///
		/// \param  lobbyID 大厅ID
		/// \param  dwMemberMax 允许的最大玩家人数
		/// \return true-成功 false-您不是大厅所有者
		///
		virtual bool SetLobbyMemberLimit(const NPL_LBYID& lobbyID, uint32_t dwMemberMax) = 0;

		///
		/// \brief  请求指定大厅信息
		///
		/// \param  lobbyID 大厅ID
		/// \return 异步请求的Token
		/// 
		/// \note   
		/// \see    cbMatchmakingRequestLobbyData_t
		///
		virtual long RequestLobbyData(const NPL_LBYID& lobbyID) = 0;

		///
		/// \brief  发送大厅聊天消息
		///
		/// \param  lobbyID 大厅ID
		/// \param  pData 消息缓冲区
		/// \param  nData 消息的长度
		/// \return true-成功 false-失败
		/// 
		virtual bool SendLobbyChatMsg(const NPL_LBYID& lobbyID, cvoid_t pData, sint32_t nData) = 0;
	}; // end class npl_matchmaking
}; // end namespace npl
#endif // __NPL_C_INTERFACE__
#endif // _NPL_MATCHMAKING_H
