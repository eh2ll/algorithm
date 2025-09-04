#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<string> A;
vector<vector<int>> B;
vector<int> g[8080];
vector<int> chk, par;
int dx[6] = {1, 1, 0, 0, -1, -1};
int dy[6] = {-1, 1, -1, 1, -1, 1};

int pos(int i, int j){
    return i * M + j;
}

int match(int cur){
    for(int nxt : g[cur]){
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

    int tc; cin >> tc;
    while(tc--){
        cin >> N >> M;
        A.resize(N);
        B.assign(N, vector<int>(M, 0));
        for(int i = 0; i < 8080; i += 1) g[i].clear();
        chk.assign(N * M, 0);
        par.assign(N * M, -1);
        int sum = 0;
        for(int i = 0; i < N; i += 1){
            cin >> A[i];
            for(int j = 0; j < M; j += 1){
                if(A[i][j] == '.'){
                    B[i][j] = 1;
                    sum += 1;
                }
            }
        }

        for(int i = 0; i < N; i += 1){
            for(int j = 0; j < M; j += 2){
                if(!B[i][j]) continue;
                for(int dir = 0; dir < 6; dir += 1){
                    int ni = i + dx[dir], nj = j + dy[dir];
                    if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
                    if(!B[ni][nj]) continue;
                    g[pos(i, j)].emplace_back(pos(ni, nj));
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < N; i += 1){
            for(int j = 0; j < M; j += 2){
                if(!B[i][j]) continue;
                chk.assign(N * M, 0);
                chk[pos(i, j)] = 1;
                if(match(pos(i, j))){
                    cnt += 1;
                }
            }
        }

        cout << sum - cnt << '\n';
    }

    return 0;
}