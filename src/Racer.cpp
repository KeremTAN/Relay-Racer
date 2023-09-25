#include "Racer.hpp"
#include "Team.hpp"

std::unique_ptr<Config> Racer::s_config = nullptr;

std::ostream& operator<<(std::ostream& os, const Racer& racer) {

    return os <<"Active Racer's Number: "<< racer.m_racer_number
    <<" Racer's Position: "<< racer.m_position
    <<" Racer's Velocity: "<< racer.m_velocity<<'\n'; 
}

void Racer::race(
   const Racer* const beforeRacer=nullptr,
   const Team* const team = nullptr) {

   if(beforeRacer)
      m_position=beforeRacer->getPosition(); 
   
   int counter = m_position % 100;
   
   while (counter < 100) {

      std::this_thread::sleep_for(std::chrono::milliseconds(1));
      m_velocity=(rand()%5)+1;
      m_position+=m_velocity;
      counter+=m_velocity;

      if(team->isPrintable()){
         
         if(counter > 100 && (this+1) != nullptr)
            (this+1)->m_position=m_position;
         
         std::unique_lock<std::shared_mutex> lock(s_config->mutex_);
         std::cout<<*team;
      }
   }

   m_velocity=0;
}

unsigned int Racer::getPosition() const { return m_position; }