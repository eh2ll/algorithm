// kks227

#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
int N, M, st = 0, en = 201;
vector<int> adj[202];
int cap[202][202], flo[202][202], cost[202][202], dis[202], par[202];
bool isq[202];

int flow(){
    int res = 0;
    while(1){
        memset(dis, inf, sizeof(dis));
        memset(par, -1, sizeof(par));
        memset(isq, 0, sizeof(isq));
        queue<int> Q;
        Q.push(st);
        isq[st] = 1;
        dis[st] = 0;
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            // cout << "Q cur : " << cur << '\n';
            isq[cur] = 0;
            for(auto nxt : adj[cur]){
                // if(nxt > 100) cout << "nxt : " << nxt << '\n' << cap[cur][nxt] << ' ' << flo[cur][nxt] << '\n' << dis[nxt] << ' ' << dis[cur] + cost[cur][nxt] << '\n';
                if(cap[cur][nxt] - flo[cur][nxt] > 0 && dis[nxt] > dis[cur] + cost[cur][nxt]){
                    dis[nxt] = dis[cur] + cost[cur][nxt];
                    par[nxt] = cur;
                    if(!isq[nxt]) Q.push(nxt), isq[nxt] = 1;
                }
            }
        }

        if(par[en] == -1) break;

        int mn = inf;
        for(int i = en; i != st; i = par[i]){
            mn = min(mn, cap[par[i]][i] - flo[par[i]][i]);
        }

        for(int i = en; i != st; i = par[i]){
            res += mn * cost[par[i]][i];
            flo[par[i]][i] += mn;
            flo[i][par[i]] -= mn;
        }

    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i += 1){
        cin >> cap[i + 100][en];
        adj[i + 100].push_back(en);
        adj[en].push_back(i + 100);
    }
    for(int i = 1; i <= M; i += 1){
        cin >> cap[st][i];
        adj[st].push_back(i);
        adj[i].push_back(st);
    }
    for(int i = 1; i <= M; i += 1){
        for(int j = 1; j <= N; j += 1){
            cin >> cost[i][j + 100];
            cap[i][j + 100] = inf;
            cost[j + 100][i] = -cost[i][j + 100];
            adj[i].push_back(j + 100);
            adj[j + 100].push_back(i);
        }
    }

    cout << flow() << '\n';

    return 0;
}