#include <bits/stdc++.h>

using namespace std;

int G, P;
int par[100005];

void init(){
    for(int i = 1; i <= G; i += 1){
        par[i] = i;
    }
}

int find(int x){
    if(par[x] == x) return par[x];

    return par[x] = find(par[x]);
}

void merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;

    if(u > v) swap(u, v);
    par[v] = u;

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> G >> P;
    
    init();
    int cnt = 0;

    for(int i = 0; i < P; i += 1){
        int x; cin >> x;
        if(find(x) - 1 < 0) break;
        merge(find(x), find(x) - 1);
        cnt += 1;
    }

    cout << cnt << '\n';

    return 0;
}