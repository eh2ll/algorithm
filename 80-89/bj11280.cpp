// kks227 2-sat

#include <bits/stdc++.h>

using namespace std;

int N, M, dcnt, scnt;
vector<int> adj[20004];
int dfsn[20004], fin[20004], sn[20004];
stack<int> S;

int oppo(int x){
    if(x & 1) return x + 1;
    else return x - 1;
}

int dfs(int cur){
    dfsn[cur] = ++dcnt;
    S.push(cur);

    int res = dfsn[cur];
    for(auto nxt : adj[cur]){
        if(dfsn[nxt] == 0) res = min(res, dfs(nxt));
        else if(!fin[nxt]) res = min(res, dfsn[nxt]);
    }

    if(res == dfsn[cur]){
        while(1){
            auto t = S.top(); S.pop();
            fin[t] = 1;
            sn[t] = scnt;
            if(t == cur) break;
        }
        scnt += 1;
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i += 1){
        int a, b; cin >> a >> b;
        if(a > 0) a *= 2;
        else a = -a * 2 - 1;
        if(b > 0) b *= 2;
        else b = -b * 2 - 1;

        adj[oppo(a)].push_back(b);
        adj[oppo(b)].push_back(a);
    }

    for(int i = 1; i <= 2 * N; i += 1){
        if(dfsn[i] == 0) dfs(i);
    }

    int flag = 1;
    for(int i = 1; i <= N; i += 1){
        if(sn[2 * i] == sn[2 * i - 1]) flag = 0;
    }

    cout << flag << '\n';

    return 0;
}