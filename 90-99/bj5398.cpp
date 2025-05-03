#include <bits/stdc++.h>

using namespace std;

int TC, H, V;
char bor[2003][2003];
int mp[2003][2003];
vector<int> adj[502];
bool chk[502];
int par[502];

int dfs(int cur){
    for(auto nxt : adj[cur]){
        if(chk[nxt]) continue;
        chk[nxt] = 1;
        if(par[nxt] == -1 || dfs(par[nxt])){
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
        memset(bor, 0, sizeof(bor));
        memset(mp, 0, sizeof(mp));
        for(int i = 0; i < 502; i += 1) adj[i].clear();

        cin >> H >> V;
        for(int i = 0; i < H; i += 1){
            int a, b; string s; cin >> a >> b >> s;
            for(int j = 0; j < s.size(); j += 1){
                bor[b][a + j] = s[j];
                mp[b][a + j] = i;
            }
        }
        for(int i = 0; i < V; i += 1){
            int a, b; string s; cin >> a >> b >> s;
            for(int j = 0; j < s.size(); j += 1){
                if(bor[b + j][a] != 0 && bor[b + j][a] != s[j]){
                    adj[mp[b + j][a]].push_back(i);
                }
            }
        }

        memset(par, -1, sizeof(par));
        int res = H + V;
        for(int i = 0; i < H; i += 1){
            memset(chk, 0, sizeof(chk));
            if(dfs(i)) res -= 1;
        }

        cout << res << '\n';
    }

    return 0;
}