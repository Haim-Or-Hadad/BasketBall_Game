#include "Leauge.hpp"
#include "Team.hpp"
#include <iostream>
#include "algorithm"
#include "vector"

using namespace std;


const int zero1 = 0;
const int TEAMS_SIZE = 20;

namespace ariel
{

Leauge::Leauge()
{
    srand(time(0));
    this->build_leauge();
}
Leauge::Leauge(std::vector<Team*> & curr_teams)
{
  srand(time(0));
    if (curr_teams.size() > TEAMS_SIZE )
    {
        throw invalid_argument("leauge have at most 20 teams");
    } 
    this->complete_leauge(&curr_teams);
}

  // Copy  constructor.
  Leauge::Leauge(const Leauge &other_leauge){
    this->all_teams = other_leauge.all_teams;
  }



void Leauge::build_leauge()
{
    if(this->all_teams.size() >= TEAMS_SIZE ){
      __throw_invalid_argument("The league has already been built");   
    } 
    size_t i= 0;
    while (this->all_teams.size() < TEAMS_SIZE)
    {
      Team * new_team = new Team();
      this->all_teams.push_back(new_team);
    }
    for (size_t i = 0; i < this->all_teams.size()-1; i++)
    {
      for (size_t j = i+1; j < this->all_teams.size(); j++)
      {
        if( this->all_teams.at(i)->getName() == this->all_teams.at(j)->getName()){
          __throw_invalid_argument("can't use twice in same name");
        }
      }
    }
}

void Leauge::complete_leauge(vector<Team*> * teams)
{
    for( Team * team_ : *teams)
    {
        this->all_teams.push_back(team_);
    }
    this->build_leauge();
}

//getter
vector<Team*> & Leauge::get_all_teams()
{
  return this->all_teams;
}
//setter
 void Leauge::set_teams(std::vector<Team*> &teams)
 {
  this->all_teams = teams;
 }

  // Copy Assignment Operator.
  Leauge & Leauge::operator=(const Leauge &other_leauge){
    this->all_teams = other_leauge.all_teams;
    return *this;
  }

 ostream &operator<<(std::ostream &output,  Leauge &leauge)
 {
     size_t i =0;
     while (i<TEAMS_SIZE)
     {
        output << leauge.all_teams.at(i)->getName() << "|";
        output << leauge.all_teams.at(i)->getWins() << "|";
        output << leauge.all_teams.at(i)->getLosses() << endl;
        i++;
     }
     return output;
 }
};