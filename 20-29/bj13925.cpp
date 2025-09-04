#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1'000'000'007;
int N, Q;
struct Node{
    ll a, b, val;
};

vector<Node> tree, lazy;

void update_lazy(int node, int st, int en){
    if(lazy[node].a == 1 && lazy[node].b == 0) return;
    ll c1 = (lazy[node].a * tree[node].val) % MOD;
    ll c2 = (lazy[node].b * (en - st + 1)) % MOD;
    tree[node].val = (c1 + c2) % MOD;
    if(st != en){
        lazy[node * 2].a = (lazy[node].a * lazy[node * 2].a) % MOD;
        lazy[node * 2].b = (lazy[node].a * lazy[node * 2].b % MOD + lazy[node].b) % MOD;
        lazy[node * 2 + 1].a = (lazy[node].a * lazy[node * 2 + 1].a) % MOD;
        lazy[node * 2 + 1].b = (lazy[node].a * lazy[node * 2 + 1].b % MOD + lazy[node].b) % MOD;
    }
    lazy[node].a = 1;
    lazy[node].b = 0;
}

void update_range(int node, int st, int en, int l, int r, ll a, ll b){
    update_lazy(node, st, en);
    if(en < l || r < st) return;
    if(l <= st && en <= r){
        lazy[node].a = (a * lazy[node].a) % MOD;
        lazy[node].b = (a * lazy[node].b % MOD + b) % MOD;
        update_lazy(node, st, en);
        return;
    }
    int mid = (st + en) / 2;
    update_range(node * 2, st, mid, l, r, a, b);
    update_range(node * 2 + 1, mid + 1, en, l, r, a, b);
    tree[node].val = (tree[node * 2].val + tree[node * 2 + 1].val) % MOD;
}

ll query(int node, int st, int en, int l, int r){
    update_lazy(node, st, en);
    if(en < l || r < st) return 0;
    if(l <= st && en <= r) return tree[node].val;
    int mid = (st + en) / 2;
    ll left = query(node * 2, st, mid, l, r);
    ll right = query(node * 2 + 1, mid + 1, en, l, r);
    return (left + right) % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int H = (int)ceil(log2(N));
    int S = (1 << (H + 1));
    tree.resize(S);
    lazy.resize(S);
    for(int i = 1; i <= N; i += 1){
        ll x; cin >> x;
        update_range(1, 1, N, i, i, 0, x);
    }
    cin >> Q;
    while(Q--){
        int op; cin >> op;
        if(op == 1){
            ll l, r, v; cin >> l >> r >> v;
            update_range(1, 1, N, l, r, 1, v);
        }
        else if(op == 2){
            ll l, r, v; cin >> l >> r >> v;
            update_range(1, 1, N, l, r, v, 0);
        }
        else if(op == 3){
            ll l, r, v; cin >> l >> r >> v;
            update_range(1, 1, N, l, r, 0, v);
        }
        else if(op == 4){
            ll l, r; cin >> l >> r;
            cout << query(1, 1, N, l, r) << '\n';
        }

        // for(int i = 1; i <= N; i += 1){
        //     cout << query(1, 1, N, i, i) << ' ';
        // }
        // cout << '\n';
    }

    return 0;
}