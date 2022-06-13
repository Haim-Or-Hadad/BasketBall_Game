#include "Team.hpp"
#include <iostream>

#include <vector>
#include <string>
#include <array>


using namespace std;
int myvar=0;
int const TEAMS_SIZE = 20;
int const ROUNDS_SIZE = 38;
const std::vector<std::string> Group_names =
{"Los_Angeles_Lakers","Boston_Celtics","Golden_State","Philadelphia","Chicago_Bulls","San_Antonio","Miami_Heat",
"New_York_Knicks","Houston","Milwaukee","Cleveland_Cavaliers","Dallas","Toronto","Phoenix_Suns","Slammed","Ball_Hogz",
"Utah_","Nets","Orlando_Magic","Chicago","Washington"};


namespace ariel
{
Team::Team() : Team((Group_names.at(myvar++%TEAMS_SIZE))){}
    
Team::Team(string const & name) : name(name),losses(0),wins(0),
                                  talent((double)rand()/(double)RAND_MAX),
                                  shot_points(0),absorb_points(0){
    if (name.empty())
    {
        __throw_invalid_argument("team must have a name");
    }
}

    // Copy constructor
    Team::Team(const Team &other_team): 
            name(std::move(other_team.getName())),
            wins(other_team.wins),
            losses(other_team.losses),
            talent(other_team.talent),
            shot_points(other_team.shot_points),
            absorb_points(other_team.absorb_points){}


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

int Team::get_Points_ratio()const
{
return shot_points-absorb_points;
}//return the relation between shoting points to absorb points of all team's games
 


/***********************************setters***********************************/

void Team::setName(string const & name){
    if (name.empty())
    {
        __throw_invalid_argument("team must have a name");
    }
    this->name = name;}

void Team::setWins(int  num_of_wins)
{
    if ( ROUNDS_SIZE < num_of_wins || num_of_wins < 0)
    {
        __throw_invalid_argument("any team can reach 38 wins and can't to wins negative numbers");
    }
    this->wins += num_of_wins;
    if ( this->getWins()  > ROUNDS_SIZE)
    {
        __throw_invalid_argument("team can't reach more then 38 wins ");
    }
}

void Team::setLosses(int  num_of_losses)
{
    if ( ROUNDS_SIZE < num_of_losses || num_of_losses < 0)
    {
        __throw_invalid_argument("any team can reach 38 at mostlosses and can't to losses negative numbers");
    }
    this->losses += num_of_losses;
    if ( this->getLosses()> ROUNDS_SIZE)
    {
        __throw_invalid_argument("team can't reach more than 38 losses ");
    }
}

void Team::set_points(int num , int num2)
{
this->absorb_points +=num2;
this->shot_points +=num;
}


// Copy Assignment Operator.
Team & Team::operator=(const Team &other_team){
    this->name = other_team.getName();
    return *this;
}
    

ostream& operator<<(ostream& output,Team & team)
{
    output << team.getName() << ": ";
    output << "talent: " << team.getTalent();
    output << "| wins: " << team.getWins();
    output << "| losses: " << team.getLosses();
    output << endl;
    return output;
}
};