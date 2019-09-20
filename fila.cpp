// OBI 2014 PJ Fase 1
#include <iostream>
#define MAXN 100005

using namespace std;

bool v[MAXN];
int main(){
    int n, m, x;
    cin >> n;
    int l[n];
    for(int i = 0; i < n; i++){
        cin >> l[i];
        v[l[i]] = true;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x;
        v[x] = false;
    }
    for(int i = 0; i < n; i++){
        if(v[l[i]]){
            cout << l[i] << " ";
        }
    }
    cout << endl;
}
