#include <bits/stdc++.h>

using namespace std;
using tii = tuple<int, int, int>;

const int inf = 0x3f3f3f3f;
int N, M;
vector<tii> edge, toDel;
int p[202], bor[202][202];

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return 0;
    if(u > v) swap(u, v);
    p[v] = u;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i += 1) fill(bor[i], bor[i] + 202, inf);
    for(int i = 1; i <= N; i += 1) bor[i][i] = 0;
    for(int i = 0; i < M; i += 1){
        int a, b, cost; cin >> a >> b >> cost;
        edge.push_back({cost, a, b});
        bor[a][b] = min(bor[a][b], cost);
        bor[b][a] = min(bor[b][a], cost);
    }
    
    // sort(edge.begin(), edge.end());
    // memset(p, -1, sizeof(p));
    // for(int i = 1; i <= N; i += 1) fill(bor[i], bor[i] + 202, inf);
    // for(int i = 1; i <= N; i += 1) bor[i][i] = 0;
    // int cntn = 0;
    // for(auto [cost, a, b] : edge){
    //     if(a == b) continue;
    //     if(merge(a, b)){
    //         bor[a][b] = bor[b][a] = cost;
    //         cntn += 1;
    //         toDel.push_back({cost, a, b});
    //     }
    //     if(cntn == N - 1) break;
    // }
    
    // for(auto [cost, a, b] : toDel){
    //     edge.erase(lower_bound(edge.begin(), edge.end(), tii{cost, a, b}));
    // }

    for(int k = 1; k <= N; k += 1){
        for(int i = 1; i <= N; i += 1){
            for(int j = 1; j <= N; j += 1){
                if(bor[i][j] > bor[i][k] + bor[k][j]){
                    bor[i][j] = bor[i][k] + bor[k][j];
                }
            }
        }
    }

    int mn = inf;
    for(int k = 1; k <= N; k += 1){
        int mx = 0;
        for(auto [cost, a, b] : edge){
            if(a == b) mx = max(mx, bor[k][a] * 2 + cost);
            else{
                mx = max(mx, bor[k][a] + bor[k][b] + cost);
            }
        }

        mn = min(mn, mx);
        // cout << k << "-" << mx << " : ";
        // for(int t = 1; t <= N; t += 1) cout << bor[k][t] << ' ';
        // cout << '\n';
    }

    cout.precision(1);
    cout << fixed;
    cout << mn / 2 << '.' << mn%2*5 << '\n';

    return 0;
}   