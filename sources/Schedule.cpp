#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Team.hpp"
#include "Leauge.hpp"
#include "iomanip"
#include "Schedule.hpp"
#include  <algorithm>
#include <bits/stdc++.h>

using namespace std;

namespace ariel
{
  Schedule::Schedule(Leauge leauge)
  {
    this->games_list = new vector<Game*>;
    this->leauge = &leauge;
    this->init_games();
  }  

  void Schedule::init_games()
  {
      vector<Team*> *teams = &this->leauge->get_all_teams();
      size_t index = 0;
      while(games_list->size() < 380)
      { 
        vector<Game*> curr_games;
        vector<Game*> curr_out_games;
        for (size_t i = 0; i < 19; i+=2)
        {
          Game *game = new Game(*teams->at(i),*teams->at(19-i));
          this->games_list->push_back(game);
          curr_games.push_back(game); 
          Game *game_out = new Game(*teams->at(19-i),*teams->at(i));
          this->games_list->push_back(game_out);
          curr_out_games.push_back(game_out);

        }
        rotate(teams->begin()+1,teams->begin()+19,teams->end());
        rotate(teams->begin()+9, teams->begin()+9, teams->end());
        this->round_games[index] = curr_games;
        this->round_games[index+1] = curr_out_games;
        index +=2;
      }
  }

  void Schedule::play_season()
  {
    for (size_t i = 0; i < 38; i++)
      {
      for (size_t j = 0; j < 10; j++)
        {
          this->round_games[i].at(j)->play();
          if (round_games[i].at(j)->getScore1()<55 || round_games[i].at(j)->getScore1()>110 )
          {
            cout << round_games[i].at(j)->getScore1() <<endl;
            cout << round_games[i].at(j)->getScore2() <<endl;
            throw invalid_argument("home team must have score between 55-100");
          }  
        }
      }
  }


  ostream &operator<<(std::ostream &output,  Schedule &schedule)
    {
      for (size_t i = 0; i < 38; i++)
      {
        output << " -----round " << i+1 << " games---- " << endl;
        int count =0;
        for (size_t j = 0; j <10; j++)
        {
          output << j+1 <<": "<< schedule.get_rounds()[i].at(j)->getTeam1().getName();
          output << " vs ";
          output << schedule.get_rounds()[i].at(j)->getTeam2().getName();
          output << endl;
        }
      }
      return output;
    }

  void Schedule::print_games_result()
  {
  for (size_t i = 0; i < 38; i++)
    {
    for (size_t j = 0; j < 10; j++)
      {
        cout << this->round_games[j][i]->getTeam1().getName();
        cout << "  vs  " ;
        cout << this->round_games[j][i]->getTeam2().getName();
        cout << endl;
        cout <<"   " <<this->round_games[j][i]->getScore1() ;
        cout << "                 " ;
        cout << this->round_games[j][i]->getScore2() ;
        cout << endl << endl;


      }
  }
}
void Schedule::print_all_games()
{
  for (size_t i = 0; i < games_list->size(); i++)
  {
    cout << "game number " << i << ": " << games_list->at(i)->getTeam1().getName();
    cout << "  vs  ";
    cout << games_list->at(i)->getTeam2().getName() << endl;
  }
  
}


void Schedule::print_table()
{
  sort(this->leauge->get_all_teams().begin(),
  this->leauge->get_all_teams().end());
  cout
   << left 
   << setw(25)
   << "Group"
   << left 
   << setw(6)
   << "games"
   <<setfill('|')
   << left
   << setw(6)
   << "Winns"
   <<setfill('|')
   << left
   << setw(7)
   << "losses"
   //<<setfill('|')
   << left 
   << setw(6)
   << "points"
   << endl;

    for( Team * team1 : this->leauge->get_all_teams())
    {
    cout
    << left
     << setw(25) 
    << team1->getName()
    << left
    << setw(6)
    << team1->get_num_of_games()
    <<setfill('|')
    << left
    <<setw(6)
    << team1->getWins()
    << setfill('|')
    << left
    << setw(6)
    << team1->getLosses()
    << left 
    << setw(6)
    << team1->get_Points_ratio()
     << endl;

        }
}
   



    
      
  };