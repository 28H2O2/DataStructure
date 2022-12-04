#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class RBT{
	public:
		RBT()//构造函数
    {
      RBT_root = new RBT_node;
      RBT_root->left = NULL;
      RBT_root->right = NULL;
    }
    ~RBT()
    {
      free(RBT_root);
    }
		void Init(string path);
		void Insert();
		void Delete();
		void Update();
		void Search();
		void Dump();
  private:

    struct RBT_node //* 真正的RBT节点
    {
      //NOTE 考虑一下这里的key 和 word
      int key;
      RBT_node *p;
      RBT_node *left;
      RBT_node *right;
      string color;
      string value;
      string pro;
      string freq;  
    };

    struct insert_node //*插入点的格式
    {
      string value;
      string pro;
      string freq;
    };
    RBT_node *RBT_root;//* root节点
    void setNIL(RBT_node &x) //*给叶节点的左右儿子设置成NIL
    {
      x.left = new RBT_node;
      x.right = new RBT_node;
      x.left->key = -1;
      x.left->value = -1;
      x.left->p = &x;
      x.left->left = NULL;
      x.left->right = NULL;
      x.right->key = -1;
      x.right->value = -1;
      x.right->p = &x;
      x.right->left = NULL;
      x.right->right = NULL;
     }   
} RBT;

class B_Tree{
	public:
		B_Tree() {};
		void Init(string path);
		void Insert();
		void Delete();
		void Update();
		void Search();
		void Dump();
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
        RBT.Init(path);
        break;}
			case 1:{ //RBT Insert by command
				string key, value;
				cin >> key >> value;
				//todo
				break;}
			case 2:{ //RBT Insert by file
				string path;
				cin >> path;
				//todo
				break;}
			case 3:{ //RBT Delete by command
				string key, value;
				cin >> key >> value;
				//todo
				break;}
			case 4:{ //RBT Delete by file
				string path;
				cin >> path;
				//todo
				break;}
			case 5:{ //RBT Update by command
				string key, value;
				cin >> key >> value;
				//todo
				break;}
			case 6:{ //RBT Search
				string key;
				cin >> key;
				//todo
				break;}
			case 7: //RBT Dump
				//todo
				break;
			case 10:{ //B-Tree Initialization
				string path;
				cin >> path;
				//todo
        BT.Init(path);
        break;}
			case 11:{ //B-Tree Insert by command
				string key, value;
				cin >> key >> value;
				//todo
				break;}
			case 12:{ //B-Tree Insert by file
				string path;
				cin >> path;
				//todo
				break;}
			case 13:{ //B-Tree Delete by command
				string key, value;
				cin >> key >> value;
				//todo
				break;}
			case 14:{ //B-Tree Delete by file
				string path;
				cin >> path;
				//todo
				break;}
			case 15:{ //B-Tree Update by command
				string key, value;
				cin >> key >> value;
				//todo
				break;}
			case 16:{ //B-Tree Search
				string key;
				cin >> key;
				//todo
				break;}
			case 17:{ //B-Tree Dump
				//todo
				break;}
			default:{
				return 0;
        }
				
		}
		
	}
}



void RBT::Init(string path)
{
  fstream file_in(path);
  string l;
  vector<string> line; //*将每一行读入line容器中
  vector<string> word;
  vector<string> pro;
  vector<string> freq;
  //NOTE ↑考虑一下是string还是int
  while (getline(file_in, l))//*e.g. toughie N 26.0
  {
    line.push_back(l);

  }
  cout << line[1] << endl;
  // *初始化根节点：用line里面解析好的数据


}

void RBT::Insert()
{

}

void RBT::Delete()
{

}

void RBT::Search()
{

}

void RBT::Dump()
{

}


void B_Tree::Init(string path)
{

}

void B_Tree::Insert()
{

}

void B_Tree::Delete()
{

}

void B_Tree::Search()
{

}

void B_Tree::Dump()
{
  
}


// NOTE free
// NOTE 考虑如何传出数据
// NOTE 需要把行变成字符串的函数放在哪里
// NOTE 构造函数与析构函数

// * RBT Tree 没有写成全局变量，而是传引用，这样会不会在接口测试的时候有问题
// * 测试有专门的接口，不要紧