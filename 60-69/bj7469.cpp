#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> tree[400'004];

void update(int node, int st, int en, int idx, int val){
    if(idx < st || en < idx) return;
    
    tree[node].push_back(val);
    if(st == en){
        return;
    }

    int mid = (st + en) / 2;
    update(node * 2, st, mid, idx, val);
    update(node * 2 + 1, mid + 1, en, idx, val);
}

int query(int node, int st, int en, int l, int r, int val){
    if(en < l || r < st) return 0;
    if(l <= st && en <= r){
        return upper_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
    }

    int mid = (st + en) / 2;
    int c1 = query(node * 2, st, mid, l, r, val);
    int c2 = query(node * 2 + 1, mid + 1, en, l, r, val);
    return c1 + c2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i += 1){
        int x; cin >> x;
        update(1, 1, N, i, x);
    }
    for(int i = 1; i < 400'004; i += 1) sort(tree[i].begin(), tree[i].end());

    for(int i = 0; i < M; i += 1){
        int l, r, x; cin >> l >> r >> x;
        int st = -1e9 - 1, en = 1e9 + 1;
        while(st + 1 < en){
            int mid = (st + en) / 2;
            if(query(1, 1, N, l, r, mid) >= x){
                en = mid;
            }
            else{
                st = mid;
            }
        }
        cout << en << '\n';
    }

    return 0;
}