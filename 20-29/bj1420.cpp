// kks227, justicehui

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int inf = 0x3f3f3f3f;
int N, M, S, E;
string bor[102];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
vector<int> adj[20004];
map<pii, int> c, f;
int par[20004];

void addEdge(int u, int v, int cost){
    c[{u, v}] = cost;
    c[{v, u}] = 0;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int runflow(){
    int ret = 0;
    while(1){
        memset(par, -1, sizeof(par));
        queue<int> Q;
        Q.push(S);
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(auto nxt : adj[cur]){
                if(par[nxt] == -1 && c[{cur, nxt}] - f[{cur, nxt}] > 0){
                    Q.push(nxt);
                    par[nxt] = cur;
                }
            }
        }
        if(par[E] == -1) break;
        for(int i = E; i != S; i = par[i]){
            f[{par[i], i}] += 1;
            f[{i, par[i]}] -= 1;
        }
        ret += 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i += 1){
        cin >> bor[i];
        for(int j = 0; j < M; j += 1){
            if(bor[i][j] == 'K') S = 2 * (i * M + j) + 1;
            else if(bor[i][j] == 'H') E = 2 * (i * M + j);
        }
    }

    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < M; j += 1){
            if(bor[i][j] == '#') continue;
            if(bor[i][j] == 'H'){
                for(int dir = 0; dir < 4; dir += 1){
                    int nx = i + dx[dir], ny = j + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                    if(bor[nx][ny] == 'K'){
                        cout << -1 << '\n';
                        return 0;
                    }
                }
            }

            int c1 = 2 * (i * M + j), c2 = c1 + 1;
            addEdge(c1, c2, 1);

            for(int dir = 0; dir < 4; dir += 1){
                int nx = i + dx[dir], ny = j + dy[dir];
                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if(bor[nx][ny] == '#') continue;
                int nxt =  2 * (nx * M + ny);
                addEdge(c2, nxt, inf);
                addEdge(nxt + 1, c1, inf);
            }
        }
    }

    cout << runflow() << '\n';

    return 0;
}