/**
 * @file STM_StateMachine.cpp
 * @brief State Machine System
 * @author nodamotoki
 */

#include <stdio.h>
#include "STM_StateMachine.h"

STM_StateMachine::STM_StateMachine()
	: stateList_(NULL),
	  stateNum_(0),
	  state_(NULL),
	  eventID_(STM_INVALID_EVENT_ID)
{
	STM_PRINT_FN();
}

void STM_StateMachine::init(STM_State* stateList[], size_t stateNum)
{
	STM_DEBUG_PRINT("stateList=%p, stateNum=%d\n", stateList, stateNum);
	stateList_ = stateList;
	stateNum_ = (int16_t)stateNum;
}

int16_t STM_StateMachine::setInitialState(int16_t initialStateID)
{
	STM_DEBUG_PRINT("initialStateID=%d\n", initialStateID);
	STM_State* initialState = searchState(initialStateID);
	if (! initialState) {
		STM_DEBUG_PRINT("initialState is null\n");
		return STM_STATE_ERROR;
	}
	state_ = initialState;
	return STM_OK;
}

void STM_StateMachine::setEventID(int16_t eventID)
{
	STM_DEBUG_PRINT("eventID=%d\n", eventID);
	eventID_ = eventID;
}

int16_t STM_StateMachine::run()
{
	STM_PRINT_FN();
	if (! state_) {
		STM_DEBUG_PRINT("state_ is null\n");
		return STM_STATE_ERROR;
	}

	int16_t nextStateID = state_->run(eventID_);
	eventID_ = STM_INVALID_EVENT_ID;			/* 毎回クリア */

	STM_State* nextState = searchState(nextStateID);
	if (nextState) {
		if (state_->id() != nextState->id()) {
			state_->exit();
			state_ = nextState;
			state_->enter();
		}
	}

	return STM_OK;
}

int16_t STM_StateMachine::getStateID()
{
	STM_PRINT_FN();
	if (! state_) {
		return STM_INVALID_STATE_ID;
	}

	return state_->id();
}

STM_State* STM_StateMachine::searchState(int16_t stateID)
{
	STM_DEBUG_PRINT("stateID=%d\n", stateID);
	for (int i = 0; i < stateNum_; ++i) {
		STM_State* state = stateList_[i];
		if (state->id() == stateID) {
			return state;
		}
	}
	return NULL;
}
