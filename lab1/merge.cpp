#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int main()
{
    void merge(vector<int> & , int , int );
    void output(const vector<int> &);

    cout << "Please input a number!" << endl;
    int num;
    cin >> num;

    // cout << "Please input some numbers" << endl;
    vector<int> b;
    int temp;
    int l = 0;
    while (cin>>temp)
    {
        b.push_back(temp);        
        if(cin.get()=='\n') break;

    }

    merge(b, 0, num - 1);

    output(b);
}

void merge(vector<int> &A, int begin, int end)
{
    if(begin >= end)
    {
        return;
    }

    int mid = (begin + end) / 2;
    merge(A, begin, mid);    //recursion
    merge(A, mid + 1, end);

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


