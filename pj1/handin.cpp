#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

enum node_color
{
  black,
  red
};

struct insert_node //*插入点的格式
{
  string word;
  string property;
  string freq;
};

class RBT{
	public:
		RBT()//构造函数
    {
      RBT_root = new RBT_node;
      RBT_root->left = NULL;
      RBT_root->right = NULL;
      RBT_root->word = "0";
    }
    ~RBT()
    {
      free(RBT_root);
    }
		void Init(string path);
		void Insert(RBT &T, string word, string property, string freq);
    void Insert(string path);//* override
    void Delete(RBT &T, string word);
    void Delete(string path);
    void Update(RBT &T, string word, string property, string freq);
		void Search(string word);
		void Dump();
  private:

    struct RBT_node //* 真正的RBT节点
    {
      //NOTE 考虑一下这里的key 和 word
      // int key;
      RBT_node *p;
      RBT_node *left;
      RBT_node *right;
      node_color color;
      string word;
      string property;
      string freq;  
    };

    RBT_node *RBT_root;//* root节点
    void setNIL(RBT_node &x) //*给叶节点的左右儿子设置成NIL
    {
      x.left = new RBT_node;
      x.right = new RBT_node;
      x.left->word = "0";
      x.left->p = &x;
      x.left->left = NULL;
      x.left->right = NULL;
      x.right->word = "0";
      x.right->p = &x;
      x.right->left = NULL;
      x.right->right = NULL;
     }
    void left_rotate(RBT &T, RBT_node *x);
    void right_rotate(RBT &T, RBT_node *x);
    void RB_insert_fixup(RBT &T, RBT_node *z);
    void traversal_pre(RBT_node *x);
    RBT_node *search_node(string word);//* 按照word找节点，很多地方用到
    int search_iterative(string word);
    void print_by_order(RBT_node *x);
    RBT_node *RB_successor_node(RBT_node *y);
    void RB_delete_fixup(RBT &T, RBT_node *x);
} RBT1;//* 全局变量
  
// NOTE  minimum↓
const  int t = 5; 

class B_Tree{
public:
  struct BT_node
  {
    BT_node *p;
    int n;//* 存储的关键字个数
    string k[2 * t];//k[0] 不用
    string property[2 * t];
    string freq[2 * t];
    bool leaf;//* 叶节点为TRUE 内部节点为FALSE
    BT_node *c[2 * t + 1]; //* 指向的子节点最多2*t个
  };
  struct BT_onlyone
  {
    BT_node *x;
    int i;//* 用于记录在x中的第几个
  };
  
  B_Tree() 
  {
    BT_root = new BT_node;
    BT_node *x = BT_root;
    x->leaf = true;
    x->n = 0;
    x->p = new BT_node;//root的父节点 备用    
  };
  ~B_Tree()
  {
    free(BT_root);
  }
  void Init(B_Tree &T, string path);
  void Insert(B_Tree &T, string path);
  void Insert(B_Tree &T, string word, string property, string freq);
  void Delete(B_Tree& T, string path , int flag);
  void Delete(B_Tree &T, string key);
  void Update(B_Tree &T, BT_node* x, string word, string property, string freq);
  void Search(B_Tree& T, string key);
  void Dump(B_Tree &T);
  BT_node* BT_getroot(){
    return BT_root;
  }

private:

  BT_node *BT_root;
  BT_node *BT_search_node(BT_node *x, string key);
  void BT_create(B_Tree &T);
  void BT_split_child(BT_node *x, int i);
  void BT_insert_nonfull(BT_node *x, string k, string property, string freq);
  void BT_order(BT_node *x);
  void BT_merge_child(BT_node *x, int i, BT_node *y, BT_node *z);
  void BT_delete_nonone(BT_node *r, string key);
  BT_onlyone BT_predecessor(BT_node *x);
  BT_onlyone BT_successor(BT_node *x);
  void BT_shift_to_right_child(BT_node *x, int i, BT_node *y, BT_node *z);
  void BT_shift_to_left_child(BT_node *x, int i, BT_node *y, BT_node *z);
} BT;


int main(){
	while (true) {
		int Optype;
		scanf("%d", &Optype);
    switch (Optype) {
			case 0:{ //RBT Initialization
				string path;
				cin >> path;
				//todo
        RBT1.Init(path);
        // cout << "Init finished!" << endl;
        break;}
			case 1:{ //RBT Insert by command
				string word, property, freq; //* 与template不同
				cin >> word >> property >> freq;
				//todo
        RBT1.Insert(RBT1, word, property, freq);
        break;}
			case 2:{ //RBT Insert by file
				string path;
				cin >> path;
				//todo
        RBT1.Insert(path);
        break;}
			case 3:{ //RBT Delete by command
				string word, property, freq; //* 与template不同
        cin >> word >> property >> freq;
        //todo
        RBT1.Delete(RBT1, word);
        break;}
			case 4:{ //RBT Delete by file
				string path;
				cin >> path;
				//todo
        RBT1.Delete(path);
        break;}
			case 5:{ //RBT Update by command
				string word, property, freq; //* 与template不同
				cin >> word >> property >> freq;
				//todo
        RBT1.Update(RBT1, word, property, freq);
        break;}
			case 6:{ //RBT Search
				string key;
				cin >> key;
				//todo
        RBT1.Search(key);
        break;}
			case 7:{ //RBT Dump
				//todo
        RBT1.Dump();
        break;}
			case 10:{ //B-Tree Initialization
				string path;
				cin >> path;
				//todo
        BT.Init(BT, path);
        break;}
			case 11:{ //B-Tree Insert by command
				string word, property, freq; //* 与template不同
				cin >> word >> property >> freq;
				//todo
        BT.Insert(BT, word, property, freq);
        break;}
			case 12:{ //B-Tree Insert by file
				string path;
				cin >> path;
				//todo
        BT.Insert(BT, path);
        break;}
			case 13:{ //B-Tree Delete by command
				string key, property, freq; //* 
        cin >> key >> property >> freq;
        BT.Delete(BT, key);
        //todo
				break;}
			case 14:{ //B-Tree Delete by file
				string path;
				cin >> path;
				//todo
        BT.Delete(BT, path, 1);
        break;}
			case 15:{ //B-Tree Update by command
				string word, property, freq; //* 与template不同
				cin >> word >> property >> freq;
				//todo
        BT.Update(BT, BT.BT_getroot(),word, property, freq);
        break;}
			case 16:{ //B-Tree Search
				string key;
				cin >> key;
        BT.Search(BT, key);
        //todo
				break;}
			case 17:{ //B-Tree Dump
				//todo
        BT.Dump(BT);
        break;}
      case 20:{
        return 0;
      }
			default:{
				return 0;
        }
				
		}
		
	}
}

void RBT::Init(string path) //* Init函数包含了读文件的功能
{
  fstream file_in(path);
  string l;
  vector<string> line; //*将每一行读入line容器中
  vector<string> word;
  vector<string> property;
  vector<string> freq;
  //NOTE ↑考虑一下是string还是int
  // *初始化根节点：用line里面解析好的数据
  while (getline(file_in, l))//*e.g. toughie N 26.0
  {
    line.push_back(l);
    // * 以下为找string的各个部分
    const char *p = l.c_str();
    const char *p1 = strstr(p, " ");
    const char *p1_1 = p1 + 1;
    const char *p2 = strstr(p1_1, " ");
    const char *p2_1 = p2 + 1;
    const char *p3 = strstr(p2_1, ".");
    char p_word[100] = {0};
    memcpy(p_word, p, p1 - p);
    string read_word = string(p_word);
    if(read_word == "Word")//* 读第一行，如果是Word就continue
      continue;
    char p_property[5] = {0};
    memcpy(p_property, p1_1, p2 - p1 - 1);
    string read_property = string(p_property);
    char p_freq[20] = {0};
    memcpy(p_freq, p2_1, p3 - p2 + 1);
    string read_freq = string(p_freq);
    word.push_back(read_word);
    property.push_back(read_property);
    freq.push_back(read_freq);
    
    // insert_node insert = {read_word, read_property, read_freq};
    Insert(RBT1, read_word, read_property, read_freq);
  }
  
  // cout << property[1] << endl;
  // cout << freq[2] << endl;



}

void RBT::left_rotate(RBT &T, RBT_node *x)
{
  RBT_node *y = x->right;
  x->right = y->left;
  y->left->p = x;
  y->p = x->p;
  if(x->p->word == "0")
    T.RBT_root = y;
  else 
  {
    if(x == x->p->left)
      x->p->left = y;
    else
      x->p->right = y;
  }
  y->left = x;
  x->p = y;
}

void RBT::right_rotate(RBT& T, RBT_node *x)
{
  RBT_node *y = x->left;
  x->left = y->right;
  y->right->p = x;
  y->p = x->p;
  // BUG
  if(x->p->word == "0")
    T.RBT_root = y; 
  else 
  {
    if(x == x->p->left)
      x->p->left = y;
    else
      x->p->right = y;
  }
  y->right = x;
  x->p = y;
}

void RBT::RB_insert_fixup(RBT &T, RBT_node *z)
{
  while (z->p->color == red)
  {
    
    if(z->p == z->p->p->left)//* 如果是父亲是左儿子
    {

      RBT_node *y = z->p->p->right;
      if(y->color == red)
      {
        z->p->color = black;
        y->color = black;
        z->p->p->color = red;
        z = z->p->p;
        
      }
      else 
      {
        if(z == z->p->right)
        {
          z = z->p;
          left_rotate(T, z);    //* case2
        }
        z->p->color = black;  //* case3
        z->p->p->color = red;
        right_rotate(T, z->p->p); 
        
      }
      // cout << z->p->word << " ";
    }
    else
    {
      RBT_node *y = z->p->p->left;//* 这里的y有没有问题?
      if(y->color == red)
      {
        z->p->color = black;
        y->color = black;
        z->p->p->color = red;
        z = z->p->p;
      }
      else 
      {
        if(z == z->p->left)
        {
          z = z->p;
          right_rotate(T, z);    //* case2
        }

        z->p->color = black;  //* case3
        z->p->p->color = red;
        left_rotate(T, z->p->p);
      }
    }
  }
  T.RBT_root->color = black;
}

void RBT::Insert(RBT &T, string word, string property, string freq)
{
  if(T.RBT_root->word == "0")//* 如果根节点为空
  {
    T.RBT_root->word = word;//* 根节点赋值
    T.RBT_root->freq = freq;
    T.RBT_root->property = property;
    T.RBT_root->color = black;
    setNIL(*T.RBT_root);
    // T.RBT_root->left = new RBT_node;
    // T.RBT_root->right = new RBT_node;
    setNIL(*(T.RBT_root->left));
    setNIL(*(T.RBT_root->right));

    T.RBT_root->p = new RBT_node;//* 创建根节点的（不存在的）父亲，便于Delete（与lab5相同）
    T.RBT_root->p->left = T.RBT_root;
    T.RBT_root->p->right = new RBT_node;
    T.RBT_root->p->word = "0";
    T.RBT_root->p->color = black;
    T.RBT_root->p->freq = "0";
    T.RBT_root->p->property = "0";

    T.RBT_root->p->right->color = black;//* BUG ?
    setNIL(*(T.RBT_root->p->right));
    return;
  }

  RBT_node* x = T.RBT_root;
  RBT_node y;
  while (x->word != "0")
  {
    if(word == x->word)
    {
      cout << "key " << x->word << " conflict" << endl;
      return;
    }
    else if(word < x->word)
      x = x->left;
    else
      x = x->right;
  }
  x->word = word;
  x->freq = freq;
  x->property = property;
  x->color = red;// *设置初始颜色为red
  setNIL(*x);//* 设置root节点左右都为NIL
  RB_insert_fixup(T, x);//* fixup
}

void RBT::Insert(string path)
{
  Init(path);
}

void RBT::Update(RBT &T, string word, string property, string freq)
{
  RBT_node *x = T.RBT_root;
  while (x->word != word && x->word != "0")
  {

    if(word < x->word)
      x = x->left;
    else
      x = x->right;
  }
  if(x->left == NULL)
  {
    T.Insert(T, word, property, freq);    
  }
  else
  {
    x->property = property;
    x->freq = freq;
  }

}

RBT::RBT_node* RBT::search_node(string word)
{
  RBT_node *x = RBT1.RBT_root;
  while (x->word != word && x->word != "0")
  {

    if(word < x->word)
      x = x->left;
    else
      x = x->right;
  }
  return x;
}

void RBT::Search(string word)
{

  RBT_node *x = search_node(word);
  if(x->left == NULL)// todo 这里是可以的吗？
    cout << "key " << word << " missing" << endl;
  else
    cout << x->word << ", " << x->property << ", " << x->freq << endl;
}

void RBT::traversal_pre(RBT_node* x)
{
  if(x == NULL)
    return;
  if(x->word != "0")
  {
    cout << x->word << ", " << x->property << ", " << x->freq << endl;
    // cout << x->color << endl;
  }

  traversal_pre(x->left);
  traversal_pre(x->right);
}

void RBT::print_by_order(RBT_node* x)
{
  if(x->word == "0")
    return;
  else
  {
    print_by_order(x->left);
    cout << x->word << ", " << x->property << ", " << x->freq << endl;
    print_by_order(x->right);
  }
}

void RBT::Dump()
{
  // traversal_pre(RBT1.RBT_root);
  print_by_order(RBT1.RBT_root);
}

RBT::RBT_node* RBT::RB_successor_node(RBT_node *y)
{
  if(y->word == "0" || y->right->word == "0")
    return NULL;
  // RBT_node *x = search_node(y->word);
  y = y->right;
  while (y->left->word != "0")
  {
    y = y->left;
  }
  return y;
}

void RBT::RB_delete_fixup(RBT& T, RBT_node *x)
{
  while (x != T.RBT_root && x->color == black)
  {
    if(x == x->p->left)
    {
      RBT_node *w = x->p->right;
      if(w->color == red)
      {
        w->color = black;
        x->p->color = red;
        left_rotate(T, x->p);
        w = x->p->right;
      }
      if(w->left->color == black && w->right->color == black)
      {
        w->color = red;
        x = x->p;
      }
      else
      {
        if(w->right->color == black)
        {
          w->left->color = black;
          w->color = red;
          right_rotate(T, w);
          w = x->p->right;
        }
        w->color = x->p->color;
        x->p->color = black;
        w->right->color = black;
        left_rotate(T, x->p);
        x = T.RBT_root;
      }
    }
    else
    {
      RBT_node *w = x->p->left;
      if(w->color == red)
      {
        w->color = black;
        x->p->color = red;
        right_rotate(T, x->p);
        w = x->p->left;
      }
      if(w->right->color == black && w->left->color == black)
      {
        w->color = red;
        x = x->p;
      }
      else
      {
        if(w->left->color == black)
        {
          w->right->color = black;
          w->color = red;
          left_rotate(T, w);
          w = x->p->left;
        }
        w->color = x->p->color;
        x->p->color = black;
        w->left->color = black;
        right_rotate(T, x->p);
        x = T.RBT_root;
      }      
    }
  }
  x->color = black;
}

void RBT::Delete(RBT& T, string word)
{
  RBT_node *z = search_node(word);

  if(z->left == NULL)
  {
    cout << "key " << word << " missing" << endl;
    return;
  }
  RBT_node *y = NULL;
  RBT_node *x = NULL;
  if(z->left->word == "0" || z->right->word == "0")
    y = z;
  else
    y = RB_successor_node(z);//* 后继

  if(y->left->word != "0")
    x = y->left;
  else
    x = y->right;
  x->p = y->p;
  if(y->p->word == "0")
  {
    T.RBT_root = x;
  }
  else
  {
    if(y == y ->p->left)
      y->p->left = x;
    else
      y->p->right = x;
  }
  if(y != z)
  {
    z->word = y->word;

  }
  if(y->color == black)
    T.RB_delete_fixup(T, x);
}

void RBT::Delete(string path)
{
  fstream file_in(path);
  string l;
  vector<string> line; //*将每一行读入line容器中
  vector<string> word;
  vector<string> property;
  vector<string> freq;
  //NOTE ↑考虑一下是string还是int
  // *初始化根节点：用line里面解析好的数据
  while (getline(file_in, l))//*e.g. toughie N 26.0
  {
    line.push_back(l);
    // * 以下为找string的各个部分
    const char *p = l.c_str();
    const char *p1 = strstr(p, " ");
    // const char *p1_1 = p1 + 1;
    // const char *p2 = strstr(p1_1, " ");
    // const char *p2_1 = p2 + 1;
    // const char *p3 = strstr(p2_1, ".");
    char p_word[100] = {0};
    memcpy(p_word, p, p1 - p);
    string read_word = string(p_word);
    if(read_word == "Word")//* 读第一行，如果是Word就continue
      continue;
    // char p_property[5] = {0};
    // memcpy(p_property, p1_1, p2 - p1 - 1);
    // string read_property = string(p_property);
    // char p_freq[20] = {0};
    // memcpy(p_freq, p2_1, p3 - p2 + 1);
    // string read_freq = string(p_freq);
    // word.push_back(read_word);
    // property.push_back(read_property);
    // freq.push_back(read_freq);
    
    // insert_node insert = {read_word, read_property, read_freq};
    Delete(RBT1, read_word);
  }
}


// *BT---------------------------------------------------
// void B_Tree::BT_create(B_Tree &T)
// {

// }
void B_Tree::BT_split_child(BT_node *x, int i)
{
  //BUG 这样写和指向NULL的区别是？
  BT_node *z = new BT_node;
  BT_node *y = x->c[i];
  z->leaf = y->leaf;
  z->n = t - 1;
  for (int j = 1; j <= t - 1; ++j)
  {
    z->k[j] = y->k[j + t];
    z->property[j] = y->property[j + t];
    z->freq[j] = y->freq[j + t];
  }
  if(!y->leaf)
  {
    for (int j = 1; j <= t; ++j)
    {
      z->c[j] = y->c[j + t];
    }
  }
  y->n = t - 1;
  for (int j = x->n + 1; j >= i + 1; --j)
  {
    x->c[j + 1] = x->c[j];
  }
  x->c[i + 1] = z;
  for (int j = x->n; j >= i; --j)
  {
    x->k[j + 1] = x->k[j];
    x->property[j + 1] = x->property[j];
    x->freq[j + 1] = x->freq[j];
  }
  x->k[i] = y->k[t];
  x->property[i] = y->property[t];
  x->freq[i] = y->freq[t];
  x->n = x->n + 1;
}

void B_Tree::BT_insert_nonfull(BT_node *x, string key, string property, string freq)
{
  int flag = 0;
  int i = x->n;
  if(x->leaf)
  {
    if(key == x->k[i])
    {
      cout << "key " << key << " conflict" << endl;
      return;
    }
    while (i >= 1 && key < x->k[i])
    {

      x->k[i + 1] = x->k[i];
      x->property[i + 1] = x->property[i];
      x->freq[i + 1] = x->freq[i];
      i = i - 1;
      if(key == x->k[i])
      {
        cout << "key " << key << " conflict" << endl;
        return;
      }
    }
    x->k[i + 1] = key;
    // cout << key << endl;
    x->property[i + 1] = property;
    x->freq[i + 1] = freq;
    // cout << property << endl;
    // cout << x->property[i + 1] << endl;
    x->n = x->n + 1;
  }
  else
  {
    if(key == x->k[i])
    {
      cout << "key " << key << " conflict" << endl;
      return;
    }
    while (i >= 1 && key < x->k[i])
    {
      i = i - 1;
      if(key == x->k[i])
      {
        cout << "key " << key << " conflict" << endl;
        return;
      }
    }
    i = i + 1;
    if(x->c[i]->n == 2 * t - 1)
    {
      BT_split_child(x, i);
      if(key > x->k[i])
      {
        i = i + 1;
      }
    }
    BT_insert_nonfull(x->c[i], key, property, freq);
  }
}

void B_Tree::Insert(B_Tree& T, string key, string property, string freq)
{
  BT_node *r = T.BT_root;
  if(r->n == 2 * t - 1)
  {
    BT_node *s = new BT_node;
    T.BT_root = s;
    s->leaf = false;
    s->n = 0;
    s->c[1] = r;
    BT_split_child(s, 1);
    BT_insert_nonfull(s, key, property, freq);
  }
  else
  {
    BT_insert_nonfull(r, key, property, freq);
  }
  BT_node *x = BT.BT_root;

}

void B_Tree::Init(B_Tree &T, string path)
{
  // T.BT_root = new BT_node;
  // BT_node *x = T.BT_root;
  // x->leaf = true;
  // x->n = 0;
  // x->p = new BT_node;//root的父节点 备用

  fstream file_in(path);
  string l;
  vector<string> line; //*将每一行读入line容器中
  vector<string> word;
  vector<string> property;
  vector<string> freq;
  //NOTE ↑考虑一下是string还是int
  // *初始化根节点：用line里面解析好的数据
  while (getline(file_in, l))//*e.g. toughie N 26.0
  {
    line.push_back(l);
    // * 以下为找string的各个部分
    const char *p = l.c_str();
    const char *p1 = strstr(p, " ");
    const char *p1_1 = p1 + 1;
    const char *p2 = strstr(p1_1, " ");
    const char *p2_1 = p2 + 1;
    const char *p3 = strstr(p2_1, ".");
    char p_word[100] = {0};
    memcpy(p_word, p, p1 - p);
    string read_word = string(p_word);
    if(read_word == "Word")//* 读第一行，如果是Word就continue
      continue;
    char p_property[5] = {0};
    memcpy(p_property, p1_1, p2 - p1 - 1);
    string read_property = string(p_property);
    char p_freq[20] = {0};
    memcpy(p_freq, p2_1, p3 - p2 + 1);
    string read_freq = string(p_freq);
    word.push_back(read_word);
    property.push_back(read_property);
    freq.push_back(read_freq);

    Insert(BT, read_word, read_property, read_freq);
  }
}

void B_Tree::Insert(B_Tree& T, string path)
{
  T.Init(T, path);
}

B_Tree::BT_node* B_Tree::BT_search_node(BT_node *x, string key)
{
  int i = 1;
  while (i <= x->n && key > x->k[i])
  {
    i = i + 1;
  }
  if(i <= x->n && key == x->k[i])
  {
    cout << x->k[i] << ", " << x->property[i] << ", " << x->freq[i] << endl;
    return x;
  }
  else
  {
    if(x->leaf == true)
    {
      cout << "key " << key << " missing" << endl;
      return x;
    }
    else
    {
      return BT_search_node(x->c[i], key);
    }
  }
}

void B_Tree::Search(B_Tree& T, string key)
{
  BT_node *x = T.BT_root;
  BT_node *y = BT_search_node(x, key);
  // if(y->leaf == true)
  //   cout << "key " << key << " missing" << endl;
  // else
  //   return;
}

void B_Tree::Update(B_Tree &T, BT_node *x, string key, string property, string freq)
{
  int i = 1;
  // BT_node *x = BT.BT_root;
  while (i <= x->n && key > x->k[i])
  {
    i = i + 1;
  }
  if(i <= x->n && key == x->k[i])
  {
    x->property[i] = property;
    x->freq[i] = freq;
    return;
  }
  else
  {
    if(x->leaf == true)
    {
      BT.Insert(BT, key, property, freq);
    }
    else
    {
      return Update(T, x->c[i], key, property, freq);
    }
  }  
}

void B_Tree::BT_order(BT_node* r)
{
  // BT_node *r = BT.BT_root;
  // cout << (long long)r << endl;
  // if(r == NULL)
  //   return;
  int i = 1;
  for (; i <= r->n; ++i)
  {
    if(r->leaf)
    {
      cout << r->k[i] << ", " << r->property[i] << ", " << r->freq[i] << endl;
      if(i == r->n)
        return;
      else
        continue;
    }
    else
    {
      BT_order(r->c[i]);
      cout << r->k[i] << ", " << r->property[i] << ", " << r->freq[i] << endl;      
    }

  }
  BT_order(r->c[i]);
}

void B_Tree::Dump(B_Tree &T)
{
  BT_node *r = BT.BT_root;
  BT_order(r);
}


void B_Tree::BT_merge_child(BT_node *x, int i, BT_node *y, BT_node *z)
{
  y->n = 2 * t - 1;
  for (int j = t + 1; j <= 2 * t - 1; ++j)
  {
    y->k[j] = z->k[j - t];//* 注意添加freq
    y->property[j] = z->property[j - t];
    y->freq[j] = z->freq[j - t]; 
  }
  y->k[t] = x->k[i];//* 从父顶点放下来的
  y->property[t] = x->property[i];
  y->freq[t] = x->freq[i];
  if(!y->leaf)
  {
    for (int j = t + 1; j <= 2 * t ; ++j)//* "2*t-1"
    {
      y->c[j] = z->c[j - t];
      // y->property[j] = z->property[j - t];
      // y->freq[j] = z->freq[j - t];
    }
  }
  for (int j = i + 1; j <= x->n; ++j)
  {
    x->c[j] = x->c[j + 1];
    x->k[j - 1] = x->k[j];//* value前移
    x->property[j - 1] = x->property[j];
    x->freq[j - 1] = x->freq[j];
  }
  x->c[x->n + 1] = NULL;
  //* free or point to NULL
  x->n--;
}

B_Tree::BT_onlyone B_Tree::BT_predecessor(BT_node *y)
{
  BT_node *x = y;
  int i = x->n;
  while (!x->leaf)
  {
    x = x->c[i + 1];
    i = x->n;
  }
  // return x->k[i];
  return {x, i};
}

B_Tree::BT_onlyone B_Tree::BT_successor(BT_node *z)
{
  BT_node *x = z;
  while (!x->leaf)
  {
    x = x->c[1];
  }
  // return x->k[1];
  return {x, 1};
}

void B_Tree::BT_shift_to_right_child(BT_node *x, int i, BT_node *y, BT_node *z)
{
  z->n++;
  int j = z->n;
  while (j > 1)
  {
    z->k[j] = z->k[j - 1];
    z->property[j] = z->property[j - 1];
    z->freq[j] = z->freq[j - 1];
    j--;
  }
  z->k[1] = x->k[i];
  z->property[1] = x->property[i];
  z->freq[1] = x->freq[i];

  x->k[i] = y->k[y->n];//*freq
  x->property[i] = y->property[y->n];
  x->freq[i] = y->freq[y->n];
  if(!z->leaf)
  {
    j = z->n;
    while (j > 0)
    {
      z->c[j + 1] = z->c[j];
      j--;
    }
    z->c[1] = y->c[y->n + 1];
  }
  y->n--;
}

void B_Tree::BT_shift_to_left_child(BT_node *x, int i, BT_node *y, BT_node *z)
{
  y->n++;
  y->k[y->n] = x->k[i];
  y->property[y->n] = x->property[i];
  y->freq[y->n] = x->freq[i];

  x->k[i] = z->k[1];
  x->property[i] = z->property[1];
  x->freq[i] = z->freq[1];
  z->n--;
  int j = 1;
  while (j <= z->n)
  {
    z->k[j] = z->k[j + 1];
    z->property[j] = z->property[j + 1];
    z->freq[j] = z->freq[j + 1];
    j++;
  }
  if(!z->leaf)
  {
    y->c[y->n + 1] = z->c[1];
    j = 1;
    while (j <= z->n + 1)
    {
      z->c[j] = z->c[j + 1];
      j++;
    }
    
  }

  
}

void B_Tree::BT_delete_nonone(BT_node *x, string key)
{
  int i = 1;
  if(x->leaf)
  {
    while (i <= x->n && key > x->k[i])
    {
      // cout << x->k[i] << ", " << x->property[i] << ", " << x->freq[i] << endl;
      i++;
    }
    if(key == x->k[i])
    {
      for (int j = i + 1; j <= x->n ; ++j)//* 大于小于交换?
      {
        x->k[j - 1] = x->k[j];
        x->property[j - 1] = x->property[j];
        x->freq[j - 1] = x->freq[j];
      }
      x->n = x->n - 1;
    }
    else
    {
      cout << "key " << key << " missing" << endl;
      return;
    }
    
    
  }
  else
  {      
    BT_node *y = x->c[i];
    BT_node *z;
    BT_node *p;
    string kk = "NULL";
    while (i <= x->n && key > x->k[i]) 
    {
      i++;
    }
    // BUG c[i]'s number is LESS than n ?????
    y = x->c[i];
    // string kk;
    if(i <= x->n)
    {
      z = x->c[i + 1];  
    }

    if(key == x->k[i])
    {
      if(y->n > t - 1)
      {
        BT_onlyone one = BT_predecessor(y);
        string property_save = one.x->property[one.i];
        string freq_save = one.x->freq[one.i];
        // kk = BT_predecessor(y);
        kk = one.x->k[one.i];
        BT_delete_nonone(y, kk);
        x->k[i] = kk;
        x->property[i] = property_save;
        x->freq[i] = freq_save;          
      }
      else if(z->n > t - 1)
      {
        {
        BT_onlyone one = BT_successor(z);
        string property_save = one.x->property[one.i];
        string freq_save = one.x->freq[one.i];
        // kk = BT_successor(z);
        kk = one.x->k[one.i];
        BT_delete_nonone(z, kk);
        x->k[i] = kk;
        x->property[i] = property_save;
        x->freq[i] = freq_save;
        }
      }
      else
      {
        BT_merge_child(x, i, y, z);
        BT_delete_nonone(y, key);
      }
    }
    else
    {
      if(i > 1)
      {
        p = x->c[i - 1];
      }
      if(y->n == t - 1)
      {
        if(i > 1 && p->n > t - 1)
        {
          BT_shift_to_right_child(x, i-1, p, y);
        }
        else if(i <= x->n && z->n > t - 1)
        {
          BT_shift_to_left_child(x, i, y, z);
        }
        else if(i > 1)
        {
          BT_merge_child(x, i - 1, p, y);
          // BT_merge_child(x, i, y, z);
          y = p;
        }
        else
        {
          BT_merge_child(x, i, y, z);
        }
      }
      BT_delete_nonone(y, key); //^_^ 这句话的位置？ 在哪个括号里面          
    }



  }
}

void B_Tree::Delete(B_Tree &T, string key)
{
  BT_node *r = T.BT_root;
  if(r->n == 1)
  {
    BT_node *y = r->c[1];
    BT_node *z = r->c[2];
    if(y->n == z->n && y->n == t - 1)
    {
      BT_merge_child(r, 1, y, z);
      T.BT_root = y;
      // free(r);
      BT_delete_nonone(y, key);    
    }
    else
    {
      BT_delete_nonone(r, key);
    }

  }
  else
  {
    BT_delete_nonone(r, key);
  }
  BT_node *x = BT.BT_root;
}

void B_Tree::Delete(B_Tree &T, string path, int flag)
{
  fstream file_in(path);
  string l;
  vector<string> line; //*将每一行读入line容器中
  vector<string> word;
  vector<string> property;
  vector<string> freq;
  //NOTE ↑考虑一下是string还是int
  // *初始化根节点：用line里面解析好的数据
  while (getline(file_in, l))//*e.g. toughie N 26.0
  {
    line.push_back(l);
    // * 以下为找string的各个部分
    const char *p = l.c_str();
    const char *p1 = strstr(p, " ");
    const char *p1_1 = p1 + 1;
    const char *p2 = strstr(p1_1, " ");
    const char *p2_1 = p2 + 1;
    const char *p3 = strstr(p2_1, ".");
    char p_word[100] = {0};
    memcpy(p_word, p, p1 - p);
    string read_word = string(p_word);
    if(read_word == "Word")//* 读第一行，如果是Word就continue
      continue;
    char p_property[5] = {0};
    memcpy(p_property, p1_1, p2 - p1 - 1);
    string read_property = string(p_property);
    char p_freq[20] = {0};
    memcpy(p_freq, p2_1, p3 - p2 + 1);
    string read_freq = string(p_freq);
    word.push_back(read_word);
    property.push_back(read_property);
    freq.push_back(read_freq);
    Delete(T, read_word);
  }
}

// NOTE free
// NOTE 考虑如何传出数据
// NOTE 需要把行变成字符串的函数放在哪里
// NOTE 代码的复用性
// NOTE 构造函数与析构函数

// * RBT Tree 没有写成全局变量，而是传引用，这样会不会在接口测试的时候有问题
// * 测试有专门的接口，不要紧