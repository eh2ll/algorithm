#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using ll = long long;

int N;
vector<pair<int, int>> A, B, C;
vector<tuple<int, int, int>> E;
int par[100003];

int find(int x){
    if(par[x] < 0) return x;
    return par[x] = find(par[x]);   
}

int merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return 0;
    if(u > v) swap(u, v);
    par[v] = u;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        int a, b, c; cin >> a >> b >> c;
        A.push_back({a, i});
        B.push_back({b ,i});
        C.push_back({c, i});
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    for(int i = 1; i < N; i += 1){
        E.push_back({A[i].X - A[i - 1].X, A[i - 1].Y, A[i].Y});
        E.push_back({B[i].X - B[i - 1].X, B[i - 1].Y, B[i].Y});
        E.push_back({C[i].X - C[i - 1].X, C[i - 1].Y, C[i].Y});
    }
    
    sort(E.begin(), E.end());
    memset(par, -1, sizeof(par));

    ll res = 0;
    for(int i = 0; i < E.size(); i += 1){
        auto [cost, a, b] = E[i];
        if(merge(a, b)){
            res += cost;
        }
    }

    cout << res << '\n';

    return 0;
}