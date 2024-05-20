#include<set>
#include<iostream>

using namespace std;

int main(){
  set<int> S;
  S.insert(7);
  S.insert(3);
  S.insert(7);
  for (auto it : S){
    cout << it << endl;
  }
}
