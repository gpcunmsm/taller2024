double perimeter(vector <point> &P) {
  double p = 0;
  int n = P.size();
  for(int i=0; i<n; i++) 
    p += dist(P[i], P[(i+1)%n]);

  return p;
}
