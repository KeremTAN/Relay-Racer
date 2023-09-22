#include "Racer.hpp"

std::ostream& operator<<(std::ostream& os, const Racer& racer) {
    return os<<" Active Racer's Number: "<< racer.m_active_racer
    <<" Racer's Position: "<< racer.m_position
    <<" Racer's Velocity: "<< racer.m_velocity<<'\n'; 
}

void Racer::operator()() {
    m_velocity=m_distribution(m_velocityGenerator);
    m_position+=m_velocity;
}

unsigned int Racer::getPosition() const { return m_position; }

unsigned int Racer::getVelocity() const { return m_velocity; }

unsigned int Racer::getActiveRacer() const { return m_active_racer; }