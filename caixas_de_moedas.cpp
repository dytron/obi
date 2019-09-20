// Caixas de Moedas - Lazy Propagation
#include <iostream>

#define MAXN 100005
#define left (2 * node)
#define right (2 * node + 1)
#define mid ((l + r) / 2)
#define neutral 0 // O elemento neutro da soma(aquele que não altera o valor do resultado) é o 0

using namespace std;

int tree[3*MAXN], lazy[3*MAXN], v[MAXN];

int op(int a, int b){
    return a + b;
}
void build(int node, int l, int r){
    lazy[node] = 0;
    if (l == r){
        tree[node] = v[l];
    }else{
        build(left, l, mid);
        build(right, mid + 1, r);
        tree[node] = op(tree[left], tree[right]);
    }
}
void do_lazy(int node, int l, int r){
    if(lazy[node]){
        tree[node] = lazy[node] * (r - l + 1);
        if(l != r){
            lazy[left] = lazy[node];
            lazy[right] = lazy[node];
        }
        lazy[node] = 0;
    }
    return;
}
void update(int node, int l, int r, int a, int b, int val){
    do_lazy(node, l, r);
    if(l > r || a > r || b < l) return;
    if(a <= l && r <= b){
        tree[node] = val * (r - l + 1);
        if(l != r){
            lazy[left] = val;
            lazy[right] = val;
        }
        return;
    }
    update(left, l, mid, a, b, val);
    update(right, mid + 1, r, a, b, val);
    tree[node] = op(tree[left], tree[right]);
}
int query(int node, int l, int r, int a, int b){
    do_lazy(node, l, r);
    if (l > r || a > r || b < l) return neutral;
    if (a <= l && r <= b) return tree[node];
    int q1 = query(left, l, mid, a, b);
    int q2 = query(right, mid + 1, r, a, b);
    return op(q1, q2);
}
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    build(1, 1, n);
    for(int i = 0; i < m; i++){
        int o, a, b, k; // Tipo de Operação
        cin >> o;
        if (o == 1){
            cin >> a >> b >> k;
            update(1, 1, n, a, b, k); // Modifica todos os valores do intervalo [a, b] para k
        }else{ // Comando de consulta
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << endl; // Imprima a quantidade de moedas no intervalo [a, b]
        }
    }
    cout << endl;
}
