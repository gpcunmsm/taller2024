#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> G; // usando lista de adyacencia
                       // 0: 1, 2, 3
                       // 1: 4, 3
                       // 2: 4, 0
                       // 3: 5, 4
                       // 4: 
                       // 5: 6
                       // 6: 5
void bfs(int start){
  queue<int> toVisit;
  vector<int> visited(G.size());
  vector<int> distances(G.size());
  int d = 1;
  toVisit.push(start);
  visited[start] = 1;

  // e = (u,v)
  while( !toVisit.empty() ){
    int u = toVisit.front();
    // if ( visited[u] == 1 ){
    //   toVisit.pop();
    //   continue;
    // }

    cout << "current vertex " << u << endl;


    for(int i=0; i<G[u].size(); i++){
      int v = G[u][i];
      if ( visited[v] == 0 ){ // 0 significa que no ha sido visitado
        cout << "adding " << v << endl;
        toVisit.push(v);
        distances[v] = distances[u]+1;
        visited[v] = 1;
      }
    }

    cout << "visited vector: ";
    for(int i=0; i<visited.size(); i++)
      cout << visited[i] << " ";
    cout << endl;

    cout << "distances vector: ";
    for(int i=0; i<distances.size(); i++)
      cout << distances[i] << " ";
    cout << endl;

    cout << "visited: " << u << endl << endl;
    toVisit.pop();
  }
}

int main(){
  vector<int> v_0 = {1, 2, 3};
  vector<int> v_1 = {4, 3};
  vector<int> v_2 = {4, 0};
  vector<int> v_3 = {5, 4};
  vector<int> v_4;
  vector<int> v_5 = {6};
  vector<int> v_6 = {5};
  G.push_back(v_0);
  G.push_back(v_1);
  G.push_back(v_2);
  G.push_back(v_3);
  G.push_back(v_4);
  G.push_back(v_5);
  G.push_back(v_6);
  // bfs(5);
  bfs(3);
}
