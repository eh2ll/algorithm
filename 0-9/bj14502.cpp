#include <bits/stdc++.h>

using namespace std;

int N, M;
int bor[10][10], arr[10][10], vis[10][10];
vector<pair<int, int>> V;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void prcnt(){
    cout << '\n';
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < M; j += 1){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    return;
}

int cnt(){
    int ret = 0;
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < M; j += 1){
            if(!arr[i][j]) ret += 1; 
        }
    }
    return ret;
}

void cpy(){
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < M; j += 1){
            arr[i][j] = bor[i][j];
        }
    }
}

void bfs(){
    cpy();
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> Q;
    for(auto [x, y] : V){
        vis[x][y] = 1;
        Q.push({x, y});
    }

    while(!Q.empty()){
        auto [cx, cy] = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir += 1){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(arr[nx][ny] == 1 || vis[nx][ny] == 1) continue;
            arr[nx][ny] = 2;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < M; j += 1){
            cin >> bor[i][j];
            if(bor[i][j] == 2) V.push_back({i, j});
        }
    }

    int res = 0;
    for(int p1 = 0; p1 < N * M; p1 += 1){
        if(bor[p1 / M][p1 % M] != 0) continue;
        bor[p1 / M][p1 % M] = 1;
        for(int p2 = p1 + 1; p2 < N * M; p2 += 1){
            if(bor[p2 / M][p2 % M] != 0) continue;
            bor[p2 / M][p2 % M] = 1;
            for(int p3 = p2 + 1; p3 < N * M; p3 += 1){
                if(bor[p3 / M][p3 % M] != 0) continue;
                bor[p3 / M][p3 % M] = 1;
                bfs();

                // cout << p1 / M << ' ' << p1 % M << ' ';
                // cout << p2 / M << ' ' << p2 % M << ' ';
                // cout << p3 / M << ' ' << p3 % M << " | ";
                // cout << cnt() << '\n';
                // if(res < cnt()) prcnt();

                res = max(res, cnt());
                bor[p3 / M][p3 % M] = 0;
            }
            bor[p2 / M][p2 % M] = 0;
        }
        bor[p1 / M][p1 % M] = 0;
    }

    cout << res << '\n';

    return 0;
}