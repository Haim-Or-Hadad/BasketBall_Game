#ifndef Team_H
#define Team_H


#include <vector>
#include <string>
#include "Role.hpp"
//#include "Player.hpp"

namespace ariel
{
class Team{
    std::string name;
    int wins;
    int losses;
    double talent;
public:
    /*****defualt constructor*****/
    Team();
    /*****Team constructor*****/
    Team(std::string & name, int wins, int losses, double talent);//, std::vector<Player*> & Players
    /*****Team constructor with name****/
    Team(std::string name);
    ~Team(){};

    /*******inline getters******/
    std::string &getName(){return this->name;}
    int getWins(){return this->wins;}
    int getLosses(){return this->losses;}
    int getTalent(){return this->talent;}
    //std::vector<Player*> &getPlayers(){return *this->Players;}
    //std::vector<string*> &getPlayers_name(){return *this->P;}
    /*******inline setters******/
    void setName(std::string &name){this->name = name;}
    void setWins(int num_of_wins){this->wins = num_of_wins;}
    void setLosses(int num_of_losses){this->losses = num_of_losses;}
    void setTalent(double talent_of_team){this->talent = talent_of_team;}
    //void setPlayers(std::vector<Player*> & O){this->Players = &O;}

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

    /****** Team operators********/
    bool operator ==(Team & t);
    //friend ostream& operator<<(ostream& output,Team const & team_);
};
};
#endif