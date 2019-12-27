///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \file npl-sensitiveword.h
///
/// \brief NPL filter word functioanl
///
#pragma once

#ifndef _NPL_SENSITIVEWORD_H
#define _NPL_SENSITIVEWORD_H
namespace npl
{
    ///
    /// \brief sensitive word interface
    /// 
    struct NPL_API INplSensitiveWord
    {
    public:
        ///
        /// \brief  检查指定内容是否包含敏感屏蔽字
        ///
        /// \param  data 检查内容
        /// \return 是否包含屏蔽字
        /// 
        /// \note   检查内容应是utf8编码
        /// \see     
        ///
        virtual bool Censor_utf8(cstr_t data) = 0;

        ///
        /// \brief  检查并替换指定内容中的屏蔽字到缓冲区
        ///
        /// \param  data 检查内容
        /// \param  out 替换返回的缓冲区
        /// \param  out_size 替换返回的缓冲区大小
        /// \return 是否包含屏蔽字
        /// 
        /// \note   检查内容应是utf8编码
        /// \see    
        ///
        virtual bool Censor_utf8(cstr_t data, pstr_t out, size_t out_size) = 0;

        ///
        /// \brief  检查指定内容是否包含敏感屏蔽字
        ///
        /// \param  data 检查内容
        /// \return 是否包含屏蔽字
        /// 
        /// \note   检查内容应是系统当前多字节编码；如果系统是gbk编码，检查内容也应是gbk编码
        /// \see     
        ///
        virtual bool Censor_mbs(cstr_t data) = 0;

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
        virtual bool Censor_mbs(cstr_t data, pstr_t out, size_t out_size) = 0;
    };

}; // end namespace npl

#endif // _NPL_SENSITIVEWORD_H
