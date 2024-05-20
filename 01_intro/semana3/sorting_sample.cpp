#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int a, int b){
  // return a>b;
  return a<b;
}

int main(){
  vector<int> V;
  V.push_back(5);
  V.push_back(2);
  V.push_back(3);
  sort(V.begin(), V.end(), comp);
  for(auto it : V)
    cout << it << " ";
  cout << endl;
}
