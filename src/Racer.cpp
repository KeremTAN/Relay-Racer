#include "Racer.hpp"

std::ostream& operator<<(std::ostream& os, const Racer& racer) {
    os <<"Team number: " <<racer.m_team_number<<
    " Racer's Position: "<<racer.m_position<<
    " Racer's Velocity"<< racer.m_velocity<<'\n';
    return os;
}