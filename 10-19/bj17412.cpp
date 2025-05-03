#include <bits/stdc++.h>

using namespace std;

int N, M;
int cap[402][402], flo[402][402], par[402];
vector<int> adj[402];

int flow(){
    int st = 1, en = 2, res = 0;
    while(1){
        memset(par, -1, sizeof(par));
        queue<int> Q;
        Q.push(st);
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(auto nxt : adj[cur]){
                if(par[nxt] == -1 && cap[cur][nxt] - flo[cur][nxt] > 0){
                    Q.push(nxt);
                    par[nxt] = cur;
                    if(nxt == en) break;
                }
            }
        }
        if(par[en] == -1) break;

        int cost = 0x3f3f3f3f;
        for(int i = en; i != st; i = par[i]){
            cost = min(cost, cap[par[i]][i] - flo[par[i]][i]);
        }
        for(int i = en; i != st; i = par[i]){
            flo[par[i]][i] += cost;
            flo[i][par[i]] -= cost;
        }
        
        res += cost;
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i += 1){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += 1;
    }

    cout << flow() << '\n';

    return 0;
}