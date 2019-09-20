// OBI 2018 PJ Fase 3
#include <iostream>

using namespace std;

int main(){
    int a1, d1, a2, d2;
    cin >> a1 >> d1 >> a2 >> d2;
    int v1 = 0, v2 = 0;
    if (d1 == a2) v1 = 1;
    if (d2 == a1) v2 = 1;
    if (v1 == v2){
        cout << -1 << endl;
    }else{
        if (v1){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }
}
