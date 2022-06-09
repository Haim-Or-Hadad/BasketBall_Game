#pragma once 

#include "Team.hpp"

namespace ariel
{
 class Game
 {
/**
 * @brief This class represents the game of two teams that play and the
 *  points of each team throughout the game and at the end.
 * @param team1:team 1 details
 * @param team2:team 2 details
 * @param team1_score: score of team 1 in current game
 * @param team2_score: score of team 2 in current game
 * @param winner : set winner of the game
 */
 private:
     Team *team1;
     Team *team2;
     Team *winner;
     int team1_score;
     int team2_score;
     
 public:
     /*****Game constructor******/
     Game(Team & home_team, Team & outside_team);
     /******Game destructor******/
     ~Game();
    //  //move constructor
    //  Game(Game &&) noexcept;
    //  //copy constructor
    //  Game(Game & game){
    //     this->team1 = game.team1;
    //     this->team2 = game.team2;
    //     this->team1_score = game.getScore1();
    //     this->team2_score = game.getScore2();
    //  }
     /**************************getters******************************/
     /**
      * @brief return pointer to team 1
      */ 
     Team & getTeam1() const;
     /**
      * @brief return pointer to team 2
      */ 
     Team & getTeam2() const;
     /**
      * @brief return the score of team 1
      */ 
     int getScore1() const;
     /**
     * @brief return the score of team 2
     */ 
     int getScore2() const;
        /**
      * @brief get the winner team
      * 
      */
     Team & getWinner();

     /************************setters**************************/
     /**
     * @brief set team1 to be team_1 by refernce
     */ 
     void setTeam1(Team & team_1);
     /**
     * @brief set team2 to be team_1 by refernce
     */ 
     void setTeam2(Team & team_2);
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
     /**
      * @brief set the winner team
      * 
      */
     void setWinner(Team * team);
    
    /*****************************class methods****************************/
    /**
     * @brief add score between 12-13 to the talenter team
     * and 10-11 to other team
     */
    void score_by_talent();
    /**
     * @brief team that have more winning get more score
     * 
     */
    void score_by_winning();
    /**
     * @brief check wich team have more seq of wins  
     */
    void score_by_moral();
    /**
     * @brief score the teams in random according to the figure
     * 
     */
    void score_teams(int x , int y , int z, int t);
     /**
     * @brief if the scores are equal check which team have star
     * 
     */
    void determine_game();
    /**
      * @brief set the winner team
      * 
      */
     void setWinner(Team & team);
    /**
     * @brief play the game
     * 
     */
    void play();


    /*****operators******/
    friend std::ostream &operator<<(std::ostream &output,  Game &game);
    Game& operator=(const Game& game);//{
    //     this->team1 = game.team1;
    //     this->team2 = game.team2;
    //     this->team1_score = game.getScore1();
    //     this->team2_score = game.getScore2();
    // }
    
 };
};


