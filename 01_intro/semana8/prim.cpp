#include <iostream>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

vector<vector<pair<int,int>>> G; // lista de adyacencia que guarda un par, primero el vertice y luego el peso de la arista
                                 // s: source
                                 // t: target
void prim(int s){
  vector<pair<int,int>> T;
  priority_queue<pair<int,int>> Q; 
  vector<int> connected(G.size());
  connected[s] = 1;

  for(int i=0; i<G[s].size(); i++) {
    auto e = G[s][i]; // e: edge
    Q.push(e); // e.first: vertex v, e.second: edge's weight
  }

  while( !Q.empty() ){
    auto e = Q.top();
    Q.pop();
    int u = e.second;
    if( connected[u] == 0 ){
      T.push_back(e);  // add vertex to solution
      connected[u] = 1;
      for(int i=0; i<G[u].size(); i++){
        auto e = G[u][i];
        Q.push(e);
      }
    }
  }

  cout << "MST: " << endl;
  for(int i=0; i<T.size(); i++)
    cout << "(" << T[i].second << "," << T[i].first << ")";
  cout << endl;

}

int main(){
  for(int i=0; i<6; i++){
    vector<pair<int,int>> tmp;
    G.push_back(tmp);
  }
  G[0].push_back(make_pair(75,2));
  G[2].push_back(make_pair(75,0));
  G[0].push_back(make_pair(9,1));
  G[1].push_back(make_pair(9,0));
  G[1].push_back(make_pair(95,2));
  G[2].push_back(make_pair(95,1));
  G[3].push_back(make_pair(51,2));
  G[2].push_back(make_pair(51,3));
  G[3].push_back(make_pair(19,1));
  G[1].push_back(make_pair(19,3));
  G[4].push_back(make_pair(42,1));
  G[1].push_back(make_pair(42,4));
  G[4].push_back(make_pair(31,3));
  G[3].push_back(make_pair(31,4));
  G[5].push_back(make_pair(2,3));
  G[3].push_back(make_pair(2,5));

  prim(0);
}

