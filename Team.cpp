#include "Team.hpp"
#include "Player.hpp"

using namespace std;

namespace ariel
{
Team::Team(){
    this->name ="maccaabi";
    this->losses =0;
    this->wins =0;
    this->Players = new vector<Player*>;
    this->talent = 0.5;

}   

Team::Team(string & name, int wins, int losses, double talent, std::vector<Player*> & Players){
    this->setLosses(losses);
    this->setWins(wins);
    this->setName(name);//this->name=name;
    //this->setPlayers(Players);//this->Players= Players;
    this->setTalent(talent);//this->talent=talent;
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

void Team::addPlayer(Player & player)
{
    this->Players->push_back(&player);
    player.setTeam(this);
}

void Team::addTeam(vector<Player*> & players_)
{
    for (Player * player_ : players_)
    {
        addPlayer(*player_);
    }
    
// void Team::removePlayer(Player & player)
// {
//     for
// }

/******operators*******/
//  bool Team::operator ==(Team & t)
//  {

//  }
}

};