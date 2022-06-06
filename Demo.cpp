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

	/********TEAM 2********/
	Team team_2{"Hapoel"};

	//Game first_game{team_1,team_2};
	//first_game.play();
	//cout << first_game << endl;

	// //BUILD NEW FULL LEAUGE///
	// Leauge le1{};
		
	// Schedule season{le1};
	
	// //print all the games of the season
	// cout << season << endl;
	// //operate play of all the games
	// season.play_season();	

	// //season.print_teamlist();
	// season.print_table();
	
	// //prints statistec
	// le1.statistics();

	//PUT TEAM1 AND TEAM2 IN VECTOR
	vector<Team*> team_list = {&team_1,&team_2};
	Leauge le2{team_list};
	cout << le2 << endl;

	//create a schedule to leauge 2
	Schedule season2{le2};
    //print all the games of the season
	cout << season2 << endl;
	season2.play_season();
	season2.print_table();
	le2.statistics();



	
}
	