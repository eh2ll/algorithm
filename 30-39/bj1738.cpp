#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll inf = 2000000009;
int N, M, par[102], vis[102];
ll d[102];
vector<pll> adj[102];
vector<int> rev[102];

void bfs(int x){
    queue<int> Q;
    Q.push(x);

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        vis[cur] = 1;
        for(auto nxt : rev[cur]){
            if(vis[nxt]) continue;
            Q.push(nxt);
            vis[nxt] = 1;
        }
    }

    return;
}

bool bellman(int st){
    fill(d, d + 102, inf);
    memset(par, -1, sizeof(par));

    d[st] = 0;
    for(int i = 0; i < N; i += 1){
        for(int cur = 1; cur <= N; cur += 1){
            if(d[cur] == inf) continue;
            for(auto [nxt, cost] : adj[cur]){
                if(d[nxt] > d[cur] + cost){
                    d[nxt] = d[cur] + cost;
                    par[nxt] = cur;
                    if(i == N - 1){
                        d[nxt] = -inf;
                    }
                }
            }
        }
        if(d[N] == inf || d[N] == -inf){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i += 1){
        ll a, b, cost; cin >> a >> b >> cost;
        adj[a].push_back({b, -cost});
        rev[b].push_back(a);
    }

    bfs(N);
    bool flag = bellman(1);
    // cout << flag << '\n';
    // for(int i = 1; i <= N; i += 1) cout << vis[i] << ' ';
    // cout << '\n';
    // for(int i = 1; i <= N; i += 1){
    //     cout << i << ' ' << par[i] << ' ' << d[i] << '\n';
    // }

    if(!flag){
        cout << "-1\n";
    }
    else{
        vector<int> path;
        for(int v = N; v != -1; v = par[v]){
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        for(auto v : path) cout << v << ' ';
        cout << '\n';
    }

    return 0;
}