#include "Snake.h"

using namespace std;

int x,y;
vector < pair < int , int > > body;
pair<int, int> snakeTail;

    void
    initSnake()
{
     body.clear();
     body.push_back({10,10});
     body.push_back({10,11});
     body.push_back({10,12});
     x = y = 10;
}

void paintSnake() {
     for(int i = 0; i < body.size(); i++) {
          pair < int , int > location = body[i];
          move(location.first ,location.second);
          addch('*');
     }
}

pair<int,int> moveSnake(int direction) {

     snakeTail = body[body.size() - 1];
     body.pop_back();

     pair <int, int> oldHead = body[0];
     pair <int,int> newHead = oldHead;

     if (direction == UP )
     {
          newHead.first--;
     }

     else if (direction == DOWN)
     {
          newHead.first++;
     }
     else if (direction == LEFT)
     {
          newHead.second--;
     }
     else if (direction == RIGHT)
     {
          newHead.second++;
     }

     body.insert(body.begin(),newHead);

     return newHead;
}

void growSnake() {
     body.push_back(snakeTail);
}

bool hasCollision() {
     if(body[0].first == 0 || body[0].first == (LINES - 1) || body[0].second == 0 || body[0].second == (COLS - 1)) {
          return true;
     }

     for(int i = 1; i < body.size(); i++) {
          if(body[0] == body[i]) {
               return true;
          }
     } 
     return false;    
}