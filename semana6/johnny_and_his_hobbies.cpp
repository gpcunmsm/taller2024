#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> S;
    for(int i=0; i<n; i++){
      int tmp;
      cin >> tmp;
      S.push_back(tmp);
    }

    // algoritmo de fuerza bruta
    int k = 1;
    while(k<1024){
      vector<int> S_xored;
      for(int i=0; i<n; i++){
        S_xored.push_back(S[i] ^ k);
      }

      // 2 4     => 6
      // 5 1     => 6

      sort(S.begin(), S.end());              // O(n log n)
      sort(S_xored.begin(), S_xored.end());  // O(n log n)

      bool equivalentSets = true;
      for(int i=0; i<n; i++){                // O(n)
        if( S[i] != S_xored[i] ){
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
