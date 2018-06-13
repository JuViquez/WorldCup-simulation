#include <cstdint>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "team.h"
#include "group.h"
#include <chrono>
#include <omp.h>
#include <mpi.h>
#include <stdio.h>

using namespace std;
using  ms = chrono::milliseconds;
using get_time = chrono::steady_clock ;

void TotalPoints(group* global, group* local){
for(int x=0;x<4;x++){
for(int y = 0; y<4;y++){
    if(global->teams[x]->name == local->teams[y]->name){
        global->teams[x]->totalPts += local->teams[y]->totalPts;
        global->teams[x]->first += local->teams[y]->first;
        global->teams[x]->second += local->teams[y]->second;
        global->teams[x]->third += local->teams[y]->third;
        global->teams[x]->fourth += local->teams[y]->fourth;
        break;
    }
}
}
}

int main(int argc, char *argv[]){

    if(argc==1){
	cerr<<"ERROR: Number of threads required"<<endl;
	return 0;
    }
    if(argc==2){
	cerr<<"ERROR: Number of loops required" <<endl;
    }
    int threads_qty = atoi(argv[1]);
    int total_loops = atoi(argv[2]);
    
    group* group1 = new group(new team("Rusia",70),new team("Arabia",72),new team("Egipto",78),new team("Uruguay",85));
    group* group2 = new group(new team("Portugal",89),new team("Espana",93),new team("Marruecos",75),new team("Iran",74));
    group* group3 = new group(new team("Francia",90),new team("Australia",79),new team("Peru",78),new team("DInamarca",82));
    group* group4 = new group(new team("Argentina",91),new team("Islandia",75),new team("Croacia",83),new team("Nigeria",80));
    group* group5 = new group(new team("Brasil",95),new team("Serbia",72),new team("Suiza",83),new team("Costa Rica",77));
    group* group6 = new group(new team("ALemania",94),new team("Mexico",82),new team("Suecia",85),new team("Corea",76));
    group* group7 = new group(new team("Belgica",89),new team("Panama",70),new team("Tunez",78),new team("Inglaterra",87));
    group* group8 = new group(new team("Polonia",88),new team("Senegal",76),new team("Colombia",86),new team("Japon",80));

    auto start = get_time::now();
    
    int numprocs, rank, namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(NULL,NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Get_processor_name(processor_name, &namelen);

    cout<< "Number or processors: "<< numprocs << endl;
    int loops_per_procs = total_loops/numprocs;
    if(rank == numprocs-1 && total_loops%numprocs != 0){
	loops_per_procs += total_loops%numprocs;
    }

    omp_set_num_threads(threads_qty);
    #pragma omp parallel
    {
	    group* group1T = new group(group1);
	    group* group2T = new group(group2);
            group* group3T = new group(group3);
	    group* group4T = new group(group4);
	    group* group5T = new group(group5);
	    group* group6T = new group(group6);
	    group* group7T = new group(group7);
	    group* group8T = new group(group8);
	
	    #pragma omp for
	    for(int i = 0; i<loops_per_procs;i++){
		group1T->generateGroupResults();
		group2T->generateGroupResults();
		group3T->generateGroupResults();
		group4T->generateGroupResults();
		group5T->generateGroupResults();
		group6T->generateGroupResults();
		group7T->generateGroupResults();
		group8T->generateGroupResults();
	    }
	    #pragma omp critical
	    TotalPoints(group1, group1T);
	    #pragma omp critical
	    TotalPoints(group2, group2T);
            #pragma omp critical
	    TotalPoints(group3, group3T);
	    #pragma omp critical
	    TotalPoints(group4, group4T);
	    #pragma omp critical
	    TotalPoints(group5, group5T);
	    #pragma omp critical
	    TotalPoints(group6, group6T);
	    #pragma omp critical
	    TotalPoints(group7, group7T);
	    #pragma omp critical
	    TotalPoints(group8, group8T);

    }
    auto end = get_time::now();
    if(rank == 0){
       
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
    auto diff = end - start;
    cout<<"Elapsed time is :  "<< chrono::duration_cast<ms>(diff).count()<<" ms "<<endl;
    }
    
MPI_Finalize();
return 0;
}
