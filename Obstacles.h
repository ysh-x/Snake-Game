#ifndef DEF_OBSTACLES

#define DEF_OBSTACLES

#include <curses.h>
#include <vector>
#include <cstdlib>

using namespace std;

void initObstacles();
void paintObstacles();
bool hittingObstacles(pair<int, int>);
#endif