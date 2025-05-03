#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, K, idx = 1;
int bor[2003][2003], par[100005];
queue<pii> Q, QQ;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int find(int x){
    if(par[x] < 0) return x;
    return par[x] = find(par[x]);
}

bool merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return 0;
    if(u > v) swap(u, v);
    par[v] = u;
    return 1;
}

int bfs(){
    int year = 0, cnt = 0;
    while(1){
        while(!Q.empty()){
            auto [cx, cy] = Q.front(); Q.pop();
            QQ.push({cx, cy});
            for(int dir = 0; dir < 4; dir += 1){
                int nx = cx + dx[dir], ny = cy + dy[dir];
                if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
                if(bor[nx][ny] == 0) continue;

                if(merge(bor[nx][ny], bor[cx][cy])){
                    cnt += 1;
                }
            }
        }

        if(cnt == K - 1){
            return year;
        }
        
        while(!QQ.empty()){
            auto [cx, cy] = QQ.front(); QQ.pop();
            for(int dir = 0; dir < 4; dir += 1){
                int nx = cx + dx[dir], ny = cy + dy[dir];
                if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
                if(bor[nx][ny]) continue;
                bor[nx][ny] = bor[cx][cy];
                Q.push({nx, ny});
            }
        }

        year += 1;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(par, -1, sizeof(par));

    cin >> N >> K;
    for(int i = 0; i < K; i += 1){
        int a, b; cin >> a >> b;
        bor[a][b] = idx++;
        Q.push({a, b});
    }

    cout << bfs() << '\n';

    return 0;
}