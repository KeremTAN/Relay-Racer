#include <iostream>
#include "Team.hpp"

int main(int argc, char** argv){
    std::vector<Team> teams(5);
    std::vector<int> printableTeams {0, 2, 3};

    for(const int&  printableTeamIx: printableTeams)
        teams[printableTeamIx].setPrintable(1);

    

    for(auto it =Team::championsList.begin(); it!=Team::championsList.end(); ++it)
         std::cout<<"The team id that comes "<<" is "<<it->second<<'\n';
    

    //std::cout<<teams[0];
    //teams[2].startRace();
    //teams[3].startRace();
    //std::cout<<teams[0];

    //std::cout<<sizeof(Racer)<<std::endl;
}