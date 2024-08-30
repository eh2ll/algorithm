#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int N, M;
const int inf = 0x3f3f3f3f;
vll arr, tree;

ll init(int node, int start, int end){
    if(start == end) return tree[node] = arr[start];

    return tree[node] = min(init(node * 2, start, (start + end) / 2), init(node * 2 + 1, (start + end) / 2 + 1, end));
}

ll find(int node, int start, int end, int left, int right){
    if(end < left || right < start) return inf;

    if(left <= start && end <= right) return tree[node];

    ll c1 = find(node * 2, start, (start + end) / 2, left, right);
    ll c2 = find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    return min(c1, c2);
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
        cout << find(1, 0, N - 1, a - 1, b - 1) << '\n';
    }

    return 0;
}