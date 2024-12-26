#include <bits/stdc++.h>

using namespace std;

int N, cnt;
string bor[102];
string inp = "MOBIS";
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int x, int y, int lev, int d){
    // cout << x << ' ' << y << '\n';
    if(bor[x][y] != inp[lev]) return;
    if(lev == 4){
        cnt += 1;
        return;
    }

    int nx = x + dx[d];
    int ny = y + dy[d];
    if(nx < 0 || ny < 0 || nx >= N || ny >= N) return;
    dfs(nx, ny, lev + 1, d);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> bor[i];
    }

    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < N; j += 1){
            if(bor[i][j] != 'M') continue;
            for(int k = 0; k < 8; k += 1){
                dfs(i, j, 0, k);
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}