#pragma once

#include "Schedule.hpp"

namespace ariel
{

class statistics
{
private:
    Schedule * schedule;
    std::vector<Team*> *table_end_season;
    std::map<std::string,int> long_wins;
    std::map<std::string,int> long_loss;

public:
    statistics(Schedule & schedule);
    ~statistics(){};
    void init_names();
    void sort_table_by_wins();
    std::vector<Team*> & get_table();
    int get_longest_seq(int flag);
    int get_longest_wins();
    int get_longest_losses();
    int get_Best_points_ratio();
    double talent_of_best_team();
    double talent_of_bad_team();
    void print_games_result();
    friend std::ostream &operator<<(std::ostream &output,  statistics &stat);

};

};