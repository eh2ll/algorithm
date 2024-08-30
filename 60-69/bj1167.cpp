#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;
int V, vis[100005], st, mx;
vector<pii> adj[100005];

void dfs(int node, int dis){
    if(mx < dis){
        mx = dis;
        st = node;
    }

    vis[node] = 1;

    for(auto cur : adj[node]){
        if(vis[cur.X]) continue;
        dfs(cur.X, dis + cur.Y);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V;
    for(int i = 1; i <= V; i += 1){
        int dmp; cin >> dmp;
        int x = 0, y = 0;
        while(1){
            cin >> x;
            if(x == -1) break;
            cin >> y;
            adj[dmp].push_back({x, y});
        }
    }

    dfs(1, 0);

    memset(vis, 0, sizeof(vis));
    mx = 0;
    dfs(st, 0);

    cout << mx << '\n';

    return 0;
}