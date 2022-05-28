#ifndef Leauge_H
#define Leauge_H
 #include "Player.hpp"
 #include "Team.hpp"


namespace ariel
{
class Leauge
{
private:
    std::vector<Team*> all_teams;
    int year;
    Team *best_team;

public:
    /*****League constructor******/
    Leauge(std::vector<Team*> curr_teams);
    /*****defualt constructor*****/
    Leauge();

    ~Leauge(){};

    /******inline getters*********/
    std::vector<Team*> get_all_teams(){return this->all_teams;}
    int get_year_of_leauge(){return this->year;}
    Team & get_best_team(){return *this->best_team;}

    /******inline setters********/
    void set_teams(std::vector<Team*> teams){this->all_teams = teams;}
    void set_year_of_leauge(int curr_year){this->year = curr_year;}
    void set_best_team(Team *t){this->best_team = t;}

    /****simulate new full leaugue****/
    void build_leauge();
    void complete_leauge(std::vector<Team*> teams);

     friend std::ostream &operator<<(std::ostream &output,  Leauge &Leauge);
};

};
#endif