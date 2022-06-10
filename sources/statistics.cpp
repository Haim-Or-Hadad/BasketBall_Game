#include "statistics.hpp"
#include <iostream>
#include <vector>
#include "Schedule.hpp"
#include  <algorithm>
#include "iomanip"

using namespace std;
int const for_table_25 = 25;
int const for_table_6 = 6;
int const for_table_7 = 7;
const int num_of_teams = 20;
const int num_of_rounds = 38;
const int games_in_round = 10;

namespace ariel
{
statistics::statistics(Schedule & schedule)
{
this->schedule = &schedule;
this->table_end_season = &this->schedule->get_Leauge().get_all_teams();
this->sort_wins_points();
init_names();
}

void statistics::init_names(){
for (size_t i = 0; i < num_of_teams; i++)
{
    this->long_wins[this->table_end_season->at(i)->getName()] = 0;
}
for (size_t i = 0; i < num_of_teams; i++)
{
    this->long_loss[this->table_end_season->at(i)->getName()] = 0;
}
}

void statistics::sort_wins_points()
{
sort(this->table_end_season->begin(),
this->table_end_season->end(),
[](Team *a, Team *b){
return (a->getWins()) > (b->getWins());});
sort(this->table_end_season->begin(),
this->table_end_season->end(),
[](Team *a, Team *b){
return (a->get_Points_ratio()) > (b->get_Points_ratio());});
}

vector<Team*> & statistics::get_table(){
    return *this->table_end_season;
}

int statistics::get_longest_seq(int flag){
int seq_of_wins = 0;
int seq_of_loss = 0;
string name;
for (size_t i = 0; i < this->schedule->get_games_list().size(); i++)
{
    Game * game = this->schedule->get_games_list().at(i);
    Team * team1 = &game->getTeam1();
    Team * team2 = &game->getTeam2();
    if (game->getScore1() > game->getScore2())
    {
        this->long_wins.at(team1->getName())++;
        this->long_loss.at(team2->getName())++;
        if (this->long_wins.at(team2->getName()) > seq_of_wins)
        {
            seq_of_wins = this->long_wins.at(team2->getName());
        }
        if (this->long_loss.at(team1->getName()) > seq_of_loss)
        {
            seq_of_loss = this->long_loss.at(team1->getName());
            name = team1->getName();
        }
        this->long_wins.at(team2->getName()) = 0;
        this->long_loss.at(team1->getName()) = 0;
    }
    else
    {
        this->long_wins.at(team2->getName())++;
        this->long_loss.at(team1->getName())++;
        if (this->long_wins.at(team1->getName()) > seq_of_wins)
        {
            seq_of_wins = this->long_wins.at(team1->getName());
        }
        if (this->long_loss.at(team2->getName()) > seq_of_loss)
        {
            seq_of_loss = this->long_loss.at(team2->getName());
            name = team2->getName();
        }
        this->long_wins.at(team1->getName()) = 0;
        this->long_loss.at(team2->getName()) = 0;
    }  
}

if(flag == 0)
{
return seq_of_wins;
}
return seq_of_loss;
}

int statistics::get_longest_wins(){
 return get_longest_seq(0);
}
int statistics::get_longest_losses(){
return get_longest_seq(1);
}

int statistics::get_Best_points_ratio(){
int to_return = 0;
for (size_t i = 0; i < num_of_teams; i++)
{
  if (this->table_end_season->at(i)->get_Points_ratio() > to_return)
  {
      to_return = this->table_end_season->at(i)->get_Points_ratio();
  }
}
  return to_return;    
}  


  void statistics::print_games_result()
  {
  for (size_t i = 0; i < num_of_rounds; i++)
    {
    for (size_t j = 0; j < games_in_round; j++)
      {
        cout << "round: " << i << " " << "game: " << j << endl;
        cout << this->schedule->get_rounds()[i][j]->getTeam1().getName();
        cout << "  vs  " ;
        cout << this->schedule->get_rounds()[i][j]->getTeam2().getName();
        cout << endl;
        cout <<"   " <<this->schedule->get_rounds()[i][j]->getScore1() ;
        cout << "                 " ;
        cout << this->schedule->get_rounds()[i][j]->getScore2() ;
        cout << endl << endl;


      }
  }
}

ostream &operator<<(std::ostream &output,  statistics &stat){
    stat.sort_wins_points();
   output
   << left 
   << setw(for_table_25)
   << "Group"
   << left 
   << setw(for_table_6)
   << "games"
   <<setfill('|')
   << left
   << setw(for_table_6)
   << "Winns"
   <<setfill('|')
   << left
   << setw(for_table_7)
   << "losses"
   << left 
   << setw(for_table_6)
   << "points"
   << endl;

    for( Team * team1 : stat.get_table())
    {
    output
    << left
     << setw(for_table_25) 
    << team1->getName()
    << left
    << setw(for_table_6)
    <<"38"
    <<setfill('|')
    << left
    <<setw(for_table_6)
    << team1->getWins()
    << setfill('|')
    << left
    << setw(for_table_6)
    << team1->getLosses()
    << left 
    << setw(for_table_6)
    << team1->get_Points_ratio()
    << endl;
    }
    output << "The longest winning streak: " << stat.get_longest_wins() << endl;
    output << "The longest lossing streak: " << stat.get_longest_losses() << endl;
    output << "talent of best team: " <<stat.table_end_season->at(0)->getTalent() << endl; 
    output << "talent of bad team: " << stat.table_end_season->at(num_of_teams-1)->getTalent() << endl; 
    return output;
}
};
