#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    set<int> S;
    for(int i=0; i<n; i++){
      int tmp;
      cin >> tmp;
      S.insert(tmp); // O(log n)
    }

    // algoritmo de fuerza bruta
    int k = 1;
    while(k<1024){
      set<int> S_xored;
      for(auto s : S){ // n veces...
        S_xored.insert(s ^ k);  // O(log n)
      }
      // n*O(log n) => O(n log n)

      bool equivalentSets = true;
      for(auto it1 = S.begin(), it2 = S_xored.begin(); it1 != S.end() && it2 != S_xored.end(); it1++, it2++){ // O(n)
        if( *it1 != *it2 ){
          equivalentSets = false;
          break;
        }
      }

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
