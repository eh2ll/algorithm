//jinho9610

#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, M, X;
vector<int> adj[100005], radj[100005];
int vis[100005];
int cnt = -1, rcnt = -1;

void dfs(int x){
    if(vis[x]) return;

    vis[x] = 1;
    cnt += 1;
    
    for(auto nxt : adj[x]) dfs(nxt);
}

void rdfs(int x){
    if(vis[x]) return;
    
    vis[x] = 1;
    rcnt += 1;
    
    for(auto nxt : radj[x]) rdfs(nxt);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X;
    for(int i = 0; i < M; i += 1){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        radj[y].push_back(x);
    }

    dfs(X);
    memset(vis, 0, sizeof(vis));
    rdfs(X);

    cout << rcnt + 1 << ' ' << N - cnt << '\n';

    return 0;
}