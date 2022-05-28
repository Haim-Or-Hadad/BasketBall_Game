#include "Leauge.hpp"
#include "Team.hpp"
#include <iostream>

using namespace std;
namespace ariel
{

Leauge::Leauge()
{
    this->build_leauge();
}
Leauge::Leauge(std::vector<Team*> curr_teams)
{
    if (curr_teams.size() > 20 )
    {
        throw invalid_argument("leauge has at most 20 teams");
    } 
    this->complete_leauge(curr_teams);

}


void Leauge::build_leauge()
{
    while (this->all_teams.size() < 20)
    {
        Team *t = new Team();
        this->all_teams.push_back(t);
    }
}

void Leauge::complete_leauge(vector<Team*> teams)
{
    for( Team * team_ : teams)
    {
        this->all_teams.push_back(team_);
    }
    this->build_leauge();
}

 ostream &operator<<(std::ostream &output,  Leauge &leauge)
 {
     size_t i =0;
     while (i<20)
     {
        output << leauge.all_teams.at(i)->getName() << "|";
        output << leauge.all_teams.at(i)->getWins() << "|";
        output << leauge.all_teams.at(i)->getLosses() << endl;
        i++;
     }
     return output;
 }
};