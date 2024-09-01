#include <iostream>
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

struct vec {
  double x, y; // magnitudes
  vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(const point &a, const point &b) {
  return vec(b.x-a.x, b.y-a.y); // vector a->b
}

double cross(const vec &a, const vec &b) {
  return a.x*b.y - a.y*b.x;
}

bool ccw(point a, point b, point c) {
  return cross(toVec(a, b), toVec(a, c)) > EPS;
}

bool collinear(point a, point b, point c) {
  return fabs(cross(toVec(a, b), toVec(a, c))) < EPS;
}

int main() {
  point a = {1, 2 };
  point b = { -2, 4};
  point c = {5, 1};

  if ( collinear(a, b, c) )
    cout << "collinear";
  else
    if ( ccw(a,b,c) )
      cout << "antihorario";
    else
      cout << "horario";
}
