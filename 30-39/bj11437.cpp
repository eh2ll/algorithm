//justicehui

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> g[50004];
int dep[50004], vis[50004];
int dp[50004][30];

void dfs(int v, int d){
    vis[v] = 1;
    dep[v] = d;
    for(auto i : g[v]){
        if(!vis[i]){
            dp[i][0] = v;
            dfs(i, d + 1);
        }
    }
}

void table(){
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

    cin >> N;
    for(int i = 0; i < N - 1; i += 1){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);
    table();

    cin >> M;
    for(int i = 0; i < M; i += 1){
        int a, b; cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}