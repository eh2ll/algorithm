#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        int N, K; cin >> N >> K;
        vector<ll> A(N);
        for(int i = 0; i < N; i += 1){
            cin >> A[i];
        }
        int dm = (K - 1) - ((N - 1) % (K - 1));
        if(dm == K - 1) dm = 0;
        for(int i = 0; i < dm; i += 1) A.push_back(0);
        sort(A.begin(), A.end(), greater<ll>());
        int M = A.size();

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(int i = 0; i < M; i += 1){
            pq.push({A[i], i});
        }

        vector<vector<ll>> g(M * 4);
        ll nxt = M, mx = 1;
        while(pq.size() > 1){
            ll sum = 0;
            vector<ll> idx(K);
            for(int i = 0; i < K; i += 1){
                auto [cw, ci] = pq.top(); pq.pop();
                sum += cw;
                idx[i] = ci;
            }
            g[nxt] = idx;
            pq.push({sum, nxt++});
        }

        ll rt = pq.top().second;
        vector<ll> D(nxt, 0);
        queue<ll> Q;
        Q.push(rt);
        while(!Q.empty()){
            ll u = Q.front(); Q.pop();
            for(auto v : g[u]){
                D[v] = D[u] + 1;
                Q.push(v);
            }
        }

        sort(D.begin(), D.begin() + N);
        ll ans = 0;
        for(int i = 0; i < M; i += 1){
            ans += A[i] * D[i];
        }

        // for(int i = 0; i < N; i += 1) cout << A[i] << ' ';
        // cout << '\n';
        // for(int i = 0; i < M; i += 1) cout << D[i] << ' ';
        // cout << '\n';

        cout << ans << '\n';
    }

    return 0;
}