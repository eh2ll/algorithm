#include <bits/stdc++.h>

using namespace std;

int bor[51][51], vis[51][51];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        int N, M; cin >> N >> M;
        swap(N, M);
        if(N == 0 && M == 0) return 0;
        
        memset(bor, 0, sizeof(bor));
        memset(vis, 0, sizeof(vis));
        
        for(int i = 0; i < N; i += 1){
            for(int j = 0; j < M; j += 1){
                cin >> bor[i][j];
            }
        }

        int cnt = 0;
        for(int i = 0; i < N; i += 1){
            for(int j = 0; j < M; j += 1){
                if(!bor[i][j] || vis[i][j]) continue;
                vis[i][j] = 1;
                cnt += 1;
                queue<pair<int, int>> Q;
                Q.push({i, j});
                while(!Q.empty()){
                    auto [cx, cy] = Q.front(); Q.pop();
                    for(int dir = 0; dir < 8; dir += 1){
                        int nx = cx + dx[dir], ny = cy + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                        if(!bor[nx][ny] || vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}