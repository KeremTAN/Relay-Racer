#ifndef RACER_HPP
#define RACER_HPP

#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <random>
#include <thread>

class Team;

class Racer {

public:
    Racer(const unsigned int& racer_number=1,
        const unsigned int& racer_postion=0)
        :m_racer_number(racer_number), m_position(racer_postion) {}

    friend std::ostream& operator<<(std::ostream& os, const Racer& racer);

    void race(const Racer* const, const Team* const);
    unsigned int getPosition() const;
        
private:
    unsigned int m_position{};
    unsigned int m_racer_number{};
    unsigned int m_velocity{0};
};

#endif