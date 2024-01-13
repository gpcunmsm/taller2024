#include<cstdlib>
#include<cstdio>

typedef struct tbst{
  struct tbst *left;
  struct tbst *right;
  int data;
} bst;

bst *NewNode(int n) {
  bst *t = (bst *)malloc(sizeof(bst));
  t->data = n;
  t->left = NULL;
  t->right = NULL;
  return t;
}

// retorna -1 si fue agregado a la izquierda, +1 si fue agregado a la derecha
int AppendNode(bst *root, bst *child) {
  if( child->data < root->data ){
    root->left = child;
    return -1;
  } else {
    root->right = child;
    return 1;
  }
}

void PrintSortedBST(bst *root) {
  if( root->left != NULL )
    PrintSortedBST(root->left);
  printf("%d\n", root->data);
  if( root->right != NULL )
    PrintSortedBST(root->right);
}

int main() {
  bst *root = NewNode(5);
  bst *child1 = NewNode(2);
  bst *child2 = NewNode(7);

  AppendNode(root, child1);
  AppendNode(root, child2);

  AppendNode(child1, NewNode(1));
  AppendNode(child1, NewNode(4));

  AppendNode(child2, NewNode(6));
  AppendNode(child2, NewNode(8));

  PrintSortedBST(root);
}
