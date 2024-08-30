#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int N, M, K;
const int MOD = 1e9+7;
vll arr, tree;

ll init(int node, int start, int end){
    if(start == end) return tree[node] = arr[start];

    return tree[node] = init(node * 2, start, (start + end) / 2) * init(node * 2 + 1, (start + end) / 2 + 1, end) % MOD;
}

ll mul(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 1;
    
    if(left <= start && end <= right) return tree[node];

    return mul(node * 2, start, (start + end) / 2, left, right) * mul(node * 2 + 1, (start + end) / 2 + 1, end, left, right) % MOD;
}

ll update(int node, int start, int end, int idx, ll diff){
    if(idx < start || end < idx) return tree[node];
    if(start == end) return tree[node] = diff;

    ll Lres = update(node * 2, start, (start + end) / 2, idx, diff);
    ll Rres = update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);

    return tree[node] = (Lres * Rres) % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i = 0; i < N; i += 1){
        ll x; cin >> x;
        arr.push_back(x);
    }

    int H = (int)ceil(log2(N));
    int S = 1 << (H + 1);
    tree.resize(S);

    init(1, 0, N - 1);

    for(int i = 0; i < M + K; i += 1){
        ll a, b, c; cin >> a >> b >> c;
        if(a == 1){
            ll diff = c;
            update(1, 0, N - 1, b - 1, diff);
        }
        else{
            cout << mul(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }

    return 0;
}