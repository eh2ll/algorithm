// justicehui

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int N, M, K;
vll arr, tree, lazy;

ll init(int node, int start, int end){
    if(start == end) return tree[node] = arr[start];

    return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}

void update_lazy(int node, int start, int end){
    if(lazy[node] != 0){
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end){
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll sum(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);

    if(end < left || right < start) return 0;

    if(left <= start && end <= right) return tree[node];

    ll c1 = sum(node * 2, start, (start + end) / 2, left, right);
    ll c2 = sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    return c1 + c2;
}

void update_range(int node, int start, int end, int left, int right, ll diff){
    update_lazy(node, start, end);

    if(end < left || right < start) return;
    
    if(left <= start && end <= right){
        tree[node] += (end - start + 1) * diff;
        if(start != end){
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }

    update_range(node * 2, start, (start + end) / 2, left, right, diff);
    update_range(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    int H = (int)(ceil(log2(N)));
    int S = (1 << (H + 1));
    lazy.resize(S);
    tree.resize(S);

    for(int i = 0; i < N; i += 1){
        ll x; cin >> x;
        arr.push_back(x);
    }

    init(1, 0, N - 1);

    for(int i = 0; i < M + K; i += 1){
        int op; cin >> op;
        if(op == 1){
            ll b, c, d; cin >> b >> c >> d;
            update_range(1, 0, N - 1, b - 1, c - 1, d);
        }
        else{
            int b, c; cin >> b >> c;
            cout << sum(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }

    return 0;
}