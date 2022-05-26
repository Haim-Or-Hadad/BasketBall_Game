
#include "Player.hpp"
#include "Game.hpp"
#include "Team.hpp"

#include <exception>

using namespace ariel;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main() {

	Team team_1{};
	string s = "moshe";
	Player haim{s,24,team_1};
	Player ilan{"ilan",27,team_1};
	Player tomer{"tomer",25,team_1};
	Player morgan{"morgan",30,team_1};
	Player wade{"wade",32,team_1};

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
	
}
