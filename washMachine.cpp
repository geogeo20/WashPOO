#include "washMachine.h"
washingMachine::washingMachine(int weight, int time) {
    this->maxCapacity = weight;
    this->workTime = time;
    this->isWorking = false;
    this->fillingStatus = 0;
    this->timeLeft = 0;
}
washingMachine::washingMachine() = default;
washingMachine::~washingMachine() = default;





void washingMachine::check()
{
    if(fillingStatus > maxCapacity/2)
        isWorking = true;
}


