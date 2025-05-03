#include <bits/stdc++.h>

using namespace std;

int N, M, bor[1'003][1'003], dp[1'003][1'003][3];

int sol(int x, int y, int pre){
    if(x > N){
        return 0;
    }
    int& ret = dp[x][y][pre];
    if(ret != -1) return ret;

    ret = 0x3f3f3f3f;
    if(pre == 0){
        if(1 <= y && y <= M){
            if(y <= M) ret = min(ret, sol(x + 1, y, 1) + bor[x][y]);
            if(y + 1 <= M) ret = min(ret, sol(x + 1, y + 1, 2) + bor[x][y]);
        }
    }
    else if(pre == 1){
        if(y >= 2){
            ret = min(ret, sol(x + 1, y - 1, 0) + bor[x][y]);
        }
        if(y <= M - 1){
            ret = min(ret, sol(x + 1, y + 1, 2) + bor[x][y]);
        }
    }
    else if(pre == 2){
        if(y >= 2) ret = min(ret, sol(x + 1, y - 1, 0) + bor[x][y]);
        if(y <= M) ret = min(ret, sol(x + 1, y, 1) + bor[x][y]);
    }

    // cout << "x y pre : " << ' ' << x << ' ' << y << ' ' << pre << ' ' << ret << '\n';

    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N >> M;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= M; j += 1){
            cin >> bor[i][j];
        }
    }

    int mn = 0x3f3f3f3f;
    for(int i = 1; i < M; i += 1){
        mn = min(mn, sol(1, i, 0));
    }
    for(int i = 1; i <= M; i += 1){
        mn = min(mn, sol(1, i, 1));
    }
    for(int i = 2; i <= M; i += 1){
        mn = min(mn, sol(1, i, 2));
    }

    cout << mn << '\n';

    return 0;
}