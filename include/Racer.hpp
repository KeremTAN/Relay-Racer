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
    Racer(const unsigned int& racer_number=1)
        :m_racer_number(racer_number) {}

    friend std::ostream& operator<<(std::ostream& os, const Racer& racer);

    void operator()();
    void race(const Racer* const, const Team* const);
    
    void setPosition(unsigned int& newPosition);
    unsigned int getPosition() const;
    unsigned int getVelocity() const;
    unsigned int getRacerNumber() const;
        
private:
    //unsigned int m_team_id{};
    unsigned int m_position{};
    unsigned int m_racer_number{};
    unsigned int m_velocity{0};
};

#endif