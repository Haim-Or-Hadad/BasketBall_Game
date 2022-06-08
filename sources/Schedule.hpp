#ifndef Schedule_H
#define Schedule_H

#include <iostream>
#include "string"
#include "vector"
#include "map"
#include "Game.hpp"
#include "Leauge.hpp"

namespace ariel
{
  class Schedule
  {
  private:
    std::map<int,std::vector<Game*>> *round_games;
    std::vector<Game*> *games_list;
    Leauge *leauge;
  public:
    //////constructor ger leauge////
    Schedule(Leauge & leauge);
    /////defualt constructor//////

    ~Schedule(){
      for (size_t i = 0; i < this->games_list->size(); i++)
      {
        delete this->games_list->at(i);
      }
    };


    /*****getters********/
    std::vector<Game*> & get_games_list(){return *games_list;}
    Leauge & get_Leauge(){return *this->leauge;}
    std::map<int,std::vector<Game*>> &get_rounds(){return *round_games;}
      
    /**
    * @brief play all the games of the season
      * 
      */
    void play_season();
    /**
    * @brief init all the games of the season 
    * 
    */
    void init_games();

    friend std::ostream &operator<<(std::ostream &output,  Schedule &schedule);

    
};
};
#endif
