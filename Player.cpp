#include "Player.hpp"
#include "Game.hpp"
#include <cstdlib>// for rand
#include "Names.cpp"
#include "Team.hpp"
#include "Role.hpp"

#define max 36
#define min 17

using namespace std;

namespace ariel
{
    Player::Player(){
        this->age = rand()%(max-min) + min;
        this->name =names[rand() % names.size()];//take one name from enum 
        this->role = roles[rand() % roles.size()];//take one name from enum 
        this->team ;
    }

    Player::Player(string name, int age, Team &team){
        this->name = name;
        this->age = age;
        this->role = roles[rand() % roles.size()];//take one name from enum 
        this->team = &team ;//need to complete!!!!!!!!!
    }

    Player::Player(Team &team){
        this->age = rand()%(max-min) + min;
        this->name = names[rand() % names.size()];//take one name from enum 
        this->role = roles[rand() % roles.size()];//take one name from enum 
        this->team = &team;
    }


}; 
 