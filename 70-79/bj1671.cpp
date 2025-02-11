#include <bits/stdc++.h>

using namespace std;

int N;

struct shark{
    int h, s, i;
};

int comp(const shark& a, const shark& b){
    if(a.h == b.h && a.s == b.s && a.i == b.i) return 2;
    else if(a.h >= b.h && a.s >= b.s && a.i >= b.i) return 1;
    else return 0;
}

vector<shark> V;
vector<int> g[102];
int chk[102], par[102];

bool dfs(int cur){
    for(auto nxt : g[cur]){
        if(chk[nxt] != -1) continue;
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

    cin >> N;
    for(int i = 0; i < N; i += 1){
        int H, S, I; cin >> H >> S >> I;
        V.push_back({H, S, I});
    }

    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < N; j += 1){
            if(i == j) continue;
            
            int cmp = comp(V[i], V[j]);
            if(cmp == 2 && i > j){
                g[i].push_back(j + 50);
            }
            else if(cmp == 1){
                g[i].push_back(j + 50);
            }
        }
    }

    // for(int i = 0; i < N; i += 1){
    //     if(g[i].size() == 0) continue;
    //     cout << i << " : ";
    //     for(auto c : g[i]) cout << c << ' ';
    //     cout << '\n';
    // }

    memset(par, -1, sizeof(par));
    int res = 0;
    for(int i = 0; i < N; i += 1){
        for(int k = 0; k < 2; k += 1){
            memset(chk, -1, sizeof(chk));
            if(dfs(i)) res += 1;
        }
    }

    // for(int i = 50; i < 50 + N; i += 1){
    //     cout << i << " : " << par[i] << '\n';
    // }

    cout << N - res << '\n';

    return 0;
}