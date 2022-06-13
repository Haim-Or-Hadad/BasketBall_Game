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
 */
 private:
     Team *team1;
     Team *team2;
     int team1_score;
     int team2_score;
    bool game_played;
     
 public:

     /*****Game constructor******/
     Game(Team & home_team, Team & outside_team);
    // Copy  constructor.
    Game(const Game &other_game);
     /******Game destructor******/
     ~Game(){};

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
      * @brief return pointer to winner team
      */ 
     Team & winner() const;
          /**
      * @brief return pointer to looser team
      */ 
     Team & looser() const;
     /**
      * @brief return the score of team 1
      */ 
     int getScore1() const;
     /**
     * @brief return the score of team 2
     */ 
     int getScore2() const;
     /**
      * @brief return true if game played , else return false
      * 
      */
     bool played() const;
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
     * @brief change the game to played
     * 
     */
    void set_played();
    /*****************************class methods****************************/
    /*
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
    // Copy Assignment Operator.
    Game & operator=(const Game &other_game);
    friend std::ostream &operator<<(std::ostream &output,  Game &game);
    
 };
};


