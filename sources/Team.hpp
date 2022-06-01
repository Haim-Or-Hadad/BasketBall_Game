#pragma once 

#include <vector>
#include <string>
#include "names.hpp"


namespace ariel
{
/**
 * @brief This class saves the group data
 * @param name - name of the group
 * @param shot_points - number of shot the rock of all season
 * @param wins - num of wins
 * @param losses - num of losses
 * @param talent - the talent of the team - number between 0 to 1
 * @param height - the sum of heights of the team
 * @param num_of_Shooting_Guard - the number of shooting guars that play in team
 * @param absorb_points - the points that the team absorb
 * @param have_star - if the group have star-1, else -0
 * @param num_of_games - how muve games the team play until now
 */    
class Team{
    std::string name;
    int shot_points;
    int wins;
    int losses;
    double talent;
    int height;
    int num_of_Shooting_Guard;
    int absorb_points;
    int have_star;
    int num_of_games;
    int seq_of_win;
    int seq_of_loss;

public:
    /********defualt constructor*********/
    Team();
    /**********Team constructor**********/
    Team(std::string name, int wins, int losses, double talent,int height);//, std::vector<Player*> & Players
    /*****Team constructor with name****/
    Team(std::string name);
    /*********Team destructor**********/
    ~Team(){};

    /******************************inline getters***********************************/
    /**
     * @brief getter:return name of team 
     */
    std::string getName(){return this->name;}
    /**
     * @brief getter:return wins number of the team  
     */
    int getWins(){return this->wins;}
    /**
     * @brief getter:return losses number of the team
     */
    int getLosses(){return this->losses;}
    /**
     * @brief getter:return the talent of team in integer
     */
    int getTalent(){return this->talent;}
    /**
     * @brief getter:return sum of heights of the players in the team
     */
    int getHeight(){return this->height;}
    /**
     * @brief getter:return number of shooting's players 
     */
    int get_shooting(){return this->num_of_Shooting_Guard;}
    /**
     * @brief getter:return true if have star to the team,else return 0
     */
    bool star(){return this->have_star == 1;}
    /**
     * @brief getter:return the relation between shoting points to absorb points of all team's games
     */
    int get_Points_ratio(){return shot_points-absorb_points;}
    /**
     * @brief getter:return number of games the team play until now
     */
    int get_num_of_games(){return this->num_of_games;}
    /**
     * @brief getter:return the number of sequence win of team
     */
    int get_seq_wins(){return this->seq_of_win;}
    /**
     * @brief getter:return the number of sequence loss of team
     */
    int get_seq_losses(){return this->seq_of_loss;}


    /***********************************inline setters***********************************/
    /**
     * @brief setter:set team name 
     */
    void setName(std::string name){this->name = name;}
    /**
     * @brief setter:set wins of the team  
    */
    void setWins(int num_of_wins){this->wins = num_of_wins;}
    /**
     * @brief setter:set Losses of team
     */
    void setLosses(int num_of_losses){this->losses = num_of_losses;}
    /**
     * @brief setter:set talent of the team
     */
    void setTalent(double talent_of_team){this->talent = talent_of_team;}
    /**
     * @brief setter:set points of team in current game
     */
    void set_points(int num){this->shot_points +=num;}
    /**
     * @brief setter:set absorb points of team in all games
     */
    void set_absorb_points(int num){this->absorb_points +=num;}
    /**
     * @brief setter:add one to the num of games
     */
    void add_game(){this->num_of_games++;}
    /**
     * @brief setter:add one to sequence of wins
     */
    void add_seq_of_win(int num){this->seq_of_win += num;}
    /**
     * @brief setter:add one to sequence of losses
     */
    void add_seq_of_loss(int num){this->seq_of_loss += num;}
    /**
     * @brief setter:reset the sequence
     */
    void reset_seq_win(){this->seq_of_win=0;}
    /**
     * @brief setter:reset the sequence
     */
    void reset_seq_loss(){this->seq_of_loss=0;}


    /*****************************class methods****************************/
    /**
     * @brief Add one point to the team that winning the game
     */    
    void addWin();
    /**
     * @brief Lowers one point to the team that lossing in the game
     * 
     */
    void addLoss();

    /***************************** Team operators*************************/
    bool operator ==(Team & t);
    friend bool operator<( Team &s1,  Team &s2);
    friend std::ostream& operator<<(std::ostream& output,Team & team);
    
    };
};
