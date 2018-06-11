#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <iostream>
using namespace std;
class team
{
    public:
	team(team* t);
        team(string nameArg, int ratingArg);
        virtual ~team();
        string name;
        int position;
        int totalPts;
        int pts;
        int rating;
        int first;
        int second;
        int third;
        int fourth;
    protected:
    private:
};

#endif // TEAM_H
