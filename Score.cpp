#include "Score.h"
#include "Game.h"


int score = 0;

void initScore() {
     score  = 0;     
}

void updateScore() {
     score++;
}

void printScore() {
     move (2,2);
     string s1 = "SCORE : " + to_string(score) + " $";
     char const *s = s1.c_str();
     addstr(s);
     
}

int getScore() {
     return score;
}