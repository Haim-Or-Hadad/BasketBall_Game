#include "Team.hpp"
#include <iostream>
#include <time.h>

using namespace std;
int myvar=0;
namespace ariel
{
Team::Team(){
    
    this->name = Group_names.at(myvar++%20);
    this->losses =0;
    this->wins =0;
    this->setTalent((double)rand()/1+0);
    this->height = rand()%20+10;
    this->num_of_Shooting_Guard = rand()%2+1;
    this->shot_points = 0;
    this->absorb_points =0;
    this->have_star = rand()%2+1;
}   

Team::Team(string name, int wins, int losses, double talent,int height){//, std::vector<Player*> & Players
    //srand(time(NULL));
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
   // srand(time(NULL));
    this->name = name;
    this->losses =0;
    this->wins =0;
    this->talent = (double)rand()/1+0;
    this->height = rand()%20+10;
    this->num_of_Shooting_Guard = rand()%2+1;
    this->shot_points = 0;
    this->absorb_points =0;
    this->have_star = rand()%2+1;
}
/**
 * @brief Explenation about the methods in the header file!
 * 
 */
void Team::addWin()
{
    this->setWins(this->wins+1);
}

void Team::addLoss()
{
    this->setLosses(this->losses+1);
}

bool operator<(Team &s1,Team &s2){
    return s1.getWins() < s2.getWins();
    }

ostream& operator<<(ostream& output,Team & team)
{
    output << team.getName() << ": ";
    output << "talent: " << team.getTalent();
    output << "height: " << team.getHeight();
    output << "num_of_Shooting_Guard: " << team.get_shooting();
    output << "have star: " << team.star();
    output << endl;
    return output;
}
};