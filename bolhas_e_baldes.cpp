// Bolhas e Baldes
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if (n == 0) return 0;
        int v[n + 1], d = 0;
        for(int i = 1; i <= n; i++) cin >> v[i];
        for(int i = 1; i <= n; i++){
            if(v[i] != i){ // Se o número não está no lugar correto
                d += 2 * abs(v[v[i]] - v[i]) + 1; // Somar número de trocas necessárias(ida + volta), ida = (v[v[i]] - v[i] + 1) e volta = (v[v[i]] - v[i])
                swap(v[i], v[v[i]]);
                i--; // Como ocorreu uma troca, deve-se permanecer nessa posição até o seu valor ser igual ao número da posição
            }
        }
        cout << ((d % 2) ? "Marcelo" : "Carlos") << endl;
    }
    return 0;
}
