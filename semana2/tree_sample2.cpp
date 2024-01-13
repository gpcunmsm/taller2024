#include<cstdlib>
#include<cstdio>

using namespace std;

typedef struct tnode{
  struct tnode *leafs[50];
  int n_leafs; // cantidad de hijos
  int data;
}node;

node *NewNode(int d) {
  node *leaf = (node *)malloc(sizeof(node));
  leaf->data = d;
  leaf->n_leafs = 0;

  return leaf;
}

void AppendNode(node *tree, node *leaf) {
  tree->leafs[tree->n_leafs] = leaf;
  tree->n_leafs++;
}

void printTree(node *root) {
  printf("%d: \n", root->data);
  for(int i=0; i<root->n_leafs; i++){
    printTree(root->leafs[i]);
  }
}

int main() {
  node *root = NewNode(1);

  node *left = NewNode(2);
  AppendNode(root, left);
  AppendNode(left, NewNode(1));
  AppendNode(left, NewNode(6));

  node *right = NewNode(7);
  AppendNode(root, right);
  AppendNode(right, NewNode(5));
  AppendNode(right, NewNode(8));
  AppendNode(right, NewNode(3));

  printTree(root);
}
