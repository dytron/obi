// OBI 2018 PJ Fase 3
#include <iostream>

using namespace std;

int main(){
    int v[4];
    for(int i = 0; i < 4; i++){
        cin >> v[i];
    }
    int r[2];
    for(int i = 0; i < 2; i++){
        r[1 - i] = (v[i] == v[3 - i]);
    }
    if(r[0] == r[1]){
        cout << -1 << endl;
        return 0;
    }
    cout << ((r[0]) ? 1 : 2) << endl;
}
