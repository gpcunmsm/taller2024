#include <iostream>
#include <cmath>
#define EPS 1e-6 // 10^-6 => 0.000001

// cpp math library uses radians
double degrees2radians(double d) {
  return d*acos(-1.0) / 180;
}

point rotation(const point &p, double theta){
  double rad = degrees2radians(theta);
  return point(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}

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


int main(){
  point p_prime = rotation(point(3,4), 180);
  cout << p_prime.x << "," << p_prime.y << endl;
}
