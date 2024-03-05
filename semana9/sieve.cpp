#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<int> primes;

void sieve(int n){
  vector<bool> s(n); // false by default
  for(int i=2; i<sqrt(n); i++){
    if( s[i] == false ){
      for(int j=2*i; j<n; j+=i)
        s[j] = true;
    }
  }

  for(int i=2; i<n; i++)
    if( !s[i] ){ // los primos terminan en false
      cout << i << " ";
      primes.push_back(i);
    }
  cout << endl;
}

int main(){
  int k;
  cin >> k; // buscamos el k-esimo primo

  int seed = 100;
  sieve(seed); // llena el vector de primos
               // 20 primos
  while(){
    sieve(seed);
    seed += 100;
    seed *= 2;
  }


  int it = 0;
  map<int,int> factors;
  while(k!=1){
    if( k%primes[it] == 0 ){
      k /= primes[it];
      cout << primes[it] << " ";
      factors[primes[it]]++;
    } else {
      it++;
    }
  }

  cout << endl << "factores: " << endl;
  for(auto f : factors){
    cout << f.first << " " << f.second << endl;
  }
  cout << endl;

  /*
  for(int i=0; i<primes.size(); i++){
    if ( k%primes[i] == 0 )
      cout << primes[i] << " ";
    if ( i > sqrt(k) )
      break;
  }
  */
}
