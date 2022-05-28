
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

	/********TEAM 2********/
	Team team_2{"Hapoel"};

	Game first_game{team_1,team_2};
	first_game.play();
	cout << first_game << endl;

	///BUILD NEW FULL LEAUGE///
	Leauge le1{};
	cout << le1 << endl;

	//PUT TEAM1 AND TEAM2 IN VECTOR
	vector<Team*> team_list = {&team_1,&team_2};
	Leauge le2{team_list};
	cout << le2 << endl;
		


	//new Schedule
	// Schedule *season = new Schedule(&le1);
	// cout << season << endl;
}
	