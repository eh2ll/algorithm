#include <bits/stdc++.h>

using namespace std;

int V, E;
int bor[3002];
int par[3002];

int find(int x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

bool merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return 0;
    if(u > v) swap(u, v);
    par[v] = u;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    iota(par, par + 3002, 0);

    cin >> V >> E;
    for(int i = 0; i < E; i += 1){
        int a, b; cin >> a >> b;
        bor[a] += 1;
        bor[b] += 1;
        merge(a, b);
    }

    int cnt = 0;
    for(int i = 1; i <= V; i += 1){
        if(bor[i] & 1) cnt += 1;
    }

    bool flag = 1;
    for(int i = 2; i <= V; i += 1){
        if(find(1) != find(i)) flag = 0;
    }
    if(!(cnt == 0 || cnt == 2)) flag = 0;

    if(flag) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}