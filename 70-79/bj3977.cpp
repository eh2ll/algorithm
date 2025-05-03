#include <bits/stdc++.h>

using namespace std;

int N, M, cnt, scnt;
vector<int> adj[100'005], sadj[100'005];
int dfsn[100'005], fin[100'005], sn[100'005], deg[100'005], svis[100'005];
stack<int> S;
vector<vector<int>> scc;

int dfs(int cur){
    dfsn[cur] = ++cnt;
    S.push(cur);
    int ret = dfsn[cur];
    for(auto nxt : adj[cur]){
        if(dfsn[nxt] == 0) ret = min(ret, dfs(nxt));
        else if(fin[nxt] == 0) ret = min(ret, dfsn[nxt]);
    }

    if(ret == dfsn[cur]){
        vector<int> curscc;
        while(1){
            int t = S.top(); S.pop();
            fin[t] = 1;
            sn[t] = scnt;
            curscc.push_back(t);
            if(t == cur) break;
        }
        sort(curscc.begin(), curscc.end());
        scc.push_back(curscc);
        scnt += 1;
    }

    return ret;
}

bool topological(int st){
    queue<int> Q;
    Q.push(st);
    svis[st] = 1;
    int tcnt = 1;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(auto nxt : sadj[cur]){
            if(svis[nxt] == 0){
                svis[nxt] = 1;
                tcnt += 1;
                Q.push(nxt);
            }
        }
    }

    if(tcnt == scnt) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        cin >> N >> M;
        for(int i = 0; i < N; i += 1) adj[i].clear();
        for(int i = 0; i < M; i += 1) sadj[i].clear();

        for(int i = 0; i < M; i += 1){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
        }

        memset(dfsn, 0, sizeof(dfsn));
        memset(fin, 0, sizeof(fin));
        memset(sn, 0, sizeof(sn));
        memset(svis, 0, sizeof(svis));
        memset(deg, 0, sizeof(deg));
        cnt = 0; scnt = 0;
        while(!S.empty()) S.pop();
        scc.clear();

        for(int i = 0; i < N; i += 1){
            if(dfsn[i] == 0){
                dfs(i);
            }
        }

        for(int i = 0; i < N; i += 1){
            for(auto nxt : adj[i]){
                if(sn[i] == sn[nxt]) continue;
                sadj[sn[i]].push_back(sn[nxt]);
                deg[sn[nxt]] += 1;
            }
        }

        int st = -1;
        for(int i = 0; i < scnt; i += 1){
            if(deg[i] == 0) st = i;
        }

        if(topological(st)){
            for(auto t : scc[st]) cout << t << '\n';
            cout << '\n';
        }
        else cout << "Confused\n\n";
    }
}