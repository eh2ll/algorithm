#include <bits/stdc++.h>

using namespace std;

const int inf = 4000001;
int N, M, K;
int arr[4000006], par[4000006];

void init(){
    for(int i = 0; i < inf + 1; i += 1){
        par[i] = i;
    }
}

int find(int x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

int merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return 0;
    if(u > v) swap(u, v);
    par[u] = v;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i = 0; i < M; i += 1){
        cin >> arr[i];
    }
    sort(arr, arr + M);
    arr[M] = inf;
    init();

    for(int i = 0; i < K; i += 1){
        int x; cin >> x;
        int idx = upper_bound(arr, arr + M + 1, x) - arr;
        cout << arr[find(idx)] << '\n';

        merge(find(idx), find(idx) + 1);
    }

    return 0;
}