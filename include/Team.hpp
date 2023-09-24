#ifndef TEAM_HPP
#define TEAM_HPP

#include <map>
#include <thread>
#include <shared_mutex>

#include "Racer.hpp"

class Team {
public:
    static unsigned int counter;
    static std::multimap<unsigned int,unsigned int,
        std::greater<unsigned int>> championsList;

    Team();

    friend std::ostream& operator<<(std::ostream& os, const Team& team);

    void startRace();
    bool isPrintable() const;
    void setPrintable(const bool& isPrintable) const;
    
private:
    std::vector<Racer> m_racers;
    unsigned int m_team_id{};
    mutable bool m_printable{};
    //std::shared_mutex& m_mapMutex;
};

#endif