
#ifndef Player_H
#define Player_H

#include <string>
#include <iostream>
#include "Role.cpp"
//#include "Team.hpp"
namespace ariel
{

class Team;
class Player
{
private:
    std::string name;
    int age;
    std::string role;
    Team *team;

public:
    /*****defualt constructor*****/
    Player();
    /*****Player constructor******/
    Player(std::string name, int age, Team &team)
    {
        this->name = std::move(name);
        this->age = age;
        this->role = roles[rand() % roles.size()];//take one name from enum 
        this->team = &team ;//need to complete!!!!!!!!!
    }
    ~Player(){};

    /***********inline getters*************/
    Team &getTeam(){return *this->team;}
    std::string &getRole(){return this->role;}
    int getAge(){return this->age;}
    std::string &getName(){return this->name;}

    /********inline setters***************/
    void setTeam(Team *other_team){this->team = other_team;}
    void setRole(std::string other_role){this->role = other_role;}
    void setAge(int other_age){this->age = other_age;}
    void setName(std::string &other_name){this->name = other_name;}
    
    
    std::vector<std::string> roles = 
    {"Point_Guard",
     "Shooting_Guard",
      "Small_Forward",
       "Power_Forward",
        "Center"};
    };



};
#endif