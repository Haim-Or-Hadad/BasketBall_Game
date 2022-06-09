#pragma once 

#include "iostream"
#include "Team.hpp"


namespace ariel
{
class Leauge
{
private:
    std::vector<Team*> *all_teams;
public:
    /*****League constructor******/
    Leauge(std::vector<Team*> & curr_teams);
    /*****defualt constructor*****/
    Leauge();

    ~Leauge(){};

    /******getters*********/
    std::vector<Team*> &get_all_teams(){return *this->all_teams;}

    /******inline setters********/
    void set_teams(std::vector<Team*> *teams){this->all_teams = teams;}
    //void set_best_team(Team *t){this->best_team = t;}

    /****simulate new full leaugue****/
    void build_leauge();
    void complete_leauge(std::vector<Team*> *teams);
    
//     void load_file(){
//         std::ifstream fin;
//         fin.open("input.txt", ios::app);
//         fin.read(all_teams, sizeof(team));
//         while (!fin.eof()) {
//         Team * team;
//         fin.read((char*)&team, sizeof(team));
//     }
//         if (!fin) {
//         //std::cout << "Error in opening the file" << std::endl;
//         //return 1; // if this is main
//         }
//         while (fin) {
//         std::string name = "h";
//         fin >> name;
//         std::cout << name << std::endl;
//         Team temp{name};
//         all_teams->push_back(&temp);
// }

    //}
     friend std::ostream &operator<<(std::ostream &output,  Leauge &Leauge);
};

};
