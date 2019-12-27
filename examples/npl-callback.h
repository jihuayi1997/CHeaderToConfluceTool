///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 Boltrend China
/// All right reserved
///
/// \file npl-callback.h
///
/// \brief NPL Callback deinfed
///

#ifndef __NPL_CALLBACK_H__
#define __NPL_CALLBACK_H__

namespace npl
{
	extern NPL_API bool RegistEvent(long iEvent, NplEventCallBack cb);
	extern NPL_API void UnRegistEvent(long iEvent);

	extern NPL_API bool RegistGameServerEvent(long iEvent, NplEventCallBack cb);
	extern NPL_API void UnRegistGameServerEvent(long iEvent);

	struct INplCallback
	{
		virtual void Invoke(long err, pvoid_t params) = 0;
	};

	template<class T>
	struct NplCallback : public INplCallback
	{
		T mObj;

		NplCallback(T &_Obj)
			: mObj(_Obj)
		{

		}

		NplCallback(const T &_Obj)
			: mObj(_Obj)
		{

		}

		virtual void Invoke(long err, pvoid_t params)
		{
			mObj(err, params);
		}
	};

	template<class C>
	struct NplCallback<void (C::*)(long, pvoid_t)> : public INplCallback
	{
		typedef void (C::* F)(long, pvoid_t);
		C *mClass;
		F  mFunc;

		NplCallback(F _MemberFunc, C* _Class)
			: mClass(_Class)
			, mFunc(_MemberFunc)
		{

		}

		void Invoke(long err, pvoid_t params)
		{
			(mClass->*mFunc)(err, params);
		}
	};

	template<>
	struct NplCallback<void(*)(long, pvoid_t)> : public INplCallback
	{
		typedef void (*F)(long, pvoid_t);

		F mFunc;
		NplCallback(F _Func)
			: mFunc(_Func)
		{

		}

		virtual void Invoke(long err, pvoid_t params)
		{
			mFunc(err, params);
		}
	};

	template<class C, class T >
	struct NplMemberCallback : public INplCallback
	{
		typedef void (C::* F)(long, pvoid_t);
		C *mClass;
		F  mFunc;

		NplMemberCallback(F _MemberFunc, C* _Class)
			: mClass(_Class)
			, mFunc(_MemberFunc)
		{
			RegistEvent(T::iEvtType, this);
		}

		~NplMemberCallback()
		{
			UnRegistEvent(T::iEvtType);
		}

		virtual void Invoke(long err, pvoid_t params)
		{
			(mClass->*mFunc)(err, params);
		}
	};
}

//auto registers/unregisters a callback member function
#define  NPL_MEMBER_CALLBACK(thisclass, paramclass, func) \
struct cb_##func : private INplCallback \
{\
	cb_##func()\
	{\
		RegistEvent(paramclass::iEvtType, this);\
	}\
	~cb_##func()\
	{\
		UnRegistEvent(paramclass::iEvtType);\
	}\
	virtual void Invoke(long err, pvoid_t params)\
	{\
		thisclass* pAddr = reinterpret_cast<thisclass*>(reinterpret_cast<char*>(this) - offsetof(thisclass, m_Callback_##func)); \
	    pAddr->func( err, params ); \
	}\
} m_Callback_##func; void func(long err, void* param);

//auto registers/unregisters a specific callback member function
#define  NPL_MEMBER_CALLBACK_EX(thisclass, paramclass, func, var) \
npl::NplMemberCallback<thisclass, paramclass> var; void func(long err, void* param)


//auto registers/unregisters a callback member function
#define  NPL_GAMESERVER_CALLBACK(thisclass, paramclass, func) \
struct cb_gameserver_##func : private INplCallback \
{\
	cb_gameserver_##func()\
	{\
		RegistGameServerEvent(paramclass::iEvtType, this);\
	}\
	~cb_gameserver_##func()\
	{\
		UnRegistGameServerEvent(paramclass::iEvtType);\
	}\
	virtual void Invoke(long err, pvoid_t params)\
	{\
		thisclass* pAddr = reinterpret_cast<thisclass*>(reinterpret_cast<char*>(this) - offsetof(thisclass, m_GameServerCallback_##func)); \
	    pAddr->func( err, params ); \
	}\
} m_GameServerCallback_##func; void func(long err, void* param);

//auto registers/unregisters a specific callback member function
#define  NPL_GAMESERVER_CALLBACK_EX(thisclass, paramclass, func, var) \
npl::NplMemberCallback<thisclass, paramclass> var; void func(long err, void* param)

#endif // __NPL_CALLBACK_H__
