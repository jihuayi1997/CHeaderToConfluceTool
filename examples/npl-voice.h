///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \file npl-voice.h
///
/// \brief voice chat
///

#ifndef __NPL_VOICE_H__
#define __NPL_VOICE_H__

#pragma pack(push, NPL_PACK_SIZE)
///
/// \brief 登录会话回调信息
///
struct cbVoiceLogin_t
{
	enum { iEvtType = enNplVoice + 1 };

	sint32_t sessionId;  /// 会话id
	sint64_t eid;        /// 语音会话中的用户id
	NPL_USRID userId;      /// 用户id
};

///
/// \brief 登出会话回调信息
///
struct cbVoiceLogout_t
{
	enum { iEvtType = enNplVoice + 2 };

	sint32_t sessionId;   /// 会话id
	NPL_USRID userId;      /// 用户id
};

///
/// \brief 开始录音回调信息
///
struct cbVoiceStartCapture_t
{
	enum { iEvtType = enNplVoice + 3 };

	sint32_t sessionId;    /// 会话id
};

///
/// \brief 停止录音回调信息
///
struct cbVoiceStopCapture_t
{
	enum { iEvtType = enNplVoice + 4 };

	sint32_t sessionId;     /// 会话id
};

///
/// \brief 屏蔽发声回调信息
///
struct cbVoiceIgnorePlayback_t
{
	enum { iEvtType = enNplVoice + 5 };

	sint32_t sessionId;     /// 会话id
	NPL_USRID userId;        /// 用户Id
	sint32_t ignore;        /// 是否屏蔽
};

///
/// \brief 设置静音回调信息
///
struct cbVoiceMutePlayback_t
{
	enum { iEvtType = enNplVoice + 6 };

	sint32_t sessionId;     /// 会话id
};

///
/// \brief 语音连接状态回调
///
struct cbVoiceConnectChange_t
{
	enum { iEvtType = enNplVoice + 7 };

	sint32_t sessionId;     /// 会话id
};

///
/// \brief 说话者信息
///
struct cbVoiceSpeakingInfo
{
	NPL_USRID userId;        /// 用户id
	sint32_t volume;         /// 说话者音量，范围0-255，值越大说话音量越大
};

///
/// \brief 获取正在说话人的列表
///
struct cbVoiceSpeakingList_t
{
	enum { iEvtType = enNplVoice + 8 };

	sint32_t sessionId;			  /// 会话id
	uint32_t speakingCount;       /// 正在说话的人的数量
	cbVoiceSpeakingInfo* speakingUserIds;    /// 正在说话人的用户id
};

///
/// \brief 创建会话回调信息
///
struct cbVoiceCreate_t
{
	enum { iEvtType = enNplVoice + 9 };

	sint32_t sessionId;  /// 会话id
	sint64_t eid;        /// 语音会话中的用户id
};


///
/// \brief 销毁会话回调信息
///
struct cbVoiceDestroy_t
{
	enum { iEvtType = enNplVoice + 10 };

	sint32_t sessionId;  /// 会话id
};


struct cbVoiceMemberInfo
{
	NPL_USRID userId;        /// 用户id
};

///
/// \brief 获取正在说话人的列表
///
struct cbVoiceMemberList_t
{
	enum { iEvtType = enNplVoice + 11 };

	sint32_t sessionId;			  /// 会话id
	uint32_t memberCount;       /// 正在说话的人的数量
	cbVoiceMemberInfo* members;
};


#pragma pack(pop)

#ifndef __NPL_C_INTERFACE__
namespace npl
{
	///
	/// \brief 实时语音模块接口
	///
	struct NPL_API INplVoice
	{
		///
		/// \brief 创建实时会话
		///
		/// \param channelType 自定义的通道类型，比如"team", "clan", "friends"...
		/// \param sessionName 自定义的会话名称
		/// 
		/// \see RegistEvent cbVoiceCreate_t
		///
		/// \note 由channelType和sessionName可确定一个会话房间，同一房间内的session可以互相通话
		///
		virtual void createSession(cstr_t channelType, cstr_t sessionName) = 0;

		///
		/// \brief 销毁的会话
		///
		/// \param sessionId 会话id
		///
		virtual void destroySession(sint32_t sessionId) = 0;

		///
		/// \brief 登录会话
		///
		/// \param sessionId 会话id
		/// 
		/// \see RegistEvent cbVoiceLogin_t
		///
		/// \note 说明：一个session可以反复login/logout。另外app切到后台时，建议logout断开，可以达到节省流量的目的
		///
		virtual void loginSession(sint32_t sessionId) = 0;

		///
		/// \brief 退出会话
		///
		/// \param sessionId 会话id
		///
		/// \see RegistEvent cbVoiceLogout_t
		///
		virtual void logoutSession(sint32_t sessionId) = 0;

		///
		/// \brief 开始录音
		///
		/// \param sessionId 会话id
		///
		/// \see RegistEvent cbVoiceStartCapture_t
		///
		virtual void startCapture(sint32_t sessionId) = 0;

		///
		/// \brief 停止录音
		///
		/// \param sessionId 会话id
		///
		/// \see RegistEvent cbVoiceStopCapture_t
		///
		virtual void stopCapture(sint32_t sessionId) = 0;

		///
		/// \brief 测试mic
		///
		/// \param sessionId 会话id
		/// \param start true, 开始测试， false, 停止测试
		///
		virtual void testMic(sint32_t sessionId, bool start) = 0;

		///
		/// \brief 增加录音音量
		///
		/// \param recordVol 默认是1，可以设置2～30
		///
		virtual void setRecordVol(sint32_t recordVol) = 0;

		///
		/// \brief 设置软件播放音量
		///
		/// \param sessionId 会话id
		/// \param persent 0表示0%，100表示100%，150表示150%
		///
		virtual void setPlaybackVol(sint32_t sessionId, uint32_t persent) = 0;

		///
		/// \brief 屏蔽发声
		///
		/// \param sessionId 会话id
		/// \param userId 需要屏蔽的用户Id
		/// \param isIgnore 是否屏蔽, true 屏蔽 false 取消屏蔽
		///
		/// \see RegistEvent cbVoiceIgnorePlayback_t
		///
		virtual void ignoreVoice(sint32_t sessionId, NPL_USRID userId, bool isIgnore) = 0;

		///
		/// \brief 静音
		///
		/// \param sessionId 会话id
		/// \param isMute 是否静音
		///
		/// \see RegistEvent cbVoiceMutePlayback_t
		///
		virtual void mutePlayback(sint32_t sessionId, bool isMute) = 0;

		///
		/// \brief 获取正在说话人的列表
		///
		/// \param sessionId 会话id
		///
		/// \see RegistEvent cbVoiceSpeakingList_t
		///
		virtual void getSpeakingList(sint32_t sessionId) = 0;

		///
		/// \brief 查询所有成员信息
		///
		/// \param sessionId 会话id
		///
		/// \see RegistEvent cbVoiceMemberList_t
		///
		virtual void getMemberList(sint32_t sessionId) = 0;
	};
}

#endif // __NPL_C_INTERFACE__
#endif // __NPL_VOICE_H__
