#include <bits/stdc++.h>

using namespace std;

const int st = 0, en = 2001, br = 2002, inf = 0x3f3f3f3f;
int N, M, K, ans;
vector<int> adj[2020];
int cap[2020][2020], flo[2020][2020], par[2020];

void flow(){
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

        int cost = inf;

        for(int i = en; i != st; i = par[i]){
            cost = min(cost, cap[ par[i] ][i] - flo[ par[i] ][i]);
        }
        for(int i = en; i != st; i = par[i]){
            flo[ par[i] ][i] += cost;
            flo[i][ par[i] ] -= cost;
        }

        ans += cost;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i = 1; i <= N; i += 1){
        cap[st][i] = 1;
        adj[st].push_back(i);
        adj[i].push_back(st);
        int x; cin >> x;
        for(int j = 0; j < x; j += 1){
            int t; cin >> t;
            t += 1000;
            cap[i][t] = 1;
            adj[i].push_back(t);
            adj[t].push_back(i);
        }
    }
    for(int i = 1001; i <= M + 1000; i += 1){
        cap[i][en] = 1;
        adj[i].push_back(en);
        adj[en].push_back(i);
    }
    cap[0][br] = K;
    adj[0].push_back(br);
    adj[br].push_back(0);
    for(int i = 1; i <= N; i += 1){
        cap[br][i] = 1;
        adj[br].push_back(i);
        adj[i].push_back(br);
    }

    flow();

    cout << ans << '\n';

    return 0;
}