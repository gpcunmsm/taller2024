#include<map>

using namespace std;

int ParentIndex(int n) {
  return (n-1)/2;
}

int main(){
  map<int, int> T;

  T[0] = 1;
  T[1] = 1;
  T[2] = 7;
  T[3] = 1;
  T[4] = 6;
  T[5] = 5;
  T[6] = 8;
}
