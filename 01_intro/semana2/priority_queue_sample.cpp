#include<queue>
#include<iostream>

using namespace std;

int main() {
  priority_queue<int> Q; // la prioridad esta definida por el mismo numero por default
  Q.push(6);
  Q.push(2);
  Q.push(9);
  while ( ! Q.empty() ){
    cout << Q.top() << endl;
    Q.pop();
  }
}
