#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1e9+9;
int TC;
ll dp[100005][4];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> TC;

    dp[0][0] = 1;
    dp[1][0] = dp[1][1] = 1;
    dp[2][0] = dp[2][2] = 1;
    dp[3][0] = 3;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for(int i = 4; i <= 100000; i += 1){
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % inf;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % inf;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % inf;
        dp[i][0] = (dp[i][1] + dp[i][2] + dp[i][3]) % inf;
    }

    // cout << 0 << ' ' << 1 << ' ' << 2 << ' ' << 3 << '\n';
    // for(int i = 0; i <= 10; i += 1){
    //     for(int j = 0; j <= 3; j += 1){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    while(TC--){
        int N; cin >> N;
        cout << dp[N][0] << '\n';
    }

    return 0;
}