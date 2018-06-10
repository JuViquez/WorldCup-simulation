#include <cstdint>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "team.h"
#include "group.h"

using namespace std;
/*
bool sortByRating(team &A, team &B){
    return (A.rating < B.rating);
}*/

int main(){

    //team* equipo1 = new team("Brazil",43);
    group* group1 = new group(new team("Brazil",92),new team("Serbia",72),new team("Suiza",73),new team("Costa Rica",85));
    //cout << "Nombre "<<group1->team1->name;
    group1->generateGroupResults();
    for(int i = 0; i<4;i++){
        cout << " team number "<<i<<group1->teams[i]->name<<endl;
    }
    cout << "-------------------------------" <<endl;
    sort(group1->teams.begin(),group1->teams.end(),[](const team* lhs, const team* rhs){return lhs->pts > rhs->pts;});
    //group1->teams.sort(sortByRating);
    for(int i = 0; i<4;i++){
        cout << " team "<<i<<group1->teams[i]->name << " points " <<group1->teams[i]->pts <<endl;
    }
return 0;
}
