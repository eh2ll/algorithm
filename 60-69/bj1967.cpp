#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int N, st, mx, vis[10004];
vector<pii> adj[10004];

void dfs(int node, int dis){
    vis[node] = 1;
    if(mx < dis){
        mx = dis;
        st = node;
    }

    for(auto nxt : adj[node]){
        if(vis[nxt.X]) continue;
        dfs(nxt.X, nxt.Y + dis);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N - 1; i += 1){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dfs(1, 0);

    memset(vis, 0, sizeof(vis));
    mx = 0;
    dfs(st, 0);

    cout << mx << '\n';

    return 0;
}