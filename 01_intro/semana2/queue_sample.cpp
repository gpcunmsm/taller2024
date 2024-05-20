#include<queue>
#include<iostream>

using namespace std;

int main() {
  queue<int> Q;
  Q.push(5);
  Q.push(2);
  Q.push(9);
  while ( ! Q.empty() ) {
    cout << Q.front() << endl;
    Q.pop();
  }
}
