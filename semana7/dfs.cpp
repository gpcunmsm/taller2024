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

void dfs(int u, vector<int> &visited){
  visited[u] = 1;
  cout << "visiting " << u << endl;
  for(int i=0; i<G[u].size(); i++){
    int v = G[u][i];
    // e: u->v
    if ( visited[v] == 0 ){
      dfs(v, visited);
    }
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

  vector<int> visited(G.size());
  dfs(5, visited);

  cout << "visited vector: ";
  for(int i=0; i<visited.size(); i++)
    cout << visited[i] << " ";
  cout << endl;
  // dfs(3);
}
