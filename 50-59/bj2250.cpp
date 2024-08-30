#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int N, num = 1;
pair<int, int> adj[10004];
pair<int, int> lev[10004];

void dfs(int x, int h){
    if(adj[x].X > 0) dfs(adj[x].X, h + 1);
    lev[h] = {min(lev[h].X, num), max(lev[h].Y, num)};
    num += 1;
    if(adj[x].Y > 0) dfs(adj[x].Y, h + 1);

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 10004; i += 1) lev[i] = {10004, 0};

    cin >> N;
    int rt = N * (N + 1) / 2;
    for(int i = 0; i < N; i += 1){
        int a, b, c; cin >> a >> b >> c;
        adj[a] = {b, c};
        if(b > 0) rt -= b;
        if(c > 0) rt -= c;
    }
    dfs(rt, 1);
    
    int row = 0, col = 0;
    for(int i = 1; i < 10004; i += 1){
        if(lev[i].first == 10004) break;
        if(col < lev[i].second - lev[i].first + 1){
            row = i;
            col = lev[i].second - lev[i].first + 1;
        }
    }

    cout << row << ' ' << col << '\n';

    return 0;
}