#include <bits/stdc++.h>
#define X first
#define Y second
#define inf 0x3f3f3f3f

using namespace std;
using ll = long long;
using tii = tuple<int, int, int>;

int TC, N, M, W;
ll d[502];
vector<tii> adj;

bool bellman(int n){
    memset(d, inf, sizeof(d));
    d[1] = 0;
    for(int i = 0; i < N; i += 1){
        bool flag = 0;
        for(auto &[s, e, t] : adj){
            if(d[s] == inf) continue;
            if(d[e] > d[s] + t){
                d[e] = d[s] + t;
                flag = 1;
            }
        }
        if(flag && i == N - 1){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    while(TC--){
        adj.clear();
    
        cin >> N >> M >> W;    

        for(int i = 0; i < M; i += 1){
            int S, E, T; cin >> S >> E >> T;
            adj.push_back({S, E, T});
            adj.push_back({E, S, T});
        }
        for(int i = 0; i < W; i += 1){
            int S, E, T; cin >> S >> E >> T;
            adj.push_back({S, E, -T});
        }

        if(!bellman(N)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}