// kks227

#include <bits/stdc++.h>

using namespace std;

int TC, N, M, cnt, scnt;

vector<int> adj[100005];
int dfsn[100005], fin[100005], sn[100005], deg[100005];
stack<int> S;
vector<vector<int>> scc;

int dfs(int cur){
    dfsn[cur] = ++cnt;
    S.push(cur);

    int res = dfsn[cur];
    for(auto nxt : adj[cur]){
        if(dfsn[nxt] == 0) res = min(res, dfs(nxt));
        else if(!fin[nxt]) res = min(res, dfsn[nxt]);
    }

    if(res == dfsn[cur]){
        vector<int> curscc;
        while(1){
            auto t = S.top(); S.pop();
            curscc.push_back(t);
            fin[t] = 1;
            sn[t] = scnt;
            if(t == cur) break;
        }

        scc.push_back(curscc);
        scnt += 1;
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    while(TC--){
        memset(dfsn, 0, sizeof (dfsn));
        memset(fin, 0, sizeof(fin));
        memset(sn, 0, sizeof(sn));
        memset(deg, 0, sizeof(deg));
        cnt = scnt = 0;
        
        for(int i = 0; i < 100005; i += 1) adj[i].clear();

        cin >> N >> M;
        for(int i = 0; i < M; i += 1){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
        }

        for(int i = 1; i <= N; i += 1){
            if(dfsn[i] == 0) dfs(i);
        }

        for(int i = 1; i <= N; i += 1){
            for(auto j : adj[i]){
                if(sn[i] != sn[j]) deg[sn[j]] += 1;
            }
        }

        int res = 0;
        for(int i = 0; i < scnt; i += 1){
            if(deg[i] == 0) res += 1;
        }

        cout << res << '\n';
    }

    return 0;
}