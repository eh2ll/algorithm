#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using pii = pair<ld, ld>;

int N, M, S, V;
vector<int> g[102], chk, par;

int match(int cur){
    for(auto nxt : g[cur]){
        if(chk[nxt]) continue;
        chk[nxt] = 1;
        if(par[nxt] == -1 || match(par[nxt])){
            par[nxt] = cur;
            return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> S >> V;
    vector<pii> A(N), B(M);
    for(int i = 0; i < N; i += 1){
        cin >> A[i].first >> A[i].second;
    }
    for(int i = 0; i < M; i += 1){
        cin >> B[i].first >> B[i].second;
        for(int j = 0; j < N; j += 1){
            ld dist = sqrt(pow(A[j].first - B[i].first, 2) + pow(A[j].second - B[i].second, 2));
            if(dist <= S * V){
                g[j].push_back(i);
            }
        }
    }

    par.assign(M, -1);
    int cnt = 0;
    for(int i = 0; i < N; i += 1){
        chk.assign(M, 0);
        if(match(i)) cnt += 1;
    }

    cout << N - cnt << '\n';

    return 0;
}