// Chaves: https://neps.academy/lesson/267
#include <bits/stdc++.h>

using namespace std;

bool complete(char a, char b){
    if(a == '{' && b == '}') return true;
    return false;
}
bool is_start(char a){
    return (a == '{');
}
bool is_end(char a){
    return (a == '}');
}
bool check(string s){
    stack<int>pilha;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(is_end(c)){
            if(pilha.empty()){
                return false;
            }
            char _c = pilha.top();
            if(!complete(_c, c)) return false;
            pilha.pop();
        }else if(is_start(c)){
            pilha.push(s[i]);
        }
    }
    return pilha.empty();
}
int main(){
    int n;
    cin >> n;
    string s, p;
    n++;
    while(n--){
        getline(cin, p);
        s += p;
    }
    cout << (check(s) ? 'S' : 'N') << endl;
}
