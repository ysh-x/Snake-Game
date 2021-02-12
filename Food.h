#ifndef DEF_FOOD

#define DEF_FOOD

#include<curses.h>
#include<vector>
#include<cstdlib>

using namespace std;

void initFood();
void paintFood();
bool eatingFood(pair<int,int>);
#endif