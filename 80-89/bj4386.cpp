// justicehui union find

#include <bits/stdc++.h>

using namespace std;
using ld = long double;

int N;
vector<pair<ld, ld>> inp;
vector<int> p(105, -1);
vector<tuple<ld, int, int>> edge;

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool isdiff(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        ld a, b; cin >> a >> b;
        for(int j = 0; j < i; j += 1){
            auto [x, y] = inp[j];
            ld cost = sqrt(pow(x - a, 2) + pow(y - b, 2));
            edge.push_back({cost, i, j});
        }
        inp.push_back({a, b});
    }
    sort(edge.begin(), edge.end());

    int cnt = 0;
    ld ans = 0;
    int e = edge.size();
    for(int i = 0; i < e; i += 1){
        auto [cost, a, b] = edge[i];
        if(!isdiff(a, b)) continue;
        ans += cost;
        cnt += 1;
        if(cnt == N - 1) break;
    }

    cout << ans << '\n';

    return 0;
}