#include <bits/stdc++.h>

using namespace std;

int T, N, M;
vector<int> tree;
map<int, int> mp;

int sum(int node, int st, int en, int l, int r){
    if(en < l || r < st) return 0;

    if(l <= st && en <= r) return tree[node];

    int c1 = sum(node * 2, st, (st + en) / 2, l, r);
    int c2 = sum(node * 2 + 1, (st + en) / 2 + 1, en, l, r);

    return c1 + c2;
}

int update(int node, int st, int en, int idx, int val){
    if(idx < st || en < idx) return tree[node];

    if(st == en){
        tree[node] = val;
        return val;
    }

    int c1 = update(node * 2, st, (st + en) / 2, idx, val);
    int c2 = update(node * 2 + 1, (st + en) / 2 + 1, en, idx, val);

    return tree[node] = c1 + c2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N >> M;
        
        tree.clear();
        int H = (int)ceil(log2(N + M));
        int S = (1 << (1 + H));
        tree.resize(S);
        for(int i = 1; i <= N; i += 1) update(1, 1, N + M, i, 1);

        mp.clear();
        for(int i = 1; i <= N; i += 1) mp[i] = N - i + 1;

        int mx = N + 1;
        for(int i = 0; i < M; i += 1){
            int x; cin >> x;
            int cnt = sum(1, 1, N + M, mp[x] + 1, mx - 1);
            update(1, 1, N + M, mp[x], 0);
            update(1, 1, N + M, mx, 1);
            
            mp[x] = mx;
            mx += 1;

            cout << cnt << ' ';
        }
        cout << '\n';
    }
}