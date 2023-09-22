#include "Team.hpp"

unsigned int Team::counter = 0;

std::ostream& operator<<(std::ostream& os, const Team& team){
    return os<<team.m_team_id<<". Team, "<<team.m_racer;
}

void Team::startRace() {
    m_racer.race();
}