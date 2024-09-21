#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

const int inf = 300001;
int N, M, K, X, d[300005];
vector<pii> adj[300005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K >> X;
    for(int i = 0; i < M; i += 1){
        int a, b; cin >> a >> b;
        adj[a].push_back({1, b});
    }

    fill(d, d + 300001, inf);
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    
    d[X] = 0;
    PQ.push({d[X], X});
    while(!PQ.empty()){
        auto cur = PQ.top(); PQ.pop();

        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            PQ.push({d[nxt.Y], nxt.Y});
        }
    }

    vector<int> V;
    for(int i = 1; i <= N; i += 1){
        if(d[i] == K) V.push_back(i);
    }

    if(V.empty()) cout << "-1\n";
    else{
        for(auto c : V) cout << c << '\n';
        cout << '\n';
    }

    return 0;
}