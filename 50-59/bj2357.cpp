#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using ll = long long;

const int inf = 1e9 + 1;
int N, M;
vector<ll> arr;
vector<pair<ll ,ll>> tree;

pair<ll, ll> init(int node, int start, int end){
    if(start == end) return tree[node] = {arr[start], arr[start]};

    auto L = init(node * 2, start, (start + end) / 2);
    auto R = init(node * 2 + 1, (start + end) / 2 + 1, end);

    return tree[node] = {min(L.X, R.X), max(L.Y, R.Y)};
}

pair<ll, ll> sum(int node, int start, int end, int left, int right){
    if(left > end || right < start) return {inf, 0};
    
    if(left <= start && end <= right) return tree[node];

    auto L = sum(node * 2, start, (start + end) / 2, left, right);
    auto R = sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    return  {min(L.X, R.X), max(L.Y, R.Y)};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i += 1){
        ll x; cin >> x;
        arr.push_back(x);
    }

    int H = (int)ceil(log2(N));
    int S = 1 << (H + 1);
    tree.resize(S);

    init(1, 0, N - 1);

    for(int i = 0; i < M; i += 1){
        ll a, b; cin >> a >> b;
        auto [mn, mx] = sum(1, 0, N - 1, a - 1, b - 1);
        cout << mn << ' ' << mx << '\n';
    }

    // cout << '\n';
    // for(int i = 0; i < S; i += 1) cout << i << ' ' << tree[i].X << ' ' << tree[i].Y << '\n';

    return 0;
}