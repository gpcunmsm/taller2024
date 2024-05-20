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

// agrega recursivamente el nodo child al nodo root
void AppendNode(bst *root, bst *child) {
  if( child->data < root->data ){
    if ( root->left != NULL ){
      return AppendNode(root->left, child);
    } else {
      root->left = child;
    }
  } else {
    if ( root->right != NULL ){
      return AppendNode(root->right, child);
    } else {
      root->right = child;
    }
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

  AppendNode(root, NewNode(2));
  AppendNode(root, NewNode(7));

  AppendNode(root, NewNode(1));
  AppendNode(root, NewNode(4));

  AppendNode(root, NewNode(8));
  AppendNode(root, NewNode(6));

  PrintSortedBST(root);
}
