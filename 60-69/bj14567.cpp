#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int N, M, deg[1003], res[1003];
vector<int> adj[1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i += 1){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        deg[b] += 1;
    }

    queue<pii> Q;
    for(int i = 1; i <= N; i += 1){
        if(deg[i] == 0) Q.push({i, 1});
    }

    while(!Q.empty()){
        auto [cur, cost] = Q.front(); Q.pop();
        res[cur] = cost;

        for(auto nxt : adj[cur]){
            deg[nxt] -= 1;
            if(deg[nxt] == 0){
                Q.push({nxt, cost + 1});
            }
        }
    }

    for(int i = 1; i <= N; i += 1) cout << res[i] << ' ';
    cout << '\n';

    return 0;
}