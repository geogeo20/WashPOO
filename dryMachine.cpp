#include "dryMachine.h"
dryMachine::dryMachine(int cloth, int time) {
    this->maxCapacity = cloth;
    this->workTime = time;
    this->isWorking = false;
    this->fillingStatus = 0;
    this->timeLeft = 0;
}

dryMachine::dryMachine() = default;
dryMachine::~dryMachine() = default;


void dryMachine::check()
{
    if(fillingStatus > maxCapacity/2)
        isWorking = true;
}



