// crocus spfa
#include <unistd.h>

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll inf = 2500000009;
int N, st, en, M;
vector<pll> adj[52];
ll dis[52], cyc[52], inq[52], fee[52], vis[52], chk[52];

bool bfs(){
    queue<int> Q;
    for(int i = 0; i < N; i += 1){
        if(chk[i]){
            Q.push(i);
            vis[i] = 1;
        }
    }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        // cout << "cur " << cur << '\n';
        vis[cur] = 1;
        if(cur == en) return true;
        for(auto [nxt, tmp] : adj[cur]){
            if(vis[nxt]) continue;
            Q.push(nxt);
            vis[nxt] = 1;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> st >> en >> M;
    for(int i = 0; i < M; i += 1){
        int a, b, cost; cin >> a >> b >> cost;
        adj[a].push_back({b, cost});
    }

    for(int i = 0; i < N; i += 1) cin >> fee[i];

    fill(dis, dis + 52, inf);
    queue<int> Q;
    Q.push(st);
    dis[st] = 0;
    cyc[st] += 1;
    inq[st] = 1;

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        inq[cur] = 0;
        
        // cout << cur << ' ' << dis[cur] << '\n';
        
        for(auto [nxt, cost] : adj[cur]){
            if(dis[nxt] <= dis[cur] + cost - fee[nxt]) continue;
            dis[nxt] = dis[cur] + cost - fee[nxt];

            if(inq[nxt]) continue;
            // cout << nxt << ' ' << inq[nxt] << ' ' << cyc[nxt] << '\n';
            cyc[nxt] += 1;
            if(cyc[nxt] == N){
                chk[nxt] = 1;
            }
            else if(cyc[nxt] > N){
                chk[nxt] = 1;
                continue;
            }

            Q.push(nxt);
            inq[nxt] = 1;
        }        
    }

    if(dis[en] == inf) cout << "gg\n";
    else{
        auto tmp = bfs();
        // cout << tmp << "!\n";
        if(tmp) cout << "Gee\n";
        else cout << - dis[en] + fee[st] << '\n';
    }

    return 0;
}