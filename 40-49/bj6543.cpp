#include <bits/stdc++.h>

using namespace std;

int N, M, cnt, scnt;
int dfsn[5003], fin[5003], sn[5003], outdegree[5003];
stack<int> S;
vector<int> adj[5003];
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

    while(1){
        cnt = 0;
        scnt = 0;
        memset(dfsn, 0, sizeof(dfsn));
        memset(fin, 0, sizeof(fin));
        memset(sn, 0, sizeof(sn));
        memset(outdegree, 0, sizeof(outdegree));
        for(int i = 0; i < 5003; i += 1) adj[i].clear();
        scc.clear();

        cin >> N;
        if(N == 0) break;
        cin >> M;

        for(int i = 0; i < M; i += 1){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
        }

        for(int i = 1; i <= N; i += 1){
            int tmp = 0;
            if(dfsn[i] == 0){
                tmp = dfs(i);
            }
        }

        for(int i = 1; i <= N; i += 1){
            for(auto j : adj[i]){
                if(sn[i] != sn[j]) outdegree[sn[i]] += 1;
            }
        }

        for(int i = 1; i <= N; i += 1){
            if(outdegree[sn[i]] == 0) cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}