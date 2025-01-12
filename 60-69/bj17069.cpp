#include <bits/stdc++.h>

using namespace std;

int N, bor[51][51];
long long dp[51][51][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= N; j += 1){
            cin >> bor[i][j];
        }
    }

    dp[1][2][0] = 1;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= N; j += 1){
            int nx0 = i, ny0 = j + 1;
            int nx1 = i + 1, ny1 = j;
            int nx2 = i + 1, ny2 = j + 1;

            if(nx0 <= N && ny0 <= N && !bor[nx0][ny0]){
                dp[nx0][ny0][0] += dp[i][j][0] + dp[i][j][2];
            }
            if(nx1 <= N && ny1 <= N && !bor[nx1][ny1]){
                dp[nx1][ny1][1] += dp[i][j][1] + dp[i][j][2];
            }
            if(nx2 <= N && ny2 <= N && !bor[nx0][ny0] && !bor[nx1][ny1] && !bor[nx2][ny2]){
                dp[nx2][ny2][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
            }
        }
    }

    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2] << '\n';

    return 0;
}