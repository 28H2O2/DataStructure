#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main()
{
    void Conversion(const string & str);//core function
    string input;
    getline(cin, input);

    Conversion(input);
    // string out = Conversion(input);
    // cout << out << endl; 
}

void Conversion(const string &str)
{
    stack<char> S;
    vector<char> out;
    for (int i = 0; i < str.length(); ++i)
    {
        char temp = str[i];
        if(temp < 58 && temp > 47)//0~9
        {
            out.push_back(temp);
        }
        else if(temp == 40)//(
        {
            S.push(temp);
        }
        else if (temp == 41)//)
        {
            while (S.top() != 40)//top = '('
            {
                out.push_back(S.top());
                S.pop();
            }
            S.pop(); // pop('(')
        }
        else if (temp == 42 || temp == 47 || temp == 109)//*/mod
        {
            if(S.size() == 0 || (S.top() != 42 && S.top() != 47 && S.top() != 109))
            {
                S.push(temp);
            }
            else
            {
                out.push_back(S.top());
                S.pop();
                S.push(temp);                
            }
        }
        else if (temp == 43 || temp == 45)//+-
        {
            
            if(S.size()==0 || (S.top()!=42 && S.top()!=43 && S.top()!=45 && S.top()!=47 && S.top()!=109))
            {
                S.push(temp);
            }
            else
            {
                out.push_back(S.top());
                S.pop();
                S.push(temp);                
            }

        }

        else
        {

        }
    }
    // end
    while (S.size() != 0)//top = '('
    {
        out.push_back(S.top());
        S.pop();
    }
    //output
    for (int i = 0; i < out.size(); ++i)
    {
        cout << out[i];
    }
}





//输入： (1+2/2*3)/2+8 2) 输出： 122/3*+2/8+

