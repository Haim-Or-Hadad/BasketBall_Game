#ifndef Game_H
#define Game_H
#include "Team.hpp"
#include <iostream>

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
    /******defualt constructor*****/
     //Game();
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
     void setScore1(int score){this->team1_score += score;}
     void setScore2(int score){this->team2_score += score;}
    
    /**
     * @brief starting a new game of leauge
     * 
     */
    /**
     *@brief add score to the heighest team 
     */
    void score_by_height();
    /**
     * @brief add score to the talent team
     * 
     */
    void score_by_talent();
    /**
     * @brief add score to the home team
     */
    void score_homeGame();
    /**
     * @brief score by num_of_Shooting_Guard
     * 
     */
    void num_of_Shooting_Guard();
    /**
     * @brief team that have more winning get more score
     * 
     */
    void score_by_winning();
    /**
     * @brief get score to the team with star
     * 
     */
    void score_star_team();
    /**
     * @brief check result of game is equal 
     * 
     */
    /**
     * @brief check wich team have more seq of wins  
     */
    void score_by_moral();
    /**
     * @brief if the scores are equal 
     * 
     */
    void determine_game();
    void play();


    /*****operators******/
    friend std::ostream &operator<<(std::ostream &output,  Game &game);
 };

 



};
#endif

