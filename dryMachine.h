
class dryMachine{

public:
    int maxCapacity, workTime;
    bool isWorking;
    dryMachine();
    dryMachine(int, int);
    ~dryMachine();
    int fillingStatus, timeLeft;

    void check();

};
