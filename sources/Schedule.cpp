#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Team.hpp"
#include "Leauge.hpp"
#include "Schedule.hpp"
#include  <algorithm>
#include <bits/stdc++.h>

using namespace std;

int const games_size = 380;
int const rounds_size = 38;
int const games_in_round = 10;
int const teams_size = 19;//19 for the loop
int const rotate_9 = 9; // for rotate the vector 

namespace ariel
{
  Schedule::Schedule(Leauge & leauge)
  {
    this->round_games = new map<int,std::vector<Game*>>();
    this->games_list = new vector<Game*>;
    this->leauge = &leauge;
    this->init_games();
  }  

  void Schedule::init_games()
  {
      vector<Team*> *teams = &this->leauge->get_all_teams();
      size_t index = 0;
      vector<Game*> curr_games ;
      vector<Game*> curr_out_games;
      while(games_list->size() < games_size)
      { 
        for (size_t i = 0; i < teams_size; i+=2)
        {
          Game *game = new Game(*teams->at(i),*teams->at(teams_size-i));
          this->games_list->push_back(game);
          curr_games.push_back(game); 
          Game *game_out = new Game(*teams->at(teams->size()-1-i),*teams->at(i));
          this->games_list->push_back(game_out);
          curr_out_games.push_back(game_out);
        }
        rotate(teams->begin()+1,teams->begin()+teams_size,teams->end());
        rotate(teams->begin()+rotate_9, teams->begin()+rotate_9, teams->end());
        this->round_games->insert(make_pair(index,curr_games));
        this->round_games->insert(make_pair(index+1,curr_out_games));
        index +=2;
        curr_games.clear();
        curr_out_games.clear();
      }
  }

  void Schedule::play_season()
  {
    for (size_t i = 0; i < rounds_size; i++)
      {
      for (size_t j = 0; j < games_in_round; j++)
        {
          this->round_games->at(i).at(j)->play();
        }
      }
  }

  //getters
  vector<Game*> & Schedule::get_games_list()
  {
  return *games_list;
  }

  Leauge & Schedule::get_Leauge()
  {
  return *this->leauge;
  }

  std::map<int,std::vector<Game*>> & Schedule::get_rounds()
  {
    return *this->round_games;
  }
  
  ostream &operator<<(std::ostream &output,  Schedule &schedule)
    {
      for (size_t i = 0; i < rounds_size; i++)
      {
        output << " -----round " << i+1 << " games---- " << endl;
        int count =0;
        for (size_t j = 0; j <games_in_round; j++)
        {
          output << j+1 <<": "<< schedule.get_rounds()[i].at(j)->getTeam1().getName();
          output << " vs ";
          output << schedule.get_rounds()[i].at(j)->getTeam2().getName();
          output << endl;
        }
      }
      return output;
    }     
  };