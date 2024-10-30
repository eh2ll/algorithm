#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int par[30004], frd[30004], cnt[30004];
int dp[30004][3003];

int find(int x){
    if(par[x] < 0) return x;

    return par[x] = find(par[x]);
}

void isdiff(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;

    if(u > v) swap(u, v);

    par[v] = u;
    frd[u] += frd[v];
    cnt[u] += cnt[v];
    
    frd[v] = 0;
    cnt[v] = 0;

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    memset(par, -1, sizeof(par));
    fill(frd, frd + 30004, 1);
    for(int i = 1; i <= N; i += 1){
        cin >> cnt[i];
    }

    for(int i = 0; i < M; i += 1){
        int a, b; cin >> a >> b;
        isdiff(a, b);
    }

    vector<pair<int, int>> V;
    V.push_back({0, 0});
    for(int i = 1; i <= N; i += 1){
        if(frd[i]) V.push_back({frd[i], cnt[i]});
    }

    int size = V.size();
    for(int i = 0; i <= size; i += 1){
        for(int j = 0; j < K; j += 1){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(V[i].first <= j){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - V[i].first] + V[i].second);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[size][K - 1] << '\n';
    // cout << size << ' ' << K << '\n';
    // for(int i = 1; i < size; i += 1) cout << V[i].first << ' ' << V[i].second << '\n';
    
    // for(int i = 0; i <= size; i += 1){
    //     for(int j = 0; j < K; j += 1){
    //         cout << dp[i][j] << '\t';
    //     }
    //     cout << '\n';
    // }

    return 0;
}