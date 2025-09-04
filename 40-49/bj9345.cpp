#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int INF = 1e9;
int N, K;
vector<pii> tree;

void update(int node, int st, int en, int idx, int val){
    if(idx < st || en < idx) return;

    if(st == en){
        tree[node] = {val, val};
        return;
    }

    int mid = (st + en) >> 1;
    update(node << 1, st, mid, idx, val);
    update(node << 1 | 1, mid + 1, en, idx, val);
    
    int mn = min(tree[node << 1].first, tree[node << 1 | 1].first);
    int mx = max(tree[node << 1].second, tree[node << 1 | 1].second);
    tree[node] = {mn, mx};
}

pii query(int node, int st, int en, int l, int r){
    if(en < l || r < st) return {INF, -INF};
    if(l <= st && en <= r) return tree[node];

    int mid = (st + en) >> 1;
    pii left = query(node << 1, st, mid, l, r);
    pii right = query(node << 1 | 1, mid + 1, en, l, r);
    return {min(left.first, right.first), max(left.second, right.second)};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        cin >> N >> K;
        int H = (int)ceil(log2(N));
        int S = (1 << (H + 1));
        tree.resize(S);
        for(int i = 0; i < N; i += 1){
            update(1, 0, N - 1, i, i);
        }
        for(int i = 0; i < K; i += 1){
            int op; cin >> op;
            if(op == 0){
                int a, b; cin >> a >> b;
                pii aa = query(1, 0, N - 1, a, a);
                pii bb = query(1, 0, N - 1, b, b);
                update(1, 0, N - 1, a, bb.first);
                update(1, 0, N - 1, b, aa.first);
            }
            else{
                int a, b; cin >> a >> b;
                pii ans = query(1, 0, N - 1, a, b);
                if(ans.first == a && ans.second == b){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
        }
        tree.clear();
    }

    return 0;
}