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
  /**
 * @brief This class creates a new schedule to the leauge 
 * @param round_games - map of vectors any key is num of round in season so there are 
 * 38 keys and to any key have 10 games in round because we have 20 teams.
 * @param games_list - list of the 380 games in season
 * @param leauge - leauge
 */
  class Schedule
  {
  private:
    std::map<int,std::vector<Game*>> round_games;
    std::vector<Game*> games_list;
    Leauge *leauge;
  public:
    //////constructor ger leauge////
    Schedule(Leauge & leauge);
    // Copy  constructor.
    Schedule(const Schedule &schedule);
    // Copy Assignment Operator.
    Schedule & operator=(const Schedule &schedule);
    // Move Constructor.
    Schedule (Schedule &&) = default;	
    // Move assignment Operator.
    Schedule& operator=(Schedule&& schedule) = default;

    ~Schedule(){};


    /*****getters********/
    /**
     * @brief return games list 
     */
    std::vector<Game*> & get_games_list();
      /**
     * @brief return leauge
     */
    Leauge & get_Leauge();
      /**
     * @brief return map of vectors
     */
    std::map<int,std::vector<Game*>> &get_rounds();
      
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
