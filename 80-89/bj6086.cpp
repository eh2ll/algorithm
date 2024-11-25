// kks227 justicehui

#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
int N;
int cap[55][55], flo[55][55];
vector<int> adj[55];
int par[55];

int toint(char c){
    if(c <= 'Z') return c - 'A';
    else return c - 'a' + 26;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        char a, b; int u, v, x;
        cin >> a >> b >> x;
        u = toint(a);
        v = toint(b);
        cap[u][v] += x;
        cap[v][u] += x;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int st = 0, en = 25, res = 0;
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