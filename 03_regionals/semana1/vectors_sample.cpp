struct vec {
  double x, y; // magnitudes
  vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(const point &a, const point &b) {
  return vec(b.x-a.x, b.y-a.y); // vector a->b
}

vec scale(const vec &v, double s) {
  return vec(v.x*s, v.y*s);
}

point translate(const point &p, const vec &v) {
  return point(p.x+v.x, p.y+v.y);
}

double norm_sq(vec v) {
  return v.x*v.x + v.y*v.y;
}
