#include <bits/stdc++.h>

using namespace std;

int N, M, S = 300, T = 301, B = 100;
int cap[302][302], flo[302][302], job[302][302];
int dis[302], vis[302], wor[302];
bool inq[302];
vector<int> g[302];

int score(int lev, int ord){
    return lev * 4 - ord;
}

bool spfa(){
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[S] = 0;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        inq[cur] = 0;
        for(auto nxt : g[cur]){
            if(dis[nxt] > dis[cur] + job[cur][nxt] && cap[cur][nxt] - flo[cur][nxt] > 0){
                dis[nxt] = dis[cur] + job[cur][nxt];
                if(!inq[nxt]) inq[nxt] = 1, Q.push(nxt);
            }
        }
    }
    return dis[T] != 0x3f3f3f3f;
}

int dfs(int cur, int cost){
    vis[cur] = 1;
    if(cur == T) return cost;
    for(int &i = wor[cur]; i < g[cur].size(); i += 1){
        int nxt = g[cur][i];
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

    while(1){
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        memset(cap, 0, sizeof(cap));
        memset(flo, 0, sizeof(flo));
        memset(job, 0, sizeof(job));
        for(int i = 0; i < 302; i += 1) g[i].clear();
        memset(inq, 0, sizeof(inq));

        for(int i = 0; i < N; i += 1){
            int x; cin >> x;
            cap[i + B][T] = x;
            g[i + B].push_back(T);
            g[T].push_back(i + B);
        }
        for(int i = 0; i < M; i += 1){
            int x; cin >> x;
            cap[S][i] = 1;
            g[S].push_back(i);
            g[i].push_back(S);
            for(int j = 0; j < 4; j += 1){
                int y; cin >> y;
                cap[i][y + B] = 1;
                g[i].push_back(y + B);
                g[y + B].push_back(i);
                job[i][y + B] -= score(x, j);
                job[y + B][i] += score(x, j);
            }
        }

        int flow = 0, cost = 0;
        while(spfa()){
            memset(vis, 0, sizeof(vis));
            memset(wor, 0, sizeof(wor));
            while(1){
                int ret = dfs(S, 0x3f3f3f3f);
                if(ret == 0) break;
                flow += ret;
                cost += ret * dis[T];
                memset(vis, 0, sizeof(vis));
            }
        }

        cout << -cost << '\n';
    }

    return 0;
}