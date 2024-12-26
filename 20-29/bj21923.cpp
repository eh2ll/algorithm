#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
int N, M;
int bor[1003][1003], dp1[1003][1003], dp2[1003][1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= M; j += 1){
            cin >> bor[i][j];
        }
    }
    
    for(int i = 0; i < 1003; i += 1){
        fill(dp1[i], dp1[i] + 1003, -inf);
        fill(dp2[i], dp2[i] + 1003, -inf);
    }
    dp1[N + 1][1] = dp2[N + 1][M] = 0;

    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= M; j += 1){
            dp1[N - i + 1][j] = max(dp1[N - i + 2][j], dp1[N - i + 1][j - 1]) + bor[N - i + 1][j];
            dp2[N - i + 1][M - j + 1] = max(dp2[N - i + 2][M - j + 1], dp2[N - i + 1][M - j + 2]) + bor[N - i + 1][M - j + 1];
        }
    }

    int res = -inf;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= M; j += 1){
            res = max(res, dp1[i][j] + dp2[i][j]);
        }
    }

    cout << res << '\n';

    return 0;
}