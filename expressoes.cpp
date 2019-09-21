// Expressões: https://neps.academy/lesson/273
#include <bits/stdc++.h>

using namespace std;

bool complete(char a, char b){
    if(a == '(' && b == ')') return true;
    if(a == '[' && b == ']') return true;
    if(a == '{' && b == '}') return true;
    return false;
}
bool is_start(char a){
    return (a == '(' || a == '[' || a == '{');
}
bool check(string s){
    stack<int>pilha;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(!is_start(c)){
            if(pilha.empty()){
                return false;
            }
            char _c = pilha.top();
            if(complete(_c, c)) pilha.pop();
            else return false;
        }else{
            pilha.push(s[i]);
        }
    }
    return pilha.empty();
}
int main(){
    int n;
    cin >> n;
    string s;
    while(n--){
        cin >> s;
        cout << (check(s) ? 'S' : 'N') << endl;
    }
}
