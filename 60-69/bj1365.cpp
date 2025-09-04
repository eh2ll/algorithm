#include <bits/stdc++.h>

using namespace std;

vector<int> tree;

void update(int node, int st, int en, int idx, int val){
    if(idx < st || en < idx) return;

    if(st == en){
        tree[node] = val;
        return;
    }

    update(node << 1, st, (st + en) >> 1, idx, val);
    update(node << 1 | 1, ((st + en) >> 1) + 1, en, idx, val);

    tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    return;
}

int query(int node, int st, int en, int l, int r){
    if(en < l || r < st) return 0;

    if(l <= st && en <= r) return tree[node];

    int c1 = query(node << 1, st, (st + en) >> 1, l, r);
    int c2 = query(node << 1 | 1, ((st + en) >> 1) + 1, en, l, r);
    return max(c1, c2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int H = (int)ceil(log2(N));
    int S = (1 << (H + 1));
    tree.resize(S);

    for(int i = 0; i < N; i += 1){
        int x; cin >> x;
        int lis = 1;
        if(x > 1) lis = query(1, 1, N, 1, x - 1) + 1;
        update(1, 1, N, x, lis);
        // cout << lis << '\n';
    }

    cout << N - query(1, 1, N, 1, N) << '\n';

    return 0;
}