// kks227

#include <bits/stdc++.h>

using namespace std;

int V, E, cnt, scnt;
vector<int> adj[10004];
int dfsn[10004], fin[10004], sn[10004];
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

        sort(curscc.begin(), curscc.end());
        scc.push_back(curscc);
        scnt += 1;
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    for(int i = 0; i < E; i += 1){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= V; i += 1){
        if(dfsn[i] == 0) dfs(i);
    }

    sort(scc.begin(), scc.end());

    cout << scnt << '\n';
    for(auto& curscc : scc){
        for(auto cur : curscc){
            cout << cur << ' ';
        }
        cout << "-1\n";
    }

    return 0;
}