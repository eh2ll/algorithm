#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int N, M, res[103][103];
vector<pii> adj[103];

void dfs(int cur){
    if(adj[cur].size() == 0){
        res[cur][cur] = 1;
        res[cur][0] = 1;
        return;
    }

    for(auto [nxt, cost] : adj[cur]){
        if(!res[nxt][0]){ 
            dfs(nxt);
        }
        for(int i = 1; i < N; i += 1){
            res[cur][i] += res[nxt][i] * cost;
        }
    }

    res[cur][0] = 1;

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i += 1){
        int a, b, cost; cin >> a >> b >> cost;
        adj[a].push_back({b, cost});
    }

    dfs(N);

    for(int i = 1; i < N; i += 1){
        if(!res[N][i]) continue;
        cout << i << ' ' << res[N][i] << '\n';
    }

    return 0;
}