#include<list>
#include<iostream>

using namespace std;

int main() {
  list<int> L;
  auto it = L.begin();
  L.insert(it, 4);
  L.insert(it, 2);
  L.insert(it, 9);
  for ( auto itr : L ){
    cout << itr << endl;
  }
}
