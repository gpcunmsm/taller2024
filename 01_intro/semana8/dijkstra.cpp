#include <iostream>
#include <vector>
#include <set>

#define INFINITY 1000000

using namespace std;

vector<int> d;
vector<vector<pair<int,int>>> G;

bool relax(int u, int v, int w){
  if(d[v] > d[u] + w ){
    d[v] = d[u] + w;
    return true;
  }
  return false;
}

void dijsktra(int s){
  set<pair<int,int>> Q; // weight, vertex
  for(int i=0; i<d.size(); i++){
    d[i] = INFINITY;
    if ( i ==s ) 
      d[i] = 0;
    Q.insert(make_pair(d[i], i));
  }

  while(!Q.empty()){
    int u = Q.begin()->second;
    Q.erase(Q.begin());

    for(int i=0; i<G[u].size(); i++){
      int v = G[u][i].second;
      int d_old = d[v];
      if ( relax(u, v, G[u][i].first) ){
        auto it = Q.find(make_pair(d_old, v));
        Q.erase(it);
        Q.insert(make_pair(d[v], v));
      }
    }
  }
}

int main(){
  for(int i=0; i<6; i++){
    vector<pair<int,int>> tmp;
    G.push_back(tmp);
    d.push_back(0);
  }
  G[0].push_back(make_pair(4,1));
  G[0].push_back(make_pair(8,2));
  G[0].push_back(make_pair(2,5));

  G[1].push_back(make_pair(8,3));
  G[1].push_back(make_pair(1,2));
  G[1].push_back(make_pair(3,4));

  G[2].push_back(make_pair(3,3));
  G[2].push_back(make_pair(1,1));

  G[3].push_back(make_pair(2,4));


  dijsktra(0);
  cout << "distances " << endl;
  for(auto it : d)
    cout << it << " ";
  cout << endl;
}
