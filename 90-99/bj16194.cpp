#include <bits/stdc++.h>

using namespace std;

int N, arr[1003], dp[1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for(int i = 1; i <= N; i += 1){
        for(int j = 0; j < i; j += 1){
            dp[i] = min(dp[i], dp[j] + arr[i - j]);
        }
    }

    // for(int i = 1; i <= N; i += 1) cout << dp[i] << ' ';
    // cout << '\n';

    cout << dp[N] << '\n';

    return 0;
}