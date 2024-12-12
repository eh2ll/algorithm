#include <bits/stdc++.h>

using namespace std;
using tii = tuple<int, int, int>;

int K, W, H;
int bor[202][202], dis[202][202][31];
int dx1[4] = {1, 0, -1, 0}, dy1[4] = {0, 1, 0, -1};
int dx2[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dy2[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> W >> H;
    for(int i = 1; i <= H; i += 1){
        for(int j = 1; j <= W; j += 1){
            cin >> bor[i][j];
        }
    }

    memset(dis, -1, sizeof(dis));

    queue<tii> Q;
    Q.push({1, 1, 0});
    dis[1][1][0] = 0;
    while(!Q.empty()){
        auto [cx, cy, cost] = Q.front(); Q.pop();
        if(cx == H && cy == W) break;

        for(int dir = 0; dir < 4; dir += 1){
            int nx = cx + dx1[dir], ny = cy + dy1[dir];
            if(nx < 1 || ny < 1 || nx > H || ny > W) continue;
            if(bor[nx][ny] == 1 || dis[nx][ny][cost] != -1) continue;
            Q.push({nx, ny, cost});
            dis[nx][ny][cost] = dis[cx][cy][cost] + 1;
        }

        if(cost < K){
            for(int dir = 0; dir < 8; dir += 1){
                int nx = cx + dx2[dir], ny = cy + dy2[dir];
                if(nx < 1 || ny < 1 || nx > H || ny > W) continue;
                if(bor[nx][ny] == 1 || dis[nx][ny][cost + 1] != -1) continue;
                Q.push({nx, ny, cost + 1});
                dis[nx][ny][cost + 1] = dis[cx][cy][cost] + 1;
            }
        }
    }

    int mn = 0x3f3f3f3f;
    for(int i = 0; i <= K; i += 1){
        if(dis[H][W][i] == -1) continue;
        mn = min(mn, dis[H][W][i]);
    }

    if(mn == 0x3f3f3f3f) cout << -1 << '\n';
    else cout << mn << '\n';

    return 0;
}