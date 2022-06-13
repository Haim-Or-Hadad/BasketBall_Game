#include "Game.hpp" 
#include <iostream>
#include <random>
#include <cmath>

using namespace std;

const int _10 = 10;
const int _4 = 4;
const int _6 = 6;
const int _3 = 3;
const int forbidden_score_50 = 50;
const int forbidden__home_score_55 = 55;
const int mean = 72;
const double Standard_Deviation1 = 8.5;
random_device rd{};
mt19937 gen{rd()};
normal_distribution<> normal_dist{mean,Standard_Deviation1};

 namespace ariel
 {

 Game::Game(Team & home_team, Team & outside_team) : team1(&home_team),
                                                     team2(&outside_team),
                                                    team1_score(0),
                                                    team2_score(0),
                                                    game_played(false){}

// Copy constructor.
 Game::Game(const Game &other_game) : team1(other_game.team1),
                                team2(other_game.team2),
                                team1_score(other_game.getScore1()),
                                team2_score(other_game.getScore2()),
                                game_played(other_game.game_played){}



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


void Game::determine_game()
{
     if (getScore1() < forbidden__home_score_55)
     {
         this->setScore1(forbidden__home_score_55-getScore1() + _10);//because home team score must be greater that 55
     }
    if (getScore2() < forbidden_score_50)
     {
         this->setScore2(forbidden_score_50-getScore2());
     }

}

void Game::score_teams(int x , int y , int z , int t){
    this->setScore1(rand()%x+y);
    this->setScore2(rand()%z+t);
}
double rand_score(){
        while (true) {
            double number = round(normal_dist(gen));
            if (number >= 55 && number <= 100)
                return number;
        }
}
 void Game::play(){
     if (played())
     {
         __throw_invalid_argument("The game has already played");
     }
     this->set_played();
     //add points by Group data
     this->setScore1(int(rand_score()));
     this->setScore2(int(rand_score()));
     if (getScore1() == getScore2())//if scores are equals
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
Team & Game::winner() const {
if (getScore1() > getScore2()){
   return *team1; 
}
return *team2;
}

Team & Game::looser() const {
if (getScore1() > getScore2()){
   return *team2; 
}
return *team1;
}

bool Game::played() const{
    return this->game_played;
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


void  Game::set_played(){
this->game_played = true;
}

// Copy Assignment Operator.
Game & Game::operator=(const Game &other_game){
    Game game(other_game);
    this->team1 = &game.getTeam1();
    this->team2 = &game.getTeam2();
    this->team1_score = game.getScore1();
    this->team2_score = game.getScore2();
    this->game_played = game.game_played;
    return *this;
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