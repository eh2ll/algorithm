// counting inversion (merge sort, segtree) (viyoung)

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> arr, tree, tmp;

int compress(int num){
    return lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin();
}

ll query(int node, int start, int end, int left, int right){
    if(end < left || right < start) return 0;

    if(left <= start && end <= right) return tree[node];

    ll c1 = query(node * 2, start, (start + end) / 2, left, right);
    ll c2 = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    return c1 + c2;
}

void update(int node, int start, int end, int idx, ll diff){
    if(idx < start || end < idx) return;
    
    if(start == end){
        tree[node] += 1;
        return;
    }

    tree[node] += 1;

    update(node * 2, start, (start + end) / 2, idx, diff);
    update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int H = (int)ceil(log2(N));
    int S = (1 << (H + 1));

    tree.resize(S);
    for(int i = 0; i < N; i += 1){
        int x; cin >> x;
        arr.push_back(x);
        tmp.push_back(x);
    }

    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    ll res = 0;
    for(auto c : arr){
        res += query(1, 0, N - 1, compress(c) + 1, N - 1);
        update(1, 0, N - 1, compress(c), 1);
        // cout << res << '\n';
    }

    // for(int i = 0; i < S; i += 1) cout << tree[i] << ' ';
    // cout << '\n';
    cout << res << '\n';

    return 0;
}
