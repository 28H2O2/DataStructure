#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int main()
{
    void merge_sort(vector<int> &, int , int , int);
    void merge(vector<int> & , int , int , int );
    void output(const vector<int> &);
    void Insertion(vector<int>& v);
    cout << "Please input n and k!" << endl;
    int n;
    int k;
    cin >> n >> k;


    cout << "Please input some numbers" << endl;
    vector<int> b;
    int temp;
    int l = 0;
    while (cin>>temp)
    {
        b.push_back(temp);        
        if(cin.get()=='\n') break;

    }

    merge_sort(b, 0, n - 1, k);

    output(b);
}

void merge(vector<int> &A, int begin, int mid, int end )//拷贝到两个新容器中然后排序
{
    vector<int> A1(A.begin() + begin, A.begin() + mid + 1);//初始化拷贝
    vector<int> A2(A.begin() + mid + 1, A.begin() + end + 1);
    int flag1 = 0;
    int flag2 = 0;
    A1.insert(A1.end(), numeric_limits<int>::max());
    A2.insert(A2.end(), numeric_limits<int>::max());
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

void merge_sort(vector<int> &A, int begin, int end, int k)
{
    if(end - begin <= k)//recurrance end
    {       
        Insertion(A);
        return;
    }
    int mid = (begin + end) / 2;
    merge_sort(A, begin, mid, k);
    merge_sort(A, mid + 1, end, k);
    merge(A, begin, mid , end);
}


void output(const vector<int>& A)
{
    for (vector<int>::const_iterator i = A.begin(); i != A.end(); ++i)
    {
        cout << *i << ' ';
    }
}

