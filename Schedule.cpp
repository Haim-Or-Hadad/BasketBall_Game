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
      //this->team_list;
      this->leauge = leauge;
      this->operate_arrangment();
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

    ostream &operator<<(std::ostream &output,  Schedule &schedule)
    {
      size_t i = 0;
        while (i < schedule.games_list->size()-1)
        {
        output << schedule.games_list->at(0)->getTeam1().getName();
        output << "vs";
        output << schedule.games_list->at(1)->getTeam1().getName();
        output << endl;
        i++;
        }
        return output;
    }
    
      
  };
