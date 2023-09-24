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
    static std::vector<unsigned int> s_championsList;
    static std::unique_ptr<Config> config;

    Team();
    ~Team() = default;

    friend std::ostream& operator<<(std::ostream& os, const Team& team);

    void operator()();
    void startRace();

    bool isPrintable() const;
    void setPrintable(const bool& isPrintable) const;

    static void printChampions();

private:
    static unsigned int counter;
    std::vector<Racer> m_racers;
    unsigned int m_team_id{};
    mutable bool m_printable{};
};

#endif