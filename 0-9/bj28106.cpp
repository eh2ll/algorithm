#include <bits/stdc++.h>

using namespace std;

const int MOD = 998'244'353;
int N, res, bor[2003], dp[2003], rev[2003];
vector<int> adj[2003];

void par(int cur, int d, int rt){
    if(cur < 0) return;
    
    if(d <= bor[cur]) dp[rt] = (dp[rt] + dp[cur]) % MOD;
    par(rev[cur], d + 1, rt);
}

void dfs(int cur){
    par(rev[cur], 1, cur);
    // cout << cur << ' ' << dp[cur] << '\n';
    if(adj[cur].size() == 0) res = (res + dp[cur]) % MOD;
    for(auto nxt : adj[cur]){
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        int x; cin >> x;
        adj[x].push_back(i);
        rev[i] = x;
    }

    rev[0] = -1;
    bor[0] = 1;
    for(int i = 1; i <= N; i += 1){
        int x; cin >> x;
        bor[i] = x;
    }

    dp[0] = 1;
    dfs(0);

    cout << res << '\n';

    return 0;
}