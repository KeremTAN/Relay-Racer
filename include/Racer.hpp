#ifndef RACER_HPP
#define RACER_HPP

#include <iostream>

class Racer {
public:
    Racer(const unsigned int& team_number=1,
        const unsigned int& position=0)
        :m_team_number(team_number), m_position(position) {}

    friend std::ostream& operator<<(std::ostream& os, const Racer& racer);
        
private:
    unsigned int m_team_number{};
    unsigned int m_position{};
    unsigned int m_velocity{};
};

#endif