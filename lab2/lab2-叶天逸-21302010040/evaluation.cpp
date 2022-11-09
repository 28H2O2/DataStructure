#include<iostream>
#include<string>
#include<cmath>
#include<stack>
#include<vector>
using namespace std;
int c2i(char);
int bincal(int, int, char);//binary calculation: int int char to operation, return result
int judgeType(char);
int Calfix(string);
int main(int argc, char *argv[]){

    string str;
    cin >> str;
    int ans = Calfix(str);
    cout << ans << endl;
    return 0; 
}

int Calfix(string str){
    
    stack<int> stn;//stack of numbers
    vector<int> type;
    size_t len = str.length();
    int ans = 0, p1, p2; // parameter1,2
    type.resize(0);
    for (size_t i = 0; i < len;i++){
        //cout << "i=" << i << endl;
        type.push_back(judgeType(str[i]));
        if(type[i]){
            stn.push(c2i(str[i]));
            //cout <<"ps1 " << stn.top() <<endl;
        }
        else{
            if(!stn.empty()){
                p2 = stn.top();
                //cout << "tpp " << stn.top();
                stn.pop();
                p1 = stn.top();
                //cout << " " << stn.top() << endl;
                stn.pop();
                p1 = bincal(p1, p2, str[i]);
                //cout << "cal " << p1 << endl;
                stn.push(p1);
                //cout << "ps2 " << stn.top() << endl;
            }
        }
    }
    if(!stn.empty())
        ans = stn.top();
    return ans;
}

int c2i(char c){
    return (c - '0');
}

int judgeType(char c){
    if(c >= '0' && c <= '9')
        return 1;
    else{
        return 0;
    }
}

int bincal(int p1, int p2, char c){
    if(c=='^')
        return (int)pow(p1,p2);
    if(c=='*')
        return p1*p2;
    if(c=='/')
        return p1/p2;
    if(c=='m')
        return p1%p2;
    if(c=='+')
        return p1+p2;
    if(c=='-')
        return p1-p2;
    return 0;
}