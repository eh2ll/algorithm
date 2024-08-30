#include <bits/stdc++.h>
using namespace std;

int N, M, R, sR, siz = 1, lev;
int arr[303][303], tmp[303][303], sav[1000];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void dfs1(int x, int y, int dis){
    if(sav[siz - 1]) return;
    
    sav[dis] = arr[x][y];
    tmp[x][y] = -1;
    // cout << x << ' ' << y << ' ' << dis << ' ' << sav[dis] << '\n';
    
    
    for(int dir = 0; dir < 4; dir += 1){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
        if(nx != 1 + lev && nx != N - lev && ny != 1 + lev && ny != M - lev) continue;
        if(tmp[nx][ny] != 0) continue;
        // cout << x << ' ' << y << ' ' << nx << ' ' << ny << '\n';
        dfs1(nx, ny, dis + 1);
    }
}

void dfs2(int x, int y, int dis){
    if(!sav[(siz - sR - 1) % siz]) return;
    
    tmp[x][y] = sav[(dis + siz - sR) % siz];
    sav[(dis + siz - sR) % siz] = 0;    
    // cout << x << ' ' << y << ' ' << tmp[x][y] << ' ' << (dis + siz - sR) % siz << '\n';
    for(int dir = 0; dir < 4; dir += 1){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
        if(nx != 1 + lev && nx != N - lev && ny != 1 + lev && ny != M - lev) continue;
        if(tmp[nx][ny] > 0) continue;
        dfs2(nx, ny, dis + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> R;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= M; j += 1){
            cin >> arr[i][j];
        }
    }

    int row = N, col = M;
    for(int k = 1; k <= min(N / 2, M / 2); k += 1){
        siz = 2 * (row - 1 + col - 1);
        sR = R % siz;
        // cout << "siz sR row col " << siz << ' ' << sR << ' ' << row << ' ' << col << '\n';
        row -= 2;
        col -= 2;

        memset(sav, 0, sizeof(sav));
        dfs1(k, k, 0);
        // for(int t = 0; t < siz + 2; t += 1) cout << sav[t] << ' ';
        // cout << '\n';
        dfs2(k, k, 0);
        // for(int t = 0; t < siz + 2; t += 1) cout << sav[t] << ' ';
        // cout << '\n';

        lev += 1;
    }

    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= M; j += 1){
            cout << tmp[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}