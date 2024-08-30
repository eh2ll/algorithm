#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, K, vis[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    memset(vis, -1, sizeof(vis));
    queue<pii> Q;
    vis[N] = 0;
    Q.push({N, 0});
    while(!Q.empty()){
        auto [cur, cost] = Q.front(); Q.pop();
        if(cur == K){
            cout << cost << '\n';
            while(!Q.empty()) Q.pop();
            break;
        }
        if(cur - 1 >= 0 && vis[cur - 1] == -1){
            vis[cur - 1] = cur;
            Q.push({cur - 1, cost + 1});
        }
        if(cur + 1 <= 100000 && vis[cur + 1] == -1){
            vis[cur + 1] = cur;
            Q.push({cur + 1, cost + 1});
        }
        if(cur * 2 <= 100000 && vis[cur * 2] == -1){
            vis[cur * 2] = cur;
            Q.push({cur * 2, cost + 1});
        }
    }

    vector<int> V;
    V.push_back(K);

    int tmp = K;
    while(tmp != N){
        V.push_back(vis[tmp]);
        tmp = vis[tmp];
    }

    reverse(V.begin(), V.end());
    for(auto c : V) cout << c << ' ';
    cout << '\n';
    
    return 0;
}