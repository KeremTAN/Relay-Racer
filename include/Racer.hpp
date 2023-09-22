#ifndef RACER_HPP
#define RACER_HPP

#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <random>
#include <thread>

class Racer {
public:
    Racer(const unsigned int& position=0)
        :m_position(position) {}

    friend std::ostream& operator<<(std::ostream& os, const Racer& racer);

    void operator()();
    void race();
    
    unsigned int getPosition() const;
    unsigned int getVelocity() const;
    unsigned int getActiveRacer() const;
        
private:
    //const unsigned int m_team_number;
    unsigned int m_position{};
    unsigned int m_active_racer{1};
    unsigned int m_velocity{0};
};

#endif