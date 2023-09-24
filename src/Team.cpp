#include "Team.hpp"

unsigned int Team::counter = 0;

Team::Team()
    :m_team_id(++counter) {

    m_racers.reserve(4);

    for(int i{1}; i<5; i++)
        m_racers.emplace_back(Racer(i));
}

std::ostream& operator<<(std::ostream& os, const Team& team) {
    return os<<"---------------------------- "
    <<team.m_team_id<<". Team ------------------------------\n"
    <<team.m_racers[0]<<team.m_racers[1]<<team.m_racers[2]<<team.m_racers[3]
    <<"-------------------------------------------------------------------\n";
}

void Team::startRace() {

    m_racers[0].race(nullptr, this);

    for(int i{1}; i < m_racers.size(); i++) {
        m_racers[i].race(&m_racers[i-1], this);
    }
}

bool Team::isPrintable() const { return m_printable; }

void Team::setPrintable(const bool& isPrintable) const { m_printable=isPrintable; }