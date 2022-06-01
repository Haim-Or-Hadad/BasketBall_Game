/**
 * @file test.cpp
 * @author Haim Or Hadad (haimor1123@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "doctest.h"
#include <iostream>
#include <vector>

#include "sources/Game.hpp"
#include "sources/Team.hpp"
#include "sources/Leauge.hpp"
#include "sources/Schedule.hpp"

using namespace std;
using namespace ariel;


/*This case checked the names and talents of the team*/
TEST_CASE("Team check fields"){
    /*create a new leauge and schedule for leauge
    the 20 teams create automatically*/
    Leauge league1{};
    Schedule season{league1};
    SUBCASE("no more then 20 teams")
    {
    CHECK_EQ(20,league1.get_all_teams().size());
    }
    //check that the Leauge constructor give different names to the 20 teams
    SUBCASE("different names")
    {
    vector<Team*> teams = league1.get_all_teams();
        for (size_t i = 0; i < league1.get_all_teams().size() - 1 ; i++)
        {
            for (size_t j = i; j < league1.get_all_teams().size(); j++)
            {
            CHECK_FALSE(teams.at(i)->getName() == teams.at(i+1)->getName());
            }
        } 
    }
    SUBCASE("talent between 0 to 1")
    {
     for (size_t i = 0; i < league1.get_all_teams().size()  ; i++)
        {
            CHECK(league1.get_all_teams().at(i)->getTalent() > 0);
            CHECK(league1.get_all_teams().at(i)->getTalent() < 1);
            }
    } 
}


