#ifndef TEAM_HPP
#define TEAM_HPP

#include "Racer.hpp"
#include <thread>

class Team {
public:
    static unsigned int counter;

    Team();

    friend std::ostream& operator<<(std::ostream& os, const Team& team);

    void startRace();
    void race();
    
private:
    std::vector<Racer> m_racers;
    unsigned int m_team_id{};
    bool isPrintable{1};
};

#endif