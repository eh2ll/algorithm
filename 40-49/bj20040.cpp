#include <bits/stdc++.h>

using namespace std;

int N, M;
int par[500005];

void init(){
    memset(par, -1, sizeof(par));
    return;
}

int find(int x){
    if(par[x] < 0) return x;
    return par[x] = find(par[x]);
}

bool isdiff(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return 0;
    par[v] = u;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    init();
    for(int i = 1; i <= M; i += 1){
        int a, b; cin >> a >> b;
        if(!isdiff(a, b)){
            cout << i << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
    return 0;
}