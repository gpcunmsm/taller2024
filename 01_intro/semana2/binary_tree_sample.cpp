#include<vector>

using namespace std;

int ParentIndex(int n) {
  return (n-1)/2;
}

int main(){
  vector<int> T;

  T.push_back(1);
  T.push_back(2);
  T.push_back(7);
  T.push_back(1);
  T.push_back(6);
  T.push_back(5);
  T.push_back(8);
}
