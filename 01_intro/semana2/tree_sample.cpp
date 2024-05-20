#include<cstdlib>

typedef struct tnode{
  struct tnode *parent;
  int data;
}node;

node *NewNode(int d, node *parent) {
  node t;
  t.data = d;
  t.parent = parent;
  return &t;
}

int main() {
  node *root = NewNode(1, NULL);
  node *left = NewNode(2, root);
  NewNode(1, left);
  NewNode(6, left);

  node *right = NewNode(7, root);
  NewNode(5, right);
  NewNode(8, right);
  NewNode(3, right);
}
