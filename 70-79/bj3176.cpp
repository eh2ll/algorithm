#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

int N, K;
vector<pii> g[100'005];
int dep[100'005], vis[100'005];
tii dp[100'005][30];

void dfs(int v, int d){
    vis[v] = 1;
    dep[v] = d;
    for(auto [u, w] : g[v]){
        if(!vis[u]){
            dp[u][0] = {v, w, w};
            dfs(u, d + 1);
        }
    }
}

void table(){
    for(int j = 1; j < 30; j += 1){
        for(int i = 1; i <= N; i += 1){
            int nxt = get<0>(dp[i][j - 1]);
            int up = get<0>(dp[nxt][j - 1]);
            int mx = max(get<1>(dp[i][j - 1]), get<1>(dp[nxt][j - 1]));
            int mn = min(get<2>(dp[i][j - 1]), get<2>(dp[nxt][j - 1]));
            dp[i][j] = {up, mx, mn};
        }
    }
}

pii lca(int u, int v){
    int mx = -1, mn = 1e7;
    if(dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    for(int i = 0; diff; i += 1){
        if(diff & 1){
            mx = max(mx, get<1>(dp[u][i]));
            mn = min(mn, get<2>(dp[u][i]));
            u = get<0>(dp[u][i]);
        }
        diff >>= 1;
    }
    if(u == v) return {mx, mn};
    for(int i = 29; i >= 0; i -= 1){
        if(get<0>(dp[u][i]) != get<0>(dp[v][i])){
            mx = max({mx, get<1>(dp[u][i]), get<1>(dp[v][i])});
            mn = min({mn, get<2>(dp[u][i]), get<2>(dp[v][i])});
            u = get<0>(dp[u][i]);
            v = get<0>(dp[v][i]);
        }
    }
    mx = max({mx, get<1>(dp[u][0]), get<1>(dp[v][0])});
    mn = min({mn, get<2>(dp[u][0]), get<2>(dp[v][0])});
    return {mx, mn};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N - 1; i += 1){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    for(int i = 0; i <= N; ++i){
        for(int j = 0; j < 30; ++j){
            dp[i][j] = {0, -1, 1e7};
        }
    }

    dfs(1, 0);
    table();

    cin >> K;
    for(int i = 0; i < K; i += 1){
        int u, v; cin >> u >> v;
        auto [mx, mn] = lca(u, v);
        cout << mn << ' ' << mx << "\n";
    }

    return 0;
}