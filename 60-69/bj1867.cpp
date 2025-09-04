#include <bits/stdc++.h>

using namespace std;

int N, K;
int par[502], chk[502];
vector<int> g[502];

int match(int cur){
    for(auto nxt : g[cur]){
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

    cin >> N >> K;
    for(int i = 1; i <= K; i += 1){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    memset(par, -1, sizeof(par));
    int cnt = 0;
    for(int i = 1; i <= 500; i += 1){
        memset(chk, 0, sizeof(chk));
        if(match(i)) cnt += 1;
    }

    cout << cnt << '\n';

    return 0;
}