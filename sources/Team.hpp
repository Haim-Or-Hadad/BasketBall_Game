#pragma once 


#include "names.hpp"


namespace ariel
{
/**
 * @brief This class creates a new team with random data of team height, talent, number of shots the team has,
 * if the team have a star.
 * The team also includes a balance of  victories and losses during the season, as well as points it has 
 * scored and those it has absorbed.
 * @param name - name of the group
 * @param shot_points - number of shot the rock of all season
 * @param wins - num of wins
 * @param losses - num of losses
 * @param talent - the talent of the team - number between 0 to 1
 * @param absorb_points - the points that the team absorb
 */    
class Team{
    std::string name;
    int wins;
    int losses;
    double talent;
    int shot_points;
    int absorb_points;
public:
    /********defualt constructor*********/
    Team();
    /*****Team constructor with name****/
    Team(std::string const & name);
    /*********Team destructor**********/
    ~Team(){};

    /******************************getters***********************************/
    /**
     * @brief getter:return name of team 
     */
    std::string getName() const;
    /**
     * @brief getter:return wins number of the team  
     */
    int getWins() const;
    /**
     * @brief getter:return losses number of the team
     */
    int getLosses()const;
    /**
     * @brief getter:return the talent of team in double
     */
    double getTalent()const;
    /**
     * @brief getter:return the relation between shoting points to absorb points of all team's games
     */
    int get_Points_ratio()const;
    /***********************************setters***********************************/
    /**
     * @brief setter:set team name 
     */
    void setName(std::string const & name);
    /**
     * @brief setter:set wins of the team  
    */
    void setWins(int  num_of_wins);
    /**
     * @brief setter:set Losses of team
     */
    void setLosses(int  num_of_losses);
    /*
     * @brief setter:set points of team in current game
     */
    void set_points(int  num, int num2);
    /***************************** Team operators*************************/
    bool operator ==(Team & t);
    friend std::ostream& operator<<(std::ostream& output,Team & team);
    
    };
};
