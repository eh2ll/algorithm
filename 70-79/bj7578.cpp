#include <bits/stdc++.h>

using namespace std;

int N, idx, arr[500005];
map<int, int> mp;
vector<int> tree;

int sum(int node, int st, int en, int l, int r){
    if(r < st || en < l) return 0;

    if(l <= st && en <= r) return tree[node];

    int s1 = sum(node * 2, st, (st + en) / 2, l, r);
    int s2 = sum(node * 2 + 1, (st + en) / 2 + 1, en, l, r);

    return s1 + s2;
}

int update(int node, int st, int en, int idx, int val){
    if(idx < st || en < idx) return tree[node];

    if(st == en){
        tree[node] = val;
        return tree[node];
    }

    int s1 = update(node * 2, st, (st + en) / 2, idx, val);
    int s2 = update(node * 2 + 1, (st + en) / 2 + 1, en, idx, val);

    return tree[node] = s1 + s2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int H = (int)ceil(log2(N));
    int S = (1 << (1 + H));
    tree.resize(S);

    for(int i = 0; i < N; i += 1){
        int x; cin >> x;
        mp[x] = idx++;
    }

    long long cnt = 0;
    for(int i = 0; i < N; i += 1){
        int x; cin >> x;
        cnt += sum(1, 0, N - 1, mp[x] - 1, N - 1);
        update(1, 0, N - 1, mp[x] - 1, 1);
    }

    cout << cnt << '\n';

    return 0;
}