#include <bits/stdc++.h>

using namespace std;

int N, res;
int par[52];
vector<tuple<int, int, int>> edge;

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

    memset(par, -1, sizeof(par));

    cin >> N;
    for(int i = 0; i < N; i += 1){
        string s; cin >> s;
        for(int j = 0; j < N; j += 1){
            if('a' <= s[j] && s[j] <= 'z'){
                if(i != j) edge.push_back({s[j] - 'a' + 1, i, j});
                res += s[j] - 'a' + 1;
            }
            else if('A' <= s[j] && s[j] <= 'Z'){
                if(i != j) edge.push_back({s[j] - 'A' + 27, i, j});
                res += s[j] - 'A' + 27;
            }
        }
    }

    sort(edge.begin(), edge.end());

    int cnt = 1;
    for(auto [cost, u, v] : edge){
        if(merge(u, v)){
            res -= cost;
            cnt += 1;
        }

        if(cnt == N) break;
    }

    if(cnt == N) cout << res << '\n';
    else cout << -1 << '\n';

    return 0;
}