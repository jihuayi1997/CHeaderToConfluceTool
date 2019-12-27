#ifndef __NPL_H__
#define __NPL_H__

#include <npl-base.h>

#include "npl-network.h"
#include "npl-user.h"
#include "npl-friend.h"
#include "npl-storage.h"
#include "npl-serverMatchmaking.h"
#include "npl-matchmaking.h"
#include "npl-cais.h"
#include "npl-sensitiveword.h"
#include "npl-leaderboard.h"
#include "npl-gameServer.h"
#include "npl-app.h"
#include "npl-voice.h"
#include "npl-utils.h"
#include "npl-htmlsurface.h"

namespace npl 
{
///
/// \brief 获取用户接口
/// 
/// \note  
/// 
NPL_API INplUser* GetNplUser();

///
/// \brief 获取好友接口
/// 
/// \note  
/// 
NPL_API INplFriend* GetNplFriend();

///
/// \brief 获取存储接口
/// 
/// \note  
/// 
NPL_API INplStorage* GetNplStorage();

///
/// \brief 获取大厅匹配接口
/// 
/// \note  
/// 
NPL_API INplMatchmaking* GetNplMatchmaking();

///
/// \brief 获取服务器匹配接口
/// 
/// \note  
/// 
NPL_API INplServerMatchmaking* GetNplServerMatchmaking();

///
/// \brief 获取P2P接口
/// 
/// \note  
/// 
NPL_API INplP2P* GetNplP2P();

/// 
/// \brief 获取GameServer P2P接口
///
NPL_API INplP2P* GetNplGameServerP2P();

///
/// \brief 获取屏蔽字接口
/// 
/// \note  
/// 
NPL_API INplSensitiveWord* GetNplSensitiveWord();

///
/// \brief 获取排行榜接口
/// 
/// \note  
/// 
NPL_API INplLeaderboard* GetNplLeaderboard();

///
/// \brief 获取游戏服务器接口
/// 
/// \note  
/// 
NPL_API INplGameServer* GetNplGameServer();

/// 
/// \brief 获取工具接口
///
NPL_API INplUtils* GetNplUtils();

/// 
/// \brief 获取语音接口
///
NPL_API INplVoice* GetNplVoice();

/// 
/// \brief Get html surface interface
///
NPL_API INplHtmlSurface* GetNplHtmlSurface();

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
NPL_API bool NplGameServer_Init(uint32_t IP, uint16_t gamePort, uint16_t queryPort, uint32_t flags, const NPL_APPID& appID, cstr_t pchVersionString);

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
NPL_API bool NplEncryptedAppTicket_DecryptTicket(cbyte_t ticketEncrypted, uint32_t ticketEncryptedBytes,
	pbyte_t ticketDecrypted, uint32_t* ticketDecryptedBytes, const byte_t byKey[NPL_ENCRYPTED_APP_TICKET_KEYLEN], int cuKey);

/// 
/// \brief  用户是否拥有指定的appID
///
/// \param  ticketDecrypted 解密的票证
/// \param  ticketDecryptedBytes ticketDecrypted字节大小
/// \param  appID 用于验证的appID
///
/// \return 是否拥有指定appID true-拥有，false-失败（票证无效或者没有该appID）
///
NPL_API bool NplEncryptedAppTicket_UserOwnsAppInTicket(cbyte_t ticketDecrypted, uint32_t ticketDecryptedBytes, const NPL_APPID& appID);

/// 
/// \brief  获取票证里的appID
///
/// \param  ticketDecrypted 解密的票证
/// \param  ticketDecryptedBytes ticketDecrypted字节大小
///
/// \return appID，若失败返回ZERO_NPLID
///
NPL_API NPL_APPID NplEncryptedAppTicket_GetTicketAppID(cbyte_t ticketDecrypted, uint32_t ticketDecryptedBytes);

/// 
/// \brief  获取票证里的UserID
///
/// \param  ticketDecrypted 解密的票证
/// \param  ticketDecryptedBytes ticketDecrypted字节大小
/// \param  pUsrID 返回用户的ID，若失败返回ZERO_NPLID
///
NPL_API void NplEncryptedAppTicket_GetTicketUserID(cbyte_t ticketDecrypted, uint32_t ticketDecryptedBytes, NPL_USRID* pUsrID);

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

///
/// \brief 释放线程局部存储对象
///
NPL_API void NplReleaseCurrentThreadMemory();


}

#endif // !__NPL_H__
