#include <iostream>
#include <cmath>
#define EPS 1e-6

using namespace std;

struct point_i {
  int x, y;
  point_i() { x = y = 0; }
  point_i(int _x, int _y) : x(_x), y(_y) {}
};
