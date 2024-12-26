#include <bits/stdc++.h>

using namespace std;

int N, M;
long long K;
int arr[1000006], par[1000006];

int find(int x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

int merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return 0;
    if(arr[u] > arr[v]) swap(u, v);
    par[v] = u;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    iota(par + 1, par + 1000006, 1);

    cin >> N >> M >> K;
    for(int i = 1; i <= N; i += 1){
        cin >> arr[i];
    }
    
    set<pair<int, int>> Sp;
    for(int i = 0; i < N; i += 1){
        int x = (i % N) + 1;
        int y = ((i + 1) % N) + 1;
        if(x > y) swap(x, y);
        Sp.insert({x, y});
    }
    
    for(int i = 0; i < M; i += 1){
        int u, v; cin >> u >> v;
        if(u > v) swap(u, v);
        Sp.erase({u, v});
    }
    
    for(auto [x, y] : Sp){
        merge(x, y);
    }

    set<int> S;
    for(int i = 1; i <= N; i += 1){
        S.insert(find(par[i]));
    }

    long long cnt = 0;
    for(auto c : S){
        cnt += arr[c];
    }

    if(cnt <= K || S.size() <= 1) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}