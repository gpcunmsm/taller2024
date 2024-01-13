#include<map>
#include<string>
#include<iostream>

using namespace std;

int main() {
  map<string, int> M;
  M["uno"] = 1;
  M["dos"] = 2;
  M["diez"] = 10;
  for ( auto it : M ){
    cout << it.first << " " << it.second << endl;
  }
}
