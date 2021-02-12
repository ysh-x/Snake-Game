#include "Game.h"
#include "UI.h"
#include "Food.h"
#include "settings_constants.h"
#include "Snake.h"
#include "Score.h"
#include "Obstacles.h"
using namespace std;

int i = 0;
//int x = 10, y = 10;
int ch = getch();
int direction;
int gameState = BEFORE_START;


void startGame() {
     initSnake();
     initFood();
     initScore();
     initObstacles();
     //initFood();
     direction = UP;
     gameState = STARTED;
}

void endGame() {
     gameState = ENDED;
}

bool gameLogic() {
     printBorder();

     if (gameState == BEFORE_START) {
          move(LINES/4 +8, COLS / 4);
          addstr("PRESS [SPACE] TO START THE GAME.");
          move(LINES / 4 + 6, COLS / 4);
          addstr("EAT MORE! EARN MORE | BEWARE OF OBSTACLES");
          move(LINES / 4 + 2, COLS / 4);
          addstr("DEVELOPED BY YOGESHWAR.G");
          move(LINES/4,COLS/4);
          addstr("CLASSICAL SNAKE GAME");
          ch = getch();
          if (ch == 32)
          {
               startGame();
          }
     }
     else if(gameState == STARTED) {
          ch = getch();
          if (ch == UP && ch != DOWN)
          {
               direction = UP;
          }
          else if (ch == DOWN && ch != UP)
          {
               direction = DOWN;
          }
          else if (ch == LEFT && ch != RIGHT)
          {
               direction = LEFT;
          }
          else if (ch == RIGHT && ch != LEFT)
          {
               direction = RIGHT;
          }
          pair<int,int> head = moveSnake(direction);

          if(eatingFood(head) == true) {
               growSnake();
               updateScore();
          }

          if(hittingObstacles(head) == true) {
               endGame();
          }
          if(hasCollision() == true) {
               endGame();
          }
          paintSnake();
          paintFood();
          printScore();
          paintObstacles();
     }
     else if(gameState == ENDED) {
          move(LINES / 4 + 2, COLS / 4);
          addstr("PRESS [SPACE] TO RE-START, [Q] TO QUIT");
          move(LINES / 4, COLS / 4);
          move(2, 2);
          int score = getScore();
          string s1 = "YOU EARNED " + to_string(score) + " $.";
          char const *s = s1.c_str();
          addstr(s);

          ch = getch();

          if(ch == 32) {
               startGame();
          }
          else if(ch == 'q' || ch == 'Q') {
               return true;
          }
     }

     return false;
   
}
