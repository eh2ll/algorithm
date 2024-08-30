#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int N, M, K;
vector<pii> adj[1003];
priority_queue<int> d[1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i = 0; i < M; i += 1){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[1].push(0);
    pq.push({d[1].top(), 1});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        
        for(auto nxt : adj[cur.Y]){
            if(d[nxt.Y].size() < K){
                d[nxt.Y].push(nxt.X + cur.X);
                pq.push({nxt.X + cur.X, nxt.Y});
            }
            else if(d[nxt.Y].top() > nxt.X + cur.X){
                d[nxt.Y].push(nxt.X + cur.X);
                d[nxt.Y].pop();
                pq.push({nxt.X + cur.X, nxt.Y});
            }
        }
    }

    for(int i = 1; i <= N; i += 1){
        if(d[i].size() < K) cout << "-1\n";
        else cout << d[i].top() << '\n';
    }

    return 0;
}