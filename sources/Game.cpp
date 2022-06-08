#include "Game.hpp" 
#include <iostream>


using namespace std;
const int _11 = 11;
const int _10 = 10;
const int _8 = 8;
const int _9 = 9;
const int _3 = 3;
const int _13 = 13;
const int _19 = 19;
const int _17 = 17;
const int forbidden_score = 55;

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


    
 void Game::score_by_height()
 {
     if (team1->getHeight() > team2->getHeight())
     {
         score_teams(_11 , _10 , _9 ,_8);
     }
     else
     {
         score_teams(_9 , _8 , _11 ,_10);
     }
 }

 void Game::score_by_talent()
    {     
    if (team1->getTalent() > team2->getTalent())
     {
         score_teams(_13 , _11 , _9 ,_3);
     }
     else
     {
         score_teams(_13 , _11 , _9 ,_3);
     }   
    }

void Game::score_homeGame()
{
    score_teams(_11 , _10 , _10 ,_9);
}

void Game::num_of_Shooting_Guard()
{
    if (team1->get_shooting() > team2->get_shooting())
    {
        score_teams(_19 , _17 , _10 ,_8);
    }
    else
    {
        score_teams(_17 , _13 , _10 ,_8);
    }
    
    
}

void Game::score_by_winning()
{
    if (team1->getWins() > team2->getWins())
    {
        this->setScore1(_8);
    }
    else
    {
        this->setScore2(_8);
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

void Game::score_star_team()
{
    if(team1->star())
    {
        this->setScore1(_8);
    }
    if(team2->star())
    {
        this->setScore2(_8);
    }
}

void Game::determine_game()
{
     if (getScore1() == getScore2())
     {
         team1->star() ? this->setScore1(_3) : this->setScore2(_3);
     }
     if (getScore1() < forbidden_score)
     {
         this->setScore1(forbidden_score-getScore1());
     }
    if (getScore2() < forbidden_score)
     {
         this->setScore1(forbidden_score-getScore2());
     }
}
void Game::score_teams(int x , int y , int z , int t){
    this->setScore1(rand()%x+y);
    this->setScore2(rand()%z+t);
}
 void Game::play(){
     // add points by Group data
     this->score_by_height();
     this->score_by_talent();
     this->score_homeGame();
     this->num_of_Shooting_Guard();
     this->score_by_winning();
     this->score_star_team();
     this->score_by_moral();
     team1->set_points(getScore1());
     team2->set_points(getScore2());
     team1->set_absorb_points(getScore2());
     team2->set_absorb_points(getScore1());
     this->determine_game();
     if (getScore1() > getScore2())
     {
         //looser = team2;
         /*****team 1*********/
        team1->setWins(1);
        /*****team 2*********/
        team2->setLosses(1);
     }
     else 
     {
         //looser = team1;
        /*****team 2*********/
         team2->setWins(1);
        /*****team 1*********/
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