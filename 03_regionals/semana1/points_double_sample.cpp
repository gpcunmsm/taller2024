#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define EPS 1e-6 // 10^-6 => 0.000001

using namespace std;

struct point {
  double x, y;
  point() { x = y = 0; }
  point(double _x, double _y) : x(_x), y(_y) {}

  bool operator < (point p2) const {
    if ( fabs(x-p2.x) > EPS ) // no son "iguales"
      return x < p2.x;
    return y < p2.y;
  }

  // operator overloading: sobrecarga de operadores
  bool operator == (const point &p2) const {
    return (fabs(x-p2.x) < EPS) && (fabs(y-p2.y) < EPS);
  }
};

double dist(const point p1, const point p2) {
  return hypot(p1.x-p2.x, p1.y-p2.y);
}

int main(){
  point p1(2,3);
  // point p2(2,3.00000001);
  point p2(2,3.001);
  bool equal = p1 == p2;
  cout << equal << endl;
  vector<point> polygon;
  polygon.push_back(point(0,0));
  polygon.push_back(point(2,4));
  polygon.push_back(point(3,9));
  polygon.push_back(point(3.000000001,2));
  polygon.push_back(point(-1,7));
  polygon.push_back(point(4,11));

  for( auto p : polygon ) 
    cout << p.x << "," << p.y << " ";
  cout << endl;
  sort(polygon.begin(), polygon.end());
  for( auto p : polygon ) 
    cout << p.x << "," << p.y << " ";
  cout << endl;
}
