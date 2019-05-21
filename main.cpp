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
        "Rochie",
        "Camasa",
        "Paltoan",
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


bool isGoodtoWash(cloth& check, washingMachine& checker, int i)
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

bool isGoodtoDrain(cloth& check, drainingMachine& checker, int i)
{
    if((getFillingStatus<drainingMachine>(checker) + check.weight < getCapacity<drainingMachine>(checker)) )
    {

        checker.fillingStatus += check.weight;
        check.stance = 2;
        check.machine = i;
        return true;
    }
    else
    {

        return false;

        }
}

bool isGoodtoDry(cloth& check, dryMachine& checker, int i)
{
    if((getFillingStatus<dryMachine>(checker)< getCapacity<dryMachine>(checker)) )
    {

        checker.fillingStatus ++;
        check.stance = 3;
        check.machine = i;
        return true;
    }
    else
    {

        return false;

        }
}

bool isGoodtoIron(cloth& check)
{
    if(check.dry)
        return true;
    else
        return false;
}

int main() {

    ifstream in;
    in.open("intrare.txt");
    vector <cloth> clothes;
    vector <washingMachine> wMachine;
    vector <drainingMachine> dMachine;
    vector <dryMachine> drMachine;
    vector <int> ironStation;

    int cCounter;

    wMachine.push_back({3000, 60});
    wMachine.push_back({15000, 50});

    dMachine.push_back({3000, 50});
    dMachine.push_back({7000, 30});

    int x,z,y;
    bool w;
    string type;;

    int counter = 1;

    while(counter == 1)
    {
        cout<<"Adauga item"<<" Da/Nu";
        cin>>type;
        if(type=="Da")
        {
            cout<<"Nume item: ";
            cin>>type;
            cout<<"Greutate: ";
            cin>>x;
            cout<<"Culoare: ";
            cin>>y;
            cout<<"Temperatura spalare: ";
            cin>>z;

//            cloth temp(x,getClothType(type),z,y);
//            clothes.push_back(temp);

            clothes.push_back({x,getClothType(type),z,y});

        }
        else
            counter = 0;
    }




         for(int j=0; j<clothes.size(); j++){
                if(clothes[j].stance ==0 && clothes[j].washed == false)
                    {
                    for(int i=0; i<wMachine.size(); i++)
                        if(!wMachine[i].isWorking && isGoodtoWash(clothes[j], wMachine[i], i) == true)
                            {
                                wMachine[i].check();
                                break;
                            }

                    }
                }

        for(int i=0 ;i<wMachine.size(); i++)
        {
            if(!getIsWorking<washingMachine>(wMachine[i]) && getFillingStatus<washingMachine>(wMachine[i])>0)
                wMachine[i].isWorking = true;
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

                            }
                        }
            }

        for(int i=0; i<clothes.size(); i++)
        {
            if(clothes[i].washed = true)
                cout<<"Spalat "<<clothType[clothes[i].clothType]<<" la temperatura "<<clothes[i].washTemp<<"\n";
        }




        cout<<"\n";



        for(int j=0; j<clothes.size(); j++){
                if(clothes[j].stance ==1 && clothes[j].drain == false)
                    {
                    for(int i=0; i<dMachine.size(); i++)
                        if(!dMachine[i].isWorking && isGoodtoDrain(clothes[j], dMachine[i], i) == true)
                            {
                                dMachine[i].check();
                                break;
                            }

                    }
                }

        for(int i=0 ;i<dMachine.size(); i++)
        {
            if(!getIsWorking<drainingMachine>(dMachine[i]) && getFillingStatus<drainingMachine>(dMachine[i])>0)
                dMachine[i].isWorking = true;
        }

        for(int i=0; i<dMachine.size(); i++)
            {
                if(getIsWorking<drainingMachine>(dMachine[i])){
                    dMachine[i].isWorking = false;
                    for(int j=0 ;j<clothes.size(); j++)
                        if(clothes[j].machine == i)
                            {
                            clothes[j].machine = NULL;
                            clothes[j].drain = true;


                            }
                        }
            }

        for(int i=0; i<clothes.size(); i++)
        {
            if(clothes[i].drain = true)
                cout<<"Stors "<<clothType[clothes[i].clothType]<<"\n";
        }

        cout<<"\n";

        for(int j=0; j<clothes.size(); j++){
                if(clothes[j].stance ==2 && clothes[j].dry == false)
                    {
                    for(int i=0; i<drMachine.size(); i++)
                        if(!drMachine[i].isWorking && isGoodtoDry(clothes[j], drMachine[i], i) == true)
                            {
                                drMachine[i].check();
                                break;
                            }

                    }
                }

        for(int i=0 ;i<drMachine.size(); i++)
        {
            if(!getIsWorking<dryMachine>(drMachine[i]) && getFillingStatus<dryMachine>(drMachine[i])>0)
                drMachine[i].isWorking = true;
        }

        for(int i=0; i<drMachine.size(); i++)
            {
                if(getIsWorking<dryMachine>(drMachine[i])){
                    drMachine[i].isWorking = false;
                    for(int j=0 ;j<clothes.size(); j++)
                        if(clothes[j].machine == i)
                            {
                            clothes[j].machine = NULL;
                            clothes[j].dry = true;


                            }
                        }
            }

        for(int i=0; i<clothes.size(); i++)
        {
            if(clothes[i].dry = true)
                cout<<"Uscat "<<clothType[clothes[i].clothType]<<"\n";
        }

        cout<<"\n";

        for(int i=0 ;i<clothes.size(); i++)
            if(isGoodtoIron(clothes[i]))
                cout<<"Calcat "<<clothType[clothes[i].clothType]<<"\n";











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
