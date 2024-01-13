#include<stack>
#include<iostream>

using namespace std;

int main() {
  stack<int> S;
  S.push(3);
  S.push(5);
  S.push(20);
  while ( ! S.empty() ) {
    cout << S.top() << endl;
    S.pop();
  }
}
