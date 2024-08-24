#include <cmath>
#include <iostream>
#define EPS 1e-6 // 10^-6 => 0.000001

using namespace std;

struct line {
  double a, b, c; // ax + by + c = 0
};

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

void pointsToLine(const point &p1, const point &p2, line &l){
  if (fabs(p1.x-p2.x) < EPS) 
    l = {1.0, 0.0, -p1.x };
  else
    l = {-(double)(p1.y-p2.y) / (p1.x-p2.x), // a
         -1.0,                               // b
         -(double)(l.a*p1.x) - p1.y };       // c
}

void pointSlopeToLine(const point &p, double m, line &l){
  l.a = -m;
  l.b = 1.0;
  l.c = -((l.a*p.x) + (l.b*p.y));
}

bool areParallel(const line &l1, const line &l2){
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areEqual(line l1, line l2){
  return areParallel(l1, l2) && (fabs(l1.c-l2.c) < EPS);
}

int main(){
  line l1 = {2, 3, 1};
  line l2 = {2, 1, 5};

  bool parallel = areParallel(l1, l2);
  cout << parallel << endl;
  point p1(3,2);
  line l3;
  pointSlopeToLine(p1, 1, l3);
  cout << l3.a << " " << l3.b << " " << l3.c << endl;
}
