#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005], dp[100005][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        cin >> arr[i];
    }

    dp[0][0] = dp[0][1] = -1e9;
    for(int i = 1; i <= N; i += 1){
        dp[i][0] = max({dp[i - 1][0] + arr[i], arr[i]});
        dp[i][1] = max({dp[i - 1][1] + arr[i], dp[i - 1][0]});
    }

    int ans = -1e9;
    for(int i = 1; i <= N; i += 1) ans = max({ans, dp[i][0], dp[i][1]});
    cout << ans << '\n';

    return 0;
}