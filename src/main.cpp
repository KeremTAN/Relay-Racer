#include <iostream>

#include "Team.hpp"
#include "InputReader.hpp"

int main(int argc, char** argv){

    std::vector<Team> teams(400);
    std::vector<int> printableTeams{};
    Racer::s_config = std::make_unique<Config>();

    std::vector<std::thread> threads;
    threads.reserve(400);

    if(InputReader{}.selectPrintableTeams(argc, argv, printableTeams) == 1)
        return 1;

    for(const int& printableTeamIx : printableTeams)
        teams[printableTeamIx].setPrintable(1);

    for (int i = 0; i < teams.size(); ++i) {
        threads.emplace_back([&teams, i]() { teams[i](); });
    }

    for (std::thread& team : threads) {
        team.join();
    }

    Team::printChampions();

    return 0;
}