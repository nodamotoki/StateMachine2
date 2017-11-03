
TARGET = STM_Test
SRC += STM_StateMachine.cpp
SRC += STM_Test.cpp
CFLAG += -g -Wall
DFLAG += -DSTM_DEBUG_ON


all:
	g++ $(CFLAG) $(DFLAG) $(SRC) -o $(TARGET)
