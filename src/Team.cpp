#include "Team.hpp"

unsigned int Team::counter = 0;
std::vector<unsigned int> Team::s_championsList{};
std::unique_ptr<Config> Team::config = nullptr;

Team::Team()
    :m_team_id(++counter) {

        m_racers.reserve(4);
        s_championsList.reserve(400);
        
        for(int i{}; i<4; i++)
            m_racers.emplace_back(Racer(i+1, i*100));
}

std::ostream& operator<<(std::ostream& os, const Team& team) {

    return os<<"---------------------------- "
    <<team.m_team_id<<". Team ------------------------------\n"
    <<team.m_racers[0]<<team.m_racers[1]<<team.m_racers[2]<<team.m_racers[3]
    <<"-------------------------------------------------------------------\n";
}

void Team::operator()(){

    m_racers[0].race(nullptr, this);

    for(int i{1}; i < m_racers.size(); i++) {
        std::unique_lock<std::shared_mutex> lock(config->mutex_);
        m_racers[i].race(&m_racers[i-1], this);
    }

    Team::s_championsList.emplace_back(m_team_id);
};

bool Team::isPrintable() const { return m_printable; }

void Team::setPrintable(const bool& isPrintable) const { m_printable=isPrintable; }

void Team::printChampions() {

    for(int i{}; i<s_championsList.size(); i++)
        std::cout<<i+1 <<". is that  Team "<<s_championsList[i]<<'\n';
}