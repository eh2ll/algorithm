#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

pii A[22];
int dp[22][100'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int C, N; cin >> C >> N;
    for(int i = 1; i <= N; i += 1){
        int a, b; cin >> a >> b;
        A[i] = {b, a};
    }
    sort(A + 1, A + 1 + N);

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= N; i += 1){
        for(int j = 0; j <= 100'000; j += 1){
            if(j == 0) dp[i][j] = 0;
            if(j >= A[i].first){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - A[i].first] + A[i].second);
            }
            else dp[i][j] = dp[i - 1][j];
        }
    }

    // for(int i = 1; i <= N; i += 1){
    //     for(int j = 0; j <= C + 10; j += 1){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    int mn = 0x3f3f3f3f;
    for(int i = C; i <= 100'000; i += 1){
        mn = min(mn, dp[N][i]);
    }
    cout << mn << '\n';

    return 0;
}