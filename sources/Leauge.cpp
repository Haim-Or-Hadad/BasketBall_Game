#include "Leauge.hpp"
#include "Team.hpp"
#include <iostream>

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
        this->all_teams->push_back(new Team());
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
    cout << "longest number of wins: " << longest_wins() << endl;
    cout << "longest number of losses: " << longest_losses() << endl;
    cout << "Best points ratio: " << Positive_point_ratio() << endl;
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