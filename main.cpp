#include <cstdint>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "team.h"
#include "group.h"

using namespace std;

int main(){


    group* group1 = new group(new team("Rusia",70),new team("Arabia",72),new team("Egipto",78),new team("Uruguay",85));
    group* group2 = new group(new team("Portugal",89),new team("Espana",93),new team("Marruecos",75),new team("Iran",74));
    group* group3 = new group(new team("Francia",90),new team("Australia",79),new team("Peru",78),new team("DInamarca",82));
    group* group4 = new group(new team("Argentina",91),new team("Islandia",75),new team("Croacia",83),new team("Nigeria",80));
    group* group5 = new group(new team("Brasil",95),new team("Serbia",72),new team("Suiza",83),new team("Costa Rica",77));
    group* group6 = new group(new team("ALemania",94),new team("Mexico",82),new team("Suecia",85),new team("Corea",76));
    group* group7 = new group(new team("Belgica",89),new team("Panama",70),new team("Tunez",78),new team("Inglaterra",87));
    group* group8 = new group(new team("Polonia",88),new team("Senegal",76),new team("Colombia",86),new team("Japon",80));

    //cout << "Nombre "<<group1->team1->name;
    for(int i = 0; i<10000;i++){
        group1->generateGroupResults();
        group2->generateGroupResults();
        group3->generateGroupResults();
        group4->generateGroupResults();
        group5->generateGroupResults();
        group6->generateGroupResults();
        group7->generateGroupResults();
        group8->generateGroupResults();
    }
    cout<<"--------------------------------------- GRUPO A --------------------------------------- "<<endl;
    sort(group1->teams.begin(),group1->teams.end(),[](const team* lhs, const team* rhs){return lhs->totalPts > rhs->totalPts;});
    for(int i = 0; i<4;i++ ){
        cout<< "TEAM -> "<<group1->teams[i]->name<<" PTS-> "<<group1->teams[i]->totalPts << " 1 lugar  " << group1->teams[i]->first << " 2 lugar " << group1->teams[i]->second << " 3 lugar " << group1->teams[i]->third << " 4 lugar "<<group1->teams[i]->fourth << endl;
    }

    cout<<"--------------------------------------- GRUPO B --------------------------------------- "<<endl;
    sort(group2->teams.begin(),group2->teams.end(),[](const team* lhs, const team* rhs){return lhs->totalPts > rhs->totalPts;});
    for(int i = 0; i<4;i++ ){
        cout<< "TEAM -> "<<group2->teams[i]->name<<" PTS-> "<<group2->teams[i]->totalPts << " 1 lugar  " << group2->teams[i]->first << " 2 lugar " << group2->teams[i]->second << " 3 lugar " << group2->teams[i]->third << " 4 lugar "<<group2->teams[i]->fourth << endl;
    }

    cout<<"--------------------------------------- GRUPO C --------------------------------------- "<<endl;
    sort(group3->teams.begin(),group3->teams.end(),[](const team* lhs, const team* rhs){return lhs->totalPts > rhs->totalPts;});
    for(int i = 0; i<4;i++ ){
        cout<< "TEAM -> "<<group3->teams[i]->name<<" PTS-> "<<group3->teams[i]->totalPts << " 1 lugar  " << group3->teams[i]->first << " 2 lugar " << group3->teams[i]->second << " 3 lugar " << group3->teams[i]->third << " 4 lugar "<<group3->teams[i]->fourth << endl;
    }

    cout<<"--------------------------------------- GRUPO D --------------------------------------- "<<endl;
    sort(group4->teams.begin(),group4->teams.end(),[](const team* lhs, const team* rhs){return lhs->totalPts > rhs->totalPts;});
    for(int i = 0; i<4;i++ ){
        cout<< "TEAM -> "<<group4->teams[i]->name<<" PTS-> "<<group4->teams[i]->totalPts << " 1 lugar  " << group4->teams[i]->first << " 2 lugar " << group4->teams[i]->second << " 3 lugar " << group4->teams[i]->third << " 4 lugar "<<group4->teams[i]->fourth << endl;
    }

    cout<<"--------------------------------------- GRUPO E --------------------------------------- "<<endl;
    sort(group5->teams.begin(),group5->teams.end(),[](const team* lhs, const team* rhs){return lhs->totalPts > rhs->totalPts;});
    for(int i = 0; i<4;i++ ){
        cout<< "TEAM -> "<<group5->teams[i]->name<<" PTS-> "<<group5->teams[i]->totalPts << " 1 lugar  " << group5->teams[i]->first << " 2 lugar " << group5->teams[i]->second << " 3 lugar " << group5->teams[i]->third << " 4 lugar "<<group5->teams[i]->fourth << endl;
    }

    cout<<"--------------------------------------- GRUPO F --------------------------------------- "<<endl;
    sort(group6->teams.begin(),group6->teams.end(),[](const team* lhs, const team* rhs){return lhs->totalPts > rhs->totalPts;});
    for(int i = 0; i<4;i++ ){
        cout<< "TEAM -> "<<group6->teams[i]->name<<" PTS-> "<<group6->teams[i]->totalPts << " 1 lugar  " << group6->teams[i]->first << " 2 lugar " << group6->teams[i]->second << " 3 lugar " << group6->teams[i]->third << " 4 lugar "<<group6->teams[i]->fourth << endl;
    }

    cout<<"--------------------------------------- GRUPO G --------------------------------------- "<<endl;
    sort(group7->teams.begin(),group7->teams.end(),[](const team* lhs, const team* rhs){return lhs->totalPts > rhs->totalPts;});
    for(int i = 0; i<4;i++ ){
        cout<< "TEAM -> "<<group7->teams[i]->name<<" PTS-> "<<group7->teams[i]->totalPts << " 1 lugar  " << group7->teams[i]->first << " 2 lugar " << group7->teams[i]->second << " 3 lugar " << group7->teams[i]->third << " 4 lugar "<<group7->teams[i]->fourth << endl;
    }

    cout<<"--------------------------------------- GRUPO H --------------------------------------- "<<endl;
    sort(group8->teams.begin(),group8->teams.end(),[](const team* lhs, const team* rhs){return lhs->totalPts > rhs->totalPts;});
    for(int i = 0; i<4;i++ ){
        cout<< "TEAM -> "<<group8->teams[i]->name<<" PTS-> "<<group8->teams[i]->totalPts << " 1 lugar  " << group8->teams[i]->first << " 2 lugar " << group8->teams[i]->second << " 3 lugar " << group8->teams[i]->third << " 4 lugar "<<group8->teams[i]->fourth << endl;
    }

return 0;
}
