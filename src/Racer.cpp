#include "Racer.hpp"

std::ostream& operator<<(std::ostream& os, const Racer& racer) {
    return os<<"Active Racer's Number: "<< racer.m_racer_number
    <<" Racer's Position: "<< racer.m_position
    <<" Racer's Velocity: "<< racer.m_velocity<<'\n'; 
}

void Racer::operator()() {
     while (m_position < 400) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        srand(static_cast<unsigned int>(time(nullptr)));
        m_velocity= rand()%5+1;
        m_position+=m_velocity;
        m_racer_number= (m_position/100)+1; /// !! ??????????? !!!!!!!!!!!!!!!!!!!!
     }
}


void Racer::race(
   const Racer* const beforeRacer=nullptr) {
   int counter{};

   if(beforeRacer){
      m_position=beforeRacer->getPosition(); 
      std::cout<< *this;
   }

   while (counter < 100) {
      m_velocity=(rand()%5)+1;
      m_position+=m_velocity;
      counter+=m_velocity;
      std::cout<<*this;
   }
   m_velocity=0;
}

void Racer::setPosition(unsigned int& newPosition) { m_position=newPosition; }

unsigned int Racer::getPosition() const { return m_position; }

unsigned int Racer::getVelocity() const { return m_velocity; }

unsigned int Racer::getRacerNumber() const { return m_racer_number; }