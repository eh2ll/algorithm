// justicehui, kks227

#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int s = 0, e = 2001;

int N, M, ans;
vector<int> adj[2003];
int cap[2003][2003], flo[2003][2003];
int par[2003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i += 1){
        cap[s][i] = 1;
        adj[s].push_back(i);
        adj[i].push_back(s);
        int tmp; cin >> tmp;
        for(int j = 0; j < tmp; j += 1){
            int x; cin >> x;
            x += 1000;
            cap[i][x] = 1;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }

    for(int i = 1001; i <= 1000 + M; i += 1){
        cap[i][e] = 1;
        adj[i].push_back(e);
        adj[e].push_back(i);
    }

    while(1){
        memset(par, -1, sizeof(par));
        queue<int> Q;
        Q.push(s);
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(auto nxt : adj[cur]){
                if(par[nxt] == -1 && cap[cur][nxt] - flo[cur][nxt] > 0){
                    Q.push(nxt);
                    par[nxt] = cur;
                    if(nxt == e) break;
                }
            }
        }
        if(par[e] == -1) break;

        int cost = inf;
        for(int i = e; i != s; i = par[i]){
            cost = min(cost, cap[ par[i] ][i] - flo[ par[i] ][i]);
        }

        for(int i = e; i != s; i = par[i]){
            flo[ par[i] ][i] += cost;
            flo[i][ par[i] ] -= cost;
        }
        ans += cost;
    }

    cout << ans << '\n';

    return 0;
}