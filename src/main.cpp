#include <iostream>
#include "Team.hpp"

int main(int argc, char** argv){
    std::mutex mtx;
    std::condition_variable cv;
    std::vector<Team> teams(5);

    //std::cout<<teams[0];
    teams[2].setPrintable(1);
    teams[3].setPrintable(1);
    teams[2].startRace();
    teams[3].startRace();
    //std::cout<<teams[0];

    //std::cout<<sizeof(Racer)<<std::endl;
}