#include "Player.hpp"
#include "Game.hpp"
#include <cstdlib>// for rand
#include "Names.cpp"
#include "Role.cpp"
#include "Team.hpp"

#define max 36
#define min 17

using namespace std;

namespace ariel
{
    Player::Player(){
        this->age = rand()%(max-min) + min;
        this->name = names(rand() % Grace);//take one name from enum 
        //this->role = &role_(rand() % Center);//take one name from enum 
        this->team ;//need to complete!!!!!!!!!
    }

    // Player::Player(string & name, int age, Team &team){
    //     this->name = name;
    //     this->age = age;
    //     //this->role = &role;//take one name from enum 
    //     this->team = &team ;//need to complete!!!!!!!!!
    // }
}; 

// using namespace ariel;
// int main(){
// Team *tel_aviv = new Team();
// string s = "haim";
// //role_ role = Power_Forward;
// Player *one = new Player(s,24,*tel_aviv);
// }