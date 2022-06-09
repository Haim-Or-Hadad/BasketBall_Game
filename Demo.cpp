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
	while (1)
	{
	 	cout << "0) Exit" << endl;
		cout << "1) print team list" << endl;
		cout << "2) print schedule" << endl;
		cout << "3) play all season" << endl;
		cout << "4) show all results" << endl;
		cout << "5) show statistics" << endl;
		cout << "Your choice : ";
		cin >> choice;
		cout << "*****************************************************" << endl;
		switch (choice){
		case 0:
			cout << "bye bye until next season" << endl;
			return 0;
		case 1:
			cout << leauge << endl;
		break;
		case 2:
			cout << season << endl;
			break;
		case 3:
			season.play_season();
			break;
		case 4:
			stat.print_games_result();
			break;
		case 5:
			cout << stat << endl;
			break;
		default:
			cout << "Wrong choice, please try again..." << endl;
		}
	}
	cout << "*****************************************************" << endl;

}
	