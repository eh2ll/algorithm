#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[1003][1003], vis[1003][1003], adj[1000006], res[1003][1003];
int idx = 1, cnt = 0;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int idx){
    vis[x][y] = idx;
    cnt += 1;

    for(int dir = 0; dir < 4; dir += 1){
        int nx = x + dx[dir], ny = y + dy[dir];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if(arr[nx][ny] || vis[nx][ny]) continue;
        dfs(nx, ny, idx);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i += 1){
        string s; cin >> s;
        for(int j = 0; j < M; j += 1){
            arr[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < M; j += 1){
            if(arr[i][j] || vis[i][j]) continue;
            cnt = 0;
            dfs(i, j, idx);
            adj[idx++] = cnt;
        }
    }

    set<int> S;
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < M; j += 1){
            if(!arr[i][j]){
                cout << 0;
                continue;
            }
            for(int dir = 0; dir < 4; dir += 1){
                int nx = i + dx[dir], ny = j + dy[dir];
                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                S.insert(vis[nx][ny]);
            }

            int tmp = 0;
            for(auto c : S){
                tmp += adj[c];
            }
            cout << (tmp + 1) % 10;

            S.clear();
        }
        cout << '\n';
    }

    return 0;
}