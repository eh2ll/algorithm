#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> tree;

void update(int node, int st, int en, int idx, ll val){
    if(idx < st || en < idx) return;

    if(st == en){
        tree[node] = val;
        return;
    }

    update(node << 1, st, (st + en) >> 1, idx, val);
    update(node << 1 | 1, ((st + en) >> 1) + 1, en, idx, val);

    tree[node] = tree[node << 1] + tree[node << 1 | 1];
    return;
}

ll sum(int node, int st, int en, int l, int r){
    if(en < l || r < st) return 0;

    if(l <= st && en <= r) return tree[node];

    ll c1 = sum(node << 1, st, (st + en) >> 1, l, r);
    ll c2 = sum(node << 1 | 1, ((st + en) >> 1) + 1, en, l, r);

    return c1 + c2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;
    int H = (int)ceil(log2(N));
    int S = (1 << (H + 1));
    tree.resize(S);

    for(int i = 0; i < M; i += 1){
        int op; cin >> op;
        if(op == 0){
            int a, b; cin >> a >> b;
            if(a > b) swap(a, b);
            cout << sum(1, 1, N, a, b) << '\n';
        }
        else{
            int a, b; cin >> a >> b;
            update(1, 1, N, a, b);
        }
    }

    return 0;
}