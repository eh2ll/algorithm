#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int arr[1003][1003], vis[1003][1003];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int sol(int x){
    memset(vis, 0, sizeof(vis));

    queue<pair<int, int>> Q;
    int ret = 0;

    for(int i = 0; i < N; i += 1){
        if(arr[i][0] <= x){
            Q.push({i, 0});
            vis[i][0] = 1;
            ret += 1;
        }
        if(arr[i][M - 1] <= x){
            Q.push({i, M - 1});
            vis[i][M - 1] = 1;
            ret += 1;
        }
    }
    for(int i = 1; i < M - 1; i += 1){
        if(arr[0][i] <= x){
            Q.push({0, i});
            vis[0][i] = 1;
            ret += 1;
        }
    }

    while(!Q.empty()){
        auto [cx, cy] = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir += 1){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(vis[nx][ny] || arr[nx][ny] > x) continue;

            Q.push({nx, ny});
            vis[nx][ny] = 1;
            ret += 1;
        }
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < M; j += 1){
            cin >> arr[i][j];
        }
    }

    int st = 0, en = 1000006;
    while(st + 1 < en){
        int mid = (st + en + 1) / 2;
        // cout << st << ": " << sol(st) << " " << mid << ": " << sol(mid) << ' ' << en << ": " << sol(en) << '\n';
        if(sol(mid) >= K) en = mid;
        else st = mid;
    }

    cout << en << '\n';

    return 0;
}