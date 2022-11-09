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

int main()
{
    void Out(int, int, vector<int> &b, vector<double> &k_vec);
    void SelectK(int  , vector<int>& , vector<double> &k_vec);
    vector<double> k_vec;
    cout << "Please input n and k!" << endl;//输入
    int n, k;
    cin >> n >> k;
    // cout << "Please input some numbers" << endl;
    vector<int> b;
    int temp;
    int l = 0;
    while (cin>>temp)
    {
        b.push_back(temp);        
        if(cin.get()=='\n') break;

    }
    SelectK(n, b, k_vec);
    // Out(n, k, b, k_vec);
}


void Out(int n, int k, vector<int> &b, vector<double> &k_vec)
{
    void merge(vector<int> & , int , int , int );
    void output(const vector<int> &);
    void Insertion(vector<int>& v);

    // NOTE 以下为计算程序执行时间
    LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    //执行排序程序
    merge(b, 0, n-1, k);

    QueryPerformanceCounter(&t2);
    double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
    k_vec.push_back(time*1000000);//记录时间 （单位：ms）
    // output(b);
}



void Insertion(vector<int>& v)
{
    for (int j = 1; j < v.size(); j++)
    {
        int key = v[j];
        int i = j - 1;
        while (v[i] >= key && i >= 0)
        {

            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = key;

    }
}

void merge(vector<int> &A, int begin, int end, int k)
{
    if(end - begin <= k)
    {
        Insertion(A);//insertionsort
        // cout << "?";
        return;
    }

    int mid = (begin + end) / 2;
    merge(A, begin, mid, k);    //recursion
    merge(A, mid + 1, end, k);

    vector<int> A1(A.begin() + begin, A.begin() + mid + 1);//初始化拷贝
    vector<int> A2(A.begin() + mid + 1, A.begin() + end + 1);
    int flag1 = 0;
    int flag2 = 0;

    A1.insert(A1.end(), A2.size(), 1000000000);
    A2.insert(A2.end(), A1.size(), 1000000000);
    for (int i = begin; i <= end; ++i)
    {
        if(A1[flag1] < A2[flag2])
        {
            A[i] = A1[flag1];
            ++flag1;
        }
        else
        {
            A[i] = A2[flag2];
            ++flag2;
        }
    }

}

void output(const vector<int>& A)
{
    for (vector<int>::const_iterator i = A.begin(); i != A.end(); ++i)
    {
        cout << *i << ' ';
    }
}

void SelectK(int n, vector<int>& b, vector<double> &k_vec)//寻找最佳k的算法
{
    vector<int> k_min;//用于存储最佳k的容器，便于之后计算平均值
    for (int i = 0; i < 50; ++i)
    {        
        for (int k = 1; k < n; ++k)//遍历可能的k
        {
            Out(n, k, b, k_vec);
        }
        auto minPosition = min_element(k_vec.begin(), k_vec.end());//查找最小的k
        k_vec.clear();
        k_min.push_back(minPosition - k_vec.begin());//找到最佳k的值
    }
    int sumValue = accumulate(begin(k_min), end(k_min), 0.0);   // accumulate函数就是求vector和的函数；
    int k_best = sumValue / k_min.size();                   // 求均值
    cout << "The best k is " << k_best << endl;
}
