#include <iostream>
#include <string>
#include <vector>
// #include "Game.hpp"
// #include "Team.hpp"
// //#include "Leauge.hpp"
#include "Schedule.hpp"

using namespace std;

namespace ariel
{
  Schedule::Schedule(Leauge *leauge){
      this->team_list;
      this->leauge = leauge;
  }  

  void Schedule::operate_arrangment(){
        for( Team * team1 : this->leauge->get_all_teams())
        {
          for ( Team * team2 : this->leauge->get_all_teams())
          {
            Game *game = new Game(*team1,*team2);
            this->games_list->push_back(game);
          }
    }
    }
    
      
  };
