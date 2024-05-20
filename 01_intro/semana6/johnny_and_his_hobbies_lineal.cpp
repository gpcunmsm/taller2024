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
    vector<int> input(n);
    for(int i=0; i<n; i++){
      int tmp;
      cin >> tmp;
      input[i] = tmp;
    }

    // algoritmo de fuerza bruta
    int k = 1;
    while(k<1024){
      vector<int> indexes(1024);
      for(auto s : input){ // O(n)
        int xored = s ^ k;
        indexes[xored] = 1; // constante
      }
      // maps -> tienen constantes altas
      // sets?
      // sort -> tiene constantes bajas
      // vectores y arreglos tienen constantes bajas

      // indexes -> 0 0 0 0 0 0 0 1 0 0 0 0 1
      //            
      // O(n log n)
      //
      // ordenacion por conteo -> algoritmos con complejidades O(n)

      bool equivalentSets = true;
      ////
      for(auto s : input){ // O(n)
        if ( indexes[s] == 0 ){ // no existe
          equivalentSets = false;
          break;
        }
      }
      // O(n)

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
