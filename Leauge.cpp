#include "Leauge.hpp"
#include "Team.hpp"

using namespace std;
namespace ariel
{

Leauge::Leauge(){
    for (size_t i = 0; i < 20; i++)
    {
        Team *t = new Team();
        this->all_teams->push_back(t);
    }  
}
Leauge::Leauge(std::vector<Team*> & all_teams){
    this->all_teams = &all_teams;
}

};