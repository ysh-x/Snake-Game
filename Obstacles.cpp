#include "Obstacles.h"
#include "settings_constants.h"

vector<pair<int, int>> obstacles;
const char obsElement = '|';

pair<int, int> makeObstacles()
{

     int x = (rand() % (LINES - 2)) + 1;
     int y = (rand() % (COLS - 2)) + 1;

     return {x, y};
}

void paintObstacles()
{
     for (int i = 0; i < obstacles.size(); i++)
     {
          move(obstacles[i].first, obstacles[i].second);
          addch(obsElement);
     }
}
void initObstacles()
{
     obstacles.clear();
     for (int i = 0; i < 10; i++)
     {
          obstacles.push_back(makeObstacles());
     }
}

bool hittingObstacles(pair<int, int> head)
{

     for (int i = 0; i < obstacles.size(); i++)
     {
          if (obstacles[i].first == head.first && obstacles[i].second == head.second)
          {
               obstacles.erase(obstacles.begin() + i);
               obstacles.push_back(makeObstacles());
               return true;
          }
     }
     return false;
}