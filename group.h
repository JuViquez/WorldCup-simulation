#ifndef GROUP_H
#define GROUP_H
#include "team.h"
#include <algorithm>
#include <vector>

class group
{
    public:
        group(team* t1,team* t2,team* t3,team* t4);
        void generateMatch(int t1, int t2);
        void generateGroupResults();
        vector<team*> teams;
        virtual ~group();
    protected:
    private:
};

#endif // GROUP_H
