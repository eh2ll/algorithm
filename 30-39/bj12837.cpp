#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

vl arr, tree;
int N, Q;

ll init(int node, int start, int end){
    if(start == end) return 0;

    return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}

ll sum(int node, int start, int end, int left, int right){
    if(right < start || end < left) return 0;

    if(left <= start && end <= right) return tree[node];

    return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(int node, int start, int end, int idx, ll diff){
    if(idx < start || end < idx) return;

    tree[node] += diff;

    if(start != end){
        update(node * 2, start, (start + end) / 2, idx, diff);
        update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    int H = (int)ceil(log2(N));
    int S = 1 << (H + 1);
    arr.resize(N + 1);
    tree.resize(S);

    for(int i = 0; i < Q; i += 1){
        ll a, b, c; cin >> a >> b >> c;
        if(a == 1){
            ll diff = c;
            arr[b - 1] += c;
            update(1, 0, N - 1, b - 1, diff);
        }
        else{
            cout << sum(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }

    return 0;
}