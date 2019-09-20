// https://neps.academy/lesson/270
#include <bits/stdc++.h>

using namespace std;

int a, b;

vector<int> solve(vector<int> &v){
    if(v.size() == 1) return v;
    vector<int> r;
    for(int i = 0; i < v.size(); i += 2){
        cin >> a >> b;
        if(a > b) r.push_back(v[i]);
        else r.push_back(v[i + 1]);
    }
    return solve(r);
}

int main(){
    vector<int> v;
    for(int i = 0; i < 16; i++) v.push_back(i);
    int resp = solve(v)[0] + (int)'A';
    cout << (char)resp << endl;
}
