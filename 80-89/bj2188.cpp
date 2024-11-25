#include <bits/stdc++.h>

using namespace std;

int N, M, st = 0, en = 401, res;
int cap[440][440], flo[440][440];
int par[440];
vector<int> adj[440];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i += 1){
        int x; cin >> x;
        cap[st][i] += 1;
        adj[st].push_back(i);
        adj[i].push_back(st);
        for(int k = 0; k < x; k += 1){
            int t; cin >> t;
            t += 200;
            cap[i][t] = 1;
            adj[i].push_back(t);
            adj[t].push_back(i);
        }
    }
    for(int i = 201; i <= 200 + M; i += 1){
        cap[i][en] += 1;
        adj[i].push_back(en);
        adj[en].push_back(i);
    }

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

    cout << res << '\n';

    return 0;
}