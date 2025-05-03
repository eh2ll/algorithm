#include <bits/stdc++.h>

using namespace std;

int N, P;
int flo[808][808], cap[808][808], par[808];
vector<int> adj[808];

int flow(){
    int st = 1, en = 2, res = 0;
    while(1){
        memset(par, -1, sizeof(par));
        queue<int> Q;
        Q.push(st);
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            // cout << cur << '\n';
            for(auto nxt : adj[cur]){
                // cout << cur << ' ' << nxt << " : " << cap[cur][nxt] << ' ' << flo[cur][nxt] << '\n';
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

    cin >> N >> P;
    for(int i = 0; i < P; i += 1){
        int a, b; cin >> a >> b;
        adj[2 * a - 1].push_back(2 * b - 2);
        adj[2 * b - 2].push_back(2 * a - 1);
        adj[2 * b - 1].push_back(2 * a - 2);
        adj[2 * a - 2].push_back(2 * b - 1);
        cap[2 * a - 1][2 * b - 2] += 1;
        cap[2 * b - 1][2 * a - 2] += 1;
    }

    for(int i = 1; i <= N; i += 1){
        adj[2 * i - 2].push_back(2 * i - 1);
        adj[2 * i - 1].push_back(2 * i - 2);
        cap[2 * i - 2][2 * i - 1] += 1;
    }

    cout << flow() << '\n';

    return 0;
}