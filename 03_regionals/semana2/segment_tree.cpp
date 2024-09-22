#include <vector>
#include <cstdio>

using namespace std;

vector<int> st;
vector<int> lazy;

void build(vector<int> &A, int idx, int left, int right) { // build max segment tree: O(n)
  if ( left == right ) {
    st[idx] = A[left];
  } else {
    int m = (right-left)/2+left;
    build(A, 2*idx+1, left, m);
    build(A, 2*idx+2, m+1, right);
    st[idx] = st[2*idx+1] > st[2*idx+2] ? st[2*idx+1] : st[2*idx+2]; // objective function
  }
}

void propagate(int seg_idx){
  if ( lazy[seg_idx] != -1 ) {
    st[seg_idx] = lazy[seg_idx];
    lazy[2*seg_idx+1] = lazy[2*seg_idx+2] = lazy[seg_idx]; // depends on objective function
    lazy[seg_idx] = -1;
  }
}

/**
 * tambien llamado RMQ (range minimum query)
 * @param seg_idx segment index for current node, to be used in st
 * @param seg_left seg_right indicates the left and right boundaries of current node
 * @param i j search query limits
 */
int range_query(int seg_idx, int seg_left, int seg_right, int i, int j) { // O(log n)
  propagate(seg_idx);
  if ( seg_left == i && seg_right == j ) 
    return st[seg_idx];

  int m = (seg_left+seg_right)/2;
  if ( j <= m )
    return range_query(2*seg_idx+1, seg_left, m, i, j);
  else if ( i>= m+1 )
    return range_query(2*seg_idx+2, m+1, seg_right, i, j);
  else {
    int l = range_query(2*seg_idx+1, seg_left, m, i, m);
    int r = range_query(2*seg_idx+2, m+1, seg_right, m+1, j);
    return l > r ? l : r;  // objective function
  }
}

void range_update(int seg_idx, int seg_left, int seg_right, int value, int i, int j) { // O(log n)
  propagate(seg_idx);

  if ( seg_left == i && seg_right == j ) {
    lazy[seg_idx] = value;
    st[seg_idx] = st[seg_idx] > value ? st[seg_idx] : value; // objective function
    return;
  }
  int m = (seg_left+seg_right)/2;
  if ( j <= m )
    range_update(2*seg_idx+1, seg_left, m, value, i, j);
  else if ( i>=m+1 )
    range_update(2*seg_idx+2, m+1, seg_right, value, i, j);
  else {
    range_update(2*seg_idx+1, seg_left, m, value, i, m);
    range_update(2*seg_idx+2, m+1, seg_right, value, m+1, j);
  }
}

void printTree(int n) {
  int level = 1;
  int column = 0;
  for(int i=0; i<st.size(); i++) {
    int spaces = n*4/(level+1);
    for ( int i=0; i<spaces; i++ )
      printf("    ");
    printf("%03d ", st[i]);

    column++;

    if (level==1 || column % level == 0) {
      column = 0;
      level *= 2;
      printf("\n");
    }
  }
}

int main() {
  //            0    1   2   3   4   5   6   7   8   9  10  11
  vector<int> A{96, 22, 95, 37, 75, 70, 93, 96, 16, 28, 29, 70};
  st = vector<int>(4*A.size(), -1);
  lazy = vector<int>(st.size(), -1);

  build(A, 0, 0, A.size()-1);

  for(int i=0; i<st.size(); i++) {
    if ( st[i] == -1 ) continue;
    printf("%d ", st[i]);
  }
  printf("\n");

  printTree(A.size());
  printf("\n");
  printf("%d \n", range_query(0, 0, A.size()-1, 3, 6));
  printf("%d \n", range_query(0, 0, A.size()-1, 1, 6));
  printf("%d \n", range_query(0, 0, A.size()-1, 5, 9));
  printf("%d \n", range_query(0, 0, A.size()-1, 3, 3));

  range_update(0, 0, A.size()-1, 99, 3, 3);
  printf("%d \n", range_query(0, 0, A.size()-1, 3, 3));

  printf("%d \n", range_query(0, 0, A.size()-1, 1, 3));
  range_update(0, 0, A.size()-1, 100, 1, 3);
  printf("%d \n", range_query(0, 0, A.size()-1, 1, 3));
}
