#include "Food.h"
#include "settings_constants.h"

vector < pair <int, int> > nibbles;
const char snakeFoody = (char)36;

pair <int, int> makeFood() {

     int x = ( rand() % (LINES - 2) ) + 1;
     int y = (rand() % (COLS - 2)) + 1;

     return {x,y};
}

void paintFood() {
     for(int i = 0; i < nibbles.size(); i++) {
          move(nibbles[i].first,nibbles[i].second);
          addch(snakeFoody);
     }
}
void initFood() {
     nibbles.clear();
     for(int i = 0; i < FOOD_CON; i++) {
          nibbles.push_back(makeFood());
     }
}

bool eatingFood(pair<int,int> head) {

     for(int i = 0; i < nibbles.size(); i++) {
          if(nibbles[i].first == head.first && nibbles[i].second == head.second) {
               nibbles.erase(nibbles.begin() + i);
               nibbles.push_back(makeFood());
               return true;
          }
          
     }
     return false;
}