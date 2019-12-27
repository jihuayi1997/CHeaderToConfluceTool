///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \file npl-network.h
///
/// \brief NPL P2p functional support
///
#ifndef __NPL_NETWORK_H__
#define __NPL_NETWORK_H__

///
/// \brief  p2p发送策略
///
enum enP2PSendPoly
{
	/// Same as regular UDP, except that it will also discard duplicate datagrams.
	eSendPoly_unreliable = 0,

	/// Regular UDP with a sequence counter.  Out of order messages will be discarded.
	/// Sequenced and ordered messages sent on the same channel will arrive in the order sent.
	eSendPoly_unreliableOrdered,

	/// The message is sent reliably, but not necessarily in any order.  Same overhead as unreliable.
	eSendPoly_reliable,

	/// This message is reliable and will arrive in the order you sent it.  Messages will be delayed while waiting for out of order messages.  Same overhead as 'unreliable_sequenced'.
	/// Sequenced and ordered messages sent on the same channel will arrive in the order sent.
	eSendPoly_reliableOrdered,
};

/// 
/// \brief  服务器连接状态信息
///
enum eP2PSocketState
{
	/// 初始
	eP2PSocket_Invalid = 0,
	/// 连接有效
	eP2PSocket_Connected = 1,

	/// 初始化中
	eP2PSocket_Initiated,
	/// 连接中
	eP2PSocket_Connecting,
	/// 连接错误
	eP2PSocket_ConnectError,
	/// 本地断开连接
	eP2PSocket_LocalDisconnect,
	/// 远端断开连接
	eP2PSocket_RemoteDisconnect,
};

#pragma pack(push, NPL_PACK_SIZE)
///
/// \brief  p2p统计信息
/// \param  messageBytesPushed              推送的字节数 INplP2P::SendP2PData
/// \param  messageBytesSent                已发送的字节数 INplP2P::SendP2PData，小于等于messageBytesPushed
/// \param  messageBytesResent              重新发送的字节数
/// \param  messageBytesReceivedProcessed   接收到的字节数
/// \param  messageBytesReceivedIgnored     接收忽略的字节数
/// \param  actualBytesSent                 实际发送的字节数，包括每个消息的数据报文字节数，以及可靠发送的字节数
/// \param  actualBytesReceived             实际接收的字节数，包括每个消息的数据报文字节数
/// \param  relay                           是否是通过服务器转发的方式
///
struct P2PSessionStatistics_t
{
	uint64_t messageBytesPushed;
	uint64_t messageBytesSent;
	uint64_t messageBytesResent;
	uint64_t messageBytesReceivedProcessed;
	uint64_t messageBytesReceivedIgnored;
	uint64_t actualBytesSent;
	uint64_t actualBytesReceived;

	bool     relay;
};

/// 
/// \brief  socket 状态变更通知
///
struct cbNetworkSocketStatusChange_t
{
	enum { iEvtType = enNetwork + 1 };
	/// 当前状态
	eP2PSocketState eStatus;
};

/// 
/// \brief  用户连接回执枚举
///
enum eNetworkSessionResult
{
	/// 成功
	eP2PConnectSession_success = 0,
	/// 当前用户没有注册
	eP2PConnectSession_notReigster = 1,
	/// 对方用户没有注册
	eP2PConnectSession_targetNotReigster = 2,
	/// 超时未响应
	eP2PConnectSession_timeout = 3,
};

/// 
/// \brief  ConnectP2P 回执信息
///
struct cbNetworkUserConnectResult_t
{
	enum { iEvtType = enNetwork + 2 };
	/// 相关用户ID
	NPL_ID targetUserID;
	/// 回执枚举
	eNetworkSessionResult eResult;
};

/// 
/// \brief  SendP2PData 回执信息
///
struct cbNetworkSendResult_t
{
	enum { iEvtType = enNetwork + 3 };
	/// SendP2PData 返回值
	uint32_t sendID;
	/// 错误信息
	eNetworkSessionResult eResult;
};

/// 
/// \brief  请求链接通知
///
struct cbNetworkUserApplyConnect_t
{
	enum { iEvtType = enNetwork + 4 };
	NPL_ID targetUserID;
};

/// 
/// \brief  断开链接通知
///
struct cbNetworkUserDisconnect_t
{
	enum { iEvtType = enNetwork + 5 };
	NPL_ID targetUserID;
};

#pragma pack(pop)

#ifndef __NPL_C_INTERFACE__
namespace npl
{
	///
	/// \brief p2p interface
	/// 
	struct INplP2P
	{
	public:
		///
		/// \brief  判断是否与指定用户处于链接状态
		///
		/// \param  uid 用户ID
		/// \return 是否处于链接状态
		/// 
		/// \note   
		/// \see    
		///
		virtual bool IsConnected(const NPL_ID & uid) = 0;

		///
		/// \brief  请求创建P2P
		///
		/// \param  uid 用户ID
		/// \param  virtualPort 虚拟端口号
		/// \param  maxConnect 允许的最大连接数量
		/// \return 是否创建成功
		/// 
		/// \note   虚拟端口号一般可用gameID
		/// \see    cbNetworkSocketStatusChange_t
		///
		virtual bool CreateP2P(uint16_t virtualPort, uint16_t maxConnect = 10) = 0;

		///
		/// \brief  请求链接指定用户
		///
		/// \param  uid 用户ID
		/// \param  timeout 超时时间（毫秒）
		/// \return 是否链接成功
		///
		/// \see    cbNetworkUserConnectResult_t
		///
		virtual bool ConnectP2P(const NPL_ID & uid, uint32_t timeout) = 0;

		///
		/// \brief  同意指定用户的链接请求
		///
		/// \param  uid 用户ID
		/// \return 是否成功
		/// 
		virtual bool AcceptP2PSession(const NPL_ID & uid) = 0;

		///
		/// \brief  发送信息给指定用户
		///
		/// \param  uid 用户ID
		/// \param  data 信息
		/// \param  size 信息长度
		/// \param  enPoly 发送策略
		/// \return sendID 对应 cbNetworkSendResult_t.sendID 0-表示发送失败
		/// 
		/// \see    cbNetworkSendResult_t 一般可以忽略这个信息
		///
		virtual uint32_t SendP2PData(const NPL_ID & uid, pvoid_t data, uint32_t size, enP2PSendPoly enPoly) = 0;

		///
		/// \brief  检查是否有可读取的消息
		///
		/// \param  msgSize 返回可读取的消息长度
		/// \return true-有 false-没有
		///
		virtual bool IsP2PPacketAvailable(uint32_t* msgSize) = 0;

		///
		/// \brief  接收指定用户的信息
		///
		/// \param  uid 用户ID
		/// \param  dest 数据缓冲
		/// \param  size 数据缓冲长度
		/// \param  length 读取的数据长度
		/// \return 是否接收到消息
		///
		virtual bool RecvP2PData(NPL_ID * uid, pvoid_t dest, uint32_t size, uint32_t* length) = 0;

		///
		/// \brief  关闭与指定用户的链接
		///
		/// \param  uid 用户ID
		/// \return 是否关闭成功
		///
		virtual bool CloseP2PSession(const NPL_ID & uid) = 0;

		///
		/// \brief  获取与指定用户通讯统计信息
		///
		/// \param  uid 用户ID
		/// \param  pStatistics 统计信息对象
		/// \return 是否获取统计信息成功
		///
		virtual bool GetP2PSessionStatistics(const NPL_ID & uid, P2PSessionStatistics_t* pStatistics) = 0;

		///
		/// \brief  关闭P2P
		///
		virtual void CloseP2P() = 0;
	};
}; // end namespace npl
#endif // __NPL_C_INTERFACE__
#endif // __NPL_NETWORK_H__
