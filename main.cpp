#include<iostream>
#include <curses.h>
#include <chrono>
#include "UI.h"
#include "Snake.h"
#include "Game.h"

using namespace std;



int timeDelayPerFrames = 100000;
int dt;

void eventLoop() {

     while(true) {
          auto lastTime = chrono::system_clock::now();
          erase();

          bool gameOver = false;
          gameOver = gameLogic();
          if(gameOver == true) {
               break;
          }
          refresh();
     
      do {
          auto currentTime = chrono::system_clock::now();
          dt = chrono::duration_cast<std::chrono::microseconds> (currentTime - lastTime).count();
      } while(dt < timeDelayPerFrames);
     }
}

int main() {

     initUI();
     eventLoop();
     destroyUI();
     std:cout << "THANKS FOR PLAYING SNAKE GAME!" << endl;
     return 0;

}