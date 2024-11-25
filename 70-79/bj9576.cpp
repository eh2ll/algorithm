// justicehui

#include <bits/stdc++.h>

using namespace std;

int TC, N, M;
vector<int> g[2003];
vector<int> par;
int chk[2003];

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

    cin >> TC;
    while(TC--){
        par.clear();
        for(int i = 0; i < 2003; i += 1){
            g[i].clear();
            par.push_back(-1);
        }

        cin >> N >> M;
        for(int i = 1; i <= M; i += 1){
            int a, b; cin >> a >> b;
            for(int j = a; j <= b; j += 1){
                g[i].push_back(j + 1000);
            }
        }

        int res = 0;
        for(int i = 1; i <= M; i += 1){
            memset(chk, 0, sizeof(chk));
            if(match(i)) res += 1;
        }
        cout << res << '\n';
    }

    return 0;
}