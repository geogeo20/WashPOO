#include <iostream>
#include <list>
#include <fstream>
#include <vector>
#include "cloth.h"
#include "washMachine.h"
#include "drainMachine.h"
#include "dryMachine.h"

using namespace std;

string clothType[6] = {
        "Pantaloni",
        "Rochii",
        "Camasi",
        "Paltoane",
        "Geaca",
        "Costum"
};

int getClothType(string type){
    for(int i=0; i<6; i++)
        if(!type.compare(clothType[i]))
            return i;
    return 0;
}

template <class T>
int getCapacity(T a)
{
	return a.maxCapacity;
}
template <class T>
int getWorkTime(T a)
{
	return a.workTime;
}
template <class T>
bool getIsWorking(T a)
{
	return a.isWorking;
}
template <class T>
int getFillingStatus(T a)
{
	return a.fillingStatus;
}
template <class T>
int getWashTemp(T a)
{
	return a.washTemp;
}


bool isGood(cloth& check, washingMachine& checker, int i)
{
    if(getFillingStatus<washingMachine>(checker) == 0)
        {

            checker.fillingStatus += check.weight;
            checker.washTemp = check.washTemp;
            check.stance = 1;
            check.machine = i;
            return true;
        }
    else if((getFillingStatus<washingMachine>(checker) + check.weight < getCapacity<washingMachine>(checker)) && getWashTemp<washingMachine>(checker) == check.washTemp)
    {

        checker.fillingStatus += check.weight;
        check.stance = 1;
        check.machine = i;
        return true;
    }
    else
    {

        return false;

        }
}

int main() {

    ifstream in;
    in.open("intrare.txt");
    vector <cloth> clothes;
    vector <washingMachine> wMachine;
    vector <drainingMachine> dMachine;
    vector <dryMachine> dryMachine;
    vector <int> ironStation;

    int cCounter;

    wMachine.push_back({3000, 60});
    wMachine.push_back({15000, 50});

    int x,y,z;
    bool w;

    int counter = 0;

    while(counter == 0)
    {
        in>>x>>y>>z>>w;
        clothes.push_back({x,y,z,w});
        in>>counter;
    }

    counter = 0;


         for(int j=0; j<clothes.size(); j++){
                if(clothes[j].stance ==0 && clothes[j].washed == false)
                    {
                    for(int i=0; i<wMachine.size(); i++)
                        if(!wMachine[i].isWorking && isGood(clothes[j], wMachine[i], i) == true)
                            {
                                wMachine[i].check();
                                break;
                            }

                    }
                }
        for(int i=0; i<wMachine.size(); i++)
            {
                if(getIsWorking<washingMachine>(wMachine[i])){
                    wMachine[i].isWorking = false;
                    for(int j=0 ;j<clothes.size(); j++)
                        if(clothes[j].machine == i)
                            {
                            clothes[j].machine = NULL;
                            clothes[j].washed = true;
                            counter++;

                            }
                        }
            }

        for(int i=0 ;i<clothes.size(); i++)
        {
            if(clothes[i].washed){
                cout<<"Spalat"<<"\n";

            }
        }







//        if(clothes[i].stance == 1 && isHeavy(clothes[i]) )
//        {
//            for(int i=0; i<dMachine.size(); i++)
//                if(dMachine.isGood(clothes[i]))
//                    //do something
//                    break;
//        }
//        if(clothes[i].stace == 2)
//        {
//            for(int i=0; i<dryMachine.size(); i++)
//                if(dryMachine[i].isGood(clothes[i]))
//                    //do somehting
//                    break;
//        }







    return 0;
}
