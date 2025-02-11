#include <bits/stdc++.h>

using namespace std;

int T;
int dp[10004][4];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1][1] = 1;
    dp[2][1] = dp[2][2] = 1;
    dp[3][1] = 2;
    dp[3][3] = 1;
    for(int i = 4; i <= 10000; i += 1){
        dp[i][1] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
        dp[i][2] = dp[i - 2][2] + dp[i - 2][3];
        dp[i][3] = dp[i - 3][3];
    }

    cin >> T;
    while(T--){
        int N; cin >> N;
        cout << dp[N][1] + dp[N][2] + dp[N][3] << '\n';
    }

    return 0;
}