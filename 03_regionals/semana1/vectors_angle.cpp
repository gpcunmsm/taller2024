#include <cmath>

double dot(const vec &a, const vec &b) {
  return a.x*b.x + a.y*b.y;
}

double cross(const vec &a, const vec &b) {
  return a.x*b.y - a.y*b.x;
}

double angle(const point &a, const point &b, const point &c) {
  vec ab = toVec(a,b);
  vec bc = toVec(b,c);
  return acos(dot(ab, bc) / sqrt(norm_sq(ab) * norm_sq(bc)));
}
