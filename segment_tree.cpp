#include <iostream>

#define MAXN 100005
#define left (2 * node)
#define right (2 * node + 1)
#define mid ((l + r) / 2)
#define neutral 0 // O elemento neutro da soma(aquele que não altera o valor do resultado) é o 0

using namespace std;

int tree[3*MAXN], v[MAXN];

int op(int a, int b){
    return a + b;
}
void build(int node, int l, int r){
    if (l == r){
        tree[node] = v[l];
    }else{
        build(left, l, mid);
        build(right, mid + 1, r);
        tree[node] = op(tree[left], tree[right]);
    }
}
void update(int node, int l, int r, int pos, int val){
    if (l == r){
        tree[node] = v[l] = val;
    }else{
        if(pos <= mid) update(left, l, mid, pos, val);
        else update(right, mid + 1, r, pos, val);
        tree[node] = op(tree[left], tree[right]);
    }
}
int query(int node, int l, int r, int a, int b){
    if (a > r || b < l) return neutral;
    if (a <= l && r <= b) return tree[node];
    int q1 = query(left, l, mid, a, b);
    int q2 = query(right, mid + 1, r, a, b);
    return op(q1, q2);
}
int main(){
    int n, k;
    while(cin >> n >> k){
        for (int i = 1; i <= n; i++){
            cin >> v[i];
        }
        build(1, 1, n);
        for(int i = 0; i < k; i++){
            char cc; // Tipo de operação: C = Modificação, Q = Consulta
            int a, b; //
            cin >> cc >> a >> b;
            if (cc == 'C'){ // Comando de alteração de valor
                update(1, 1, n, a, b); // Alterar para (b) o valor contido na posição (a)
            }else{ // Comando de consulta
                cout << query(1, 1, n, a, b) << " "; // Imprima o resultado da consulta no intervalo [a, b]
            }
        }
        cout << endl;
    }
}
