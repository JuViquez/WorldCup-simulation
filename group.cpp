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
        this->teams[t1]->pts++;
        this->teams[t2]->pts++;
    }else if(random_int<21+porcentage){
        this->teams[t1]->pts = this->teams[t1]->pts + 3;
    }else{
        this->teams[t2]->pts = this->teams[t2]->pts + 3;
    }
}

void group::generateGroupResults(){
    generateMatch(0,1);
    generateMatch(2,3);
    generateMatch(0,3);
    generateMatch(2,1);
    generateMatch(0,2);
    generateMatch(1,3);
    sort(this->teams.begin(),this->teams.end(),[](const team* lhs, const team* rhs){return lhs->pts > rhs->pts;});
    for(int i = 0; i<4;i++){
        //cout << " team "<<i<<group1->teams[i]->name << " points " <<group1->teams[i]->pts <<endl;
        this->teams[i]->totalPts = this->teams[i]->pts + this->teams[i]->totalPts;
        if(i==0){
            this->teams[i]->first++;
        }if(i==1){
            this->teams[i]->second++;
        }if(i==2){
            this->teams[i]->third++;
        }else{
            this->teams[i]->fourth++;
        }
        this->teams[i]->pts = 0;
    }
}

group::~group()
{
    //dtor
}
