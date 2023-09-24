#include <iostream>
#include "Team.hpp"

int main(int argc, char** argv){

    std::vector<Team> teams(400);
    std::vector<std::thread> threads;
    Team::config = std::make_unique<Config>();

    std::vector<int> printableTeams {0, 2, 5, 7};

    for(const int&  printableTeamIx: printableTeams)
        teams[printableTeamIx].setPrintable(1);

    threads.reserve(400);
    for (int i = 0; i < teams.size(); ++i) {
        threads.emplace_back([&teams, i]() { teams[i](); });
    }

    for (std::thread& team : threads) {
        team.join();
    }

    Team::printChampions();
}