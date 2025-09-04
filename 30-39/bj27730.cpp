#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll N, M, totA, totB;
int chdA[100'005], chdB[100'005], vis[100'005];
ll ansA[100'005], ansB[100'005]; 
vector<pll> A[100'005], B[100'005];

int dfsA(int cur, ll tot){
    vis[cur] = 1;
    int cnt = 0;
    for(auto [c, nxt] : A[cur]){
        if(vis[nxt]) continue;
        dfsA(nxt, tot + c);
        cnt += chdA[nxt];
    }
    totA += tot;
    return chdA[cur] = cnt + 1;
}

int dfsB(int cur, ll tot){
    vis[cur] = 1;
    int cnt = 0;
    for(auto [c, nxt] : B[cur]){
        if(vis[nxt]) continue;
        dfsB(nxt, tot + c);
        cnt += chdB[nxt];
    }
    totB += tot;
    return chdB[cur] = cnt + 1;
}

void calcA(int cur, ll tot){
    vis[cur] = 1;
    ansA[cur] = tot;
    for(auto [c, nxt] : A[cur]){
        if(vis[nxt]) continue;
        calcA(nxt, tot - chdA[nxt] * c + (N - chdA[nxt]) * c);
    }
}

void calcB(int cur, ll tot){
    vis[cur] = 1;
    ansB[cur] = tot;
    for(auto [c, nxt] : B[cur]){
        if(vis[nxt]) continue;
        calcB(nxt, tot - chdB[nxt] * c + (M - chdB[nxt]) * c);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N - 1; i += 1){
        int a, b, c; cin >> a >> b >> c;
        A[a].push_back({c, b});
        A[b].push_back({c, a});
    }
    dfsA(1, 0);
    memset(vis, 0, sizeof(vis));
    ansA[1] = totA;
    calcA(1, totA);

    // for(int i = 1; i <= N; i += 1) cout << chdA[i] << ' ';
    // cout << '\n';
    // for(int i = 1; i <= N; i += 1) cout << ansA[i] << ' ';
    // cout << '\n' << '\n';

    memset(vis, 0, sizeof(vis));
    cin >> M;
    for(int i = 0; i < M - 1; i += 1){
        int a, b, c; cin >> a >> b >> c;
        B[a].push_back({c, b});
        B[b].push_back({c, a});
    }
    dfsB(1, 0);
    memset(vis, 0, sizeof(vis));
    ansB[1] = totB;
    calcB(1, totB);

    // for(int i = 1; i <= M; i += 1) cout << ansB[i] << ' ';
    // cout << '\n';

    ll mnA = LLONG_MAX, mnB = LLONG_MAX, mnAidx = -1, mnBidx = -1;
    for(int i = 1; i <= N; i += 1){
        if(ansA[i] < mnA){
            mnA = ansA[i];
            mnAidx = i;
        }
    }
    for(int i = 1; i <= M; i += 1){
        if(ansB[i] < mnB){
            mnB = ansB[i];
            mnBidx = i;
        }
    }

    cout << mnAidx << ' ' << mnBidx << '\n';
    cout << mnA * M + N * M + mnB * N << '\n';

    return 0;
}