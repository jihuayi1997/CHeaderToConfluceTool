///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \file npl-storage.h
///
/// \brief NPL remote storage functioanl
///

#ifndef __NPL_STORAGE_H__
#define __NPL_STORAGE_H__

/// 流文件句柄
typedef long StreamFileHandle_t;
/// UGC唯一句柄
typedef sint64_t UGCHandle_t;
///发布内容的唯一句柄
typedef sint64_t PublishedFileId_t;
///发布内容的更新句柄
typedef long UGCUpdateHandle_t;

/// StreamFileHandle_t无效值
const StreamFileHandle_t StreamFileHandleInvalid = -1;

/// UGCHandle_t无效值
const UGCHandle_t UGCHandleInvalid = 0;

/// PublishedFileId_t无效值
const PublishedFileId_t PublishedFileIdInvalid = 0;

/// UGCUpdateHandle_t无效值
const UGCUpdateHandle_t UGCUpdateHandleInvalid = 0;

enum enPublishedFileVisibility
{
	/// 所有人可见
	eVisibility_Public = 0,
	/// 仅创建者可见
	eVisibility_Private = 1,
};

enum enStorageSyncType
{
	/// use latest-based
	eSyncType_latestBased = 0,
	/// use remote-based
	eSyncType_remoteBased = 1,
	/// use remote-based
	eSyncType_localBased = 2,
};

#pragma pack(push, NPL_PACK_SIZE)
///
/// \brief  文件详细信息
///
/// \param  filename 文件名
/// \param  filesize 文件大小（字节）
/// \param  ctime 文件创建时间
/// \param  mtime 最后一次修改时间
/// 
/// \note   
/// \see    INplStorage 
///
struct FileInfo_t
{
	char filename[NPL_FILE_LEN];
	uint64_t filesize;
	uint64_t ctime;
	uint64_t mtime;
};

///
/// \brief  UGC描述信息
///
/// \param  appId 应用ID
/// \param  usrId 用户ID
/// \param  filesize 文件大小（字节）
/// \param  file 文件名
/// 
/// \note   
/// \see    INplStorage 
///
struct UGCInfomation_t
{
	NPL_APPID appId;
	NPL_USRID usrId;
	uint64_t filesize;
	char file[NPL_FILE_LEN];
};

///
/// \brief notify locale file push to remote complated
///
struct cbLocaleFilePushCompleted
{
	enum { iEvtType = enNplStorage + 1 };
	/// 游戏APPID
	NPL_APPID appId;
	/// 文件名
	char filename[NPL_FILE_LEN];
	/// 文件路径
	char pathname[NPL_PATH_LEN];
	/// 文件大小
	uint64_t filesize;
};

///
/// \brief notify remote file pull to locale complated
///
struct cbRemoteFilePullCompleted
{
	enum { iEvtType = enNplStorage + 2 };
	/// 游戏APPID
	NPL_APPID appId;
	/// 文件名
	char filename[NPL_FILE_LEN];
	/// 文件路径
	char pathname[NPL_PATH_LEN];
	/// 文件大小
	uint64_t filesize;
};

///
/// \brief 写云端文件回应
/// 
struct cbWriteFileAsyncResult_t
{
	enum { iEvtType = enNplStorage + 3 };
	/// 文件名
	char filename[NPL_FILE_LEN];
	/// 文件写入字节数
	uint64_t filesize;
};

///
/// \brief 读云端文件回应
/// 
struct cbReadFileAsyncResult_t
{
	enum { iEvtType = enNplStorage + 4 };
	/// 读取文件的文件名
	char filename[NPL_FILE_LEN];
	/// 读取文件的偏移量
	size_t offset;
	/// 读取文件的请求长度
	size_t length;
	/// 读取文件的token
	long token;
};

///
/// \brief chunk write notify
/// 
struct cbStreamWriteChunkResult_t
{
	enum { iEvtType = enNplStorage + 5 };
	/// opened filename
	char filename[NPL_FILE_LEN];
	/// locale pathname
	char pathname[NPL_PATH_LEN];
	/// stream file handle
	StreamFileHandle_t handle;
	/// stream file upload bytes;
	unsigned long upload_bytes;
};

///
/// \brief notify stream file close
/// 
struct cbStreamCloseFileResult_t
{
	enum { iEvtType = enNplStorage + 6 };
	/// opened filename
	char filename[NPL_FILE_LEN];
	/// locale pathname
	char pathname[NPL_PATH_LEN];
	/// stream file handle
	StreamFileHandle_t handle;
};

///
/// \brief remove remote file
/// 
struct cbForgotFileResult_t
{
	enum { iEvtType = enNplStorage + 7 };
	/// removed file name
	char filename[NPL_FILE_LEN];
};

///
/// \brief UGC下载完成通知
/// 
struct cbUGCDownloadResult_t
{
	enum { iEvtType = enNplStorage + 8 };
	/// UGC句柄
	UGCHandle_t handle;
	/// UGC基本信息
	UGCInfomation_t details;
};

///
/// \brief UGC上传完成通知
/// 
struct cbUGCUploadResult_t
{
	enum { iEvtType = enNplStorage + 9 };
	/// UGC句柄
	UGCHandle_t handle;
};

/// 
/// \brief  搜索发布列表结束通知
///
struct cbUGCSearchResult_t
{
	enum { iEvtType = enNplStorage + 10 };
	/// 每页数量
	sint32_t pageSize;
	/// 第几页
	sint32_t pageIndex;
	/// 返回数量
	sint32_t resultSize;
	/// 总量
	sint32_t totalCount;
	///结果的句柄数组
	PublishedFileId_t publishedFileIds[NPL_UGC_SEARCH_MAX_RESULT];
};

///
/// \brief UGC删除通知
/// 
struct cbUGCDeleteResult_t
{
	enum { iEvtType = enNplStorage + 11 };
	/// 句柄
	PublishedFileId_t publishedFileId;
};

///
/// \brief 同步文件结果通知
/// 
struct cbSyncFilesResult_t
{
	enum { iEvtType = enNplStorage + 12 };
};

///
/// \brief 取消流文件结果通知
/// 
struct cbStreamWriteAbortResult_t
{
	enum { iEvtType = enNplStorage + 13 };
	/// opened filename
	char filename[NPL_FILE_LEN];
	/// locale pathname
	char pathname[NPL_PATH_LEN];
	/// stream file handle
	StreamFileHandle_t handle;
};

/// 
/// \brief  获取用已发布内容的结束通知
///
struct cbEnumerateUserPublishedFilesResult_t
{
	enum { iEvtType = enNplStorage + 14 };
	/// 返回数量
	sint32_t resultSize;
	/// 总量
	sint32_t totalCount;
	///结果的数组
	PublishedFileId_t publishedFileIds[NPL_ENUM_PUBLISHED_FILE_MAX_RESULT];
};

///
/// \brief 文件共享结果通知
/// 
struct cbFileShareResult_t
{
	enum { iEvtType = enNplStorage + 15 };
	/// UGC句柄
	UGCHandle_t handle;
	///共享的文件名
	char filename[NPL_FILE_LEN];
};

///
/// \brief 获取详细信息结果通知
/// 
struct cbPublishedFileDetailsResult_t
{
	enum { iEvtType = enNplStorage + 16 };
	/// 发布内容句柄
	PublishedFileId_t publishedFileId;
	/// 目标appid，有可能是编辑器使用
	NPL_APPID appId;
	/// 支持的DLC
	NPL_APPID gameId;
	/// 文件拥有者的ID
	NPL_USRID ownerId;
	/// 主文件的ugc句柄
	UGCHandle_t fileHandle;
	/// 预览文件的ugc句柄
	UGCHandle_t previewFileHandle;
	/// 更新日期
	sint32_t updateTime;
	/// 创建日期
	sint32_t createTime;
	/// 可被搜索类型
	enPublishedFileVisibility enVisibility;
	///title
	char title[NPL_PUBLISHED_FILE_TITLE_NAME_LEN];
	///描述
	char description[NPL_PUBLISHED_FILE_DESCRIPTION_LEN];
	///tag
	char tags[NPL_PUBLISHED_FILE_TAG_LEN];
};

///
/// \brief 订阅已发布内容的结果通知
/// 
struct cbSubscribePublishedFileResult_t
{
	enum { iEvtType = enNplStorage + 17 };
	/// 订阅的发布内容的句柄
	PublishedFileId_t publishedFileId;
};

///
/// \brief 取消订阅结果通知
/// 
struct cbUnsubscribePublishedFileResult_t
{
	enum { iEvtType = enNplStorage + 18 };
	/// 结果句柄数组
	PublishedFileId_t publishedFileId;
};

/// 
/// \brief  获取用户已订阅的结果通知
///
struct cbEnumerateUserSubscribedFilesResult_t
{
	enum { iEvtType = enNplStorage + 19 };
	/// 返回数量
	sint32_t resultSize;
	/// 总量
	sint32_t totalCount;
	///结果句柄数组
	PublishedFileId_t publishedFileIds[NPL_ENUM_PUBLISHED_FILE_MAX_RESULT];
};

/// 
/// \brief  创建发布内容的结果通知
///
struct cbUGCCreatePublish_t
{
	enum { iEvtType = enNplStorage + 20 };
	//发布内容句柄
	PublishedFileId_t publishedFileId;
};

/// 
/// \brief  更新发布内容的结果通知
///
struct cbUGCUpdatePublishedCommitResult_t
{
	enum { iEvtType = enNplStorage + 21 };
	//发布内容句柄
	PublishedFileId_t publishedFileId;
};

/// 
/// \brief  同步开始通知
///
struct cbStorageSyncBegin_t
{
	enum { iEvtType = enNplStorage + 22 };

	/// 需要下载的文件，远端对应文件大小总和
	uint64_t downloadBytes;
	/// 需要上传的文件，本地对应文件大小总和
	uint64_t uploadBytes;
	/// 需要下载的文件数量
	uint32_t downloadCount;
	/// 需要上传的文件数量
	uint32_t uploadCount;
	/// 需要从远端删除的文件数量
	uint32_t forgotCount;
	/// 需要从本地删除的文件数量
	uint32_t deleteCount;
	/// 创建同步任务失败的文件数量
	uint32_t errorCount;
};

/// 
/// \brief  同步结束通知
///
struct cbStorageSyncEnd_t
{
	enum { iEvtType = enNplStorage + 23 };

	/// 下载的字节总数
	uint64_t downloadBytes;
	/// 上传的字节总数
	uint64_t uploadBytes;
	/// 下载成功的文件数量
	uint32_t downloadSucceed;
	/// 下载失败的文件数量
	uint32_t downloadFailed;
	/// 上传成功的文件数量
	uint32_t uploadSucceed;
	/// 上传失败的文件数量
	uint32_t uploadFailed;
	/// 从远端删除成功的文件数量
	uint32_t forgotSuccess;
	/// 从远端删除失败的文件数量
	uint32_t forgotFailed;
	/// 从本地删除成功的文件数量
	uint32_t deleteSuccess;
	/// 从本地删除失败的文件数量
	uint32_t deleteFailed;
};

/// 
/// \brief  同步询问
///
struct cbStorageSyncAsk_t
{
	enum { iEvtType = enNplStorage + 24 };

	/// localOlder 和 localInexistence 远端文件大小总和
	uint64_t downloadBytes;
	/// remoteOlder 和 remoteInexistence 本地文件大小总和
	uint64_t uploadBytes;
	/// 本地较旧文件数量
	uint32_t localOlder;
	/// 远端较旧文件数量
	uint32_t remoteOlder;
	/// 本地不存在的文件数量
	uint32_t localInexistence;
	/// 远端不存在的文件数量
	uint32_t remoteInexistence;
};

/// 
/// \brief  notify locale file push to remote start
///
struct cbLocaleFilePushStart
{
	enum { iEvtType = enNplStorage + 25 };
	/// 游戏APPID
	NPL_APPID appId;
	/// 文件名
	char filename[NPL_FILE_LEN];
	/// 文件路径
	char pathname[NPL_PATH_LEN];
	/// 文件大小
	uint64_t filesize;
};

/// 
/// \brief  notify remote file pull to locale start
///
struct cbRemoteFilePullStart 
{
	enum { iEvtType = enNplStorage + 26 };
	/// 游戏APPID
	NPL_APPID appId;
	/// 文件名
	char filename[NPL_FILE_LEN];
	/// 文件路径
	char pathname[NPL_PATH_LEN];
	/// 文件大小
	uint64_t filesize;
};

#pragma pack(pop)

#ifndef __NPL_C_INTERFACE__
namespace npl
{
	///
	/// \brief 存储接口
	/// 
	struct INplStorage
	{
		///
		/// \brief	判断文件是否存在
		///
		/// \param	pFileName 判断的文件名
		///
		/// \return	文件是否存在
		/// 
		/// \note	目标文件名默认目录为游戏存档目录
		/// 
		virtual bool IsFileExist(cstr_t pFileName) = 0;

		///
		/// \brief 获取文件大小
		/// \param	pFileName 文件名
		/// \return	文件字节数
		/// 
		/// \note	目标文件名默认目录为游戏存档目录
		/// 
		virtual size_t GetFileSize(cstr_t pFileName) = 0;

		///
		/// \brief	获取文件最后修改时间
		///
		/// \param	pFileName 目标文件名
		///
		/// \return 最后一次修改时间（秒为单位）
		/// 
		/// \note	目标文件名默认目录为游戏存档目录
		/// 
		virtual uint64_t GetFileTime(cstr_t pFileName) = 0;

		///
		/// \brief 写文件到本地
		///
		/// \param	pFileName 目标文件名
		/// \param	pData 写入的数据缓冲首地址
		/// \param	nSize 写入的数据缓冲长度
		///
		/// \return	已成功写入的字节数
		/// 
		/// \note	目标文件名默认目录为游戏存档目录
		/// 
		virtual sint32_t WriteFile(cstr_t pFileName, cvoid_t pData, sint32_t nSize) = 0;

		///
		/// \brief 从本地读文件
		///
		/// \param	pFileName 目标文件名
		/// \param	pData 读取的数据缓冲首地址
		/// \param	nSize 读取的数据缓冲长度
		///
		/// \return	已成功读取的字节数
		/// 
		/// \note	目标文件名默认目录为游戏存档目录
		/// 
		virtual sint32_t ReadFile(cstr_t pFileName, pvoid_t pData, sint32_t nSize) = 0;

		///
		/// \brief 异步写文件到云端
		///
		/// \param	pFileName 目标文件名
		/// \param	pData 写入的数据缓冲首地址
		/// \param	nSize 写入的数据缓冲长度
		///
		/// \return	返回异步调用句柄，用户可通过RegistCallback注册回调函数，以待该异步操作完成时调用。
		/// 
		/// \note	目标文件名默认目录为游戏存档目录
		/// \see	RegistCallback cbWriteFileAsyncResult_t
		/// 
		virtual long WriteFileAsync(cstr_t pFileName, cvoid_t pData, size_t nSize) = 0;

		///
		/// \brief 从云端异步读文件
		///
		/// \param	pFileName 目标文件名
		/// \param	nOffset 写入的数据缓冲首地址
		/// \param	nLength 写入的数据缓冲长度
		///
		/// \return	返回异步调用句柄，用户可通过RegistCallback注册回调函数，以待该异步操作完成时调用。
		/// 
		/// \note	目标文件名默认目录为游戏存档目录
		/// \see	RegistCallback ReadFileAsyncComplate cbReadFileAsyncResult_t
		/// 
		virtual long ReadFileAsync(cstr_t pFileName, size_t nOffset, size_t nLength) = 0;

		///
		/// \brief	异步读文件完成
		///
		/// \param	nToken	异步操作句柄
		/// \param	pData	存储已读取数据的缓冲
		/// \param	nSize	读取缓冲的尺寸
		///
		/// \return	返回实际读取的字节数，失败返回 -1
		/// 
		/// \note	该函数必须在ReadFileAsync调用结束后使用，
		///			若nToken所指的异步操作未完成或已对其调用过ReadFileAsyncComplate则该调用会失败，并返回-1。
		///			若调用ReadFileAsync成功而不调用该函数则有可能造成内存泄漏。
		/// 
		virtual long ReadFileAsyncComplate(long nToken, pvoid_t pData, size_t nSize) = 0;

		///
		/// \brief 删除本地文件
		/// 
		/// \param	pFileName 目标文件名
		///
		/// \return	文件是否已被删除
		///
		/// \note	目标文件名默认目录为游戏存档目录
		/// \see	ForgotFile
		///
		virtual bool RemoveFile(cstr_t pFileName) = 0;

		///
		/// \brief 删除远程文件
		/// 
		/// \param	pFileName 远程文件名
		///
		/// \return	远程文件是否已被删除
		///
		/// \note	该函数为阻塞操作
		/// \see	RemoveFile
		/// 
		virtual bool ForgotFile(cstr_t pFileName) = 0;

		///
		/// \brief 打开文件流
		///
		/// \param	pFileName 远程文件名
		/// 
		/// \return	远程文件句柄，失败返回 -1
		///
		/// \note	流文件上传时必须先调用该函数初始化，该函数在访问服务器不畅时会产生阻塞。
		/// \see	StreamFileWrite StreamFileClose StreamFileAbort
		/// 
		virtual StreamFileHandle_t StreamFileOpen(cstr_t pFileName) = 0;

		///
		/// \brief 写数据到流
		///
		/// \param	hFile	通过StreamFileOpen获取的远程文件句柄
		/// \param	pData	写入的流缓冲首址
		/// \param	nSize	写入的流数据长度
		///
		/// \return	数据是否提交成功
		///
		/// \note	该函数是一个异步操作，但并不是每个调用都会触发一个对应的异步回应。
		///			该操作会以通知的方式告知流数据的上传情况，
		///			可以通过调用RegistNotify函数注册eEvent_StorageStreamWriteChunk事件来获取通知。
		///	\see	RegistNotify cbStreamWriteChunkResult_t
		/// 
		virtual bool StreamFileWrite(StreamFileHandle_t hFile, cvoid_t pData, size_t nSize) = 0;

		///
		/// \brief 关闭流文件
		///
		/// \param	hFile	通过StreamFileOpen获取的远程文件句柄
		/// 
		/// \return	关闭操作是否提交成功
		///
		/// \note	该操作是一个异步操作，但并不会立即执行，而是等待所有已提交数据都完成上传后才真正提交。
		///			该操作会以通知的方式告知文件关闭情况。
		///			可以通过调用RegistNotify函数注册eEvent_StorageStreamWriteClose事件来获取通知。
		///	\see	RegistNotify cbStreamCloseFileResult_t
		///
		virtual bool StreamFileClose(StreamFileHandle_t hFile) = 0;

		///
		/// \brief 取消流文件上传
		///
		/// \param	hFile	通过StreamFileOpen获取的远程文件句柄
		/// 
		/// \return	是否已取消上传
		/// 
		/// \note	文件上传取消后服务器会恢复到之前的文件版本
		///	\see	RegistNotify cbStreamWriteAbortResult_t
		/// 
		virtual bool StreamFileAbort(StreamFileHandle_t hFile) = 0;

		///
		/// \brief	同步文件 (SyncFiles(eSyncType_latestBased))
		///
		/// \return	同步请求是否已提交
		///
		/// \note	同步操作会将本地文件和服务器文件进行合并处理。\
		///			本地未上传或更新过的文件会被推送到服务器，\
		///			远程未下载或更新过的文件会被拉取到本地。\
		///			同步文件会发送通知，cbSyncFilesResult_t, cbRemoteFilePullCompleted, cbLocaleFilePushCompleted, cbRemoteFilePullStart, cbLocaleFilePushStart, cbStorageSyncBegin_t, cbStorageSyncEnd_t
		///	\see	RegistNotify cbSyncFilesResult_t, cbRemoteFilePullCompleted, cbLocaleFilePushCompleted, cbRemoteFilePullStart, cbLocaleFilePushStart, cbStorageSyncBegin_t, cbStorageSyncEnd_t
		/// 
		virtual bool SyncFiles() = 0;

		///
		/// \brief	同步文件
		///
		/// \param  eSyncType: 同步方式
		///
		/// \return	同步请求是否已提交
		///
		/// \note	同步文件会发送通知，cbSyncFilesResult_t, cbRemoteFilePullCompleted, cbLocaleFilePushCompleted, cbRemoteFilePullStart, cbLocaleFilePushStart, cbStorageSyncBegin_t, cbStorageSyncEnd_t
		///	\see	RegistNotify cbSyncFilesResult_t, cbRemoteFilePullCompleted, cbLocaleFilePushCompleted, cbRemoteFilePullStart, cbLocaleFilePushStart, cbStorageSyncBegin_t, cbStorageSyncEnd_t
		/// 
		virtual bool SyncFiles(enStorageSyncType eSyncType) = 0;

		///
		/// \brief	获取本地游戏目录save文件夹内的文件数量
		///
		/// \return	save文件夹内的文件数量
		/// 
		virtual long GetFileCount() = 0;

		///
		/// \brief 获取文件详细信息
		///
		/// \param	nIndex	文件的序号，范围为[0, FileCount)，不正确的索引会导致调用返回false
		/// \param	pInfo	文件的描述结构
		///
		/// \return 文件信息是否已获取
		///
		/// \note	函数调用成功后pInfo所指的结构中的数据才有效。
		/// \see	GetFileCount
		/// 
		virtual bool GetFileInfo(int nIndex, FileInfo_t *pInfo) const = 0;

		///
		/// \brief 获取云端存储使用情况
		///
		/// \param	nUsed	out 已用的空间（字节）
		/// \param	nTotal	out 空间总大小（字节）
		///
		/// \return	调用是否成功
		///
		/// \note	该操作是一个阻塞操作，在网络条件不好的情况下有可能花费较长的时间。
		/// 
		virtual bool GetCloudSpace(uint64_t *nUsed, uint64_t *nTotal) = 0;

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
		virtual long FileShare(cstr_t pFileName) = 0;

		///
		/// \brief 检查云存储是否开通
		///
		/// \return	云存储是否可用
		/// 
		virtual bool IsCloudStorageEnable() = 0;

		///
		/// \brief 检查云存储是否被游戏使用
		///
		/// \return	云存储是否可用
		/// 
		virtual bool IsCloudStorageUsed() = 0;

		///
		/// \brief 设置云存储游戏使用权限
		///
		/// \param	bEnable true:允许, false:不允许
		///
		/// \return	云存储是否可用
		/// 
		virtual bool DoCloudStorageUsed(bool bEnable) = 0;

		///
		/// \brief 下载用户生成内容
		///
		/// \param	hContent	UGC上下文句柄
		/// \param	nPriority	下载优先级
		///
		/// \return	异步调用句柄
		///
		/// \note	该函数会启动hContent指定的UGC内容的下载，并在操作完成后以回调的方式通知用户下载完成或失败。\
		///			文件下载的默认位置为游戏的缓存目录。
		/// \see	RegistCallback cbUGCDownloadResult_t
		/// 
		virtual long UGCDownload(UGCHandle_t hContent, int nPriority) = 0;

		///
		/// \brief 下载用户生成内容到指定未知
		///
		/// \param	hContent	UGC上下文句柄
		/// \param	nPriority	下载优先级
		/// \param	pLocation	下载文件的保存路径
		///
		/// \return	异步调用句柄
		///
		/// \note	该函数会启动hContent指定的UGC内容的下载，并在操作完成后以回调的方式通知用户下载完成或失败。\
		///			文件下载的默认位置为pLocation指定的目录。
		/// \see	RegistCallback cbUGCDownloadResult_t
		/// 
		virtual long UGCDownloadTo(UGCHandle_t hContent, int nPriority, cstr_t pLocation) = 0;

		///
		/// \brief 获取下载信息
		///
		/// \param	hContent	UGC上下文句柄
		/// \param	nTotalDL	已下载字节数
		/// \param	nSpeedDL	平均下载速度（Bytes/S）
		/// \param	nTotalBytes 总下载字节数
		///
		/// \return	调用是否成功
		/// 
		virtual bool UGCGetDownloadInfo(UGCHandle_t hContent, sint64_t *nTotalDL, sint64_t *nSpeedDL, sint64_t *nTotalBytes) = 0;

		///
		/// \brief 获取UGC描述信息
		///
		/// \param	hContent	UGC上下文句柄
		/// \param	pDetails	UGC的描述结构指针
		///
		/// \return	调用是否成功
		/// \see	UGCInfomation_t
		/// 
		/// \note UGC文件下载后调用才有效
		virtual bool UGCGetDetails(UGCHandle_t hContent, UGCInfomation_t *pDetails) = 0;

		///
		/// \brief 读取UGC文件
		///
		/// \param	hContent	UGC上下文句柄
		/// \param	nOffset		读取的文件偏移量
		/// \param	pData		读取缓冲地址
		/// \param	nSize		读取的字节数
		///
		/// \return	已写入缓冲的字节数，调用失败返回 -1
		///
		/// \note	读取UGC文件内容前，需先下载UGC文件到本地。否则调用失败！
		/// 
		virtual sint32_t UGCRead(UGCHandle_t hContent, uint32_t nOffset, pvoid_t pData, size_t nSize) = 0;

		/// 
		/// \brief 获取UGC缓存的文件数量
		///
		/// \return	返回已下载的UGC文件数量
		/// 
		virtual sint32_t UGCGetCachedCount()const = 0;

		///
		/// \brief 获取UGC缓存的文件句柄
		///
		/// \param	nCachedIndex	缓存的UGC文件索引
		///
		/// \return	返回nCachedIndex对应的UGC上下文句柄
		/// 
		virtual UGCHandle_t UGCGetHandle(sint32_t nCachedIndex)const = 0;

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
		virtual long SearchUGC(cstr_t condition, sint32_t pageSize, sint32_t pageNumber) = 0;

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
		virtual long UGCCreatePublish(cstr_t pFile, cstr_t pPreviewFile, NPL_APPID gameId, cstr_t pTitle, cstr_t pDescription, cstr_t pTags, int nMediaType, enPublishedFileVisibility enVisiblity) = 0;

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
		virtual UGCUpdateHandle_t UGCCreatePublishedUpdateRequest(PublishedFileId_t  nPublishedFileId) = 0;

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
		virtual bool UGCUpdatePublishedFile(UGCUpdateHandle_t updateHandle, cstr_t pFile) = 0;

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
		virtual bool UGCUpdatePublishedPreview(UGCUpdateHandle_t updateHandle, cstr_t pPreview) = 0;

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
		virtual bool UGCUpdatePublishedTitle(UGCUpdateHandle_t updateHandle, cstr_t pTitle) = 0;

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
		virtual bool UGCUpdatePublishedDescription(UGCUpdateHandle_t updateHandle, cstr_t pDescription) = 0;

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
		virtual bool UGCUpdatePublishedTags(UGCUpdateHandle_t updateHandle, cstr_t pTags) = 0;

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
		virtual bool UGCUpdatePublishedVersion(UGCUpdateHandle_t updateHandle, cstr_t targetVersion, cstr_t minVersion) = 0;

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
		virtual bool UGCUpdatePublishedData(UGCUpdateHandle_t updateHandle, cstr_t pJsonString) = 0;

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
		virtual bool UGCUpdatePublishedVisibility(UGCUpdateHandle_t updateHandle, enPublishedFileVisibility enVisibility) = 0;

		///
		/// \brief 提交更新
		///
		/// \param	updateHandle	更新句柄
		///
		/// \return	异步操作句柄，可通过RegistCallback注册回调函数，系统会在操作完成后调用。
		/// 
		virtual long UGCUpdatePublishedCommit(UGCUpdateHandle_t updateHandle) = 0;

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
		virtual bool GetUGCPublishProgress(long token, sint64_t *nTotalUL, sint64_t *nSpeedUL, sint64_t *nTotalBytes) = 0;

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
		virtual bool GetUGCPublishedUpdateProgress(UGCUpdateHandle_t updateHandle, sint64_t *nTotalUL, sint64_t *nSpeedUL, sint64_t *nTotalBytes) = 0;

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
		virtual long DelUGCPublished(PublishedFileId_t nPublishedFileId) = 0;

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
		virtual long EnumerateUserPublishedFiles(uint32_t nStartIndex) = 0;

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
		virtual long GetPublishedFileDetails(PublishedFileId_t nPublishedFileId, bool bRefresh) = 0;

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
		virtual long SubscribePublishedFile(PublishedFileId_t nPublishedFileId) = 0;

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
		virtual long UnsubscribePublishedFile(PublishedFileId_t nPublishedFileId) = 0;

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
		virtual long EnumerateUserSubscribedFiles(uint32_t nStartIndex) = 0;
	};
}
#endif // __NPL_C_INTERFACE__
#endif // __NPL_STORAGE_H__
