#include<iostream>
#include<vector>

using namespace std;

int main(){
  vector<int> V; // no hay necesidad de indicar el tamano inicial del vector
  V.push_back(2);
  V.push_back(1);
  V.push_back(4);
  for ( int i=0; i<V.size(); i++ ) {
    cout << V[i] << endl;
  }
}
