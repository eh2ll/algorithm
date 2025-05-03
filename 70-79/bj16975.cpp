#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, Q, arr[100005];
vector<ll> tree, lazy;

ll init(int node, int st, int en){
    if(st == en) return tree[node] = arr[st];

    ll c1 = init(node * 2, st, (st + en) / 2);
    ll c2 = init(node * 2 + 1, (st + en) / 2 + 1, en);

    return tree[node] = c1 + c2;
}

void update_lazy(int node, int st, int en){
    if(lazy[node]){
        tree[node] += (en - st + 1) * lazy[node];
        if(st != en){
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    return;
}

void update_range(int node, int st, int en, int l, int r, int diff){
    update_lazy(node, st, en);
    
    if(en < l || r < st) return;

    if(l <= st && en <= r){
        tree[node] += (en - st + 1) * diff;
        if(st != en){
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }

    update_range(node * 2, st, (st + en) / 2, l, r, diff);
    update_range(node * 2 + 1, (st + en) / 2 + 1, en, l, r, diff);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int st, int en, int idx){
    update_lazy(node, st, en);

    if(idx < st || en < idx) return 0;

    if(st == en) return tree[node];

    ll c1 = query(node * 2, st, (st + en) / 2, idx);
    ll c2 = query(node * 2 + 1, (st + en) / 2 + 1, en, idx);

    return tree[node] = c1 + c2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        cin >> arr[i];
    }

    int H = (int)ceil(log2(N));
    int S = (1 << (1 + H));
    tree.resize(S);
    lazy.resize(S);

    init(1, 1, N);

    cin >> Q;
    while(Q--){
        int op; cin >> op;
        if(op & 1){
            int l, r, k; cin >> l >> r >> k;
            update_range(1, 1, N, l, r, k);
        }
        else{
            int idx; cin >> idx;
            cout << query(1, 1, N, idx) << '\n';
        }
    }

    return 0;
}