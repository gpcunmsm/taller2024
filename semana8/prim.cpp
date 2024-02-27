#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<pair<int,int>>> G; // lista de adyacencia que guarda un par, primero el vertice y luego el peso de la arista
// s: source
// t: target
void prim(int s){
  vector<pair<int,int>> T;
  priority_queue<pair<int,int>> Q; // TODO: check if this is sorting based on the first element!
  vector<int> connected(G.size());
  connected[s] = 1;

  for(int i=0; i<G[s].size(); i++) {
    auto e = G[s][i]; // e: edge
    Q.push(e); // e.first: vertex v, e.second: edge's weight
  }

  while( !Q.empty() ){
    auto e = Q.top();
    int u = e.first;
    if( connected[u] == 0 ){
      T.push_back(make_pair(u, );  // add vertex to solution
      connected[u] = 1;
      for(int i=0; i<G[u].size(); i++){
        // if( ) // dont add 
        auto e = G[u][i];
        Q.push(e);
      }
    } 
    Q.pop();
  }

  cout << "MST: " << endl;
  for(int i=0; i<T.size(); i++)
    cout << T[i] << " ";
  cout << endl;

}

int main(){
  for(int i=0; i<6; i++){
    vector<pair<int,int>> tmp;
    G.push_back(tmp);
  }
  G[0].push_back(make_pair(2,75));
  G[2].push_back(make_pair(0,75));
  G[0].push_back(make_pair(1,9));
  G[1].push_back(make_pair(0,9));
  G[1].push_back(make_pair(2,95));
  G[2].push_back(make_pair(1,95));
  G[3].push_back(make_pair(2,51));
  G[2].push_back(make_pair(3,51));
  G[3].push_back(make_pair(1,19));
  G[1].push_back(make_pair(3,19));
  G[4].push_back(make_pair(1,42));
  G[1].push_back(make_pair(4,42));
  G[4].push_back(make_pair(3,31));
  G[3].push_back(make_pair(4,31));
  G[5].push_back(make_pair(3,2));
  G[3].push_back(make_pair(5,2));

  prim(0);
}

