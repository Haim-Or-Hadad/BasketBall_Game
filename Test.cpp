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

TEST_CASE("Team"){
    //team name can't be null
    CHECK_THROWS(Team noletter1{""});
    CHECK_THROWS(Team noletter2{""});
    CHECK_NOTHROW(Team my_team{"haim_team"});
    Team my_team{"haim_team"};
    //team can't win negative number of win or more than 38 games
    CHECK_THROWS(my_team.setWins(-1));
    CHECK_THROWS(my_team.setWins(38));
    CHECK_THROWS(my_team.setWins(-37));
    CHECK_NOTHROW(my_team.setWins(1));
    CHECK_EQ ( 1, my_team.getWins());
    //team can't loss negative number of losses or more than 38 games
    CHECK_THROWS(my_team.setLosses(-1));
    CHECK_THROWS(my_team.setLosses(38));
    CHECK_THROWS(my_team.setLosses(-37));
    CHECK_NOTHROW(my_team.setLosses(1));
    CHECK_EQ ( 1, my_team.getLosses());
}

TEST_CASE("Game"){
Team my_team{"haim_team"};
Team other_team{"other_team"};
Game first_game{my_team,other_team};
//team score must be positive numbers
CHECK_THROWS(first_game.setScore1(-3));
CHECK_NOTHROW(first_game.setScore1(0));
CHECK_THROWS(first_game.setScore2(-7));
CHECK_NOTHROW(first_game.setScore1(0));
first_game.play();
CHECK_NOTHROW(first_game.getScore1());
CHECK_NOTHROW(first_game.getScore2());
}

TEST_CASE("leauge"){
    vector <Team*> teams1;
    for (size_t i = 0; i < 21; i++)
    {
        Team *new_team = new Team();
        teams1.push_back(new_team);
    }
    //try to add 21 teams to leauge
    CHECK_THROWS(Leauge leauge{teams1});
    vector <Team*> teams2;
    for (size_t i = 0; i < 19; i++)
    {
        Team new_team2{to_string(i)};
        teams2.push_back(&new_team2);
    }
    Team invalid_team2{"1"};
    teams2.push_back(&invalid_team2);
    CHECK_THROWS(Leauge le{teams2});

}


