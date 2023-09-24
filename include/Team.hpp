#ifndef TEAM_HPP
#define TEAM_HPP

#include "Racer.hpp"
#include <thread>

class Team {
public:
    static unsigned int counter;

    Team();

    friend std::ostream& operator<<(std::ostream& os, const Team& team);

    void startRace();
    bool isPrintable() const;
    void setPrintable(const bool& isPrintable) const;
    
private:
    std::vector<Racer> m_racers;
    unsigned int m_team_id{};
    mutable bool m_printable{};
};

#endif