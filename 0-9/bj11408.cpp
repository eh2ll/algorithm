#include <bits/stdc++.h>

using namespace std;

int N, M, st = 0, en = 801;
int cap[1'000][1'000], flo[1'000][1'000], job[1'000][1'000];
int dis[1'000], vis[1'000], wor[1'000];
bool inq[1'000];
vector<int> adj[1'000];

bool spfa(){
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[st] = 0;
    queue<int> Q;
    Q.push(st);
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        inq[cur] = 0;
        for(auto nxt : adj[cur]){
            if(dis[nxt] > dis[cur] + job[cur][nxt] && cap[cur][nxt] - flo[cur][nxt] > 0){
                dis[nxt] = dis[cur] + job[cur][nxt];
                if(!inq[nxt]) inq[nxt] = 1, Q.push(nxt);
            }
        }
    }

    return dis[en] != 0x3f3f3f3f;
}

int dfs(int cur, int cost){
    vis[cur] = 1;
    if(cur == en) return cost;

    for(int& i = wor[cur]; i < (int)adj[cur].size(); i += 1){
        auto nxt = adj[cur][i];
        if(!vis[nxt] && dis[nxt] == dis[cur] + job[cur][nxt] && cap[cur][nxt] - flo[cur][nxt] > 0){
            int ret = dfs(nxt, min(cost, cap[cur][nxt] - flo[cur][nxt]));
            if(ret > 0){
                flo[cur][nxt] += ret;
                flo[nxt][cur] -= ret;
                return ret;
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i += 1){
        int t; cin >> t;
        cap[st][i] = 1;
        adj[st].push_back(i);
        adj[i].push_back(st);
        for(int j = 1; j <= t; j += 1){
            int a, b; cin >> a >> b;
            cap[i][a + 400] = 1;
            adj[i].push_back(a + 400);
            adj[a + 400].push_back(i);
            job[i][a + 400] = -b;
            job[a + 400][i] = +b;
        }
    }
    for(int i = 401; i <= 800; i += 1){
        cap[i][en] = 1;
        adj[i].push_back(en);
        adj[en].push_back(i);
    }

    int flow = 0, cost = 0;
    while(spfa()){
        memset(vis, 0, sizeof(vis));
        memset(wor, 0, sizeof(wor));
        while(1){
            int ret = dfs(st, 0x3f3f3f3f);
            if(ret == 0) break;
            flow += ret;
            cost += ret * dis[en];
            memset(vis, 0, sizeof(vis));
        }
    }

    cout << flow << '\n' << -cost << '\n';

    return 0;
}