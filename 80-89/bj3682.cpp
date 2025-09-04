// 2% idea from kks227

#include <bits/stdc++.h>

using namespace std;

int N, M, cnt, scnt;
vector<int> g[20'004];
int dfsn[20'004], fin[20'004], sn[20'004], indeg[20'004], outdeg[20'004];
stack<int> S;
vector<vector<int>> scc;

int dfs(int cur){
    dfsn[cur] = ++cnt;
    S.push(cur);

    int ret = dfsn[cur];
    for(int nxt : g[cur]){
        if(dfsn[nxt] == 0) ret = min(ret, dfs(nxt));
        else if(!fin[nxt]) ret = min(ret, dfsn[nxt]);
    }

    if(ret == dfsn[cur]){
        vector<int> curscc;
        while(!S.empty()){
            int top = S.top(); S.pop();
            fin[top] = 1;
            sn[top] = scnt;
            curscc.push_back(top);
            if(top == cur) break;
        }

        sort(curscc.begin(), curscc.end());
        scc.push_back(curscc);
        scnt += 1;
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        cnt = scnt = 0;
        for(int i = 0; i < 20'004; i += 1) g[i].clear();
        memset(dfsn, 0, sizeof(dfsn));
        memset(fin, 0, sizeof(fin));
        memset(sn, 0, sizeof(sn));
        memset(indeg, 0, sizeof(indeg));
        memset(outdeg, 0, sizeof(outdeg));
        scc.clear();

        cin >> N >> M;
        for(int i = 0; i < M; i += 1){
            int a, b; cin >> a >> b;
            g[a].emplace_back(b);
        }

        for(int i = 1; i <= N; i += 1){
            if(!dfsn[i]) dfs(i);
        }

        for(int i = 1; i <= N; i += 1){
            for(int nxt : g[i]){
                if(sn[i] != sn[nxt]){
                    outdeg[sn[i]] += 1;
                    indeg[sn[nxt]] += 1;
                }
            }
        }

        int cntin = 0, cntout = 0;
        for(int i = 0; i < scnt; i += 1){
            if(outdeg[i] == 0) cntout += 1;
            if(indeg[i] == 0) cntin += 1;
        }

        if(scnt == 1) cout << 0 << '\n';
        else cout << max(cntin, cntout) << '\n';
    }

    return 0;
}