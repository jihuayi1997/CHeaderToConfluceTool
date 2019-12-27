#ifndef __NPL_MACRO_H__
#define __NPL_MACRO_H__

#if defined(_MSC_VER)
# if defined(_NPL_EXPORTS)
#  ifdef _DLL
# 	define NPL_API __declspec(dllexport)
#  elif defined( _LIB )
# 	define NPL_API
#  endif
# else
#  if defined(_NPL_STATIC)
# 	define NPL_API
#  else
# 	define NPL_API __declspec(dllimport)
#  endif
# endif
#elif defined(__GNUC__)
#	if defined( _NPL_EXPORTS ) && defined( _DLL )
#		define NPL_API __attribute__((__visibility__("default")))
#	else
#		define NPL_API
#	endif
#else 
#	define NPL_API
#endif

#if defined(_MSC_VER)
#  if _MSC_VER >= 1600  // vc2010
#    include<stdint.h>
#    define __STDINT_H_USING_SYS__
#  endif // _MSC_VER >= 1600
#endif


#define NPL_JOIN_X(x, y)				x##y
#define NPL_JOIN(x, y)				NPL_JOIN_X(x, y)
#define NPL_JOIN_WITH(with, x, y)	NPL_JOIN( x, NPL_JOIN(with, y) )

#define NPL_LINEID(x)	NPL_JOIN(x, __LINE__)

#define NPL_STRING1(x)	#x
#define NPL_STRING2(x)	NPL_STRING1(x)
#define NPL_STRING3(x)	NPL_STRING2(x)
#define NPL_STRING(x)	NPL_STRING3(x)

#define NPL_ARGS_0(...) 
#define NPL_ARGS_1(P1, ...) P1
#define NPL_ARGS_2(P1, P2, ...) P2
#define NPL_ARGS_3(P1, P2, P3, ...) P3
#define NPL_ARGS_4(P1, P2, P3, P4, ...) P4
#define NPL_ARGS_5(P1, P2, P3, P4, P5, ...) P5
#define NPL_ARGS_6(P1, P2, P3, P4, P5, P6, ...) P6
#define NPL_ARGS_7(P1, P2, P3, P4, P5, P6, P7, ...) P7
#define NPL_ARGS_8(P1, P2, P3, P4, P5, P6, P7, P8, ...) P8
#define NPL_ARGS_9(P1, P2, P3, P4, P5, P6, P7, P8, P9, ...) P9

#define NPL_ARGS_N(N,...) NPL_JOIN(NPL_ARGS_, N) ( __VA_ARGS__ )

//-------------------------------------------------------------------------------------------------------------------------------------------------//
// 安全删除定义
//-------------------------------------------------------------------------------------------------------------------------------------------------//
#ifndef SAFE_DELETE
#	define SAFE_DELETE( p )			do{delete(p);(p) = NULL;}while(false)
#endif

#ifndef SAFE_DELETE_TYPE
#	define SAFE_DELETE_TYPE( p, t )	do{delete((t*)p);(p) = NULL;}while(false)
#endif

#ifndef SAFE_DELETE_ARRAY
#	define SAFE_DELETE_ARRAY( p )	do{delete[] (p); (p) = NULL;}while(false)
#endif

#ifndef SAFE_RELEASE
#	define SAFE_RELEASE( p )		do{if(p){ (p)->Release(); (p) = NULL; }}while(false)
#endif

#define NPL_UNREF(P) (P)
#define NPL_NOUSE(P) (P)

#define NPL_MAKESW(a, b) (((uint16_t(a)) & 0xff)       | ((uint16_t(b) & 0xff) << 8))
#define NPL_MAKEDW(a, b) (((uint32_t(a)) & 0xffff)     | ((uint32_t(b) & 0xffff) << 16))
#define NPL_MAKEQW(a, b) (((uint64_t(a)) & 0xffffffff) | ((uint64_t(b) & 0xffffffff) << 32))

#define NPL_LOWORD(l) ((uint16_t)(((uint32_t)(l)) & 0xffff))
#define NPL_HIWORD(l) ((uint16_t)((((uint32_t)(l)) >> 16) & 0xffff))
#define NPL_LOBYTE(w) ((uint8_t) (((uint32_t)(w)) & 0xff))
#define NPL_HIBYTE(w) ((uint8_t) ((((uint32_t)(w)) >> 08) & 0xff))

#define NPL_BIT(w)			(1ULL<<(w))

#define NPL_CHK_BIT(v,bit)	(((v)&NPL_BIT(bit))!=0)
#define NPL_GET_BIT(v,bit)	(((v)&NPL_BIT(bit))?1:0)
#define NPL_SET_BIT(v,bit)	(((v)|NPL_BIT(bit)))
#define NPL_CLR_BIT(v,bit)	(((v)&(~NPL_BIT(bit))))

#define NPL_CHK_FLAGS(v,flags)	(((v)&(flags))==flags)
#define NPL_ADD_FLAGS(v,flags)	(((v)|(flags)))
#define NPL_CLR_FLAGS(v,flags)	(((v)&(~(flags))))

#define NPL_MIN( a, b )	((a)>(b)?(b):(a))
#define NPL_MAX( a, b )	((a)<(b)?(b):(a))
#define NPL_RNG( v, l, u ) ((v)<(l)?(l):(v)>(u)?(u):(v))

#define NPL_VOID void(0)

// 内存对齐
#define NPL_ALIGN_MEM(x, align) (((x) + (align) - 1) & ~((align)-1))
// 向上取整
#define NPL_ALIGN_UP(x, align) ((x)&(-align))
// 向下取整
#define NPL_ALIGN_DOWN(x, align) (-(-(x)&-(align)))
// 计算数组长度
#define NPL_COUNTOF(a) (sizeof(a) / sizeof(a[0]))
// 数组下标检查
#define NPL_INDEXOF(a, i) (i >= 0 && i < NPL_COUNTOF(a))
// 通过成员变量指针获取结构首地址
#define NPL_POINTER(p, t, m) ((t *)((char*)p - (size_t)(&((t *)0)->m)))

#if defined(_WINDOWS)
# include <crtdbg.h>
# define NPL_ASSERT_MSG(expr, msg, ...) \
	(void)( ( !!( expr ) ) || \
	( 1 != _CrtDbgReport( _CRT_ASSERT, __FILE__, __LINE__, NULL, msg, ##__VA_ARGS__ ) ) || \
	( _CrtDbgBreak(), 0 ) )
#endif

#if defined(_LINUX)
#define XGC_ASSERT_MSG(expr, FMT, ...) \
	if( !(expr) ) { fprintf( stderr, "%s:%d:" FMT "\n", __FILE__, __LINE__, ##__VA_ARGS__ ); }
#endif

#ifdef _DEBUG
#	define NPL_ASSERT(expr)						NPL_ASSERT_MSG(expr,#expr,0)
#	define NPL_ASSERT_RETURN(expr,ret,...)		if(!(expr)){ NPL_ASSERT_MSG(false,#expr, ##__VA_ARGS__); return ret; }
#	define NPL_ASSERT_THROW(expr,ret,...)		if(!(expr)){ NPL_ASSERT_MSG(false,#expr, ##__VA_ARGS__); throw( ret ); }
#	define NPL_ASSERT_BREAK(expr,...)			if(!(expr)){ NPL_ASSERT_MSG(false,#expr, ##__VA_ARGS__); break; }
#	define NPL_ASSERT_CONTINUE(expr,...)			if(!(expr)){ NPL_ASSERT_MSG(false,#expr, ##__VA_ARGS__); continue; }
#	define NPL_ASSERT_RELEASE(expr,msg,...)		if(!(expr)){ NPL_ASSERT_MSG(false,#expr, ##__VA_ARGS__); }else{ (expr)->Release(); }
#	define NPL_ASSERT_MESSAGE(expr,msg,...)		if(!(expr)){ NPL_ASSERT_MSG(false,msg, ##__VA_ARGS__); }
#	define NPL_DEBUG_MESSAGE(msg,...)			NPL_ASSERT_MSG(false,msg,##__VA_ARGS__)
#	define NPL_ASSERT_POINTER(expr)				NPL_ASSERT_MSG((expr),"NULL POINT FOUND, IS'T RIGHT?")
#	define NPL_VERIFY(expr)						NPL_ASSERT_MSG((expr),"")
#elif defined(NPL_ASSERT_LOG)
#	define NPL_ASSERT(expr)						if(!(expr)){ LOG_WRN( "ASSERT " "%s", #expr ); }
#	define NPL_ASSERT_RETURN(expr,ret,...)		if(!(expr)){ LOG_WRN( "ASSERT " __VA_ARGS__ ); return ret; }
#	define NPL_ASSERT_THROW(expr,ret,...)		if(!(expr)){ LOG_WRN( "ASSERT " __VA_ARGS__ ); throw( ret ); }
#	define NPL_ASSERT_BREAK(expr,...)			if(!(expr)){ LOG_WRN( "ASSERT " __VA_ARGS__ ); break; }
#	define NPL_ASSERT_CONTINUE(expr,...)			if(!(expr)){ LOG_WRN( "ASSERT " __VA_ARGS__ ); continue; }
#	define NPL_ASSERT_RELEASE(expr,msg,...)		if(!(expr)){ LOG_WRN( "ASSERT " __VA_ARGS__ ); }else{(expr)->Release();}
#	define NPL_ASSERT_MESSAGE(expr,msg,...)		if(!(expr)){ LOG_WRN( "ASSERT " msg, __VA_ARGS__ ); }
#	define NPL_DEBUG_MESSAGE(msg,...)			if(!(0000)){ LOG_WRN( "ASSERT " msg, __VA_ARGS__ ); }
#	define NPL_ASSERT_POINTER(expr)				if(!(expr)){ LOG_WRN( "ASSERT " "%s", #expr ); }
#	define NPL_VERIFY(expr)						NPL_ASSERT(expr)
#else
#	define NPL_ASSERT(expr)						(void)(expr)
#	define NPL_ASSERT_RETURN(expr,ret,...)		if(!(expr)){return ret;}
#	define NPL_ASSERT_THROW(expr,ret,...)		if(!(expr)){throw( ret );}
#	define NPL_ASSERT_BREAK(expr,...)			if(!(expr)){break;}
#	define NPL_ASSERT_CONTINUE(expr,...)			if(!(expr)){continue;}
#	define NPL_ASSERT_RELEASE(expr,msg,...)		if( (expr)){(expr)->Release();}
#	define NPL_ASSERT_MESSAGE(expr,msg,...)		(void)(expr)
#	define NPL_DEBUG_MESSAGE(msg,...)			(void)(0)
#	define NPL_ASSERT_POINTER(expr)				(void)(expr)
#	define NPL_VERIFY(expr)						(void)(expr)
#endif

// for signed
typedef signed char			sint8_t;
typedef short				sint16_t;
typedef int					sint32_t;
typedef long long			sint64_t;

#ifndef __STDINT_H_USING_SYS__
typedef unsigned char		uint8_t;
typedef unsigned short		uint16_t;
typedef unsigned int		uint32_t;
typedef unsigned long long	uint64_t;
#endif

// for real
typedef float				real32_t;
typedef double				real64_t;
typedef long double			real128_t;

// for words
typedef uint8_t				byte_t;
typedef uint16_t			word_t;
typedef uint32_t			quat_t;

// for string
typedef const char*			cstr_t;
typedef char*				pstr_t;

typedef const wchar_t*		cwstr_t;
typedef wchar_t*			pwstr_t;

// for buffer
typedef const byte_t*		cbyte_t;
typedef byte_t*				pbyte_t;

typedef const void*			cvoid_t;
typedef void*				pvoid_t;

#endif // __NPL_MACRO_H__
