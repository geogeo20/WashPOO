class drainingMachine{

public:
    int maxCapacity, workTime;
    bool isWorking;
    drainingMachine();
    drainingMachine(int, int);
    ~drainingMachine();
    int fillingStatus, timeLeft;

    void check();

};
