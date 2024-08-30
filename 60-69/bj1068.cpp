#include <bits/stdc++.h>
using namespace std;

int N, D, cnt;
vector<int> V[52];
int vis[52];

int dfs(int n){
    if(vis[n] || n == D){
        return 0;
    }
    vis[n] = 1;

    int tot = 0;
    for(auto nxt : V[n]){
        if(nxt == D) continue;
        tot += dfs(nxt);
    }
    // cout << tot << '\n';
    return max(tot, 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int rt = 0;
    for(int i = 0; i < N; i += 1){
        int x; cin >> x;
        if(x < 0){
            rt = i;
            continue;
        }
        V[x].push_back(i);
    }
    
    cin >> D;
    for(auto cur : V[D]){
        V[D].pop_back();
    }

    int res = dfs(rt);

    cout << res << '\n';

    return 0;
}