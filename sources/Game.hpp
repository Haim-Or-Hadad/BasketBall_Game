#pragma once 

#include "Team.hpp"
#include <iostream>

namespace ariel
{
 class Game
 {
/**
 * @brief This class represents game of two team
 * @param team1:team 1 details
 * @param team2:team 2 details
 * @param team1_score: score of team 1 in current game
 * @param team2_score: score of team 2 in current game
 */
 private:
     Team *team1;
     Team *team2;
     int team1_score;
     int team2_score;
 public:
     /*****Game constructor******/
     Game(Team & team1, Team & team2);
     /******Game destructor******/
     ~Game();

     /**************************inline getters******************************/
     /**
      * @brief return pointer to team 1
      */ 
     Team & getTeam1(){return *this->team1;}
     /**
      * @brief return pointer to team 2
      */ 
     Team & getTeam2(){return *this->team2;}
     /**
      * @brief return the score of team 1
      */ 
     int getScore1(){return this->team1_score;}
     /**
     * @brief return the score of team 2
     */ 
     int getScore2(){return this->team2_score;}

     /************************inline setters**************************/
     /**
     * @brief set team1 to be team_1 by refernce
     */ 
     void setTeam1(Team & team_1){this->team1 = &team_1;}
     /**
     * @brief set team2 to be team_1 by refernce
     */ 
     void setTeam2(Team & team_2){this->team2 = &team_2;}
     /**
     * @brief add score to team1
     */ 
     void setScore1(int score);
     /**
      * @brief add score to team2
      * 
      * @param score 
      */
     void setScore2(int score);
    
    /*****************************class methods****************************/
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
     * @brief check wich team have more seq of wins  
     */
    void score_by_moral();
    /**
     * @brief if the scores are equal 
     * 
     */
    void determine_game();
    /**
     * @brief play the game
     * 
     */
    void play();


    /*****operators******/
    friend std::ostream &operator<<(std::ostream &output,  Game &game);
 };
};


