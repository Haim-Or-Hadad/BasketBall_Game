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
#include "sources/statistics.hpp"

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
    CHECK_EQ(20,league1.get_all_teams().size());//check constructor create 20 new teams
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
            CHECK(league1.get_all_teams().at(i)->getTalent() > 0);//check talent bigger than 0
            CHECK(league1.get_all_teams().at(i)->getTalent() < 1);//check talent smaller than 1
            }
    } 
}

TEST_CASE("Team"){
    //team name can't be null
    CHECK_THROWS(Team noletter1{""});
    CHECK_THROWS(Team noletter2{""});
    CHECK_NOTHROW(Team my_team{"haim_team"});//check constructor of team by name
    Team my_team{"haim_team"};
    //team can't win negative number of win or more than 38 games
    CHECK_THROWS(my_team.setWins(-1));
    CHECK_THROWS(my_team.setWins(39));
    CHECK_THROWS(my_team.setWins(-37));
    CHECK_NOTHROW(my_team.setWins(1));
    CHECK_EQ ( 1, my_team.getWins());//check that setwins add win to "my_team"
    //team can't loss negative number of losses or more than 38 games
    CHECK_THROWS(my_team.setLosses(-1));
    CHECK_THROWS(my_team.setLosses(39));
    CHECK_THROWS(my_team.setLosses(-37));
    CHECK_NOTHROW(my_team.setLosses(1));
    CHECK_EQ ( 1, my_team.getLosses());//check that setlosses add loss to "my_team"
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
    size_t i =0;
    //while(i<1000){
    //first_game.play();
    // CHECK(first_game.getScore1() >= 55);//check home team score greater that 55
    // CHECK(first_game.getScore2() >= 50);//check score greater than 50
    // CHECK(first_game.getScore1() <= 100);//check score smaller than than 100
    // CHECK(first_game.getScore2() <= 100);//check score smaller than than 100
    // i++;}
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
    //try create leauge with two teams same name
    CHECK_THROWS(Leauge le{teams2});
}

TEST_CASE("Scheedule"){
    /********TEAM 1********/
	Team team_1{"home"};
	/********TEAM 2********/
	Team team_2{"out"};
    vector<Team*> team_list = {&team_1,&team_2};
	Leauge le2{team_list};
	//create a schedule to leauge 2
	Schedule season{le2};
    CHECK_EQ(season.get_games_list().size() , 380);//check games in season are 380
    for (size_t i = 0; i < 38; i++)
    {
        CHECK_EQ(season.get_rounds().at(i).size() , 10);//check any round have 10 games
    }
    CHECK_THROWS(season.get_Leauge().build_leauge());//The league has already been built
    //season.play_season();

    for (size_t i = 0; i < 380; i++)
    {
    season.get_games_list().at(i)->play();//The game has already played
    CHECK(season.get_games_list().at(i)->getScore1() >= 55);//check home team score greater that 55
    CHECK(season.get_games_list().at(i)->getScore2() >= 50);//check score greater than 50
    CHECK(season.get_games_list().at(i)->getScore1() <= 100);//check score smaller than than 100
    CHECK(season.get_games_list().at(i)->getScore2() <= 100);//check score smaller than than 100
    }
    //string name = season.get_games_list().at(0)->getTeam1().getName();
    for (size_t i = 0; i < 38; i++)
    {
        string name = season.get_Leauge().get_all_teams().at(i % 19)->getName();
        int count = 0;
        for (size_t j = 0; j < 10; j++)
        {
            if (name == season.get_rounds()[i][j]->getTeam1().getName()||
                name == season.get_rounds()[i][j]->getTeam2().getName())
            {
                count++;
            }
        }
        CHECK_EQ( count , 1);//In a round any team has one game
    }
    
    
}

