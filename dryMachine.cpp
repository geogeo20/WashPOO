#include "dryMachine.h"
dryMachine::dryMachine(int cloth, int time) {
    this->maxCapacity = cloth;
    this->workTime = time;
    this->isWorking = false;
    this->fillingStatus = 0;
    this->timeLeft = 0;
}

dryMachine::dryMachine(){}
dryMachine::~dryMachine() = default;






