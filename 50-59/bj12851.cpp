#include <bits/stdc++.h>

using namespace std;

int N, M, dis[100005], vis[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    fill(dis, dis + 100001, -1);
    dis[N] = 0;
    vis[N] = 1;

    queue<int> Q;
    Q.push(N);
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();

        for(auto nxt : {cur - 1, cur + 1, cur * 2}){
            if(nxt < 0 || nxt > 100000) continue;

            if(dis[nxt] != -1){
                if(dis[nxt] == dis[cur] + 1) vis[nxt] += vis[cur];
            }
            else{
                dis[nxt] = dis[cur] + 1;
                vis[nxt] = vis[cur];
                Q.push(nxt);
            }
        }
    }

    cout << dis[M] << '\n' << vis[M] << '\n';

    return 0;
}