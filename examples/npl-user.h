///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 netease China
/// All right reserved
///
/// \file npl-user.h
///
/// \brief NPL user info
///
#ifndef __NPL_USER_H__
#define __NPL_USER_H__

#include <npl-errors.h>

#pragma pack(push, NPL_PACK_SIZE)
///
/// \brief  用户数据接收回执结构
///
/// \param  uid 用户ID
/// \param  appId 应用ID
///
struct cbUserDataReceived_t
{
	enum { iEvtType = enNplUser + 1 };
	/// 用户ID
	NPL_USRID uid;
	/// 应用ID
	NPL_APPID appId;
};

///
/// \brief  用户数据保存回执结构
///
/// \param  uid 用户ID
/// \param  appId 应用ID
///
struct cbUserDataUpload_t
{
	enum { iEvtType = enNplUser + 2 };
	/// 用户ID
	NPL_USRID uid;
	/// 应用ID
	NPL_APPID appId;
};

///
/// \brief  全局数据接收回执结构
///
/// \param  appId 应用ID
///
struct cbGlobalDataReceived_t
{
	enum { iEvtType = enNplUser + 3 };
	/// 应用ID
	NPL_APPID appId;
};

/// 
/// \brief  加密ticket回执结构
///
struct cbEncryptedAppTicketResponse_t
{
	enum { iEvtType = enNplUser + 6 };
	/// 错误码 ERR_OK 表示成功
	npl::errcode err;
};

///
/// \brief  用户昵称修改回执结构
///
/// \param  uid 用户ID
///
struct cbNickNameChange_t
{
	enum { iEvtType = enNplUser + 7 };
	/// 用户ID
	NPL_USRID uid;
};

/// 
/// \brief  与NplServer 链接建立（通常这是第一个回调）
///
struct cbNplServersConnected_t
{
	enum { iEvtType = enNplUser + 8 };
};

/// 
/// \brief  与NplServer 链接失败
///
struct cbNplServerConnectFailure_t
{
	enum { iEvtType = enNplUser + 9 };
	sint32_t result;
	bool stillRetrying;
};

/// 
/// \brief  与NplServer 链接断开
///
struct cbNplServersDisconnected_t
{
	enum { iEvtType = enNplUser + 10 };
	sint32_t result;
};

/// 
/// \brief  与GameServer断开连接
///
/// \note   gameserver EndAuthSession/SendUserDisconnect
///
struct cbClientGameServerDeny_t
{
	enum { iEvtType = enNplUser + 11 };
	/// source NPL_ID (userID or gameServerID who GetAuthSessionTicket or client user InitiateGameConnection)
	NPL_ID srcID;
	/// target NPL_ID (userID or gameServerID which BeginAuthTicket/SendUserConnectAndAuthenticate)
	NPL_ID dstID;
};

#pragma pack(pop)

///
/// \brief	成就状态枚举值
///
enum enAchievementStat
{
    /// 成就未达成
    enAchievementStat_unachieve = 0,
    /// 成就已达成
    enAchievementStat_achieve = 1,
    /// 已领取奖励
    enAchievementStat_awarded = 2,
};

/// 
/// \brief  成就符号
///
enum enAchievementWay
{
    /// 大于
    enAchievementWay_gt = 1,
    /// 大于等于
    enAchievementWay_ge = 2,
    /// 小于等于
    enAchievementWay_le = 3,
    /// 小于
    enAchievementWay_lt = 4,
};

#pragma pack(push, NPL_PACK_SIZE)
///
/// \brief  成就列表信息通知
///
struct cbAchievementListRefreshed_t
{
	enum { iEvtType = enNplUser + 4 };
    /// 刷新成就的角色ID
    NPL_USRID userID;
};

///
/// \brief  成就信息通知
///
struct cbAchievementRefreshed_t
{
	enum { iEvtType = enNplUser + 5 };
    /// 刷新成就的角色ID
    NPL_USRID userID;
    /// 成就API名称
    char achievementApiName[NPL_ACHIEVEMENT_NAME_LEN];
};

///
/// \brief  成就详细信息
///
struct AchievementInfo_t
{
    /// 成就ID
    sint32_t achievementId;
    /// 状态
    enAchievementStat enStat;
    /// 成就Api名称
    char apiName[NPL_ACHIEVEMENT_NAME_LEN];
    /// 成就展示名称
    char showName[NPL_ACHIEVEMENT_NAME_LEN];
    /// 描述信息
    char desc[NPL_ACHIEVEMENT_DESC_LEN];
    /// 达成点数URL
	sint32_t icon;

    /// 自定义属性
    char attr[NPL_ACHIEVEMENT_ATTR_LEN];
    /// 奖励点数
    sint32_t awardPoint;
    /// 解锁时间戳
    uint32_t unlockTime;
};

///
/// \brief  成就事件详细信息
///
struct AchievementEvent_t
{
    /// 成就ID
    sint32_t achievementId;
    /// 事件统计项的名称
    char evtParam[NPL_STATISTICS_EVENT_NAME_LEN];
    /// 比较符号
    enAchievementWay enWay;
    /// 事件的当前进度
    real64_t progressCur;
    /// 事件的上限进度
    real64_t progressMax;
};
#pragma pack(pop)

#ifndef __NPL_C_INTERFACE__
namespace npl
{
    ///
    /// \brief user interface
    /// 
	struct NPL_API INplUser
	{
        ///
        /// \brief  用户是否已登录游戏
        ///
        /// \return 用户是否登录
        /// 
		virtual bool IsLogon() = 0;

        ///
        /// \brief  获取用户ID
        ///
        /// \return 用户ID
        /// 
		virtual NPL_USRID GetUserId() = 0;

		///
		/// \brief  获取当前用户账号
		///
		/// \return 用户账号  
		///
		virtual cstr_t GetUserName() = 0;

		/// 
		/// \brief  获取用户Token
		/// 
		/// \return token
		///
		virtual cstr_t GetUserToken() = 0;

        ///
        /// \brief  获取用户数据保存路径
        ///
        /// \return 用户数据保存路径
        /// 
		virtual cstr_t GetUserDirectory() = 0;

        ///
        /// \brief  请求用户游戏数据
        ///
        /// \return 异步请求的Token
        /// 
        /// \see    RegistCallback cbUserDataReceived_t
        ///
		virtual long RequestUserData() = 0;

        ///
        /// \brief  请求指定用户的游戏数据
        ///
        /// \param  userId 用户ID
        /// \return 异步请求的Token
        /// 
        /// \see    RegistCallback cbUserDataReceived_t
        ///
		virtual long RequestUserData(const NPL_USRID & userId) = 0;

        ///
        /// \brief  当前用户是否存在指定游戏数据
        ///
        /// \param  key 游戏数据名
        /// \return 游戏数据是否存在
        /// 
		virtual bool IsExistData(cstr_t key) = 0;

		///
		/// \brief  获取当前用户游戏数据sint32_t值
		///
		/// \param  key 游戏数据名
		/// \param  default 数据名不存在时的默认值
		/// \return 游戏数据值
		/// 
		virtual sint32_t GetUserData(cstr_t key, sint32_t defaultValue) = 0;

        ///
        /// \brief  获取当前用户游戏数据sint64_t值
        ///
        /// \param  key 游戏数据名
        /// \param  default 数据名不存在时的默认值
        /// \return 游戏数据值
        /// 
        virtual sint64_t GetUserData(cstr_t key, sint64_t defaultValue) = 0;

        ///
        /// \brief  获取当前用户游戏数据real64_t值
        ///
        /// \param  key 游戏数据名
        /// \param  default 数据名不存在时的默认值
        /// \return 游戏数据值
        /// 
        virtual real64_t GetUserData(cstr_t key, real64_t defaultValue) = 0;

        ///
        /// \brief  获取当前用户游戏数据cstr_t值
        ///
        /// \param  key 游戏数据名
        /// \param  default 数据名不存在时的默认值
        /// \return 游戏数据值
        /// 
		virtual cstr_t GetUserData(cstr_t key, cstr_t defaultValue) = 0;
        
        ///
        /// \brief  指定用户是否存在指定游戏数据
        ///
        /// \param  userId 指定用户ID
        /// \param  key 游戏数据名
        /// \return 游戏数据是否存在
        /// 
        virtual bool IsExistData(const NPL_USRID & userId, cstr_t key) = 0;

		///
		/// \brief  获取指定用户游戏数据sint32_t值
		///
		/// \param  userId 指定用户ID
		/// \param  key 游戏数据名
		/// \param  default 数据名不存在时的默认值
		/// \return 游戏数据值
		/// 
		virtual sint32_t GetUserData(const NPL_USRID & userId, cstr_t key, sint32_t defaultValue) = 0;

		///
        /// \brief  获取指定用户游戏数据sint64_t值
        ///
        /// \param  userId 指定用户ID
        /// \param  key 游戏数据名
        /// \param  default 数据名不存在时的默认值
        /// \return 游戏数据值
        /// 
        virtual sint64_t GetUserData(const NPL_USRID & userId, cstr_t key, sint64_t defaultValue) = 0;

        ///
        /// \brief  获取指定用户游戏数据real64_t值
        ///
        /// \param  userId 指定用户ID
        /// \param  key 游戏数据名
        /// \param  default 数据名不存在时的默认值
        /// \return 游戏数据值
        /// 
        virtual real64_t GetUserData(const NPL_USRID & userId, cstr_t key, real64_t defaultValue) = 0;

        ///
        /// \brief  获取指定用户游戏数据cstr_t值
        ///
        /// \param  userId 指定用户ID
        /// \param  key 游戏数据名
        /// \param  default 数据名不存在时的默认值
        /// \return 游戏数据值
        /// 
		virtual cstr_t GetUserData(const NPL_USRID & userId, cstr_t key, cstr_t defaultValue) = 0;

		///
		/// \brief  设置当前用户的游戏数据
		///
		/// \param  key 游戏数据名
		/// \param  value 游戏数据sint32_t值
		/// \return 是否设置成功
		/// 
		/// \note   设置后，若未保存则不影响NPL服务器上的数据
		///
		virtual bool SetUserData(cstr_t key, sint32_t value) = 0;

        ///
        /// \brief  设置当前用户的游戏数据
        ///
        /// \param  key 游戏数据名
        /// \param  value 游戏数据sint64_t值
        /// \return 是否设置成功
        /// 
        /// \note   设置后，若未保存则不影响NPL服务器上的数据
        ///
        virtual bool SetUserData(cstr_t key, sint64_t value) = 0;

        ///
        /// \brief  设置当前用户的游戏数据
        ///
        /// \param  key 游戏数据名
        /// \param  value 游戏数据real64_t值
        /// \return 是否设置成功
        /// 
        /// \note   设置后，若未保存则不影响NPL服务器上的数据
        ///
        virtual bool SetUserData(cstr_t key, real64_t value) = 0;

        ///
        /// \brief  设置当前用户的游戏数据
        ///
        /// \param  key 游戏数据名
        /// \param  value 游戏数据cstr_t值
        /// \return 是否设置成功
        /// 
        /// \note   设置后，若未保存则不影响NPL服务器上的数据
        ///
		virtual bool SetUserData(cstr_t key, cstr_t value) = 0;

		///
		/// \brief	更新用户的平均值数据
		/// 
		/// \param	key 变量名（需确保是均值变量）
		/// \return	是否更新成功
		///
		virtual bool UpdUserAvgData(cstr_t key, real32_t fSectionCount, real64_t fSectionSeconds) = 0;

        ///
        /// \brief  保存当前用户数据
        ///
        /// \return 异步请求的Token
        /// 
        /// \see    RegistCallback cbUserDataUpload_t
        ///
		virtual long SaveUserData() = 0;

        ///
        /// \brief  清除当前用户所有数据
        /// 
        /// \note   清除后，若未保存则不影响NPL服务器上的数据
        ///
		virtual void ClearUserData() = 0;

        ///
        /// \brief  请求全局游戏数据
        ///
        /// \param  nHistoryDays 几天前的历史数据
        /// \return 异步请求的Token
        /// 
        /// \see    RegistCallback cbGlobalDataReceived_t
        ///
		virtual long RequestGlobalData(int nHistoryDays) = 0;

        ///
        /// \brief  获取全局游戏数据sint64_t值
        ///
        /// \param  key 游戏数据名
        /// \param  default 数据名不存在时的默认值
        /// \return 游戏数据值
        /// 
        virtual sint64_t GetGlobalData(cstr_t key, sint64_t defaultValue) = 0;

        ///
        /// \brief  获取全局游戏数据real64_t值
        ///
        /// \param  key 游戏数据名
        /// \param  default 数据名不存在时的默认值
        /// \return 游戏数据值
        /// 
        virtual real64_t GetGlobalData(cstr_t key, real64_t defaultValue) = 0;

        ///
        /// \brief  获取全局游戏数据cstr_t值
        ///
        /// \param  key 游戏数据名
        /// \param  default 数据名不存在时的默认值
        /// \return 游戏数据值
        ///
		virtual cstr_t GetGlobalData(cstr_t key, cstr_t defaultValue) = 0;

		///
        /// \brief  设置自己的昵称
        ///
        /// \param  nickName 昵称
        /// \return 异步请求的Token
        /// 
        /// \note 
        /// \see   RegistCallback cbNickNameChange_t
        ///
		virtual sint32_t SetNickName(cstr_t nickName) = 0;

		///
		/// \brief  获取自己的昵称
		///
		/// \param  
		/// \return 自己的昵称
		/// 
		/// \note   
		/// \see    
		///
		virtual cstr_t GetNickName() = 0;

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
        virtual int InitiateGameConnection(pvoid_t pAuthBlob, int cbMaxAuthBlob, NPL_SVRID gameServerID, uint32_t unIPServer, uint16_t usPortServer, bool bSecure) = 0;

        ///
        /// \brief  通知游戏服务器断开链接
        ///
        /// \param  unIPServer 服务器IP
        /// \param  usPortServer 服务器Port
        /// 
        /// \note   注意：实际断开的链接是对应InitiateGameConnection链接成功的gameServerID的P2P链接
        ///
        virtual void TerminateGameConnection(uint32_t unIPServer, uint16_t usPortServer) = 0;

        ///
        /// \brief  获取认证Ticket
        ///
        /// \param  pTicket 接收认证信息的缓冲区
		/// \param  cbMaxTicket 接收认证信息的缓冲区长度（尽量长的定义该缓冲区，认证信息可能有1024字节）
		/// \param  pcbTicket 认证信息的长度
        /// \return 认证信息句柄
        ///
        virtual AuthTicketHandle_t GetAuthSessionTicket(pvoid_t pTicket, int cbMaxTicket, uint32_t* pcbTicket) = 0;

		/// 
		/// \brief  销毁认证Ticket
		/// \param  hAuthTicket ticket句柄
		///
		virtual void CancelAuthTicket(AuthTicketHandle_t hAuthTicket) = 0;

		/// 
		/// \brief  认证nplid相关的票据
		/// \param  pAuthTicket 票据
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
		/// \brief  请求加密数据票证
		///
		/// \param  pDataToInclude 放入票证里的数据
		/// \param  cbDataToInclude 放到票证里的数据字节长度
		/// \return 请求句柄
		///
		/// \see    cbEncryptedAppTicketResponse_t
		///
		virtual long RequestEncryptedAppTicket(cvoid_t pDataToInclude, int cbDataToInclude) = 0;

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
		virtual bool GetEncryptedAppTicket(pvoid_t pTicket, int cbMaxTicket, uint32_t* pcbTicket) = 0;

        //////////////////////////////////////////////////////////////////////////
        ///
        /// \brief  获取成就列表
        ///
        /// \param  
        /// \return 异步请求的Token
        /// \see    cbAchievementListRefreshed_t
        ///
        virtual long RefreshAchievementList() = 0;

        ///
        /// \brief  获取指定用户成就列表
        ///
        /// \param  userID 用户ID
        /// \return 异步请求的Token
        /// \see    cbAchievementListRefreshed_t
        ///
        virtual long RefreshAchievementList(const NPL_USRID& userID) = 0;

        ///
        /// \brief  获取成就详细信息
        ///
        /// \param  achName 成就API名称
        /// \return 异步请求的Token
        /// \see    cbAchievementRefreshed_t
        ///
        virtual long RefreshAchievementInfo(cstr_t achName) = 0;

        ///
        /// \brief  获取指定用户成就详细信息
        ///
        /// \param  userID 用户ID
        /// \param  achName 成就API名称
        /// \return 异步请求的Token
        /// \see    cbAchievementRefreshed_t
        ///
        virtual long RefreshAchievementInfo(const NPL_USRID& userID, cstr_t achName) = 0;

        ///
        /// \brief  清理指定成就状态
        ///
        /// \param  achName 成就API名称
        /// \return true-请求已发出 
        ///
        virtual bool ClearAchievement(cstr_t achName) = 0;

        ///
        /// \brief  获取成就是否已经解锁
        ///
        /// \param  achName 成就API名称
        /// \param  pbAchieved 是否已解锁成就
        /// \return 找到achName对应成就就返回true-成功，否则返回失败
        ///
        virtual bool GetAchievement(cstr_t achName, bool* pbAchieved) = 0;

        ///
        /// \brief  获取指定用户成就是否已经解锁
        ///
        /// \param  userID 用户ID
        /// \param  achName 成就API名称
        /// \param  pbAchieved 是否已解锁成就
        /// \return 找到userID玩家achName对应成就就返回true-成功，否则返回失败
        ///
        virtual bool GetUserAchievement(const NPL_USRID& userID, cstr_t achName, bool* pbAchieved) = 0;

        ///
        /// \brief  获取成就是否已经解锁和解锁时间
        ///
        /// \param  achName 成就API名称
        /// \param  pbAchieved 是否已解锁成就
        /// \param  unlockTime 解锁时间（s）
        /// \return 找到achName对应成就就返回true-成功，否则返回失败
        ///
        virtual bool GetAchievementAndUnlockTime(cstr_t achName, bool* pbAchieved, uint32_t* unlockTime) = 0;

        ///
        /// \brief  获取指定用户成就是否已经解锁和解锁时间
        ///
        /// \param  userID 用户ID
        /// \param  achName 成就API名称
        /// \param  pbAchieved 是否已解锁成就
        /// \param  unlockTime 解锁时间（s）
        /// \return 找到userID玩家achName对应成就就返回true-成功，否则返回失败
        ///
        virtual bool GetUserAchievementAndUnlockTime(const NPL_USRID& userID, cstr_t achName, bool* pbAchieved, uint32_t* unlockTime) = 0;

        ///
        /// \brief  获取成就图标
        ///
        /// \param  achName 成就API名称
        /// \param  icon 返回ICON
        /// \return 找到achName对应成就就返回true-成功，否则返回失败
        ///
        virtual bool GetAchievementIcon(cstr_t achName, sint32_t* icon) = 0;

        ///
        /// \brief  获取成就自定义属性值
        ///
        /// \param  achName 成就API名称
        /// \param  key 键名称(name/desc/attr)
        /// \return 值
        ///
        virtual cstr_t GetAchievementDisplayAttribute(cstr_t achName, cstr_t key) = 0;

        ///
        /// \brief  标注成就进度
        ///
        /// \param  achName 成就API名称
        /// \param  nCurProgress 当前进度
        /// \param  nMaxProgress 解锁所需进度
        /// \return 找到achName对应成就就返回true-成功，否则返回失败
        /// 
        /// \note   需使用SaveUserData上传到Npl服务器
        ///
        virtual bool IndicateAchievementProgress(cstr_t achName, uint32_t nCurProgress, uint32_t nMaxProgress) = 0;

        ///
        /// \brief  通过成就ID获取成就信息
        ///
        /// \param  achName 成就API名称
        /// \param  *info 返回成就信息
        /// \return 找到achName对应成就就返回true-成功，否则返回失败
        ///
        virtual bool GetAchievementDetailInfo(cstr_t achName, AchievementInfo_t* info) = 0;

        ///
        /// \brief  获取成就列表请求返回的成就数量
        ///
        /// \param  
        /// \return 成就数量
        ///
        virtual sint32_t GetNumAchievements() = 0;

        ///
        /// \brief  通过游标获取成就名称
        ///
        /// \param  index 游标,不应大于GetNumAchievements返回值
        /// \return 成就API名称
        ///
        virtual cstr_t GetAchievementName(sint32_t index) = 0;

        ///
        /// \brief  通过游标获取成就信息
        ///
        /// \param  index 游标,不应大于GetNumAchievements返回值
        /// \param  *info 返回成就信息
        /// \return true-成功，需满足GetNumAchievements返回值大于0，并且index在[0,GetNumAchievements返回值)区间；否则返回false-失败
        ///
        virtual bool GetAchievementDetailInfo(sint32_t index, AchievementInfo_t* info) = 0;

        ///
        /// \brief  通过成就ID获取成就事件数量
        ///
        /// \param  achName 成就API名称
        /// \return 事件数量 -1:未找到
        /// 
        virtual sint32_t GetNumAchievementEvents(cstr_t achName) = 0;

        ///
        /// \brief  通过事件游标获取相应成就的事件信息
        ///
        /// \param  achName 成就API名称
        /// \param  index 事件游标，不应大于GetNumAchievementEvents返回值
        /// \param  *info 返回成就事件信息
        /// \return true-成功，需满足找到achName成就信息，
        ///             并且GetNumAchievementEvents返回值大于0，并且index在[0,GetNumAchievementEvents返回值)区间
        ///         否则返回false-失败
        ///
        virtual bool GetAchievementEventInfo(cstr_t achName, sint32_t index, AchievementEvent_t* info) = 0;

        ///
        /// \brief  设置成就状态
        ///
        /// \param  achName 成就API名称
        /// \param  enStat 状态
        /// \return 找到achName对应成就就返回true-成功，否则返回失败
        ///
        /// \note   需使用SaveUserData上传到Npl服务器
        ///
        virtual bool SetAchievementStat(cstr_t achName, enAchievementStat enStat) = 0;

        ///
        /// \brief  设置成就属性
        ///
        /// \param  achName 成就API名称
        /// \param  attr 自定义的属性
        /// \return 找到achName对应成就就返回true-成功，否则返回失败
        ///
        /// \note   需使用SaveUserData上传到Npl服务器
        ///
        virtual bool SetAchievementAttr(cstr_t achName, cstr_t attr) = 0;

        ///
        /// \brief  获取成就属性
        ///
        /// \param  achName 成就API名称
        /// \return 自定义的属性
        ///
		virtual cstr_t GetAchievementAttr(cstr_t achName) = 0;
	};
}
#endif // __NPL_C_INTERFACE__
#endif // __NPL_USER_H__
