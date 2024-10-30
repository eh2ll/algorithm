#include <bits/stdc++.h>

using namespace std;

int N, mx1, mx2;
int bor[11][11], whi[11][11], bla[11][11];
int xx[20], yy[20];

void sol1(int pos, int cnt){
    int cx = pos / N;
    int cy = pos % N;

    mx1 = max(mx1, cnt);

    // cout << cx << ' ' << cy << ' ' << cnt << '\n';

    xx[cx + cy] = 1;
    yy[cy - cx + 10] = 1;

    int j = 0;
    while(pos + j < N * N){
        j += 1;
        int nx = (pos + j) / N, ny = (pos + j) % N;
        if(!whi[nx][ny] || (nx + ny) % 2 == 1) continue;
        if(xx[nx + ny] || yy[ny - nx + 10]) continue;
        
        xx[nx + ny] = 1;
        yy[ny - nx + 10] = 1;
        sol1(pos + j, cnt + 1);
        xx[nx + ny] = 0;
        yy[ny - nx + 10] = 0;
    }

    xx[cx + cy] = 0;
    yy[cy - cx + 10] = 0;
}

void sol2(int pos, int cnt){
    int cx = pos / N;
    int cy = pos % N;

    mx2 = max(mx2, cnt);

    // cout << cx << ' ' << cy << ' ' << cnt << '\n';

    xx[cx + cy] = 1;
    yy[cy - cx + 10] = 1;

    int j = 0;
    while(pos + j < N * N){
        j += 1;
        int nx = (pos + j) / N, ny = (pos + j) % N;
        if(!bla[nx][ny] || (nx + ny) % 2 == 0) continue;
        if(xx[nx + ny] || yy[ny - nx + 10]) continue;
        
        xx[nx + ny] = 1;
        yy[ny - nx + 10] = 1;
        sol2(pos + j, cnt + 1);
        xx[nx + ny] = 0;
        yy[ny - nx + 10] = 0;
    }

    xx[cx + cy] = 0;
    yy[cy - cx + 10] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < N; j += 1){
            cin >> bor[i][j];
            if(bor[i][j] && (i + j) % 2 == 0) whi[i][j] = 1;
            else if(bor[i][j] && (i + j) % 2 == 1) bla[i][j] = 1;
        }
    }

    for(int pos = 0; pos < N * N; pos += 1){
        int x = pos / N, y = pos % N;
        if(!whi[x][y] || (x + y) % 2 == 1) continue;
        // cout << x << ' ' << y << '\n';
        sol1(pos, 1);
    }
    // cout << "______\n";
    for(int pos = 0; pos < N * N; pos += 1){
        int x = pos / N, y = pos % N;
        if(!bla[x][y] || (x + y) % 2 == 0) continue;
        // cout << x << ' ' << y << '\n';
        sol2(pos, 1);
    }

    cout << mx1 + mx2 << '\n';

    return 0;
}