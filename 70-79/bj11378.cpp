#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<int> adj[1'003];
int chk[1'003], par[1'003];

int match(int cur){
    for(auto nxt : adj[cur]){
        if(chk[nxt]) continue;
        chk[nxt] = 1;
        if(par[nxt] == -1 || match(par[nxt])){
            par[nxt] = cur;
            return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i = 1; i <= N; i += 1){
        int t; cin >> t;
        for(int j = 1; j <= t; j += 1){
            int x; cin >> x;
            adj[i].push_back(x);
        }
    }

    int ans = 0;
    memset(par, -1, sizeof(par));
    for(int i = 1; i <= N; i += 1){
        memset(chk, 0, sizeof(chk));
        if(match(i)) ans += 1;
    }

    int idx = 1, cnt = 0;
    while(idx <= N && cnt < K){
        memset(chk, 0, sizeof(chk));
        if(match(idx)) cnt += 1;
        else idx += 1;
    }

    cout << ans + cnt << '\n';

    return 0;
}