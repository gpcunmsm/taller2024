#include <iostream>
#include <vector>

using namespace std;

// primer argumento es el arreglo
// segundo argumento es el indice referente al segment tree
// tercer argumento es el indice de la izquierda
// cuarto argumento es el indice de la derecha
void build(vector<int> &st, vector<int> &A, int idx, int left, int right) { // build max segment tree
  if ( left == right ) {
    st[idx] = A[left];
  } else {
    int m = (right-left)/2+left;
    build(st, A, 2*idx+1, left, m);
    build(st, A, 2*idx+2, m+1, right);
    st[idx] = st[2*idx+1] > st[2*idx+2] ? st[2*idx+1] : st[2*idx+2];
  }
}

int main(){
  vector<int> A{96, 23, 96, 37, 75, 70, 93, 96, 16, 28, 29, 70};
  vector<int> st(4*A.size(), -1);

  build(st, A, 0, 0, A.size()-1);

  for(int i=0; i<st.size(); i++) {
    if ( st[i] == -1 ) continue;
    cout << st[i] <<  " " ;
  }

}
