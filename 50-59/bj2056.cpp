#include <bits/stdc++.h>

using namespace std;

int N;
int deg[10'004], dis[10'004], wrk[10'004];
vector<int> adj[10'004];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        int t; cin >> wrk[i] >> t;
        for(int j = 0; j < t; j += 1){
            int x; cin >> x;
            adj[x].push_back(i);
            deg[i] += 1;
        }
    }

    queue<int> Q;
    for(int i = 1; i <= N; i += 1){
        if(deg[i] == 0) Q.push(i);
    }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(auto nxt : adj[cur]){
            deg[nxt] -= 1;
            dis[nxt] = max(dis[nxt], dis[cur] + wrk[cur]);
            if(deg[nxt] == 0) Q.push(nxt);
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i += 1){
        ans = max(ans, dis[i] + wrk[i]);
    }

    cout << ans << '\n';

    return 0;
}