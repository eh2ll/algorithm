// 금광세그 (https://seungwuk98.tistory.com/39), (https://stonejjun.tistory.com/92)

#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
int N, Q, U, V;
int arr[100005];

struct nod{
    int all, l, r, mid;
};
vector<nod> tree;
// nod tree[4040400];

nod update(int node, int start, int end, int idx, int val){
    if(idx < start || end < idx) return tree[node];

    if(start == end) return tree[node] = {val, val, val, val};

    nod a = update(node * 2, start, (start + end) / 2, idx, val);
    nod b = update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
    tree[node].all = a.all + b.all;
    tree[node].l = max(a.l, a.all + b.l);
    tree[node].r = max(b.r, b.all + a.r);
    tree[node].mid = max({a.mid, b.mid, a.r + b.l});

    return tree[node];
}

nod query(int node, int start, int end, int left, int right){
    if(end < left || right < start) return {0, -inf, -inf, -inf};

    if(left <= start && end <= right) return tree[node];

    nod a = query(node * 2, start, (start + end) / 2, left, right);
    nod b = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    nod c;
    c.all = a.all + b.all;
    c.l = max(a.l, a.all + b.l);
    c.r = max(b.r, b.all + a.r);
    c.mid = max({a.mid, b.mid, a.r + b.l});

    return c;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q >> U >> V;
    int H = (int)ceil(log2(N));
    int S = (1 << (1 + H));
    tree.resize(S);
    for(int i = 0; i < S; i += 1){
    // for(int i = 1; i <= 4 * N; i += 1){
        tree[i].all = 0;
        tree[i].l = -inf;
        tree[i].r = -inf;
        tree[i].mid = -inf;
    }

    for(int i = 1; i <= N; i += 1){
        cin >> arr[i];
        update(1, 1, N, i, U * arr[i] + V);
    }
    for(int i = 0; i < Q; i += 1){
        int c, a, b; cin >> c >> a >> b;
        if(c & 1){
            arr[a] = b;
            update(1, 1, N, a, U * b + V);
        }
        else{
            cout << query(1, 1, N, a, b).mid - V << '\n';
        }
    }

    return 0;
}