#include <iostream>
#include "Team.hpp"

int main(int argc, char** argv){

    std::vector<Team> teams(400);
    std::vector<int> printableTeams{};
    Team::s_config = std::make_unique<Config>();

    std::vector<std::thread> threads;
    threads.reserve(400);

    for (int i = 1; i < argc; ++i) {

        int teamId = std::atoi(argv[i]);

        if (teamId == 0 && argv[i][0] != '0') {
            std::cerr << "Invalid Input: " << argv[i] << " is not a number." << std::endl;
            return 1;
        }

        if (teamId < 1 || teamId > 400) {
            std::cerr << "Invalid Input: " << argv[i] << " is not a number between 1 and 400." << std::endl;
            return 1;
        }

        printableTeams.push_back(--teamId);
    }

    for(const int&  printableTeamIx: printableTeams)
        teams[printableTeamIx].setPrintable(1);

    for (int i = 0; i < teams.size(); ++i) {
        threads.emplace_back([&teams, i]() { teams[i](); });
    }

    for (std::thread& team : threads) {
        team.join();
    }

    Team::printChampions();
}