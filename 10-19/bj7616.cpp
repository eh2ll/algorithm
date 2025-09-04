// flow with struct. kks227, justicehui
#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int to, cap, dual;
    Edge(int t, int c, int d) : to(t), cap(c), dual(d) {}
    Edge() {}
};

// st와 en을 잡을 때는, 정점 분할하고 /2를 했을 때 분할된 것들이 같아야 함... 
const int st = 1 * 2 + 1, en = 2 * 2;
vector<Edge> g[10'004];
int N, K, cases = 1;
int par[10'004], path[10'004];

void addEdge(int u, int v, int cap){
    // 아직 v에 역방향 간선 추가 안됐으니 g[v].size()가 인덱스이고, g[u]는 추가됐으니 ~
    g[u].emplace_back(v, cap, g[v].size());
    g[v].emplace_back(u, 0, g[u].size() - 1);
}

bool flow(){
    int cnt = 0;
    while(1){
        memset(par, -1, sizeof(par));
        memset(path, 0, sizeof(path));
        queue<int> Q;
        Q.push(st);
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(int idx = 0; idx < g[cur].size(); idx += 1){
                auto [nxt, cap, dual] = g[cur][idx];
                if(par[nxt] == -1 && cap > 0){
                    par[nxt] = cur;
                    path[nxt] = idx;
                    Q.push(nxt);
                    if(nxt == en) break;
                }
            }
        }
        if(par[en] == -1) break;

        int cost = 1;
        for(int i = en; i != st; i = par[i]){
            g[par[i]][path[i]].cap -= cost;
            g[i][g[par[i]][path[i]].dual].cap += cost;
        }

        cnt += 1;
        if(cnt == K) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        for(int i = 0; i < 10'004; i += 1) g[i].clear();

        cin >> K >> N;
        if(N == 0 && K == 0) break;

        for(int i = 1; i <= N; i += 1){
            addEdge(i * 2, i * 2 + 1, 1);
            while(1){
                int j; cin >> j;
                addEdge(i * 2 + 1, j * 2, 1);
                if(cin.get() == '\n') break;
            }
        }

        cout << "Case " << cases++ << ":\n";
        if(flow()){
            while(K--){
                int cur = st;
                while(cur / 2 != en / 2){
                    if(cur % 2 == 0){
                        cur = cur + 1;
                        continue;
                    }
                    cout << cur / 2 << ' ';
                    for(auto &[nxt, cap, dual] : g[cur]){
                        if((nxt / 2 == cur / 2)) continue;
                        if(cap == 0){
                            cap = 1;
                            cur = nxt;
                            break;
                        }
                    }
                }
                cout << 2 << '\n';
            }
        }
        else{
            cout << "Impossible" << '\n';
        }

        cout << '\n';
    }

    return 0;
}