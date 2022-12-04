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
			case 7: {//RBT Dump				//todo
        RBT1.Dump();
        break;
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

