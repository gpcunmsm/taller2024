#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) { 
  return a.second < b.second; 
}

int main(){
  vector<pair<int,int>> V;
  V.push_back(make_pair(2,5));
  V.push_back(make_pair(7,2));
  V.push_back(make_pair(7,3));
  V.push_back(make_pair(1,3));
  stable_sort(V.begin(), V.end(), compare);
  for(auto it : V)
    cout << "(" << it.first << " " << it.second << ") ";
  cout << endl;
}
