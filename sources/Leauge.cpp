#include "Leauge.hpp"
#include "Team.hpp"
#include <iostream>
#include "algorithm"
using namespace std;
namespace ariel
{

Leauge::Leauge()
{
    srand(time(0));
    this->all_teams = new vector<Team*>();
    this->build_leauge();
}
Leauge::Leauge(std::vector<Team*> curr_teams)
{
  srand(time(0));
  this->all_teams = new vector<Team*>();
    if (curr_teams.size() > 20 )
    {
        throw invalid_argument("leauge have at most 20 teams");
    } 
    this->complete_leauge(curr_teams);
}


void Leauge::build_leauge()
{
    size_t i= 0;
    while (this->all_teams->size() < 20)
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

void Leauge::complete_leauge(vector<Team*> teams)
{
    for( Team * team_ : teams)
    {
        this->all_teams->push_back(team_);
    }
    this->build_leauge();
}

void Leauge::statistics()
{
    int num_of_teams =0;
    scanf("%d", &num_of_teams);
    for (size_t i = 0; i < num_of_teams; i++)
    {
      cout << "team in place " << i << " in leauge: " << *this->all_teams->at(i) << endl;
    }
    cout << "longest number of wins: " << longest_wins() << endl;
    cout << "longest number of losses: " << longest_losses() << endl;
    cout << "Best points ratio: " << Positive_point_ratio() << endl;
    cout << "talent of best team: " << this->all_teams->at(0)->getTalent() << endl;
    cout << "talent of bad team: " << this->all_teams->at(19)->getTalent() << endl;
}

int Leauge::longest_wins()
{
int to_return = 0;
for (size_t i = 0; i < 20; i++)
{
  if (this->get_all_teams().at(i)->get_seq_wins() > to_return)
  {
      to_return = this->get_all_teams().at(i)->get_seq_wins();
  }
}
  return to_return;    
}

int Leauge::longest_losses()
{
int to_return = 21;
for (size_t i = 0; i < 20; i++)
{
  if (this->get_all_teams().at(i)->get_seq_wins() < to_return)
  {
      to_return = this->get_all_teams().at(i)->get_seq_wins();
  }
}
  return to_return;    
}

int  Leauge::Positive_point_ratio()
{
int to_return = 0;
for (size_t i = 0; i < 20; i++)
{
  if (this->get_all_teams().at(i)->get_Points_ratio() > to_return)
  {
      to_return = this->get_all_teams().at(i)->get_Points_ratio();
  }
}
  return to_return;    
}   

 ostream &operator<<(std::ostream &output,  Leauge &leauge)
 {
     size_t i =0;
     while (i<20)
     {
        output << leauge.all_teams->at(i)->getName() << "|";
        output << leauge.all_teams->at(i)->getWins() << "|";
        output << leauge.all_teams->at(i)->getLosses() << endl;
        i++;
     }
     return output;
 }
};