//justicehui
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

ll init(vll &arr, vll &tree, int node, int start, int end){
    if(start == end){
        return tree[node] = arr[start];
    }
    return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2) + init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end); 
}

ll sum(vll &arr, vll &tree, int node, int start, int end, int left, int right){
    if(left > end || right < start){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    return sum(arr, tree, node * 2, start, (start + end) / 2, left, right) + sum(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vll &arr, vll &tree, int node, int start, int end, int idx, ll diff){
    if(idx < start || idx > end) return;
    tree[node] += diff;
    if(start != end){
        update(arr, tree, node * 2, start, (start + end) / 2, idx, diff);
        update(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
    }
}

int N, M, K;
vll arr, tree;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i = 0; i < N; i += 1){
        ll x; cin >> x;
        arr.push_back(x);
    }
    int H = (int)ceil(log2(N));
    int S = (1 << (H + 1));
    arr.resize(N + 1);
    tree.resize(S);

    init(arr, tree, 1, 0, N - 1);
    for(int i = 0; i < M + K; i += 1){
        ll a, b, c; cin >> a >> b >> c;
        if(a == 1){
            ll diff = c - arr[b - 1];
            arr[b - 1] = c;
            update(arr, tree, 1, 0, N - 1, b - 1, diff);
        }
        else{
            ll res = sum(arr, tree, 1, 0, N - 1, b - 1, c - 1);
            cout << res << '\n';
        }
    }

    return 0;
}