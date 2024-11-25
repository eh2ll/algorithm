#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> tree, lazy;

void update_lazy(int node, int st, int en){
    if(lazy[node] & 1){
        tree[node] = (en - st + 1) - tree[node];
        if(st != en){
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    return;
}

void update_range(int node, int st, int en, int l, int r){
    update_lazy(node, st, en);

    if(en < l || r < st) return;

    if(l <= st && en <= r){
        tree[node] = (en - st + 1) - tree[node];
        if(st != en){
            lazy[node * 2] += 1;
            lazy[node * 2 + 1] += 1;
        }
        return;
    }

    update_range(node * 2, st, (st + en) / 2, l, r);
    update_range(node * 2 + 1, (st + en) / 2 + 1, en, l, r);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int st, int en, int l, int r){
    update_lazy(node, st, en);
    
    if(en < l || r < st) return 0;

    if(l <= st && en <= r) return tree[node];

    int c1 = query(node * 2, st, (st + en) / 2, l, r);
    int c2 = query(node * 2 + 1, (st + en) / 2 + 1, en, l, r);

    return c1 + c2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    int H = (int)ceil(log2(N));
    int S = (1 << (1 + H));
    tree.resize(S);
    lazy.resize(S);

    for(int i = 0; i < M; i += 1){
        int op, s, t; cin >> op >> s >> t;
        if(op & 1){
            cout << query(1, 1, N, s, t) << '\n';
        }
        else{
            update_range(1, 1, N, s, t);
        }
    }
}