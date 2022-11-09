#include<iostream>
#include<vector>

using namespace std;

int main()
{

    void Insertion(vector<int>& v);
    void output(const vector<int>& x);


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

    Insertion(b);

    output(b);

    
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

void output(const vector<int>& A)
{
    for (vector<int>::const_iterator i = A.begin(); i != A.end(); ++i)
    {
        cout << *i << ' ';
    }
}