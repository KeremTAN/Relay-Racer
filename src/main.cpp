#include <iostream>
#include "Racer.hpp"
#include "Team.hpp"

int main(int argc, char** argv){
    std::mutex mtx;
    std::condition_variable cv;
    std::vector<Team> teams(1);

    std::cout<<sizeof(Racer)<<std::endl;

    for(const auto& team : teams) {
        std::cout<<team;
    }

    for (auto& team : teams) {
        team.startRace();
    }
    std::cout<<teams[0];
}