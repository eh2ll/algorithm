#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M;
int dp[40004][30], dis[40004][30], vis[40004], dep[40004];
vector<pii> g[40004];

void dfs(int v, int d){
    vis[v] = 1;
    dep[v] = d;

    for(auto [cost, nxt] : g[v]){
        if(vis[nxt]) continue;
        dp[nxt][0] = v;
        dis[nxt][0] = cost;
        dfs(nxt, d + 1);
    }
}

void make_table(){
    for(int j = 1; j < 30; j += 1){
        for(int i = 1; i <= N; i += 1){
            dp[i][j] = dp[ dp[i][j - 1] ][j - 1];
            dis[i][j] = dis[ dp[i][j - 1] ][j - 1] + dis[i][j - 1];
        }
    }
}

int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    int ret = 0;
    // cout << "df " << diff;
    for(int i = 0; diff; i += 1){
        // if(diff & 1) cout << " ds1 " << dis[u][i];
        if(diff & 1) ret += dis[u][i], u = dp[u][i];
        diff >>= 1;
    }
    // cout << " rt1 " << ret << ' ';
    if(u == v) return ret;

    for(int i = 29; i >= 0; i -= 1){
        if(dp[u][i] != dp[v][i]){
            ret += dis[u][i] + dis[v][i];
            u = dp[u][i];
            v = dp[v][i];
        }
    }

    // cout << " rt2 " << ret << " u v " << dis[u][0] << ' ' << dis[v][0] << '\n'; 
    return ret + dis[u][0] + dis[v][0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N - 1; i += 1){
        int a, b, cost; cin >> a >> b >> cost;
        g[a].push_back({cost, b});
        g[b].push_back({cost, a});
    }

    dfs(1, 0);
    make_table();

    cin >> M;
    for(int i = 0; i < M; i += 1){
        int u, v; cin >> u >> v;
        cout << lca(u, v) << '\n';
    }

    return 0;
}