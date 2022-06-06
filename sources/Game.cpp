#include "Game.hpp" 
#include <iostream>
#include <time.h>

using namespace std;

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


void Game::setScore1(int score){
    if (score < 0){
        __throw_invalid_argument("score must be positive number");
    }
    this->team1_score += score;
    }

void Game::setScore2(int score){
    if (score < 0){
        __throw_invalid_argument("score must be positive number");
    }
    this->team2_score += score;
    }
    
 void Game::score_by_height()
 {
     if (team1->getHeight() > team2->getHeight())
     {
         this->setScore1(rand()%11+10);
         this->setScore2(rand()%8+17);
     }
     else
     {
         this->setScore1(rand()%8+7);
         this->setScore2(rand()%11+10);
     }
 }

 void Game::score_by_talent()
    {
        
    if (team1->getTalent() > team2->getTalent())
     {
         this->setScore1(rand()%13+12);
         this->setScore2(rand()%12+11);
     }
     else
     {
         this->setScore2(rand()%13+12);
         this->setScore1(rand()%11+10);
     }   
    }

void Game::score_homeGame()
{
    this->setScore1(rand()%11+10);
    this->setScore2(rand()%10+9);
}

void Game::num_of_Shooting_Guard()
{
    if (team1->get_shooting() > team2->get_shooting())
    {
        this->setScore1(rand()%19+17);
        this->setScore2(rand()%18+16);
    }
    else
    {
        this->setScore1(rand()%18+16);
        this->setScore2(rand()%19+17);
    }
    
    
}

void Game::score_by_winning()
{
    if (team1->getWins() > team2->getWins())
    {
        this->setScore1(6);
    }
    else
    {
        this->setScore2(6);
    }  
}

void Game::score_by_moral()
{
    if (team1->get_seq_wins() > team2->get_seq_wins())
    {
        this->setScore1(2);
    }
    else
    {
        this->setScore2(2);
    }
    
    
}

void Game::score_star_team()
{
    if(team1->star())
    {
        this->setScore1(6);
    }
    if(team2->star())
    {
        this->setScore2(6);
    }
}

void Game::determine_game()
{
     if (getScore1() == getScore2())
     {
         team1->star() ? this->setScore1(3) : this->setScore2(4);
     }
     if (getScore1() < 55)
     {
         this->setScore1(55-getScore1());
     }
    if (getScore2() < 55)
     {
         this->setScore1(55-getScore2());
     }
    // if (getScore1() > 100)
    //  {
    //      this->setScore1(-(getScore1()-100));
    //  }
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
     team1->add_game();
     team2->add_game();
     this->determine_game();
     if (getScore1() > getScore2())
     {
         /*****team 1*********/
        team1->add_seq_of_win(1);
        team1->reset_seq_loss();
        team1->addWin();
        /*****team 2*********/
        team2->reset_seq_win();
        team2->add_seq_of_loss(1);
        team2->addLoss();
     }
     else 
     {
        /*****team 2*********/
        team1->add_seq_of_win(1);
        team1->reset_seq_loss();
         team2->addWin();
        /*****team 1*********/
        team1->add_seq_of_loss(1);
        team1->reset_seq_win();
        team1->addLoss();
     }
         
     
     
        
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
     output << endl;
 return output;
 }
 };