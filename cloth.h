
class cloth {
public:
    int weight, clothType, washTemp;
    bool color;
    bool washed = false;
    bool drain = false;
    bool dry = false;
    int machine;
    cloth();
    cloth(int, int, int, bool);
    ~cloth();
    int stance;
    int print();
};

