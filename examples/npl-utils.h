///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 netease China
/// All right reserved
///
/// \file npl-leaderboard.h
///
/// \brief NPL leaderboard functional
///
#ifndef _NPL_UTILS_H__
#define _NPL_UTILS_H__

#ifndef __NPL_C_INTERFACE__
namespace npl
{
	///
	/// \brief  server leaderboard interface
	///
	struct NPL_API INplUtils
	{
	public:
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
		virtual bool GetImageSize(sint32_t iImage, uint32_t* puWidth, uint32_t* puHeight) = 0;

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
		virtual bool GetImageRGBA(sint32_t iImage, uint8_t* pubDest, int nDestBufferSize) = 0;

		///
		/// \brief 根据用户IP获得玩家所在国家信息
		///
		virtual cstr_t GetIPCountry() = 0;
	};
}; 
#endif __NPL_C_INTERFACE__

#endif // _NPL_UTILS_H__
