#include "Racer.hpp"

std::ostream& operator<<(std::ostream& os, const Racer& racer) {
    return os<<" Active Racer's Number: "<< racer.m_active_racer
    <<" Racer's Position: "<< racer.m_position
    <<" Racer's Velocity: "<< racer.m_velocity<<'\n'; 
}

void Racer::operator()() {
     while (m_position < 400) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        srand(static_cast<unsigned int>(time(nullptr)));
        m_velocity= rand()%5+1;
        m_position+=m_velocity;
        m_active_racer= (m_position/100)+1; /// !! ??????????? !!!!!!!!!!!!!!!!!!!!
     }
}


void Racer::race() {
     while (m_position < 400) {
        m_velocity= (rand()%5)+1;
        m_position+=m_velocity;
        std::cout<<*this;
     }
}


unsigned int Racer::getPosition() const { return m_position; }

unsigned int Racer::getVelocity() const { return m_velocity; }

unsigned int Racer::getActiveRacer() const { return m_active_racer; }