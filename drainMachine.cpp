#include "drainMachine.h"
drainingMachine::drainingMachine(int weight, int time) {
    this->maxCapacity = weight;
    this->workTime = time;
    this->isWorking = false;
    this->fillingStatus = 0;
    this->timeLeft = 0;
}

drainingMachine::drainingMachine() = default;
drainingMachine::~drainingMachine() = default;


void drainingMachine::check()
{
    if(fillingStatus > maxCapacity/2)
        isWorking = true;
}
