#include <bits/stdc++.h>

using namespace std;

int N, w[10004], dp[10004][2], vis[10004];
vector<int> adj[10004];
vector<int> par[10004][2];

void dfs(int cur){
    vis[cur] = 1;
    int mx0 = 0;
    int mx1 = 0;
    for(auto nxt : adj[cur]){
        if(vis[nxt]){
            continue;
        }
        else{
            dfs(nxt);
            if(dp[nxt][0] > dp[nxt][1]){
                mx0 += dp[nxt][0];
                for(auto k : par[nxt][0]) par[cur][0].push_back(k);
            }
            else{
                mx0 += dp[nxt][1];
                for(auto k : par[nxt][1]) par[cur][0].push_back(k);
            }

            mx1 += dp[nxt][0];
            for(auto k : par[nxt][0]) par[cur][1].push_back(k);
        }
    }
    dp[cur][0] = mx0;
    dp[cur][1] = mx1 + w[cur];
    par[cur][1].push_back(cur);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        cin >> w[i];
    }
    for(int i = 1; i < N; i += 1){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    if(dp[1][0] > dp[1][1]){
        cout << dp[1][0] << '\n';
        sort(par[1][0].begin(), par[1][0].end());
        for(auto k : par[1][0]) cout << k << ' ';
        cout << '\n';
    }
    else{
        cout << dp[1][1] << '\n';
        sort(par[1][1].begin(), par[1][1].end());
        for(auto k : par[1][1]) cout << k << ' ';
        cout << '\n';
    }

    return 0;
}