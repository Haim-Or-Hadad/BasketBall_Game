#include "Game.hpp" 
#include <iostream>

using namespace std;

 namespace ariel
 {

 Game::Game(Team & home_team, Team & outside_team)
 {
     this->team1= &home_team;
     this->team2 = &outside_team;
     this->team1_score = 0;
     this->team2_score =0;
 }
 
 Game::~Game(){}

 void Game::play(){
     this->setScore1(rand() % 80 +40);
     this->setScore2(rand() % 80 +40);
     if (getScore1() > getScore2())
     {
        setWinner(*team1);
        setLosser(*team2);
     }
     else
     {
         setWinner(*team2);
         setLosser(*team1);
     }
     
        
 }

 ostream &operator<<(ostream &output,  Game &game)
 {
     output << game.getTeam1().getName();
     output << "      ";
     output << game.getTeam2().getName();
     output << endl;
     output << game.getScore1();
     output << "            ";
     output << game.getScore2();
     output << endl;
 return output;
 }
 };