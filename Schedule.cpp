#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Team.hpp"
#include "Leauge.hpp"
#include "Schedule.hpp"

using namespace std;

namespace ariel
{
  Schedule::Schedule(Leauge *leauge,vector<Team*> *t_list){
      this->team_list = t_list;
  }  

  void Schedule::operate_arrangment(){
  //for( auto team1 = this->team_list->begin(); team1 != this->team_list->end(); ++team1){
     //for( auto team2 = this->team_list->begin(); team2 != this->team_list->end(); ++team2){
        for( Team * team1 : *this->team_list)
        {
          for (Team * team2 : *this->team_list)
          {
            Game *game = new Game(*team1,*team2);
            this->games_list->push_back(game);
          }
        
          
        
        
    }
    }
    
      
  }
};