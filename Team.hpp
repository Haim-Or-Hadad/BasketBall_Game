#ifndef Team_H
#define Team_H


#include <vector>
#include <string>

#include "Player.hpp"

namespace ariel
{
class Team{
    std::string name;
    int wins;
    int losses;
    double talent;
    std::vector<Player*> *Players;
public:
    /*****defualt constructor*****/
    Team();
    /*****Team constructor*****/
    Team(std::string & name, int wins, int losses, double talent, std::vector<Player*> & Players);
    /*****Team constructor with name****/
    Team(std::string name);
    ~Team(){};

    /*******inline getters******/
    std::string &getName(){return this->name;}
    int getWins(){return this->wins;}
    int getLosses(){return this->losses;}
    int getTalent(){return this->talent;}
    std::vector<Player*> &getPlayers(){return *this->Players;}
    //std::vector<string*> &getPlayers_name(){return *this->P;}
    /*******inline setters******/
    void setName(std::string &name){this->name = name;}
    void setWins(int num_of_wins){this->wins = num_of_wins;}
    void setLosses(int num_of_losses){this->losses = num_of_losses;}
    void setTalent(double talent_of_team){this->talent = talent_of_team;}
    void setPlayers(std::vector<Player*> & O){this->Players = &O;}

    /******class methods******/
    /**
     * @brief Add one point to the team that winning the game
     */    
    void addWin();
    /**
     * @brief Lowers one point to the team that lossing in the game
     * 
     */
    void addLoss();
    /**
     * @brief Add player to the team
     * @param player - Player to be added 
     */
    void addPlayer(Player & player);
    /**
     * @brief Add a list of player to the team
     * @param players list/vector to be added
     */
    void addTeam(std::vector<Player*> & players_);
    /**
     * @brief Remove player from the team
     * @param player to be removed
     */
    void removePlayer(Player & player);
    /**
     * @brief Create a random players list
     * 
     */
    void  create_random_players();//{
    // Team *t = new Team();
    // t->name ="maccaabi";
    // // t->losses =0;
    // // t->wins =0;
    // t->Players = new vector<Player*>;
    // // t->talent = 0.5;
    // return *t;
    // }
    /****** Team operators********/
    bool operator ==(Team & t);
    //friend ostream& operator<<(ostream& output,Team const & team_);
};
};
#endif