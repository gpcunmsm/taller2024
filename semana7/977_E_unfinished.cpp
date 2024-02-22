// Analisis: https://jamboard.google.com/d/10pdFp29vyZcntChtMexhbqmep-vclsjab_yARtmS7B4/edit?usp=sharing
#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &G, vector<int> &visited, vector<int> & colors, int s){
  visited[s] = 1;
  colors[s]++;

  for(int i=0; i<G[s].size(); i++){
    int v = G[s][i];
    if( visited[v] == 0 ) {
      dfs(G, visited, colors, v);
    } else {
      colors[v]++;
    }
  }
}

// return 1 si es que es un ciclo, 0 caso contrario
int findCycle(vector<vector<int>> &G, vector<int> &visited, int s){
  vector<int> colors(visited.size());

  cout << "doing dfs... " << endl;
  dfs(G, visited, colors, 1);
  cout << "colors... " << endl;
  for(int i=0; i<colors.size(); i++){
    if( colors[i] == 0 ) continue;

    cout << colors[i] << " ";
  }
  cout << endl;
  return 0;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G; // 0-indexed
  for(int i=0; i<n; i++){
    vector<int> t;
    G.push_back(t);
  }

  for(int i=0; i<m; i++){
    int u, v;
    cin >> u >> v;
    G[u-1].push_back(v-1);
    G[v-1].push_back(u-1);
  }
  for(int i=0; i<G.size(); i++){
    cout << i << ": " ;
    for(int j=0; j<G[i].size(); j++)
      cout << G[i][j] << " ";
    cout << endl;
  }

  vector<int> visited(G.size());

  int cycles = 0;

  for(int i=0; i<visited.size(); i++){
    if ( visited[i] == 0 ) // el componente al que pertenece el vertice i no ha sido visitado aun
      cycles += findCycle(G, visited, i);
  }

  cout << cycles << endl;

}
