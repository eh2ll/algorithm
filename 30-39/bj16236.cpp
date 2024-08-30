#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int N, sha, gro;
int arr[22][22], vis[22][22];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
pii st;

int sol(){
    memset(vis, 0, sizeof(vis));
    queue<pii> Q;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> PQ;
    int x = st.X;
    int y = st.Y;

    Q.push({x, y});
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir += 1){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(arr[nx][ny] > sha || vis[nx][ny]) continue;
            Q.push({nx, ny});
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;

            if(arr[nx][ny] < sha && arr[nx][ny] > 0){
                PQ.push({vis[nx][ny], {nx, ny}});
            }
        }
    }

    if(PQ.empty()) return -1;
    auto nxtT = PQ.top();
    int dis = nxtT.X;
    pii nxt = nxtT.Y;
    arr[nxt.X][nxt.Y] = 0;
    st = nxt;
    gro += 1;
    if(sha == gro){
        sha += 1;
        gro = 0;
    }

    return dis;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < N; j += 1){
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                st = {i, j};
                arr[i][j] = 0;
            }
        }
    }

    sha = 2;
    gro = 0;
    int tot = 0;
    while(1){
        int ret = sol();
        if(ret < 0) break;
        tot += ret;
        // cout << sha << ' ' << gro << '\n';
        // cout << st.X << ' ' << st.Y << ':' << ret << '\n';
    }

    cout << tot << '\n';

    return 0;
}