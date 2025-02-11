#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M, st, en;
vector<pii> adj[100005];
int vis[100005];

void dfs(int cur, int k){
    vis[cur] = 1;
    for(auto [cost, nxt] : adj[cur]){
        if(cost < k) continue;
        if(vis[nxt]) continue;
        dfs(nxt, k);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i += 1){
        int a, b, cost; cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }
    cin >> st >> en;

    int l = 0, r = 1'000'000'001;
    while(l + 1 < r){
        int mid = (l + r + 1) / 2;
        memset(vis, 0, sizeof(vis));

        dfs(st, mid);

        if(vis[en]) l = mid;
        else r = mid;
    }

    cout << l << '\n';

    return 0;
}