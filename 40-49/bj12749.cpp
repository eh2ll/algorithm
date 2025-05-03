#include <bits/stdc++.h>

using namespace std;

int N, cnt, vis[5'003], nvis[5'003];
vector<int> adj[5'003], newadj[5'003];

pair<int, int> dfs(int cur){
    nvis[cur] = 1;
    int child = 1, sum = 0;
    for(auto nxt : newadj[cur]){
        if(!nvis[nxt]){
            auto [t, tt] = dfs(nxt);
            child += t;
            sum += t + tt;
        }
    }
    // cout << "dfs cur : " << cur << ' ' << "child : " << child << '\n';
    return {child, sum};
}

int bfs(int st){
    int cnt = 0;
    queue<int> Q;
    Q.push(st);
    vis[st] = 1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        cnt += 1;
        // cout << cur <<  '\n';
        for(auto nxt : adj[cur]){
            if(!vis[nxt]){
                Q.push(nxt);
                vis[nxt] = vis[cur] + 1;
                newadj[cur].push_back(nxt);
            }
        }
    }

    auto res = dfs(st);
    // cout << st << ' ' << res.first << ' ' << res.second << '\n';

    if(cnt == N) return res.first + res.second;
    else return 0x3f3f3f3f;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        int k; cin >> k;
        for(int j = 0; j < k; j += 1){
            int x; cin >> x;
            adj[x].push_back(i);
        }
    }

    int mn = 0x3f3f3f3f;
    for(int i = 1; i <= N; i += 1){
        memset(vis, 0, sizeof(vis));
        memset(nvis, 0, sizeof(nvis));
        for(int i = 0; i < 5'003; i += 1) newadj[i].clear();
        mn = min(mn, bfs(i));
    }

    cout << mn << '\n';

    return 0;
}