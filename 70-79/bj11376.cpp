#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> g[3003];
vector<int> par(3003, -1);
int chk[3003];

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

    cin >> N >> M;
    for(int i = 1; i <= N; i += 1){
        int x; cin >> x;
        for(int j = 0; j < x; j += 1){
            int k; cin >> k;
            // g[2 * i - 1 + j].push_back(k);
            g[2 * i - 1].push_back(k);
            g[2 * i].push_back(k);
        }
    }

    int res = 0;
    for(int i = 1; i <= 2 * N; i += 1){
        memset(chk, 0, sizeof(chk));
        if(match(i)) res += 1;
    }

    cout << res << '\n';

    return 0;
}