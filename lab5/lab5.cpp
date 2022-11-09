#include<iostream>
using namespace std;

struct BST
{
  int value;
  int key;//满足binary search tree
  // int length;
  BST *p;//parent node
  BST *left;
  BST *right;
};
BST NIL;// empty node

struct node
{
  int key;
  int value;
};

struct tree
{
  BST *root;
  // int length;
};

void setNIL(BST & x)//给叶节点的左右儿子设置成NIL
{
  x.left = new BST;
  x.right = new BST;
  x.left->key = -1;
  x.left->value = -1;
  x.left->p = &x;
  // x.left->length = x.length + 1;
  x.left->left = NULL;
  x.left->right = NULL;
  x.right->key = -1;
  x.right->value = -1;
  x.right->p = &x;
  // x.right->length = x.length + 1;
  x.right->left = NULL;
  x.right->right = NULL;

  return;
}

BST* search_key(tree& T, int k)//找到key值对应的节点
{
  BST *x = T.root;
  while (x->key != k && x->key != -1)//向下寻找到合适的位置
  {
    if(k < x->key)
      x = x->left;
    else
      x = x->right;
  }
  return x;
}


// NOTE MAIN BEGIN---------------------------------------------
int main()
{
  void insert(tree & T, node z);
  int minimum(tree & T, node x);
  int maximum(tree & T, node x);
  void DELETE(tree & T, node z);
  void traversal_pre(tree & T, BST *x);
  void traversal_in(tree & T, BST * x);
  void traversal_pos(tree & T, BST * x);
  void setNIL(BST & x);
  int search_recursion(tree & T, node x, int k);
  int search_iterative(tree & T, node x, int k);
  int successor(tree & T, node y);
  int predecessor(tree & T, node y);
  BST *minimum_node(tree & T, node y);//为DELETE使用的函数
  BST *maximum_node(tree & T, node y);
  BST *successor_node(tree & T, node y);
  BST *predecessor_node(tree & T, node y);

  tree T;//Initialize
  T.root = NULL;
  // T.length = 0;
  BST NIL;
  NIL.key = -1;
  NIL.value = -1;
  NIL.p = NULL;
  NIL.left = NULL;
  NIL.right = NULL;

  node n1 = {4, 40};
  node n2 = {2, 20};
  node n3 = {1, 10};
  node n4 = {8, 80};
  node n5 = {3, 30};
  node n6 = {6, 60};
  node n7 = {12, 120};

  insert(T, n1);
  insert(T, n2);
  insert(T, n3);
  insert(T, n4);
  insert(T, n5);
  insert(T, n6);
  insert(T, n7);
  // TODO test code ↓
  // cout << T.root->left->right->value << endl;
  // cout << search_recursion(T, n2, 1) << endl;
  // cout << minimum(T, n1) << endl;
  // cout << maximum(T, n1) << endl;
  // cout << successor(T, n5) << endl;
  // cout << predecessor(T, n2) << endl;
  // DELETE(T, n2);
  // cout << T.root->right->right->value << endl;
  // cout << maximum(T, n1) << endl;
  // cout << search_iterative(T, n1, 2);
  traversal_pre(T, T.root);
  cout << endl;
  traversal_in(T, T.root);
  cout << endl;
  traversal_pos(T, T.root);
  cout << endl;
}
// NOTE MAIN END---------------------------------------
void insert(tree& T, node z)
{
  if(T.root == NULL)//如果这棵树为空
  {
    T.root = new BST;
    // T.length = 1;
    T.root->left = NULL;
    T.root->right = NULL;
    T.root->value = z.value;
    T.root->key = z.key;
    T.root->p = new BST;
    T.root->p->left = T.root;
    T.root->p->key = -1;
    T.root->p->value = -1;
    T.root->p->right = new BST;
    setNIL(*(T.root->p->right));
    // setNIL(*T.root->p);
    // T.root->length = 1;
    
    setNIL(*T.root);//设置root节点左右都为NIL
    return;
  }

  BST* x = T.root;//loop mode
  
  while (x->key != -1)//向下寻找到合适的位置
  {
    if(z.key < x->key)
      x = x->left;
    else
      x = x->right;
  }
  x->key = z.key;
  x->value = z.value;
  setNIL(*x);

}//插入的时候将插入的节点左右都设置成NIL

int search_iterative(tree & T, node y, int k)
{
  if(y.key == -1)
    return -1;
  if(y.key == k)
    return y.value;
  BST *x = search_key(T, y.key);
  while (x->key != k && x->key != -1)
  {
    if(x->key > k)
      x = x->left;
    else
      x = x->right;
  }
  return x->value;
}

int search_recursion(tree & T, node y, int k)
{
  if(y.key == -1)
    return -1;
  if(y.key == k)
    return y.value;
  BST *x = search_key(T, y.key);
  if(y.key > k)
    return search_recursion(T, {x->left->key, x->left->value}, k);
  else
    return search_recursion(T, {x->right->key, x->right->value}, k);
}

int minimum(tree &T, node y)
{
  if(y.key == -1)
    return -1;
  BST *x = search_key(T, y.key);
  while (x->left->key != -1)
  {
    x = x->left;
  }
  return x->value;
}

BST* minimum_node(tree &T, node y)
{
  if(y.key == -1)
    return NULL;
  BST *x = search_key(T, y.key);
  while (x->left->key != -1)
  {
    x = x->left;
  }
  return x;
}

int maximum(tree &T, node y)
{
  if(y.key == -1)
    return -1;
  BST *x = search_key(T, y.key);
  while (x->right->key != -1)
  {
    x = x->right;
  }
  return x->value;
}

BST* maximum_node(tree &T, node y)
{
  if(y.key == -1)
    return NULL;
  BST *x = search_key(T, y.key);
  while (x->right->key != -1)
  {
    x = x->right;
  }
  return x;
}

int successor(tree & T, node y)
{
  int minimum(tree & T, node y);
  if(y.key == -1)
    return -1;
  BST *x = search_key(T, y.key);
  if(x->right->value == -1)
    return -1;
  return minimum(T, {x->right->key, x->right->value});
}

BST* successor_node(tree & T, node y)
{
  BST* minimum_node(tree & T, node y);
  if(y.key == -1)
    return NULL;
  BST *x = search_key(T, y.key);
  if(x->right->value == -1)
    return NULL;
  return minimum_node(T, {x->right->key, x->right->value});
}

int predecessor(tree & T, node y)
{
  int maximum(tree & T, node y);
  if(y.key == -1)
    return -1;
  BST *x = search_key(T, y.key);
  if(x->left->value == -1)
    return -1;
  return maximum(T, {x->left->key, x->left->value});
}

BST * predecessor_node(tree & T, node y)
{
  BST* maximum_node(tree & T, node y);
  if(y.key == -1)
    return NULL;
  BST *x = search_key(T, y.key);
  if(x->left->value == -1)
    return NULL;
  return maximum_node(T, {x->left->key, x->left->value});
}

void DELETE(tree & T, node z)
{
  BST *x = search_key(T, z.key);
  if(x->left->key == -1 && x->right->key == -1)//leaf node
  {
    if(x->p->right->key == x->key)//检查叶节点在左侧还是右侧
    {
      x->p->right = x->right;
      // free(x->left);
      free(x);
    }
    else
    {
      x->p->left = x->left;
      // free(x->left);
      free(x);
    }
    return;
  }
  // NOTE 
  if(x->left->key != -1 && x->right->key != -1) // 左右儿子都存在
  {
    BST *y = successor_node(T, z);
    if(y->left->key == -1 && y->right->key == -1)//leaf node
    {
      if(y->p->right->key == y->key)//检查叶节点是否是右儿子
        y->p->right = y->right;
      else
        y->p->left = y->left;


        if(x->p->right->key == x->key)//检查叶节点是否是右儿子
          x->p->right = y;
        else
          x->p->left = y;
      }
    // if(y->right->key != -1)//有右儿子
    // {
    //   y->p->left = y->right;
    //   y->right->p = y->p;
    // }
    // else
    // {
    //   y->p->right = y->left;
    //   y->left = y->p->right;
    // }    

    y->left = x->left;
    y->right = x->right;
    y->p = x->p;
    x->left->p = y;
    x->right->p = y;
    if(T.root->key == x->key)
      T.root = y;

    return;  
  }      

   


  if(x->left->key == -1)//左节点是空的
  {
    if(x->p->right->key == x->key)//检查叶节点是否是右儿子
    {
      x->p->right = x->left;
      x->left->p = x->p;
      free(x);
    }
    else
    {
      x->p->left = x->left;
      x->left->p = x->p;
      free(x);
    }
    return;
  }
  else//右节点是空的
  {
    if(x->p->right->key == x->key)//检查叶节点是否是右儿子
    {
      x->p->right = x->right;
      x->right->p = x->p;
      free(x);
    }
    else
    {
      x->p->left = x->right;
      x->right->p = x->p;
      free(x);
    }
    return;
  }
}

void traversal_pre(tree & T, BST* x)
{
  if(x == NULL)
    return;
  if(x->value != -1)
    cout << x->value << ", ";
  traversal_pre(T, x->left);
  traversal_pre(T, x->right);
}

void traversal_in(tree & T, BST* x)
{
  if(x == NULL)
    return;
  traversal_in(T, x->left);
  if(x->value != -1)
    cout << x->value << ", ";
  traversal_in(T, x->right);
}

void traversal_pos(tree & T, BST* x)
{
  if(x == NULL)
    return;
  traversal_pos(T, x->left);
  traversal_pos(T, x->right);
  if(x->value != -1)
    cout << x->value << ", ";  
}




// BUG free
