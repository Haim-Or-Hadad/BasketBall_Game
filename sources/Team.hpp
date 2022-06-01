// #ifndef Team_H
// #define Team_H
#pragma once 

#include <vector>
#include <string>
#include "Role.hpp"
//#include "Player.hpp"

namespace ariel
{
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
    /*****defualt constructor*****/
    Team();
    /*****Team constructor*****/
    Team(std::string name, int wins, int losses, double talent,int height);//, std::vector<Player*> & Players
    /*****Team constructor with name****/
    Team(std::string name);
    ~Team(){};

    /*******inline getters******/
    std::string getName(){return this->name;}
    int getWins(){return this->wins;}
    int getLosses(){return this->losses;}
    int getTalent(){return this->talent;}
    int getHeight(){return this->height;}
    int get_shooting(){return this->num_of_Shooting_Guard;}
    bool star(){return this->have_star == 1;}
    int get_Points_ratio(){return shot_points-absorb_points;}
    int get_num_of_games(){return this->num_of_games;}
    int get_seq_wins(){return this->seq_of_win;}
    int get_seq_losses(){return this->seq_of_loss;}
    //std::vector<Player*> &getPlayers(){return *this->Players;}
    //std::vector<string*> &getPlayers_name(){return *this->P;}
    /*******inline setters******/
    void setName(std::string name){this->name = name;}
    void setWins(int num_of_wins){this->wins = num_of_wins;}
    void setLosses(int num_of_losses){this->losses = num_of_losses;}
    void setTalent(double talent_of_team){this->talent = talent_of_team;}
    void set_points(int num){this->shot_points +=num;}
    void set_absorb_points(int num){this->absorb_points +=num;}
    void add_game(){this->num_of_games++;}
    void add_seq_of_win(int num){this->seq_of_win += num;}
    void add_seq_of_loss(int num){this->seq_of_loss += num;}
    void reset_seq_win(){this->seq_of_win=0;}
    void reset_seq_loss(){this->seq_of_loss=0;}
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
     friend bool operator<( Team &s1,  Team &s2);

    friend std::ostream& operator<<(std::ostream& output,Team & team);
};
};
// #endif