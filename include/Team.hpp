#ifndef TEAM_HPP
#define TEAM_HPP

#include <map>
#include <thread>
#include <shared_mutex>

#include "Racer.hpp"

struct Config {
    std::shared_mutex mutex_;
};

class Team {
public:
    static std::unique_ptr<Config> s_config;

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