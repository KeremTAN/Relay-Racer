#ifndef RACER_HPP
#define RACER_HPP

#include <iostream>
#include <random>

class Racer {
public:
    Racer(const unsigned int& position=0)
        :m_position(position), m_distribution(1, 5) {}

    friend std::ostream& operator<<(std::ostream& os, const Racer& racer);

    void operator()();
    
    unsigned int getPosition() const;
    unsigned int getVelocity() const;
    unsigned int getActiveRacer() const;
        
private:
    //const unsigned int m_team_number;
    unsigned int m_position{};
    unsigned int m_active_racer{1};
    unsigned int m_velocity{0};
    std::mt19937 m_velocityGenerator;
    std::uniform_int_distribution<unsigned char> m_distribution;
};

#endif