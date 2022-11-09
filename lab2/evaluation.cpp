#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main()
{
    void Evaluation(const string &str);
    string input;
    getline(cin, input);

    Evaluation(input);
}

void Evaluation(const string &str)
{
    stack<int> S;
    for (int i = 0; i < str.length(); ++i)
    {
        char temp = str[i];
        if(temp < 58 && temp > 47)//0~9
        {
            S.push(temp - 48);
        }
        else if (temp == 42 || temp == 47 || temp == 109 || temp == 43 || temp == 45)//operator
        {
            int a, b, res;
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            switch (temp)
            {
            case 42:
                S.push(a * b);
                break;
            case 47:
                S.push(b / a);
                break;
            case 109:
                S.push(b % a);
                break;
            case 43:
                S.push(a + b);
                break;
            case 45:
                S.push(b - a);
                break;

            default:
                break;
            }

        }
        // cout << S.top() << endl;
    }
    cout << S.top() << endl;
}

