#ifndef TEAM_HPP
#define TEAM_HPP

#include "Racer.hpp"
#include <thread>

class Team {
public:
    static unsigned int counter;

    Team()
        :m_team_id(++counter) {};

    friend std::ostream& operator<<(std::ostream& os, const Team& team);

    void startRace();
    void race();
    
private:
    Racer m_racer{};
    unsigned int m_team_id{};
};

#endif