#ifndef Schedule_H
#define Schedule_H

#include <iostream>
#include "string"
#include "vector"
#include "map"
#include "Game.hpp"
#include "Team.hpp"
#include "Leauge.hpp"

namespace ariel
{
  class Schedule
  {
  private:
    std::map<int,std::vector<Game*>> round_games;
    std::vector<Game*> *games_list;
    Leauge *leauge;
  public:
    //////constructor ger leauge////
    Schedule(Leauge leauge);
    /////defualt constructor//////
    Schedule(){};

    ~Schedule(){};


    /*****getters********/
    std::map<int,std::vector<Game*>> get_rounds(){return round_games;}
      
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
    /**
     * @brief print all the results off the games in season
     */
    void print_games_result();
    /**
     * @brief print the games of all the season
     * 
     */
    void print_all_games();
    void print_table();

    friend std::ostream &operator<<(std::ostream &output,  Schedule &schedule);

    void print_teamlist()
    {
      size_t i =0;
      for( size_t j =0 ; j <20 ; j++)
      {
        std::cout << "problem" << std::endl;
        std::cout << i++ << ": "<< leauge->get_all_teams().at(j)->getName() << std::endl;
      }

    }
    
};
};
#endif
