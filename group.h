#ifndef GROUP_H
#define GROUP_H
#include "team.h"

class group
{
    public:
        group(team* t1,team* t2,team* t3,team* t4);
        void generateMatch(team* t1, team* t2);
        void generateGroupResults();
        team* team1;
        team* team2;
        team* team3;
        team* team4;
        virtual ~group();
    protected:
    private:
};

#endif // GROUP_H
