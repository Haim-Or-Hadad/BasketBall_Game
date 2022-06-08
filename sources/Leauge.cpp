#include "Leauge.hpp"
#include "Team.hpp"
#include <iostream>
#include "algorithm"

using namespace std;

const int zero1 = 0;
const int teams_size = 20;

namespace ariel
{

Leauge::Leauge()
{
    srand(time(0));
    this->all_teams = new vector<Team*>();
    this->build_leauge();
}
Leauge::Leauge(std::vector<Team*> & curr_teams)
{
  srand(time(0));
  this->all_teams = new vector<Team*>();
    if (curr_teams.size() > teams_size )
    {
        throw invalid_argument("leauge have at most 20 teams");
    } 
    this->complete_leauge(&curr_teams);
}


void Leauge::build_leauge()
{
    size_t i= 0;
    while (this->all_teams->size() < teams_size)
    {
      Team * new_team = new Team();
      this->all_teams->push_back(new_team);
    }
    for (size_t i = 0; i < this->all_teams->size()-1; i++)
    {
      for (size_t j = i+1; j < this->all_teams->size(); j++)
      {
        if( this->all_teams->at(i)->getName() == this->all_teams->at(j)->getName()){
          __throw_invalid_argument("can't use twice in same name");
        }
      }
      
    }
    
}

void Leauge::complete_leauge(vector<Team*> * teams)
{
    for( Team * team_ : *teams)
    {
        this->all_teams->push_back(team_);
    }
    this->build_leauge();
}


 ostream &operator<<(std::ostream &output,  Leauge &leauge)
 {
     size_t i =0;
     while (i<teams_size)
     {
        output << leauge.all_teams->at(i)->getName() << "|";
        output << leauge.all_teams->at(i)->getWins() << "|";
        output << leauge.all_teams->at(i)->getLosses() << endl;
        i++;
     }
     return output;
 }
};