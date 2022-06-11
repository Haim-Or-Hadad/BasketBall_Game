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
const int TEAMS_SIZE = 20;
const int ROUNDS_SIZE = 38;
const int ROUND_GAMES = 10;

namespace ariel
{
statistics::statistics(Schedule & schedule)
{
this->schedule = &schedule;
this->table_end_season = &this->schedule->get_Leauge().get_all_teams();
this->sort_wins_points();
init_names();
}

// Copy  constructor.
statistics::statistics(const statistics &statistics){
this->long_loss = statistics.long_loss;
this->long_wins = statistics.long_wins;
this->schedule = statistics.schedule;
this->table_end_season = statistics.table_end_season;
}

void statistics::init_names(){
for (size_t i = 0; i < TEAMS_SIZE; i++)
{
    this->long_wins[this->table_end_season->at(i)->getName()] = 0;
}
for (size_t i = 0; i < TEAMS_SIZE; i++)
{
    this->long_loss[this->table_end_season->at(i)->getName()] = 0;
}
}

/*sort the table of teams by wins and points ratio
*/
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

/*this func run over the map and calculate the longest sequence of wins and losses.
when team has win in game we add to team 1 to seq of win and win the team loss i check if this seq
of wins bigger than the  seq of win in map of string key and value of long_win.
*/
std::pair<int, int> statistics::get_longest_seq(){
int seq_of_wins = 0;
int seq_of_loss = 0;
for (size_t i = 0; i < ROUNDS_SIZE; i++)
{
    for (size_t j = 0; j < ROUND_GAMES; j++)
    {
    Game * game = this->schedule->get_rounds()[i][j];
    if (this->schedule->get_rounds()[i][j]->played()){//if the game played
        this->long_wins.at(game->winner().getName())++;
    this->long_loss.at(game->looser().getName())++;
    int looser_wins =this->long_wins.at(game->looser().getName());
    int winner_wins =this->long_wins.at(game->winner().getName());
    int looser_loss = this->long_loss.at(game->winner().getName());
    int winner_loss = this->long_loss.at(game->looser().getName());
    int max_wins = max(looser_wins,winner_wins);
    if (max_wins > seq_of_wins)
    {
        seq_of_wins = max_wins;
    }
    int max_losses = max(looser_loss,winner_loss);
    if (max_losses > seq_of_loss)
    {
        seq_of_loss = max_losses;
    }
    this->long_wins.at(game->looser().getName()) = 0;
    this->long_loss.at(game->winner().getName()) = 0;
    }
        }
}

return make_pair(seq_of_wins, seq_of_loss);
}


vector<Team*> & statistics::get_table(){
    return *this->table_end_season;
}


int statistics::get_Best_points_ratio(){
int to_return = 0;
for (size_t i = 0; i < TEAMS_SIZE; i++)
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
  for (size_t i = 0; i < ROUNDS_SIZE; i++)
    {
    for (size_t j = 0; j < ROUND_GAMES; j++)
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



// Copy Assignment Operator.
statistics & statistics::operator=(const statistics &other_stat){
if(this == &other_stat){
      return *this;}
delete other_stat.table_end_season;
statistics stat1(*other_stat.schedule);
this->long_loss = stat1.long_loss;
this->long_wins = stat1.long_wins;
this->schedule = stat1.schedule;
this->table_end_season = stat1.table_end_season;;
return *this;
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
    std::pair<int, int> sequence = stat.get_longest_seq();
    output << "The longest winning streak of: "<<sequence.first << endl;
    output << "The longest lossing streak of: " << sequence.second << endl;
    output << "talent of best team: " <<stat.table_end_season->at(0)->getTalent() << endl; 
    output << "talent of bad team: " << stat.table_end_season->at(TEAMS_SIZE-1)->getTalent() << endl; 
    return output;
}
};
