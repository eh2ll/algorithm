#include <bits/stdc++.h>

using namespace std;

int N, M, vis[602][602];
string bor[602];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    pair<int, int> st;
    for(int i = 0; i < N; i += 1){
        cin >> bor[i];
        for(int j = 0; j < M; j += 1){
            if(bor[i][j] == 'I') st = {i, j};
        }
    }

    queue<pair<int, int>> Q;
    Q.push(st);
    vis[st.first][st.second] = 1;

    int tot = 0;
    while(!Q.empty()){
        auto [cx, cy] = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir += 1){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(bor[nx][ny] == 'X' || vis[nx][ny]) continue;

            if(bor[nx][ny] == 'P'){
                tot += 1;
            }

            Q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }

    if(tot) cout << tot << '\n';
    else cout << "TT\n";

    return 0;

}