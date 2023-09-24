#ifndef TEAM_HPP
#define TEAM_HPP

#include "Racer.hpp"

class Team {
public:

    Team();
    ~Team() = default;

    friend std::ostream& operator<<(std::ostream&, const Team&);

    void        operator()();
    void        startRace();

    bool        isPrintable() const;
    void        setPrintable(const bool&) const;

    static void printChampions();

private:
    static unsigned int                 counter;
    static std::vector<unsigned int>    s_championsList;

    std::vector<Racer>                  m_racers;
    unsigned int                        m_team_id{};
    mutable bool                        m_printable{};
};

#endif