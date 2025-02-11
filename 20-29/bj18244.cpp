#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int N;
int dp[102][5][10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < 10; i += 1) dp[1][2][i] = 1;

    for(int i = 1; i < 10; i += 1) dp[2][3][i] = 1;
    for(int i = 0; i < 9; i += 1) dp[2][1][i] = 1;
    
    for(int i = 3; i <= N; i += 1){
        for(int k = 0; k < 9; k += 1){
            dp[i][4][k + 1] = (dp[i - 1][3][k]) % MOD;
        }
        for(int k = 0; k < 9; k += 1){
            dp[i][3][k + 1] = (dp[i - 1][0][k] + dp[i - 1][1][k]) % MOD;
        }
        for(int k = 1; k < 10; k += 1){
            dp[i][1][k - 1] = (dp[i - 1][3][k] + dp[i - 1][4][k]) % MOD;
        }
        for(int k = 1; k < 10; k += 1){
            dp[i][0][k - 1] = (dp[i - 1][1][k]) % MOD;
        }
    }

    long long cnt = 0;
    for(int j = 4; j >= 0; j -= 1){
        for(int k = 0; k < 10; k += 1){
            cnt = (cnt + dp[N][j][k]) % MOD;
        }
    }

    cout << cnt << '\n';

    return 0;
}