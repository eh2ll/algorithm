#include <bits/stdc++.h>

using namespace std;

int N, res = 0x3f3f3f3f;
int arr[1003][3], dp[1003][3], vis[1003];

int preN(int a, int b){
    return (a - 1 + b) % b;
}

int posN(int a, int b){
    return (a + 1 + b) % b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    for(int rgb = 0; rgb < 3; rgb += 1){
        for(int i = 0; i < N; i += 1) fill(dp[i], dp[i] + 3, 0x3f3f3f3f);
        
        dp[0][rgb] = arr[0][rgb];
        for(int cur = 1; cur < N; cur += 1){
            dp[cur][0] = min(dp[cur - 1][1], dp[cur - 1][2]) + arr[cur][0];
            dp[cur][1] = min(dp[cur - 1][2], dp[cur - 1][0]) + arr[cur][1];
            dp[cur][2] = min(dp[cur - 1][0], dp[cur - 1][1]) + arr[cur][2];
        }

        res = min({res, dp[N - 1][preN(rgb - 1, 3)], dp[N - 1][posN(rgb + 1, 3)]});
    }

    cout << res << '\n';

    return 0;
}