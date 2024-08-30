#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int N, D;
vector<pii> V;

bool compare(pii& a, pii& b){
    if(a.Y == b.Y) return a.X < b.X;
    else return a.Y < b.Y;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        int x, y; cin >> x >> y;
        if(x < y) V.push_back({x, y});
        else V.push_back({y, x});
    }
    cin >> D;

    sort(V.begin(), V.end(), compare);

    int res = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < V.size(); i += 1){
        int cnt = 0;
        auto cur = V[i];
        
        if(cur.Y <= cur.X + D) pq.push(cur.X);
        else continue;

        while(!pq.empty()){
            auto pre = pq.top();
            // cout << cur.X << ' ' << cur.Y << ' ' << pre << '\n';
            if(pre >= cur.Y - D) break;
            else pq.pop();
        }
        res = max(res, (int)pq.size());
    }

    cout << res << '\n';

    return 0;
}