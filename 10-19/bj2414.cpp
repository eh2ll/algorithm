#include <bits/stdc++.h>

using namespace std;

int N, M;
string bor[51];
int rr[51][51], cc[51][51];
vector<int> g[2'000];
int par[2'000], chk[2'000];


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
    int rs = 1, cs = 1;
    for(int i = 0; i < N; i += 1){
        cin >> bor[i];
        for(int j = 0; j < M; j += 1){
            if(bor[i][j] == '*'){
                rr[i][j] = rs;
                if(j == M - 1 || bor[i][j + 1] == '.') rs += 1;
            }
        }
    }
    for(int j = 0; j < M; j += 1){
        for(int i = 0; i < N; i += 1){
            if(bor[i][j] == '*'){
                cc[i][j] = cs;
                if(i == N - 1 || bor[i + 1][j] == '.') cs += 1;
            }
        }
    }

    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < M; j += 1){
            if(bor[i][j] == '*'){
                g[rr[i][j]].push_back(cc[i][j]);
            }
        }
    }

    memset(par, -1, sizeof(par));
    int cnt = 0;
    for(int i = 1; i < rs; i += 1){
        memset(chk, 0, sizeof(chk));
        if(match(i)) cnt += 1;
    }

    cout << cnt << '\n';

    return 0;
}