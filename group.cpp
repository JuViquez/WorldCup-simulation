#include "group.h"
#include "team.h"
#include <cstdint>
#include <string>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

group::group(team* t1,team* t2,team* t3,team* t4)
{
    this->teams.push_back(t1);
    this->teams.push_back(t2);
    this->teams.push_back(t3);
    this->teams.push_back(t4);
}

void group::generateMatch(int t1, int t2){
    double porcentage = ((this->teams[t1]->rating*100)/(this->teams[t1]->rating+this->teams[t2]->rating))-10;
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(0,100);
    int random_int = uni(rng);
    if (random_int<21){
        //empate
        this->teams[t1]->pts++;
        this->teams[t2]->pts++;
    }else if(random_int<21+porcentage){
        //gana team 1
        this->teams[t1]->pts = this->teams[t1]->pts + 3;
    }else{
        //gana team 2
        this->teams[t1]->pts = this->teams[t1]->pts + 3;
    }
    /*
    cout <<"porcentaje "<<porcentage<<endl;
    for (int i = 0; i < 10; i++){
        cout<<random_integer<<endl;
        random_integer = uni(rng);
    }*/
}

void group::generateGroupResults(){
    generateMatch(0,1);
    cout <<"Name of the team "<< this->teams[0]->name;
}

group::~group()
{
    //dtor
}
