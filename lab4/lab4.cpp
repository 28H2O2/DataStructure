#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;


typedef struct student
{
  string info;
  int key;
} struct_student;

struct_student NIL;
struct_student DELETED;
//global
int n = 46;
int m = 128;
vector<string> words;
vector<string> name;
vector<int> num_name;

int h1(int k, int m)//hash function1 multiplication
{
  return ((311*k)%512)>>2;
}

int h2(int k, int m)//hash function2 division
{
  return k % m;
}

int double_hashing(int k, int m, int i)//double hashing
{
  return (h1(k, m) + i * h2(k, m)) % m;
}

int INSERT(vector<struct_student>& ht, int k, int m, string inf)
{
  int i = 0;
  int j;
  while (i < m)
  {
    j = double_hashing(k, m, i);
    if(ht[j].key == -1)
    {
      ht[j].key = k;
      ht[j].info = inf;
      return j;
    }
    ++i;
  }
  cout << "hashtable overflow!" << endl;
  return -1;
}

string SEARCH(vector<struct_student>& ht, int k, int m)// k equals name
{
  int i = 0;
  int j;
  while (i < m)
  {
    j = double_hashing(k, m, i);
    if(ht[j].key == -1)
    {
      cout << "can't find k!" << endl;
      return "NULL";
    }
    if(ht[j].key == k)
      return ht[j].info;
    ++i;
  }
  cout << "can't find k!" << endl;
  return "NULL";
  
}

int DELETE(vector<struct_student>& ht, int k, int m, string inf)
{
  int i = 0;
  int j;
  while (1)
  {
    j = double_hashing(k, m, i);
    if( i == m)
      return -1;
    if( ht[j].key == -1 | ht[j].key == 0)
      return -1;
    if(ht[j].key == k)
    {
      ht[j].key = 0;//DELETED
      ht[j].info = ' ';
    }
    ++i;
  }


  
}

int main()
{
  double Evaluate(vector<struct_student> & ht);
  int n = 46;// 46 people
  fstream f("lab4pinyin.txt");
  string line;
  while (getline(f, line))
  {
    words.push_back(line);
  }
  // INFO read data from txt

  // vector<int> reverse_key;
  for (int i = 0; i < n; ++i)//read name
    {
      int start = 12;//name_start
      while (words[i][start] >= 'a' && words[i][start] <= 'z')
      {
        ++start;
      }
      string name_str = words[i].substr(12, start - 12);
      name.push_back(name_str);
    }
  for (int i = 0; i < n; ++i)//create number
  {
    int num = 0;
    for (int j = 0; j < name[i].length();++j)
    {
      num += (int)name[i][j];
      // cout << num << " ";
    }
    num_name.push_back(num);
  }

  vector<struct_student> hashtable;

  struct_student NIL;//empty
  NIL.info = ' ';
  NIL.key = -1;
  struct_student DELETED;//deleted
  DELETED.info = ' ';
  DELETED.key = 0;

  for (int i = 0; i < m; ++i)// initialization
    hashtable.push_back(NIL);// -1 equals nil

  for (int i = 0; i < n; ++i)
  {
    INSERT(hashtable, num_name[i], m, words[i]);
  }  

  // DELETE(hashtable, num_name[6], m, "20307110123 zhangyihan 物理学 男");

  // string namestring;
  // getline(cin, namestring);
  // int num = 0;
  // for (int j = 0; j < namestring.length();++j)
  //   {
  //     num += (int)namestring[j];
  //     // cout << num << " ";
  //   }
  // cout << SEARCH(hashtable, num, m) << endl;

  // cout << "average = "<< Evaluate(hashtable) << endl;

}

double Evaluate(vector<struct_student>& ht) //average
{
  for (int i = 0; i < n; ++i)
  {
    INSERT(ht, num_name[i], m, words[i]);
  }
  //INFO SEARCH↓
  int sum = 0;

  for (int s = 0; s < n; ++s)
  {  
    int i = 0;
    int j;
    while (i < m)
    {
      j = double_hashing(num_name[i], m, i);
      // if (ht[j].key == -1)
      // {
      //   cout << "can't find k!" << endl;
      //   return "NULL";
      // }
      if (ht[j].key == num_name[i])
      {
        sum += (i + 1);
        break;
      }  

      ++i;
    }    
  }
  double res = 0;
  res = sum / n;
  return res;
}


