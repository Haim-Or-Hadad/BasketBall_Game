#include "Team.hpp"
#include <iostream>
#include <time.h>

using namespace std;
int myvar=0;

namespace ariel
{
Team::Team(){
    this->name = Group_names.at(myvar++%20);
    this->setLosses(0);
    this->setWins(0);
    this->setTalent((double)rand()/(double)RAND_MAX);//talent between 0 to 1
    this->height = rand()%20+10;//height's sum of team is between 10 to 20
    this->num_of_Shooting_Guard = rand()%2+1;//the team have 1 or 2 shooting guard
    this->shot_points = 0;
    this->absorb_points =0;
    this->have_star = rand()%2+1;//the team have 1 or 2 star
}   

Team::Team(string name, int wins, int losses, double talent,int height){
    this->setLosses(losses);
    this->setWins(wins);
    this->setName(name);//this->name=name;
    this->setTalent(talent);//this->talent=talent;
    this->height = height;
    this->num_of_Shooting_Guard = rand()%2+1;
    this->shot_points = 0;
    this->absorb_points =0;
    this->have_star = rand()%2+1;
    }

Team::Team(string name){
    this->setName(name);
    this->setLosses(0);
    this->setWins(0);
    this->setTalent((double)rand()/(double)RAND_MAX);//talent between 0 to 1
    this->height = rand()%20+10;
    this->num_of_Shooting_Guard = rand()%2+1;
    this->shot_points = 0;
    this->absorb_points =0;
    this->have_star = rand()%2+1;
    this->num_of_games = 0;
}

void Team::setName(std::string name){
    if (name == "")
    {
        __throw_invalid_argument("team must have a name");
    }
    this->name = name;}

void Team::setWins(int num_of_wins)
{
    if ( 38 <= num_of_wins || num_of_wins < 0)
    {
        __throw_invalid_argument("any team can reach 38 wins and can't to wins negative numbers");
    }
    this->wins = num_of_wins;
    if ( this->getWins()  > 38)
    {
        __throw_invalid_argument("team can't reach more then 38 wins ");
    }
}

void Team::setLosses(int num_of_losses)
{
    if ( 38 <= num_of_losses || num_of_losses < 0)
    {
        __throw_invalid_argument("any team can reach 38 losses and can't to losses negative numbers");
    }
    this->losses = num_of_losses;
    if ( this->getLosses()> 38)
    {
        __throw_invalid_argument("team can't reach more then 38 losses ");
    }
}

void Team::addWin()
{
    this->setWins(this->wins+1);
}

void Team::addLoss()
{
    this->setLosses(this->losses+1);
}

bool operator<(Team &s1,Team &s2)
{
    return s1.getWins() < s2.getWins();
}

ostream& operator<<(ostream& output,Team & team)
{
    output << team.getName() << ": ";
    output << "talent: " << team.getTalent();
    output << "height: " << team.getHeight();
    output << "num_of_Shooting_Guard: " << team.get_shooting();
    output << "have star: " << team.star();
    output << "wins: " << team.getWins();
    output << "losses: " << team.getLosses();
    output << endl;
    return output;
}
};