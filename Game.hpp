#ifndef Game_H
#define Game_H
#include "Team.hpp"
#include "Player.hpp"

namespace ariel
{
 //class Player;
 class Game
 {
 private:
     Team *team1;
     Team *team2;
     Team * winner_team;
     Team * losser_team;
     int team1_score;
     int team2_score;
 public:
    /*****defualt constructor*****/
     Game();
     /*****Game constructor*****/
     Game(Team & team1, Team & team2);
     ~Game();

     /*********inline getters**********/
     Team & getTeam1(){return *this->team1;}
     Team & getTeam2(){return *this->team2;}
     Team & getWinner(){return *this->winner_team;}
     Team & getLosser(){return *this->losser_team;}
     int getScore1(){return this->team1_score;}
     int getScore2(){return this->team2_score;}

     /*********inline setters************/
     void setTeam1(Team & team_1){this->team1 = &team_1;}
     void setTeam2(Team & team_2){this->team2 = &team_2;}
     void setWinner(Team & winnerTeam){this->winner_team = &winnerTeam;}
     void setLosser(Team & losserTeam){this->losser_team = &losserTeam;}
     void setScore1(int score){this->team1_score = score;}
     void setScore2(int score){this->team2_score = score;}

 };

 



};
#endif

