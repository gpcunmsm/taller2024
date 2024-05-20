#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> input(n);
    for(int i=0; i<n; i++){
      int tmp;
      cin >> tmp;
      input[i] = tmp;
    }

    // algoritmo de fuerza bruta
    int k = 1;
    while(k<1024){
      map<int, int> S_xored;
      for(auto s : input){  // n
        int xored = s ^ k;
        S_xored[xored] = 1; // O(log n)
      }
      // O(n log n)

      // 0 1 2 3   <- input
      // k=1
      // 0^1=>1, 1^1=>1, 2^1=>1 3^1=>1     <- map
      //  1 =>1,  0=>1,  3=>1    2=>1

      bool equivalentSets = true;
      ////
      for(auto s : input){ // n
        auto it = S_xored.find(s); // O(log n)
        if ( it == S_xored.end() ) { // no existe
          equivalentSets = false;
          break;
        }
      } // O(n log n)

      if ( equivalentSets )
        break;
      k++;
    }

    if ( k >= 1024 )
      cout << "-1" << endl;
    else 
      cout << k << endl;

    /*
    for(int i=0; i<n; i++)
      cout << S[i] << " ";
    cout << endl;
    for(int i=0; i<n; i++)
      cout << S_xored[i] << " ";
      */
  }
}
