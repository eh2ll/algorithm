#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int INF = 1e9 + 7;

vector<int> tree;

void update(int node, int st, int en, int idx, int diff){
    if(idx < st || en < idx) return;

    if(st == en){
        tree[node] += diff;
        return;
    }

    int mid = (st + en) >> 1;
    update(node << 1, st, mid, idx, diff);
    update(node << 1 | 1, mid + 1, en, idx, diff);

    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

int sum(int node, int st, int en, int l, int r){
    if(en < l || r < st) return 0;

    if(l <= st && en <= r) return tree[node];

    int mid = (st + en) >> 1;
    int c1 = sum(node << 1, st, mid, l, r);
    int c2 = sum(node << 1 | 1, mid + 1, en, l, r);

    return c1 + c2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--){        
        int N; cin >> N;

        tree.clear();
        int H = (int)ceil(log2(N));
        int S = (1 << (H + 1));
        tree.resize(S);
        
        vector<pii> A(N);
        vector<int> B(N), C(N);

        for(int i = 0; i < N; i += 1){
            cin >> A[i].first >> A[i].second;
            B[i] = A[i].first;
            C[i] = A[i].second;
        }
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        B.erase(unique(B.begin(), B.end()), B.end());
        C.erase(unique(C.begin(), C.end()), C.end());

        for(int i = 0; i < N; i += 1){
            A[i].first = lower_bound(B.begin(), B.end(), A[i].first) - B.begin() + 1;
            A[i].second = lower_bound(C.begin(), C.end(), A[i].second) - C.begin() + 1;
        }
        sort(A.begin(), A.end(), [](const pii &a, const pii &b){
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });
        
        for(int i = 0; i < N; i += 1){
            update(1, 1, N, A[i].second, 1);
        }

        long long tot = 0;
        for(int i = 0; i < N; i += 1){
            // cout << A[i].first << ' ' << A[i].second << " : " << sum(1, 1, N, 1, A[i].second) - 1 << '\n';
            tot += sum(1, 1, N, 1, A[i].second) - 1;
            update(1, 1, N, A[i].second, -1);
        }

        cout << tot << '\n';
    }

    return 0;
}