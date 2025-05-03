// googling.. counting inversion에 2개 한 번에 넣는 느낌..

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> tree;

struct arr{
    int x, y, z;
    bool operator < (const arr & a){
        return x < a.x;
    }
};

vector<arr> A;

void update(int node, int st, int en, int idx, int diff){
    if(idx < st || en < idx) return;

    if(st == en){
        tree[node] = diff;
        return;
    }

    update(node << 1, st, ((st + en) >> 1), idx, diff);
    update(node << 1 | 1, ((st + en) >> 1) + 1, en, idx, diff);

    tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
}

int query(int node, int st, int en, int l, int r){
    if(en < l || r < st) return INT_MAX;

    if(l <= st && en <= r) return tree[node];

    int c1 = query(node << 1, st, ((st + en) >> 1), l, r);
    int c2 = query(node << 1 | 1, ((st + en) >> 1) + 1, en, l, r);

    return min(c1, c2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int H = (int)ceil(log2(N));
    int S = (1 << (1 + H));
    tree.resize(S + 1);
    A.resize(N + 1);
    for(int i = 1; i <= N; i += 1){
        int x; cin >> x;
        A[x].x = i;
    }
    for(int i = 1; i <= N; i += 1){
        int x; cin >> x;
        A[x].y = i;
    }
    for(int i = 1; i <= N; i += 1){
        int x; cin >> x;
        A[x].z = i;
    }

    sort(A.begin() + 1, A.end());
    for(int i = 1; i <= N; i += 1){
        update(1, 1, N, i, N + 1);
    }

    int cnt = 0;
    for(int i = 1; i <= N; i += 1){
        if(query(1, 1, N, 1, A[i].y) > A[i].z) cnt += 1;
        update(1, 1, N, A[i].y, A[i].z);
    }

    cout << cnt << '\n';

    return 0;
}