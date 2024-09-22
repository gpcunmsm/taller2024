#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int>> G; // lista de adyacencia

void bfs(int start){ // O(V+E)
  queue<int> toVisit;
  vector<int> visited(G.size());
  vector<int> distances(G.size());
  int d = 1;
  toVisit.push(start);
  visited[start] = 1;

  while( !toVisit.empty() ){
    int u = toVisit.front();
    toVisit.pop();

    for(int i=0; i<G[u].size(); i++){
      int v = G[u][i];
      if ( visited[v] == 0 ){ // 0 significa que no ha sido visitado
        toVisit.push(v);
        distances[v] = distances[u]+1;
        visited[v] = 1;
      }
    }

    cout << "visited: " << u << endl << endl;
  }
}

void dfs(int start){ // O(V+E), iterative version
  stack<int> toVisit;
  vector<int> visited(G.size());
  vector<int> distances(G.size());
  int d = 1;
  toVisit.push(start);
  visited[start] = 1;

  while( !toVisit.empty() ){
    int u = toVisit.top();
    toVisit.pop();

    for(int i=0; i<G[u].size(); i++){
      int v = G[u][i];
      if ( visited[v] == 0 ){ // 0 significa que no ha sido visitado
        toVisit.push(v);
        distances[v] = distances[u]+1;
        visited[v] = 1;
      }
    }

    cout << "visited: " << u << endl << endl;
  }
}

int main(){
  vector<int> v_0 = {1, 2};
  vector<int> v_1 = {3, 4, 0};
  vector<int> v_2 = {5, 0};
  vector<int> v_3 = {1};
  vector<int> v_4 = {1, 6};
  vector<int> v_5 = {2};
  vector<int> v_6 = {4};
  G.push_back(v_0);
  G.push_back(v_1);
  G.push_back(v_2);
  G.push_back(v_3);
  G.push_back(v_4);
  G.push_back(v_5);
  G.push_back(v_6);

  cout << "BFS" << endl;
  bfs(0);

  cout << "DFS" << endl;
  dfs(0);
}
