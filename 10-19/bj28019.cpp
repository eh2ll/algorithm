#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M;
ll dis, mx;
tuple<int, int, int> edge[1000006];
vector<pair<int, int>> adj[50004];
int par[50004], vis[50004];

int find(int x){
    if(par[x] < 0) return x;
    return par[x] = find(par[x]);
}

int merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return 0;
    if(u > v) swap(u, v);
    par[v] = u;
    return 1;
}

void dfs(int cur, ll tot){
    vis[cur] = 1;
    bool leaf = 1;
    for(auto [cost, nxt] : adj[cur]){
        if(vis[nxt]) continue;
        dfs(nxt, tot + cost);
        leaf = 0;
    }

    if(leaf){
        mx = max(mx, tot);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i += 1){
        int a, b, cost; cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }
    sort(edge, edge + M, greater<tuple<int, int, int>>());

    memset(par, -1, sizeof(par));
    int cnt = 1;
    for(int i = 0; i < M; i += 1){
        auto [cost, u, v] = edge[i];
        if(merge(u, v)){
            adj[u].push_back({cost, v});
            adj[v].push_back({cost, u});
            cnt += 1;
            dis += 2 * cost;
        }
        if(cnt == N) break;
    }

    int rt; cin >> rt;
    dfs(rt, 0);

    cout << dis - mx << '\n';

    return 0;

}