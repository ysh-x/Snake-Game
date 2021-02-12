#ifndef DEF_SNAKE
#include <vector>

#define DEF_SNAKE
#include<curses.h>
#include "settings_constants.h"

using namespace std;

void initSnake();
void paintSnake();
pair<int,int> moveSnake(int);
void growSnake();
bool hasCollision();
#endif 