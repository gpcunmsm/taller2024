double area(vector <point> &P) {
  double a = 0;
  int n = P.size();
  for(int i=0; i<n; i++)
    a += (P[i].x*P[(i+1)%n].y - P[(i+1)%n].x*P[i].y);

  return fabs(a)/2.0;
}
