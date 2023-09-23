#include <iostream>
#include "Team.hpp"

int main(int argc, char** argv){
    std::mutex mtx;
    std::condition_variable cv;
    std::vector<Team> teams(1);

    //std::cout<<teams[0];
    teams[0].startRace();
    //std::cout<<teams[0];
}