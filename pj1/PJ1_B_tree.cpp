#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


struct insert_node //*插入点的格式
{
  string word;
  string property;
  string freq;
};

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
			case 0:{ //B-Tree Initialization
				string path;
				cin >> path;
				//todo
        BT.Init(BT, path);
        break;}
			case 1:{ //B-Tree Insert by command
				string word, property, freq; //* 与template不同
				cin >> word >> property >> freq;
				//todo
        BT.Insert(BT, word, property, freq);
        break;}
			case 2:{ //B-Tree Insert by file
				string path;
				cin >> path;
				//todo
        BT.Insert(BT, path);
        break;}
			case 3:{ //B-Tree Delete by command
				string key, property, freq; //* 
        cin >> key >> property >> freq;
        BT.Delete(BT, key);
        //todo
				break;}
			case 4:{ //B-Tree Delete by file
				string path;
				cin >> path;
				//todo
        BT.Delete(BT, path, 1);
        break;}
			case 5:{ //B-Tree Update by command
				string word, property, freq; //* 与template不同
				cin >> word >> property >> freq;
				//todo
        BT.Update(BT, BT.BT_getroot(),word, property, freq);
        break;}
			case 6:{ //B-Tree Search
				string key;
				cin >> key;
        BT.Search(BT, key);
        //todo
				break;}
			case 7:{ //B-Tree Dump
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