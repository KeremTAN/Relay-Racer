#ifndef TEAM_HPP
#define TEAM_HPP

#include "Racer.hpp"

class Team {
public:
    Team()
        :m_team_id(++counter) {};

    friend std::ostream& operator<<(std::ostream& os, const Team& team);

    void startRace();
    
private:
    Racer m_racer{};
    unsigned int m_team_id{};
    static unsigned int counter;
};

#endif