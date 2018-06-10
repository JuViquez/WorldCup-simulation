#include <cstdint>
#include <string>
#include <iostream>
#include "team.h"
#include "group.h"

using namespace std;

int main(){

    //team* equipo1 = new team("Brazil",43);
    group* group1 = new group(new team("Brazil",92),new team("Serbia",72),new team("Suiza",43),new team("Costa Rica",43));
    //cout << "Nombre "<<group1->team1->name;
    group1->generateGroupResults();
return 0;
}
