#include<iostream>
#include<string>
#include<cmath>
#include<stack>
#include<vector>
using namespace std;
int judgeType(char);
int level(char);
string Profix(string);
int Calfix(string);
int main(int argc, char *argv[]){

    string str;
    cin >> str;
    string pro = Profix(str);

    cout << pro << endl;
    return 0; 
}

string Profix(string str){
    vector<int> type;
    size_t len = str.length();
    type.resize(0);
    stack<char> sta;
    string tmp(str);
    for (string::iterator i = tmp.begin(); i != tmp.end();i++)
        *i = ' ';
    int i_tmp = 0;
    for (size_t i = 0; i < len;i++){
        
        type.push_back(judgeType(str[i]));
        
        if(type[i]){
            tmp[i_tmp] = str[i];
            i_tmp++;
        }
        else{
            if(str[i]=='('){
                sta.push(str[i]);
                continue;
            }
            if(str[i]==')'){
                while(sta.top() != '(' && !sta.empty()){
                    tmp[i_tmp] = sta.top();
                    i_tmp++;
                    sta.pop();
                }
                sta.pop();
                continue;
            }
            if(!sta.empty() && level(sta.top()) <= level(str[i])){
                while(!sta.empty() && level(sta.top()) <= level(str[i])){
                    tmp[i_tmp] = sta.top();
                    i_tmp++;
                    sta.pop();
                }
                sta.push(str[i]);
            }
            else{
                sta.push(str[i]);
            }
        }
    }
    while(!sta.empty()){
        tmp[i_tmp] = sta.top();
        i_tmp++;
        sta.pop();
    }
    for (int i = 0; i < len;i++){
        if(tmp[i]==' '){
            tmp = tmp.substr(0, i);   
            break;
        }
    }
    return tmp;
}

int judgeType(char c){
    if(c >= '0' && c <= '9')
        return 1;
    else{
        return 0;
    }
}

int level(char c){
    //HIGH
    if(c=='('||c==')')
        return 16;
    if(c=='^')
        return 3;
    if(c=='*'||c=='/'||c=='m')
        return 4;
    if(c=='+'||c=='-')
        return 5;
    //LOW
    return 0;
}


