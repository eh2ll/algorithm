#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, K;
int arr[100005];
vector<ll> tree;

ll init(int node, int st, int en){
    if(st == en) return tree[node] = (arr[st] > 0) - (arr[st] < 0);
    
    ll c1 = init(node * 2, st, (st + en) / 2);
    ll c2 = init(node * 2 + 1, (st + en) / 2 + 1, en);
    
    return tree[node] = c1 * c2;
}

ll query(int node, int st, int en, int l, int r){
    if(en < l || r < st) return 1;

    if(l <= st && en <= r) return tree[node];

    ll c1 = query(node * 2, st, (st + en) / 2, l, r);
    ll c2 = query(node * 2 + 1, (st + en) / 2 + 1, en, l, r);

    return c1 * c2;
}

ll update(int node, int st, int en, int idx, ll val){
    if(idx < st || en < idx) return tree[node];

    if(st == en) return tree[node] = val;

    ll c1 = update(node * 2, st, (st + en) / 2, idx, val);
    ll c2 = update(node * 2 + 1, (st + en) / 2 + 1, en, idx, val);

    return tree[node] = c1 * c2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> N >> K){
        tree.clear();
        int H = (int)ceil(log2(N));
        int S = (1 << (1 + H));
        tree.resize(S + 1);
        for(int i = 1; i <= N; i += 1){
            cin >> arr[i];
        }

        init(1, 1, N);

        for(int i = 0; i < K; i += 1){
            char c; int a, b;
            cin >> c >> a >> b;
            if(c == 'C'){
                update(1, 1, N, a, (b > 0) - (b < 0));
            }
            else{
                int flag = query(1, 1, N, a, b);
                if(flag == 1) cout << "+";
                else if(flag == 0) cout << 0;
                else cout << "-";
            }

            // for(int i = 1; i <= S; i += 1) cout << tree[i] << ' ';
            // cout << '\n';
        }

        cout << '\n';
    }

    return 0;
}