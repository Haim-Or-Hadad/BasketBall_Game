#include "Game.hpp" 
#include <iostream>
#include <random>
#include <cmath>


using namespace std;

const int _10 = 10;
const int _8 = 8;
const int _9 = 9;
const int _3 = 3;
const int forbidden_score = 50;
random_device rd{};
mt19937 gen{rd()};
normal_distribution<> home{73,8.8};
normal_distribution<> out{72,8.7};

 namespace ariel
 {

 Game::Game(Team & home_team, Team & outside_team)
 {
     this->team1= &home_team;
     this->team2 = &outside_team;
     this->team1_score = 0;
     this->team2_score = 0;
 }
 
 Game::~Game(){}

 void Game::score_by_talent()
    {     
    if (team1->getTalent() > team2->getTalent())
     {
         score_teams(_9 , _8 , _8 ,_3);
     }
     else
     {
         score_teams(_9 , _8 , _8 ,_3);
     }   
    }

void Game::score_by_moral()
{
    if (team1->getWins() > team2->getWins())
    {
        this->setScore1(_3);
    }
    else
    {
        this->setScore2(_3);
    }
    
    
}


void Game::determine_game()//if scores are equals
{
     if (getScore1() < forbidden_score)
     {
         this->setScore1(forbidden_score-getScore1() + _10);//because home team score must be greater that 55
     }
    if (getScore2() < forbidden_score)
     {
         this->setScore2(forbidden_score-getScore2());
     }
}
void Game::score_teams(int x , int y , int z , int t){
    this->setScore1(rand()%x+y);
    this->setScore2(rand()%z+t);
}

 void Game::play(){
     if (this->getScore1() > 0 || this->getScore2() >0)
     {
         __throw_invalid_argument("The game has already played");
     }
     //add points by Group data
     this->setScore1(round(home(gen)));
     this->setScore2(round(out(gen)));
     this->score_by_talent();
     if (getScore1() == getScore2())
     {
        this->score_by_moral();
     }
    this->determine_game();
     team1->set_points(getScore1(), getScore2());
     team2->set_points(getScore2(), getScore1());
    
     if (getScore1() > getScore2())
     {
        team1->setWins(1);
        team2->setLosses(1);
     }
     else 
     {
        team2->setWins(1);
        team1->setLosses(1);
     }
         
     
     
        
 }

/**************************getters******************************/
Team & Game::getTeam1() const
{
return *this->team1;
}

Team & Game::getTeam2() const
{
return *this->team2;
}

int Game::getScore1() const
{
return this->team1_score;
}

int Game::getScore2() const
{
return this->team2_score;
}
Team & Game::getWinner(){
return *this->winner;
}
/************************setters**************************/
void Game::setTeam1(Team & team_1)
{
this->team1 = &team_1;
}

void Game::setTeam2(Team & team_2)
{
this->team2 = &team_2;
}

void Game::setScore1(int score)
{
if (score < 0){
    __throw_invalid_argument("score must be positive number");
}
this->team1_score += score;
}

void Game::setScore2(int score)
{
if (score < 0){
    __throw_invalid_argument("score must be positive number");
}
this->team2_score += score;
}

void Game::setWinner(Team & team){
this->winner = &team;
}

 ostream &operator<<(ostream &output,  Game &game)
 {

     
     output << game.getTeam1().getName();
     output << "      ";
     output << game.getTeam2().getName();
     output << endl;
     output << game.getScore1();
     output << "            ";
     output << game.getScore2();
 return output;
 }
 };