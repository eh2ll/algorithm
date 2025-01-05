#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
int TC, arr[3];
ll dp[1000006][8];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < 8; i += 1) dp[1][i] = 1;
    dp[2][1] = dp[2][2] = dp[2][4] = 1;
    dp[2][3] = dp[2][5] = dp[2][6] = 2;
    dp[2][7] = 3;
    for(int i = 3; i <= 1000000; i += 1){
        dp[i][1] = (dp[i - 1][1] * dp[i - 2][1]) % MOD;
        dp[i][2] = (dp[i - 2][2] * dp[i - 1][2]) % MOD;
        dp[i][4] = (dp[i - 1][4] * dp[i - 1][4]) % MOD;
        
        dp[i][3] = (dp[i - 1][3] * (dp[i - 2][3] + dp[i - 1][3])) % MOD;
        dp[i][5] = (2 * (dp[i - 2][5] * dp[i - 1][5])) % MOD;
        dp[i][6] = (dp[i - 1][6] * (dp[i - 2][6] + dp[i - 1][6])) % MOD;

        dp[i][7] = ((dp[i - 1][7] + dp[i - 2][7]) * (dp[i - 1][7] + dp[i - 2][7]));
        dp[i][7] -= (dp[i - 2][7] * dp[i - 2][7]);
        dp[i][7] %= MOD;
    }

    cin >> TC;
    while(TC--){
        int h, S; cin >> h >> S;
        int tmp = 0;
        for(int i = 0; i < S; i += 1){
            int x; cin >> x;
            if(x == -1) tmp += 1;
            else if(x == 0) tmp += 2;
            else if(x == 1) tmp += 4;
        }

        cout << dp[h][tmp] << '\n';
    }

    return 0;
}