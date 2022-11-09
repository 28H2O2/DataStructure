#include<iostream>
using namespace std;

struct BST
{
  int value;
  int key;//满足binary search tree
  int length;
  BST *p;//parent node
  BST *left;
  BST *right;
};

void setNIL(BST & x)//给叶节点的左右儿子设置成NIL
{
  x.left = new BST;
  x.right = new BST;
  x.left->key = -1;
  x.left->value = -1;
  x.left->p = &x;
  x.left->length = x.length + 1;
  x.left->left = NULL;
  x.left->right = NULL;
  x.right->key = -1;
  x.right->value = -1;
  x.right->p = &x;
  x.right->length = x.length + 1;
  x.right->left = NULL;
  x.right->right = NULL;

  return;
}
int main()
{
  BST x;
  x.key = 1;
  x.value = 100;
  setNIL(x);

  cout << "?" << x.left->key << endl;
}