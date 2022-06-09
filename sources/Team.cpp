#include "Team.hpp"
#include <iostream>

using namespace std;
int myvar=0;
int const teams_size = 20;
int const rounds_size = 38;


namespace ariel
{
Team::Team(): Team(Group_names.at(myvar++%teams_size)){}
    

Team::Team(string const & name){
    this->setName(name);
    this->losses = 0;
    this->wins = 0;
    this->talent = ((double)rand()/(double)RAND_MAX);//talent between 0 to 1
    this->height = rand()%teams_size+(teams_size/2);//height between 10 to 20
    this->num_of_Shooting_Guard = rand()%2+1;//2 or 1 shoots player
    this->shot_points = 0;
    this->absorb_points =0;
    this->have_star = rand()%1+0;//the tea have one star at most
}

////////////////////////getters//////////////////////////
string Team::getName()const
{
return this->name;
}//return name of team

int Team::getWins()const
{
return this->wins;
}//return wins number of the team

int Team::getLosses()const
{
return this->losses;
}//return losses number of the team

double Team::getTalent()const
{
return this->talent;
}//return the talent of team

int Team::getHeight()const
{
return this->height;
}//return sum of heights of the players in the team
    
int Team::get_shooting()const
{
return this->num_of_Shooting_Guard;
}//return number of shooting's players

bool Team::star()const
{
return this->have_star == 1;
}//return true if have star to the team,else return 0

int Team::get_Points_ratio()const
{
return shot_points-absorb_points;
}//return the relation between shoting points to absorb points of all team's games
 


/***********************************setters***********************************/

void Team::setName(std::string const & name){
    if (name.empty())
    {
        __throw_invalid_argument("team must have a name");
    }
    this->name = name;}

void Team::setWins(int  num_of_wins)
{
    if ( rounds_size < num_of_wins || num_of_wins < 0)
    {
        __throw_invalid_argument("any team can reach 38 wins and can't to wins negative numbers");
    }
    this->wins += num_of_wins;
    if ( this->getWins()  > rounds_size)
    {
        __throw_invalid_argument("team can't reach more then 38 wins ");
    }
}

void Team::setLosses(int  num_of_losses)
{
    if ( rounds_size < num_of_losses || num_of_losses < 0)
    {
        __throw_invalid_argument("any team can reach 38 at mostlosses and can't to losses negative numbers");
    }
    this->losses += num_of_losses;
    if ( this->getLosses()> rounds_size)
    {
        __throw_invalid_argument("team can't reach more then 38 losses ");
    }
}

void Team::set_points(int num)
{
this->shot_points +=num;
}

void Team::set_absorb_points(int num)
{
this->absorb_points +=num;
}


ostream& operator<<(ostream& output,Team & team)
{
    output << team.getName() << ": ";
    output << "talent: " << team.getTalent();
    output << "| height: " << team.getHeight();
    output << "| num_of_Shooting_Guard: " << team.get_shooting();
    output << "| have star: " << team.star();
    output << "| wins: " << team.getWins();
    output << "| losses: " << team.getLosses();
    output << endl;
    return output;
}
};