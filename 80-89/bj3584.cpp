#include <bits/stdc++.h>

using namespace std;

int TC, N, root;
vector<int> g[10004];
int dep[10004];
int vis[10004];
int deg[10004];
int dp[10004][30];

void dfs(int v, int d){
    vis[v] = 1;
    dep[v] = d;

    for(auto nxt : g[v]){
        if(vis[nxt]) continue;
        dp[nxt][0] = v;
        dfs(nxt, d + 1);
    }
}

void make_table(){
    for(int j = 1; j < 30; j += 1){
        for(int i = 1; i <= N; i += 1){
            dp[i][j] = dp[ dp[i][j - 1] ][j - 1];
        }
    }    
}

int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    for(int i = 0; diff; i += 1){
        if(diff & 1) u = dp[u][i];
        diff >>= 1;
    }
    if(u == v) return u;

    for(int i = 29; i >= 0; i -= 1){
        if(dp[u][i] != dp[v][i]) u = dp[u][i], v = dp[v][i];
    }
    return dp[u][0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    while(TC--){
        for(int i = 0; i < 10004; i += 1) g[i].clear();
        memset(dep, 0, sizeof(dep));
        memset(vis, 0, sizeof(vis));
        memset(dp, 0, sizeof(dp));
        memset(deg, 0, sizeof(deg));

        cin >> N;
        for(int i = 0; i < N - 1; i += 1){
            int a, b; cin >> a >> b;
            g[a].push_back(b);
            deg[b] += 1;
        }

        for(int i = 1; i <= N; i += 1){
            if(deg[i]) continue;
            root = i;
        }

        dfs(root, 0);
        make_table();

        int u, v; cin >> u >> v;
        cout << lca(u, v) << '\n';
    }

    return 0;
}