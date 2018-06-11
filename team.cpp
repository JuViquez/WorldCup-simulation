#include "team.h"
#include <string>
#include <iostream>
using namespace std;

team::team(team* t){
    this->name = t->name;
    this->position = t->position;
    this->totalPts = t->totalPts;
    this->rating= t->rating;
    this->pts= t->pts;
    this->first= t->first;
    this->second= t->second;
    this->third= t->third;
    this->fourth= t->fourth;
}

team::team(string nameArg, int ratingArg)
{
    this->name = nameArg;
    this->position = 0;
    this->totalPts = 0;
    this->rating=ratingArg;
    this->pts=0;
    this->first=0;
    this->second=0;
    this->third=0;
    this->fourth=0;
}

team::~team()
{
    //dtor
}
