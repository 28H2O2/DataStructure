#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>
#include<limits>
#include <algorithm>
#include <windows.h>
#include<numeric>
using namespace std;
  int k, n;

int main()
{
  void Time(int, int);
  for (int k = 2; k < 200; k++)
  {
    Time(k, 10000);
  }
}

void Time(int k, int n)
{
  void create_max(vector<int> &a, int k, int n, int l);
  void EXTRACT_MAX(vector<int> & a, int& n, int k);
  void INCREASE_KEY(vector<int> & a, int i, int key, int& n, int k);
  void INSERT(vector<int> &a, int x, int &n, int k);
  void output(const vector<int> &a);

  // //input begin  
  // cout << "Please input k and n!" << endl;
  // cin >> k >> n;
  vector<int> a;
  for (int i = 0; i < n; ++i)
  {
    a.push_back(n - i);
  }
    // int temp;
    // int l = 0;
    // while (cin>>temp)
    // {
    //     a.push_back(temp);
    //     if(cin.get()=='\n') break;

    // }
    // input finished
    // k = 3;
    // n = 17;
    // vector<int> a;//stable input
    // a = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 1, 8, 9, 7, 3, 1, 2, 4};
    int farest = k * n + k;
  for (int i = n; i < farest; ++i)//将不存在的子节点变成最小值
    a.push_back(numeric_limits<int>::min());
  create_max(a, k, n, n);//创建最大堆
  // output(a);
  // int i, key;
  // INCREASE_KEY(a, i, key, n, k);
  // int x;
  // INSERT(a, x, n, k);
  int i;
  // NOTE 以下为计算程序执行时间
  LARGE_INTEGER t1, t2, tc;
  QueryPerformanceFrequency(&tc);
  QueryPerformanceCounter(&t1);
  //执行排序程序
  INSERT(a, 1000, n, k);

  QueryPerformanceCounter(&t2);
  double time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
  cout << k<<" "<<time << " " << endl;
}

void output(const vector<int>& a)
{
  for (int i = 0; i < n; ++i)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

void create_max(vector<int> &a, int k, int n, int l)
{
    if(l < 0)
      return;

    int minOfSons = l * k + 1;//最小的子节点
    vector<int> temp;
    for (int j = minOfSons; j < minOfSons + k && j < n; ++j){
      temp.push_back(a[j]);      
    }
    if(minOfSons < n)
    {
      auto maxValue = max_element(temp.begin(), temp.end());
      int maxOfSons = *maxValue;// 最大值
      int maxPosition = maxValue - temp.begin();//最大值的下标
      temp.clear();
      if(maxOfSons > a[l])
      {
        swap(a[l], a[maxPosition + minOfSons]);        
        l = maxPosition + minOfSons;      
      }
      else{
        l = l - 1;
      }
      create_max(a, k, n, l);      
    }
    else{
      create_max(a, k, n, l - 1);      
    }
    
}

void EXTRACT_MAX(vector<int>& a, int& n, int k)
{
  if(n < 1)
  {
    cout << "error : heap underflow" << endl;
    return;    
  }
  else
  {
    int max = a[0];//最大值
    a[0] = a[n - 1];
    n = n - 1;
    a[n] = numeric_limits<int>::min();
    create_max(a, k, n, n);
  }
  // output(a);
}

void INSERT(vector<int>& a, int x, int &n, int k)
{
  a[n] = x;
  ++n;
  create_max(a, k, n, n);
  // output(a);
}

void INCREASE_KEY(vector<int>& a, int i, int key, int& n, int k)
{
  if(key < a[i - 1])
  {
    cout << "error:new key is smaller than current key" << endl;
    return;
  }
  else
  {
    a[i - 1] = key;
    // BUG ↓?????stl_vector.h dead loop
    // while (i > 0 && (a[(i - 1) / k] - a[i - 1] < 0));
    // {
    //   swap(a[(i - 1) / k], a[i - 1]);
    //   i = (i - 1) / k;
    //   cout << "i = " << i << endl;
    // }
    // return;
    create_max(a, k, n, n);
  }
  // output(a);
}

