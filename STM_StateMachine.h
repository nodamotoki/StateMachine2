/**
 * @file STM_StateMachine.h
 * @brief State Machine System
 * @author nodamotoki
 */
#pragma once
#ifndef STM_STATE_MACHINE_H_INCLUDED
#define STM_STATE_MACHINE_H_INCLUDED

/******************************************************************************/
/* Macro Function                                                             */
/******************************************************************************/
#ifdef STM_DEBUG_ON
//#define STM_DEBUG_PRINT(...)		do { printf("%s:%d:%s:", __FILE__, __LINE__, __func__); printf(__VA_ARGS__); } while(0)
#define STM_DEBUG_PRINT(...)		do { printf("%s:", __PRETTY_FUNCTION__); printf(__VA_ARGS__); } while(0)
#define STM_PRINT_FN()				do { printf("%s\n", __PRETTY_FUNCTION__); } while(0)
#else
#define STM_DEBUG_PRINT(...)
#define STM_PRINT_FN()
#endif /* STM_DEBUG_ON */

#define COUNTOF(array)				(sizeof(array)/sizeof((array)[0]))
#define STM_IS_ERROR(resultValue)	((resultValue) < 0)


/******************************************************************************/
/* Constant                                                                   */
/******************************************************************************/
const int16_t STM_INVALID_STATE_ID = -1;		/* 不正な状態ID (0未満の状態IDはすべて不正) */
const int16_t STM_INVALID_EVENT_ID = -1;		/* 不正なイベントID (0未満のイベントIDもすべて不正) */

/**
 * 関数の戻り値
 */
const int16_t STM_OK					=  0;	/* OK */
const int16_t STM_RANGE_ERROR			= -1;	/* 範囲エラー */
const int16_t STM_STATE_ERROR			= -2;	/* 不正な状態ID */
const int16_t STM_EVENT_ERROR			= -3;	/* 不正なイベントID */


/******************************************************************************/
/* Class                                                                      */
/******************************************************************************/
class STM_State {
public:
	virtual void enter() = 0;
	virtual int16_t run(int16_t eventID) = 0;
	virtual void exit() = 0;
	virtual int16_t id() = 0;
	virtual ~STM_State() {}
};


class STM_StateMachine /* final */
{
public:
	STM_StateMachine();
	// virtul ~STM_StateMachine();
	void init(STM_State* stateList[], size_t stateNum);
	int16_t setInitialState(int16_t initialStateID);
	void setEventID(int16_t eventID);
	int16_t run();
	int16_t getStateID();
private:
	STM_State* searchState(int16_t stateID);
private:
	STM_State**			stateList_;				/* 状態オブジェクトのポインタの配列をさすポインタ */
	int16_t				stateNum_;				/* 状態オブジェクトの配列の要素数 */
	STM_State*			state_;					/* 現在の状態を表す状態オブジェクトへのポインタ */
	int16_t				eventID_;				/* 最後のイベントのイベントID */
};

#endif /* STM_STATE_MACHINE_H_INCLUDED */
