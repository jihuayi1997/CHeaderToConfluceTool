///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \file npl-leaderboard.h
///
/// \brief NPL leaderboard functional
///
#ifndef _NPL_LEADERBOARD_H
#define _NPL_LEADERBOARD_H

typedef long NplLeaderboardHandle_t;
typedef sint64_t UGCHandle_t;

#pragma pack(push, NPL_PACK_SIZE)
///
/// \brief  触发统计事件通知
///
/// \see    TriggerEvent 
///
struct cbTriggerEvent_t 
{
	enum { iEvtType = enNplLeaderboard + 1 };
    char evt[NPL_STATISTICS_EVENT_NAME_LEN];
};

///
/// \brief  获取统计事件回执
///
/// \see    GetStatisticsEventInfo 
///
struct cbStatisticsGetEventInfo_t
{
	enum { iEvtType = enNplLeaderboard + 2 };
    char evt[NPL_STATISTICS_EVENT_NAME_LEN];
};

/// 
/// \brief  统计事件项信息
///
struct StatisticsEventInfoParam_t
{
    /// 事件的API
    char evtApi[NPL_STATISTICS_EVENT_NAME_LEN];
    /// 事件显示名称
    char evtShow[NPL_STATISTICS_EVENT_NAME_LEN];
    /// 统计项名称
    char evtParam[NPL_STATISTICS_EVENT_NAME_LEN];
    /// 事件的值
    real64_t value;
};
#pragma pack(pop)

///
/// \brief	排行榜类型枚举值
///
enum enLeaderboardKind
{
    /// 全量（默认）（取已生成的排行榜的数据， 取全局绝对值）
    enLeaderboard_global = 0,
    /// 好友（返回该玩家所有好友的排行榜列表）（实时计算，好友之间相对值）
    enLeaderboard_friend = 2,
    /// 自己的排名 （全局）（取已生成的排行榜的数据， 取全局绝对值）
    enLeaderboard_self = 4,
};

///
/// \brief  排行榜参数值格式化枚举值
///
enum enLeaderboardArgFmt
{
    /// numicer
    enLeaderboardArgFmt_numicer = 0,
    /// seconds
    enLeaderboardArgFmt_seconds = 1,
    /// milliseconds
    enLeaderboardArgFmt_milliseconds = 2,
};

///
/// \brief  排行榜参数值排序方式
///
enum enLeaderboardArgSort
{
    /// none
    enLeaderboardArgSort_none = 0,
    /// asc
    enLeaderboardArgSort_asc = 1,
    /// desc
    enLeaderboardArgSort_desc = 2,
};

#pragma pack(push, NPL_PACK_SIZE)
///
/// \brief  获取排行榜数据回执
///
/// \see    FindLeaderboard 
///
struct cbFindLeaderboard_t
{
	enum { iEvtType = enNplLeaderboard + 3};
    /// 排行榜句柄
    NplLeaderboardHandle_t hLeaderboard;
};

///
/// \brief  获取指定用户排行榜数据回执
///
/// \see    DownloadLeaderboardEntries 
///
struct cbDownloadLeaderboardEntries_t
{
	enum { iEvtType = enNplLeaderboard + 4 };
    /// 排行榜句柄
    NplLeaderboardHandle_t hLeaderboard;
};

///
/// \brief  获取指定用户排行榜数据回执
///
/// \see    DownloadLeaderboardEntriesForUsers 
///
struct cbDownloadLeaderboardEntriesForUsers_t
{
	enum { iEvtType = enNplLeaderboard + 5 };
    /// 排行榜句柄
    NplLeaderboardHandle_t hLeaderboard;
};


///
/// \brief  提交附加数据设置回执
///
/// \see    CommitExtra
///
struct cbLeaderboadCommitExtra_t
{
	enum { iEvtType = enNplLeaderboard + 6 };
};

/// 
/// \brief  排行榜信息
///
struct LeaderboardEntryInfo_t 
{
    /// 排名
    sint32_t ranking;
    /// 玩家ID
    NPL_USRID userId;
    /// 玩家名称
    char userName[NPL_USERNAME_LEN];
    /// 展示值
    real64_t displayValue;
	/// UGC句柄
	UGCHandle_t ugcHandle;
};

/// 
/// \brief  UGC内容绑到排行榜回执
///
struct cbLeaderboardUGCSet_t
{
	enum { iEvtType = enNplLeaderboard + 7 };
	/// 排行榜句柄
	NplLeaderboardHandle_t hLeaderboard;
};

#pragma pack(pop)

#ifndef __NPL_C_INTERFACE__
namespace npl
{
    ///
    /// \brief  server leaderboard interface
    ///
    struct NPL_API INplLeaderboard
    {
    public:
        ///
        /// \brief  事件触发上报
        ///
        /// \param  evt 统计事件的API名称
        /// \param  parameter 上报的数据
        /// \return 请求是否成功 true-成功 false-失败
        ///
        virtual bool TriggerEvent(cstr_t evt, real64_t parameter) = 0;

        ///
        /// \brief  获取事件信息 
        ///
        /// \param  evt 统计事件的API名称
        /// \return 异步请求的Token
        /// 
        /// \note   
        /// \see    RegistCallback cbStatisticsGetEventInfo_t
        ///
        virtual long GetStatisticsEventInfo(cstr_t evt) = 0;

        ///
        /// \brief  获取事件统计项数量
        ///
        /// \return 事件统计项数量
        ///
        virtual sint32_t GetStatisticsEventParamCount() = 0;

        ///
        /// \brief  通过游标获取事件统计项
        ///
        /// \param  index 游标，不应大于GetStatisticsEventParamCount返回值
        /// \param  *param 返回事件统计项
        /// \return true-成功，需要满足GetStatisticsEventParamCount返回值大于0，并且index在[0, GetStatisEventParamCount返回值)区间；否则false-失败
        ///
        virtual bool GetStatisticsEventParam(sint32_t index, StatisticsEventInfoParam_t* param) = 0;

        ///
        /// \brief  获取自己周围排行榜数据
        ///
        /// \param  name 排行榜API名称
        /// \return 异步请求的Token
        /// 
        /// \note   
        /// \see    RegistCallback cbFindLeaderboard_t
        ///
        virtual long FindLeaderboard(cstr_t name) = 0;

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
        virtual long DownloadLeaderboardEntries(cstr_t name, enLeaderboardKind enKind, sint32_t nRangeStart, sint32_t nRangeEnd) = 0;

        ///
        /// \brief  获取指定用户排行榜数据
        ///
        /// \param  name 排行榜API名称
		/// \param  users 用户ID（可多人）
		/// \param  userCount 用户ID数量
        /// \return 异步请求的Token
        /// 
        /// \note   
        /// \see    RegistCallback cbDownloadLeaderboardEntriesForUsers_t
        ///
        virtual long DownloadLeaderboardEntriesForUsers(cstr_t name, NPL_USRID* users, sint32_t userCount) = 0;

		/// 
		/// \brief  获取排行榜数据总数
		///
		/// \param  hLeaderboard 句柄
		/// \return 总数
		///
		virtual uint32_t GetTotalCount(NplLeaderboardHandle_t hLeaderboard) = 0;

        ///
        /// \brief  获取排行榜展示名称
        ///
        /// \param  hLeaderboard 句柄
        /// \return 展示名称
        ///
        virtual cstr_t GetShowName(NplLeaderboardHandle_t hLeaderboard) = 0;

        ///
        /// \brief  获取排行榜重置时间戳
        ///
        /// \param  hLeaderboard 句柄
        /// \return 重置时间戳（秒）
        ///
        virtual uint64_t GetResetTimestamp(NplLeaderboardHandle_t hLeaderboard) = 0;

        ///
        /// \brief  获取排行榜刷新时间戳
        ///
        /// \param  hLeaderboard 句柄
        /// \return 刷新时间戳（秒）
        ///
        virtual uint64_t GetRefreshTimestamp(NplLeaderboardHandle_t hLeaderboard) = 0;

        ///
        /// \brief  获取排行榜参数值排序方式枚举值
        ///
        /// \param  hLeaderboard 句柄
        /// \return 排行榜参数值排序方式枚举值
        ///
        virtual enLeaderboardArgSort GetLeaderboardSortMethod(NplLeaderboardHandle_t hLeaderboard) = 0;

        ///
        /// \brief  获取排行榜参数值格式化枚举值
        ///
        /// \param  hLeaderboard 句柄
        /// \return 排行榜参数值格式化枚举值
        ///
        virtual enLeaderboardArgFmt GetLeaderboardDisplayType(NplLeaderboardHandle_t hLeaderboard) = 0;

        ///
        /// \brief  获取排行榜排名数量
        ///
        /// \param  hLeaderboard 句柄
        /// \return hLeaderboard句柄对应下载到本地的排行榜条目数量
        ///
        virtual sint32_t GetEntryCount(NplLeaderboardHandle_t hLeaderboard) = 0;

        ///
        /// \brief  获取排行榜详细信息
        ///
        /// \param  hLeaderboard 句柄
        /// \param  index 游标，不应大于GetEntryCount返回值
        /// \param  info 返回具体信息结构
        /// \return true-成功，需要满足GetEntryCount返回值大于0，并且index在[0, GetEntryCount返回值)区间；否则false-失败
        ///
        virtual bool GetEntryInfo(NplLeaderboardHandle_t hLeaderboard, sint32_t index, LeaderboardEntryInfo_t* info) = 0;

        ///
        /// \brief  获取排行榜附加数据数量
        ///
        /// \param  hLeaderboard 句柄
        /// \param  index 游标，不应大于GetEntryCount返回值
        /// \return 附加数据数量 -1:error
        ///
        virtual sint32_t GetExtraCount(NplLeaderboardHandle_t hLeaderboard, sint32_t index) = 0;

        ///
        /// \brief  获取数值类型附加数据
        ///
        /// \param  hLeaderboard 句柄
        /// \param  index 游标，不应大于GetEntryCount返回值
        /// \param  extraIndex 游标，不应大于GetExtraCount返回值
        /// \param  *extra 返回数值类型值
        /// \return true-成功，需要满足
        ///             GetEntryCount返回值大于0
        ///             并且GetExtraCount返回值大于0
        ///             并且index在[0, GetEntryCount返回值)区间
        ///             并且extraIndex在[0, GetExtraCount返回值)区间
        ///         否则 false-失败
        ///
        virtual bool GetExtra(NplLeaderboardHandle_t hLeaderboard, sint32_t index, sint32_t extraIndex, real64_t* extra) = 0;

        ///
        /// \brief  获取字符串类型附加数据
        ///
        /// \param  hLeaderboard 句柄
        /// \param  index 游标，不应大于GetEntryCount返回值
        /// \param  extraIndex 游标，不应大于GetExtraCount返回值
        /// \param  *extra 返回字符串类型值
        /// \param  extraSize 字符串值长度
        /// \return true-成功，需要满足
        ///             GetEntryCount返回值大于0
        ///             并且GetExtraCount返回值大于0
        ///             并且index在[0, GetEntryCount返回值)区间
        ///             并且extraIndex在[0, GetExtraCount返回值)区间
        ///         否则 false-失败
        ///
        virtual bool GetExtra(NplLeaderboardHandle_t hLeaderboard, sint32_t index, sint32_t extraIndex, pstr_t extra, size_t extraSize) = 0;

        ///
        /// \brief  设置数值类型附加数据
        ///
        /// \param  hLeaderboard 句柄
        /// \param  extraPos 位置游标，范围[0, 20]
        /// \param  value 值
        /// \return true-成功，需要满足extraPos在[0, 20]区间
        ///         否则 false-失败
        /// \note   需要调用CommitExtra提交到Npl服务器
        ///
        virtual bool SetNumericalExtra(NplLeaderboardHandle_t hLeaderboard, sint32_t extraPos, real64_t value) = 0;

        ///
        /// \brief  设置字符串类型附加数据
        ///
        /// \param  hLeaderboard 句柄
        /// \param  extraPos 位置游标，范围[0, 20]
        /// \param  value 值
        /// \return true-成功，需要满足extraPos在[0, 20]区间
        ///         否则 false-失败
        /// \note   需要调用CommitExtra提交到Npl服务器
        ///
        virtual bool SetStringExtra(NplLeaderboardHandle_t hLeaderboard, sint32_t extraPos, cstr_t value) = 0;

        ///
        /// \brief  提交附加数据设置
        ///
        /// \param  hLeaderboard 句柄
        /// \return 异步请求的Token
        /// 
        /// \see    RegistCallback cbLeaderboadCommitExtra_t
        ///
        virtual long CommitExtra(NplLeaderboardHandle_t hLeaderboard) = 0;

		///
		/// \brief  把UGC内容绑到排行榜
		///
		/// \param  hLeaderboard 排行榜句柄
		/// \param  hUGC UGC句柄
		/// \return 异步请求的Token
		/// 
		/// \see    RegistCallback cbLeaderboardUGCSet_t
		///
		virtual long AttachLeaderboardUGC(NplLeaderboardHandle_t hLeaderboard, UGCHandle_t hUGC) = 0;

    };
};
#endif __NPL_C_INTERFACE__

#endif // _NPL_LEADERBOARD_H
