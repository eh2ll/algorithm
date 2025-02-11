#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using tii = tuple<long double, int, int>;

int N, M;
pii bor[1003];
vector<tii> edge;
int par[1003];

int find(int x){
    if(par[x] < 0) return x;
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

    cin >> N >> M;
    for(int i = 1; i <= N; i += 1){
        int a, b; cin >> a >> b;
        bor[i] = {a, b};
        for(int j = 1; j < i; j += 1){
            auto [x, y] = bor[j];
            long double dis = sqrt(pow(x - a, 2) + pow(y - b, 2));
            edge.push_back({dis, i, j});
        }
    }
    sort(edge.begin(), edge.end());

    memset(par, -1, sizeof(par));

    for(int i = 1; i <= M; i += 1){
        int a, b; cin >> a >> b;
        merge(a, b);
    }

    long double cnt = 0;
    for(auto [cost, u, v] : edge){
        if(merge(u, v)){
            cnt += cost;
        }
    }

    cout.precision(2);
    cout << fixed;
    cout << cnt << '\n';

    return 0;
}