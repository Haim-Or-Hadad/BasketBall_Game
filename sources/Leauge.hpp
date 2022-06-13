#pragma once 

#include "iostream"
#include "Team.hpp"
#include <vector>

namespace ariel
{
/**
 * @brief This class creates a new leauge with 20 new teams 
 * @param all_teams - vector that contains all the teams
 */
class Leauge
{
private:
    std::vector<Team*> all_teams;
public:
    /*****League constructor******/
    Leauge(std::vector<Team*> & curr_teams);
    /*****defualt constructor*****/
    Leauge();
    // Copy  constructor.
    Leauge(const Leauge &other_leauge);

    ~Leauge(){};

    /******getters*********/
    std::vector<Team*> &get_all_teams();

    /******setters********/
    void set_teams(std::vector<Team*> & teams);

    /****simulate new full leaugue****/
    /**
     * @brief build new leauge with 20 new teams 
     * */
    void build_leauge();
    /**
     * @brief if numbers of teams in leauge is under than 20 so the func complete to 20
     */
    void complete_leauge(std::vector<Team*> *teams);
    /******operator*********/
    // Copy Assignment Operator.
    Leauge & operator=(const Leauge &other_leauge);
    friend std::ostream &operator<<(std::ostream &output,  Leauge &Leauge);
};

};
