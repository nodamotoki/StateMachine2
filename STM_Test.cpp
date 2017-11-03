/**
 * @file STM_Test.cpp
 * @brief State Machine System
 * @author nodamotoki
 */

#define STM_STATE_MACHINE_TEST_ON
#ifdef STM_STATE_MACHINE_TEST_ON
#include <stdio.h>
#include <stdlib.h>
#include "STM_StateMachine.h"

/******************************************************************************/
/* Macro Function                                                             */
/******************************************************************************/


/******************************************************************************/
/* Constant                                                                   */
/******************************************************************************/
enum {
	STATE_0,
	STATE_1,
	STATE_2,
	MAIN_STATE_NUM
};

enum {
	EVENT_0,
	EVENT_1,
	EVENT_2,
	MAIN_EVENT_NUM
};


/******************************************************************************/
/* Type                                                                       */
/******************************************************************************/





/******************************************************************************/
/* State0                                                                     */
/******************************************************************************/
class STM_State0 : public STM_State
{
public:
	STM_State0();
	void init();
	virtual ~STM_State0();
	virtual void enter();
	virtual int16_t run(int16_t eventID);
	virtual void exit();
	virtual int16_t id();
};

STM_State0::STM_State0()
{
	STM_PRINT_FN();
}

void STM_State0::init()
{
	STM_PRINT_FN();
}

STM_State0::~STM_State0()
{
	STM_PRINT_FN();
}

void STM_State0::enter()
{
	STM_PRINT_FN();
}

int16_t STM_State0::run(int16_t eventID)
{
	//STM_PRINT_FN();
	STM_DEBUG_PRINT("eventID=%d\n", eventID);
	switch (eventID) {
	case EVENT_0:
		return STATE_1;
		break;
	case EVENT_1:
		break;
	case EVENT_2:
		break;
	default:
		break;
	}
	return id();
}

void STM_State0::exit()
{
	STM_PRINT_FN();
}

int16_t STM_State0::id()
{
	return STATE_0;
}

/******************************************************************************/
/* State1                                                                    */
/******************************************************************************/
class STM_State1 : public STM_State
{
public:
	STM_State1();
	void init();
	virtual ~STM_State1();
	virtual void enter();
	virtual int16_t run(int16_t eventID);
	virtual void exit();
	virtual int16_t id();
};

STM_State1::STM_State1()
{
	STM_PRINT_FN();
}

void STM_State1::init()
{
	STM_PRINT_FN();
}

STM_State1::~STM_State1()
{
	STM_PRINT_FN();
}

void STM_State1::enter()
{
	STM_PRINT_FN();
}

int16_t STM_State1::run(int16_t eventID)
{
	//STM_PRINT_FN();
	STM_DEBUG_PRINT("eventID=%d\n", eventID);
	switch (eventID) {
	case EVENT_0:
		break;
	case EVENT_1:
		return STATE_2;
		break;
	case EVENT_2:
		break;
	default:
		break;
	}
	return id();
}

void STM_State1::exit()
{
	STM_PRINT_FN();
}

int16_t STM_State1::id()
{
	return STATE_1;
}


/******************************************************************************/
/* State2                                                                    */
/******************************************************************************/
class STM_State2 : public STM_State
{
public:
	STM_State2();
	void init();
	virtual ~STM_State2();
	virtual void enter();
	virtual int16_t run(int16_t eventID);
	virtual void exit();
	virtual int16_t id();
};

STM_State2::STM_State2()
{
	STM_PRINT_FN();
}

void STM_State2::init()
{
	STM_PRINT_FN();
}

STM_State2::~STM_State2()
{
	STM_PRINT_FN();
}

void STM_State2::enter()
{
	STM_PRINT_FN();
}

int16_t STM_State2::run(int16_t eventID)
{
	//STM_PRINT_FN();
	STM_DEBUG_PRINT("eventID=%d\n", eventID);
	switch (eventID) {
	case EVENT_0:
		break;
	case EVENT_1:
		break;
	case EVENT_2:
		return STATE_0;
		break;
	default:
		break;
	}
	return id();
}

void STM_State2::exit()
{
	STM_PRINT_FN();
}

int16_t STM_State2::id()
{
	return STATE_2;
}


/******************************************************************************/
/* StateMachine Controller                                                    */
/******************************************************************************/
class Controller
{
public:
	Controller();
	~Controller();
	void run(int16_t eventID);
private:
	STM_StateMachine	stm_;
	STM_State0			state0_;
	STM_State1			state1_;
	STM_State2			state2_;
	STM_State*			stateList_[MAIN_STATE_NUM];
};

Controller::Controller()
{
	STM_PRINT_FN();

	state0_.init();
	state1_.init();
	state2_.init();
	stateList_[0] = &state0_;
	stateList_[1] = &state1_;
	stateList_[2] = &state2_;
	stm_.init(stateList_, COUNTOF(stateList_));
	stm_.setInitialState(state0_.id());
}

Controller::~Controller()
{
	STM_PRINT_FN();

}

void Controller::run(int16_t eventID)
{
	STM_PRINT_FN();

	stm_.setEventID(eventID);
	stm_.run();
}


/******************************************************************************/
/* Function                                                                   */
/******************************************************************************/
int main(int argc, char *argv[])
{
	char buf[100];
	Controller c;

	while (fgets(buf, sizeof(buf), stdin)) {
		int16_t eventID = (int16_t) strtol(buf, NULL, 0);
		c.run(eventID);
	}

	return 0;
}

#endif /* STM_STATE_MACHINE_TEST_ON */
