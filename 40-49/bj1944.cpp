#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int inf = 0x3f3f3f3f;
int N, M, idx;
string bor[51];
int vis[51][51], dis[256][256], par[256];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
vector<pii> st;
map<pii, int> mp;
int flag = 1;

void sol(pii start){
    queue<pii> Q;
    Q.push(start);
    memset(vis, -1, sizeof(vis));
    vis[start.first][start.second] = 0;
    
    while(!Q.empty()){
        auto [cx, cy] = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir += 1){
            int nx = cx + dx[dir], ny = cy + dy[dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(bor[nx][ny] == '1' || vis[nx][ny] >= 0) continue;
            Q.push({nx, ny});
            vis[nx][ny] = vis[cx][cy] + 1;
        }
    }

    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < N; j += 1){
            if(bor[i][j] == 'K' || bor[i][j] == 'S'){
                dis[mp[start]][mp[{i, j}]] = vis[i][j];
            }
        }
    }
}

int find(int x){
    if(par[x] < 0) return x;
    return par[x] = find(par[x]);
}

int merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return 0;
    if(u > v) swap(u, v);
    par[v] = u;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i += 1){
        cin >> bor[i];
        for(int j = 0; j < N; j += 1){
            if(bor[i][j] == 'K' || bor[i][j] == 'S'){
                mp[{i, j}] = idx++;
                st.push_back({i, j});
            }
        }
    }

    for(int i = 0; i < 256; i += 1) fill(dis[i], dis[i] + 256, inf);
    for(int i = 0; i < st.size(); i += 1){
        sol(st[i]);
    }

    vector<tuple<int, int, int>> edge;
    for(int i = 0; i < idx; i += 1){
        for(int j = 0; j < idx; j += 1){
            if(i == j) continue;
            edge.push_back({dis[i][j], i, j});
        }
    }

    sort(edge.begin(), edge.end());
    memset(par, -1, sizeof(par));
    int res = 0;
    for(auto [cost, u, v] : edge){
        if(cost == inf){
            // cout << cost << ' ' << u << ' ' << v << '\n';
            res = -1;
            break;
        }
        if(merge(u, v)){
            res += cost;
            // cout << cost << ' ' << u << ' ' << v << '\n';
        }
    }

    if(res < 0) cout << -1 << '\n';
    else cout << res << '\n';

    return 0;
}