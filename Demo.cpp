/**
 * @file main.cpp
 * @author Haim Or Hadad (haimor1123@gmail.com)
 * @brief to run the file please write in the terminal 
 * "g++ Schedule.cpp  Leauge.cpp Game.cpp Team.cpp Player.cpp main.cpp -o main"
 * @version 0.1
 * @date 2022-05-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Game.hpp"
#include "Team.hpp"
#include "Leauge.hpp"
#include "Schedule.hpp"

#include <exception>
#include  <algorithm>
using namespace ariel;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main() {
	/********TEAM 1********/
	Team team_1{"maccabi"};
	string s = "moshe";

	/********TEAM 2********/
	Team team_2{"Hapoel"};
	cout << team_2 << endl;

	Game first_game{team_1,team_2};
	first_game.play();
	cout << first_game << endl;

	///BUILD NEW FULL LEAUGE///
	Leauge le1{};
	//cout << le1 << endl;

	//PUT TEAM1 AND TEAM2 IN VECTOR
	// vector<Team*> team_list = {&team_1,&team_2};
	// Leauge le2{team_list};
	// cout << le2 << endl;
		
	Schedule season{le1};
	for (size_t i = 0; i < 20; i++)
	{
		//cout << *le1.get_all_teams().at(i) << endl;
	}
	
	//print all the games of the season
	//season.print_all_games();
	//print all the games of the season
	//cout << season << endl;
	//operate play of all the games
	season.play_season();	
	//print the results of the games
	//season.print_games_result();
	
	//season.print_teamlist();
	season.print_table();
	
	//prints statistec
	le1.statistics();
}
	