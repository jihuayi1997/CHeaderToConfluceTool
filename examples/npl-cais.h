///
/// COPYRIGHT NOTICE
/// CopyRight (c) 2018 netease China
/// All right reserved
///
/// \file npl-cais.h
///
/// \brief NPL cais functional
///
#ifndef __NPL_CAIS_H__
#define __NPL_CAIS_H__

/// 
/// \brief  防沉迷提示信息
///
enum enCAISText
{
	/// 提示：您累计在线时间已满1小时
	enCAIS_moreThanOneHour = 0,
	/// 提示：您累计在线时间已满2小时
	enCAIS_moreThanTwoHour,
	/// 提示：您累计在线时间已满3小时，请您下线休息，做适当身体活动
	enCAIS_moreThanThreeHour,
	/// 提示：您已经进入疲劳游戏时间，您的游戏收益将降为正常值的50％，为了您的健康，请尽快下线休息，做适当身体活动，合理安排学习生活
	enCAIS_moreThanFourHour,
	/// 提示：您已进入不健康游戏时间，为了您的健康，请您立即下线休息。如不下线，您的身体将受到损害，您的收益已降为零，直到您的累计下线时间满5小时后，才能恢复正常
	enCAIS_moreThanFiveHour,
	/// 提示：由于您未通过实名认证，您已经被防沉迷系统所限制
	enCAIS_start,
};

/// 
/// \brief  防沉迷收益处理
///
enum enCAISIncome
{
	/// 收益正常
	enCAIS_normal = 0,
	/// 收益减半
	enCAIS_half = 1,
	/// 收益降为0
	enCAIS_zero = 2,
	/// 收益恢复正常(同normal)
	enCAIS_recover = 3,
};

#pragma pack(push, NPL_PACK_SIZE)

///
/// \brief  用户累计时长通知结构
///
struct cbCAISInfoNotify_t
{
	enum { iEvtType = enNplCais + 4 };
	/// 当前已累计在线时长（单位:秒）
	uint32_t seconds;
	/// 防沉迷提示信息
	enCAISText text;
	/// 防沉迷收益处理
	enCAISIncome income;
	/// 应在多少秒后提示一次（值为0时无需提醒）
	uint32_t repeat;
};

#pragma pack(pop)

#endif // __NPL_CAIS_H__
