#include <bits/stdc++.h>

using namespace std;

int N, M, T, bor[55][55], p1, p2;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void bfs(){
    int tmp[55][55];
    memset(tmp, 0, sizeof(tmp));

    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= M; j += 1){
            if(!bor[i][j]) continue;

            tmp[i][j] += bor[i][j];
            for(int dir = 0; dir < 4; dir += 1){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
                if((nx == p1 && ny == 1) || (nx == p2 && ny == 1)) continue;

                tmp[nx][ny] += bor[i][j] / 5;
                tmp[i][j] -= bor[i][j] / 5;
            }
        }
    }

    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= M; j += 1){
            bor[i][j] = tmp[i][j];
        }
    }

    return;
}

void up_cir(int r, int c){
    bor[r - 1][c] = 0;
    for(int i = r - 2; i >= 1; i -= 1){
        bor[i + 1][1] = bor[i][1];
    }

    for(int j = 2; j <= M; j += 1){
        bor[1][j - 1] = bor[1][j];
    }

    for(int i = 2; i <= r; i += 1){
        bor[i - 1][M] = bor[i][M];
    }

    for(int j = M - 1; j >= 2; j -= 1){
        bor[r][j + 1] = bor[r][j];
    }
    bor[r][c + 1] = 0;
}

void lo_cir(int r, int c){
    bor[r + 1][c] = 0;
    for(int i = r + 2; i <= N; i += 1){
        bor[i - 1][1] = bor[i][1];
    }

    for(int j = 2; j <= M; j += 1){
        bor[N][j - 1] = bor[N][j];
    }

    for(int i = N - 1; i >= r; i -= 1){
        bor[i + 1][M] = bor[i][M];
    }

    for(int j = M - 1; j >= 2; j -= 1){
        bor[r][j + 1] = bor[r][j];
    }
    bor[r][c + 1] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= M; j += 1){
            cin >> bor[i][j];
            if(!p1 && bor[i][j] == -1) p1 = i;
            else if(p1 && bor[i][j] == -1) p2 = i;
        }
    }

    while(T--){
        bfs();
        up_cir(p1, 1);
        lo_cir(p2, 1);
    }

    int res = 0;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= M; j += 1){
            if(bor[i][j] == -1) continue;
            res += bor[i][j];
        }
    }

    cout << res << '\n';

    return 0;
}