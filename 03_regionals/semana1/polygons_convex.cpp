// test de direccion: en que direccion se encuentra c respecto al vector a->b
// CW (horario) o CCW (antihorario)
bool ccw(point a, point b, point c) {
  return cross(toVec(a, b), toVec(a, c)) > EPS;
}

bool isConvex(const vector<point> &P) {
  int n = P.size();
  bool firstTurn = ccw(P[0], P[1], P[2]);
  for (int i=1; i<n; i++)
    if (ccw(P[i], P[(i+1)%n], P[(i+2)%n]) != firstTurn)
      return false;
  return true
}
