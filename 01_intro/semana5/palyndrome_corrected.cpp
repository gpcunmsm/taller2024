#include <iostream>
#include <map>
#include <vector>

using namespace std;

int max(int x, int y){
  return x > y ? x : y;
}

// lcp(aa, 0, 1
int lcp(string s, int i, int j){
  if ( i > j )
    return 0;
  if ( i == j )
    return 1;
  if ( s[i] == s[j] ) 
    return 2+lcp(s, i+1, j-1);
    //       lcp(aa, 1, 0)
  else
    return max(lcp(s, i, j-1), lcp(s, i+1, j));
}

// map<pair<int, int>, int> M;
vector<vector<int>> V;

int lcp_with_memoization(string s, int i, int j){
  if ( i > j )
    return 0;

  // cout << "(" << i << "," << j << "): " ;
  // for(int k=i; k<=j; k++)
  //   cout << s[k];
  // cout << endl;

  if ( i == j ){
    // M[make_pair(i,j)] = 1;

    V[i][j] = 1;
    return 1;
  }

  if ( s[i] == s[j] ) {
    /*
    auto it = M.find(make_pair(i+1, j-1));
    int value;
    if ( it == M.end() ){ // not found
      value = lcp_with_memoization(s, i+1, j-1);
      M[make_pair(i,j)] = value + 2;
    } else {
      value = it->second;
    }
    return value+2;
    */

    int value = V[i+1][j-1];
    if ( value == 0 ) { // not set
      value = lcp_with_memoization(s, i+1, j-1) ;
      V[i][j] = value + 2;
    }
    return value+2;
  } else {
    /*
    auto it1 = M.find(make_pair(i, j-1));
    int value1;
    if ( it1 == M.end() ){
      value1 = lcp_with_memoization(s, i, j-1);
    } else {
      value1 = it1->second;
    }

    auto it2 = M.find(make_pair(i+1, j));
    int value2;
    if ( it2 == M.end() ){
      value2 = lcp_with_memoization(s, i+1, j);
    } else {
      value2 = it2->second;
    }
    int answer = max(value1, value2);
    M[make_pair(i,j)] = answer;
    return answer;
    */

    int v1 = V[i][j-1];
    if ( v1 == 0 )
      v1 = lcp_with_memoization(s, i, j-1);

    int v2 = V[i+1][j];
    if ( v2 == 0 )
      v2 = lcp_with_memoization(s, i+1, j);
    int answer = max(v1, v2);
    V[i][j] = answer;
    // cout << "answer: " << answer << endl;
    return answer;
  }
}

void buildPalyndrome(string sequence){
  int i=V.size()-1, j=0;
  vector<char> r;
  while(1){
    if ( i == j ){
      r.push_back(sequence[i+1]); // FIXME
      break;
    }
    if ( V[j][i] == V[j+1][i-1]+2 ){
      r.push_back(sequence[i]);
      j++;
      i--;
    } else {
      if ( V[j][i-1] > V[j+1][i] ) { // izquierda es mayor
        j++;
      } else {
        i--;
      }
    }
  }

  cout << "sol" << endl;
  for(int i=0; i<r.size(); i++)
    cout << r[i];
  for(int i=r.size()-2; i>=0; i--)
    cout << r[i];

}
// int lcp_iterative(){
// }

int main(){
  string sequence;
  cin >> sequence;
  for(int i=0; i<sequence.size(); i++){
    vector<int> tmp;
    for(int j=0; j<sequence.size(); j++){
      tmp.push_back(0);
    }
    V.push_back(tmp);
  }


  // cout << lcp(sequence, 0, sequence.size()-1);
  cout << lcp_with_memoization(sequence, 0, sequence.size()-1) << endl;

  cout << "tabla: " << endl;
  for(int i=0; i<sequence.size(); i++){
    for(int j=0; j<sequence.size(); j++)
      cout << V[i][j] << " ";
    cout << endl;
  }

  buildPalyndrome(sequence);

}
