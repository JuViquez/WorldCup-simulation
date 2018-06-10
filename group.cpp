#include "group.h"
#include "team.h"
#include <cstdint>
#include <string>
#include <iostream>
#include <random>

using namespace std;

group::group(team* t1,team* t2,team* t3,team* t4)
{
    this->team1=t1;
    this->team2=t2;
    this->team3=t3;
    this->team4=t4;
}

void group::generateMatch(team* t1, team* t2){
    double porcentage = ((t1->rating*100)/(t1->rating+t2->rating))-10;
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(0,100);
    int random_integer = uni(rng);
    cout <<t1->name<<"-"<<t2->name <<porcentage;;
    for (int i = 0; i < 10; i++){
        cout<<random_integer<<endl;
        random_integer = uni(rng);
    }
}

void group::generateGroupResults(){
    generateMatch(this->team1,this->team2);
}

group::~group()
{
    //dtor
}
