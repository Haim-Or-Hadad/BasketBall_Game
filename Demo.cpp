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
#include "statistics.hpp"
#include <exception>
#include  <algorithm>
using namespace ariel;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main() {

	//single game
	Team first{"first"};
	Team second{"second"};
	Game game{first , second};
	cout << "######## result before game: ########" << endl;
	cout << game << endl; // result before game
	game.play();
	cout << "######## result after game: ########" << endl;
	cout << game << endl; // result after game
	try
	{
		game.play(); // try to play the game again
	}
	catch(const std::exception& e)
	{
		std::cerr << "game is already played" << '\n';
	}
	cout << "---------------------------------------" << endl;

	//full season with teams that i give them the names and random teams of constructor
	Team a{"a"};
	Team b{"b"};
	Team c{"c"};
	Team d{"d"};
	vector<Team*> my_team_list1 = {&a,&b,&c,&d};
	Leauge leauge1{my_team_list1};
	cout << "######## leauge table with wins and losses:########" << endl;
	cout << leauge1 << endl; //print all leauge
	Schedule season1{leauge1};
	statistics stat1{season1};
	//cout << stat1 << endl;//show that stat is empty before games is play
	//cout << season1 << endl;// print all round and games of season 
	season1.play_season();
	//statistics stat1{season1};
	cout << "######## stat in the end of season:########" << endl;
	cout << stat1 << endl;
	cout << "---------------------------------------" << endl;

	//check the stat after one round
	Leauge leauge2{};
	Schedule season2{leauge2};
	for (size_t i = 0; i < 10; i++)
	{
		season2.get_rounds().at(0).at(i)->play();
	}
	statistics stat2{season2};
	cout << "######## stat after one game:########" << endl;
	cout << stat2 << endl;
	cout << "---------------------------------------" << endl;

	////////////////////////////////////////////////////////////////////
	/////////////////////////////my menu////////////////////////////////
	////////////////////////////////////////////////////////////////////
	Team maccabi{"maccabi"};
	Team hapoel{"hapoel"};
	Team zafrir{"zafrir"};

	vector<Team*> team_list;
	team_list.push_back(&maccabi);
	team_list.push_back(&hapoel);
	team_list.push_back(&zafrir);

	//BUILD NEW FULL LEAUGE///
	Leauge leauge{team_list};
	Schedule season{leauge};
	statistics stat{season};

	int choice;
	// while (1)
	// {
	//  	cout << "0) Exit" << endl;
	// 	cout << "1) print team list" << endl;
	// 	cout << "2) print schedule" << endl;
	// 	cout << "3) play all season" << endl;
	// 	cout << "4) show all results" << endl;
	// 	cout << "5) show statistics" << endl;
	// 	cout << "Your choice : ";
	// 	cin >> choice;
	// 	cout << "*****************************************************" << endl;
	// 	switch (choice){
	// 	case 0:
	// 		cout << "bye bye until next season" << endl;
	// 		return 0;
	// 	case 1:
	// 		cout << leauge << endl;
	// 	break;
	// 	case 2:
	// 		cout << season << endl;
	// 		break;
	// 	case 3:
	// 		season.play_season();
	// 		break;
	// 	case 4:
	// 		stat.print_games_result();
	// 		break;
	// 	case 5:
	// 		cout << stat << endl;
	// 		break;
	// 	default:
	// 		cout << "Wrong choice, please try again..." << endl;
	// 	}
	// }
	// cout << "*****************************************************" << endl;
}
	