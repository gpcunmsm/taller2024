#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  vector<int> V;
  V.push_back(5);
  V.push_back(2);
  V.push_back(3);
  sort(V.begin(), V.end());
  for(auto it : V)
    cout << it << " ";
  cout << endl;
}
