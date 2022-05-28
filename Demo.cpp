
#include "Player.hpp"
#include "Game.hpp"
#include "Team.hpp"
#include "Leauge.hpp"
#include "Schedule.hpp"

#include <exception>

using namespace ariel;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main() {
	/********TEAM 1********/
	Team team_1{"maccabi"};
	string s = "moshe";
	Player haim{s,24,team_1};
	Player ilan{"ilan",27,team_1};
	Player tomer{"tomer",25,team_1};
	Player morgan{"morgan",30,team_1};
	Player wade{};

	team_1.addPlayer(haim);
	team_1.addPlayer(ilan);
	team_1.addPlayer(tomer);
	team_1.addPlayer(morgan);
	team_1.addPlayer(wade);

	// /*
	// 	prints:
	// 	ilan
	// 	tomer
	// 	morgan
	// 	wade
	// */
	for(Player * player : team_1.getPlayers()){
		cout << player->getName() << endl;
	}

	for(Player * player : team_1.getPlayers()){
		cout << player->getRole() << endl;
	}

	/********TEAM 1********/
	Team team_2{"Hapoel"};
	Player doron{"doron",24,team_2};
	Player boaz{"boaz",27,team_2};
	Player amit{"amit",25,team_2};
	Player anat{"anat",30,team_2};
	Player yona{"yona",41,team_2};

	team_2.addPlayer(doron);
	team_2.addPlayer(boaz);
	team_2.addPlayer(amit);
	team_2.addPlayer(anat);
	team_2.addPlayer(yona);

	for(Player * player : team_2.getPlayers()){
		cout << player->getName() << endl;
	}

	Game first_game{team_1,team_2};
	first_game.play();
	cout << first_game << endl;

	///BUILD NEW LEAUGE///
	Leauge le{};
	cout << le.get_all_teams().at(0)->getName() << endl;
	cout << le.get_all_teams().at(1)->getName() << endl;
	cout << le.get_all_teams().at(2)->getName() << endl;
	cout << le.get_all_teams().at(3)->getName() << endl;
}		


	//new Schedule
	//Schedule season = new Schedule(le);

	