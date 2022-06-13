#pragma once

#include "Schedule.hpp"

namespace ariel
{

class statistics
{
/**
 * @brief this class calculates statistics to the leauge in the end of the season.
 * @param schedule - Schedule
 * @param table_end_season - vector that save the statistics of the season
 * @param long_wins - map of strings keys of the teams name with value of the wins
 * @param long_loss - map of strings keys of the teams name with value of the losses
 * 
 */
private:
    Schedule * schedule;
    std::vector<Team*> *table_end_season;
    std::map<std::string,int> long_wins;
    std::map<std::string,int> long_loss;

public:
    /********defualt*********/
    statistics(Schedule & schedule);
    // Copy  constructor.
    statistics(const statistics &statistics);

    ~statistics(){};

    ////////////////////////////class methods////////////////////////
    /**
     * @brief init the names of the teams in long_wins and long_losses maps
     * 
     */
    void init_names();
        /**
     * @brief sort the table by wins
     * 
     */
    void sort_wins_points();
    /**
     * @brief Get a pair of longest seq of wins and losses
     */
    std::pair<int, int> get_longest_seq();
    /**
     * @brief Get the Best points ratio 
     */
    int get_Best_points_ratio();
    /**
     * @brief print games result
     * 
     */
    void print_games_result();
    
    //getter
    /**
     * @brief Get the table object
     */
    std::vector<Team*> & get_table();

    /*****operators*****/
    // Copy Assignment Operator.
    statistics & operator=(const statistics &other_stat);
    friend std::ostream &operator<<(std::ostream &output,  statistics &stat);

};

};