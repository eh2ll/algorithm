#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int a, b, c, d;
map<pii, int> vis;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c >> d;
    
    int res = 1e9;

    queue<pii> Q;
    Q.push({0, 0});
    vis[{0, 0}] = 1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(cur.X == c && cur.Y == d){
            res = min(res, vis[cur]);
            break;
        }

        if(!vis[{a, cur.Y}]){
            vis[{a, cur.Y}] = vis[cur] + 1;
            Q.push({a, cur.Y});
        }
        
        if(!vis[{cur.X, b}]){
            vis[{cur.X, b}] = vis[cur] + 1;
            Q.push({cur.X, b});
        }

        if(!vis[{0, cur.Y}]){
            vis[{0, cur.Y}] = vis[cur] + 1;
            Q.push({0, cur.Y});
        }

        if(!vis[{cur.X, 0}]){
            vis[{cur.X, 0}] = vis[cur] + 1;
            Q.push({cur.X, 0});
        }

        pii nxt = {0, 0};
        if(cur.X + cur.Y >= b) nxt = {cur.X + cur.Y - b, b};
        else nxt = {0, cur.X + cur.Y};
        if(!vis[nxt]){
            vis[nxt] = vis[cur] + 1;
            Q.push(nxt);
        }

        if(cur.X + cur.Y >= a) nxt = {a, cur.X + cur.Y - a};
        else nxt = {cur.X + cur.Y, 0};
        if(!vis[nxt]){
            vis[nxt] = vis[cur] + 1;
            Q.push(nxt);
        }
    }

    if(res == 1e9) cout << "-1\n";
    else cout << res - 1 << '\n';

    return 0;

}