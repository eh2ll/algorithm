#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
int N, M;
vector<pair<int, int>> tree;

void update(int node, int st, int en, int idx, int diff){
    if(idx < st || en < idx) return;

    if(st == en){
        tree[node] = {diff, idx};
        return;
    }

    update(node << 1, st, (st + en) >> 1, idx, diff);
    update(node << 1 | 1, ((st + en) >> 1) + 1, en, idx, diff);

    tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
}

pair<int, int> query(int node, int st, int en, int l, int r){
    if(en < l || r < st) return {INF, -1};

    if(l <= st && en <= r) return tree[node];

    auto c1 = query(node << 1, st, (st + en) >> 1, l, r);
    auto c2 = query(node << 1 | 1, ((st + en) >> 1) + 1, en, l, r);

    return min(c1, c2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int H = (int)ceil(log2(N));
    int S = (1 << (1 + H));
    tree.resize(S + 1);
    for(int i = 1; i <= N; i += 1){
        int x; cin >> x;
        update(1, 1, N, i, x);
    }
    cin >> M;
    for(int i = 0; i < M; i += 1){
        int op; cin >> op;
        if(op == 1){
            int idx, diff; cin >> idx >> diff;
            update(1, 1, N, idx, diff);
        }
        else{
            int l, r; cin >> l >> r;
            auto ret = query(1, 1, N, l, r);
            cout << ret.second << '\n';
        }

        // for(int i = 1; i <= S; i += 1){
        //     cout << tree[i].first << ' ';
        // }
        // cout << '\n';
    }

    return 0;
}