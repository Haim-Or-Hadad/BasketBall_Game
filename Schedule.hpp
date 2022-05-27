#include <iostream>
#include "string"
#include "vector"
#include "Game.hpp"
//#include "Team.hpp"
#include "Leauge.hpp"

namespace ariel
{
  class Schedule
  {
  private:
      std::vector<Game*> *games_list;
      std::vector<Team*> *team_list;
  public:
      //////constructor ger leauge////
      Schedule(Leauge *leauge , std::vector<Team*> *t_list);
      /////defualt constructor//////
      Schedule();

      ~Schedule();


      /*****getters********/
       std::vector<Game*> & getLeauge(){return *games_list;}
    

     void operate_arrangment();
  };
  
    
};
