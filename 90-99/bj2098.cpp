#include <bits/stdc++.h>

using namespace std;

int N;
int bor[20][20], dis[20][(1 << 16)];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < N; j += 1){
            cin >> bor[i][j];
        }
    }

    // fill(dis, dis + (20 * (1 << 16)), (1000000 * 16 + 1));
    for(int i = 0; i < N; i += 1) fill(dis[i], dis[i] + (1 << 16), (1000000 * 16 + 1));

    queue<pair<int, int>> Q;
    dis[0][0] = 0;
    Q.push({0, 0});
    while(!Q.empty()){
        auto [cur, vis] = Q.front(); Q.pop();
        for(int nxt = 0; nxt < N; nxt += 1){
            if((bor[cur][nxt] == 0) || (vis & (1 << nxt))) continue;
            // cout << cur << ' ' << nxt << '\n';

            int nvis = vis | (1 << nxt);

            if(dis[nxt][nvis] <= dis[cur][vis] + bor[cur][nxt]) continue;
            dis[nxt][nvis] = dis[cur][vis] + bor[cur][nxt];
            Q.push({nxt, nvis});
        }
    }

    int mn = 1000000 * 16 + 1;
    cout << dis[0][(1 << N) - 1] << '\n';

    return 0;
}