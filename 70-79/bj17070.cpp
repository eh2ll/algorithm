#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, bor[20][20], dis[20][20][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= N; j += 1){
            cin >> bor[i][j];
        }
    }

    dis[1][2][0] = 1;
    for(int cx = 1; cx <= N; cx += 1){
        for(int cy = 1; cy <= N; cy += 1){
            int nx1 = cx + 1;
            int ny1 = cy;
            int nx2 = cx + 1;
            int ny2 = cy + 1;
            int nx3 = cx;
            int ny3 = cy + 1;

            if(nx1 <= N && ny1 <= N && bor[nx1][ny1] == 0){
                dis[nx1][ny1][1] += dis[cx][cy][1];
                dis[nx1][ny1][1] += dis[cx][cy][2];
            }
            if(nx3 <= N && ny3 <= N && bor[nx3][ny3] == 0){
                dis[nx3][ny3][0] += dis[cx][cy][0];
                dis[nx3][ny3][0] += dis[cx][cy][2];
            }
            if(nx1 <= N && nx2 <= N && nx3 <= N && ny1 <= N && ny2 <= N && ny3 <= N && bor[nx1][ny1] == 0 && bor[nx2][ny2] == 0 && bor[nx3][ny3] == 0){
                dis[nx2][ny2][2] += dis[cx][cy][0];
                dis[nx2][ny2][2] += dis[cx][cy][1];
                dis[nx2][ny2][2] += dis[cx][cy][2];
            }
        }
    }

    cout << dis[N][N][0] + dis[N][N][1] + dis[N][N][2] << '\n';

    return 0;
}