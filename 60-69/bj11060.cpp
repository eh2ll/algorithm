#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
int N;
int arr[1103], dp[1103];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    if(N == 1){
        cout << 0 << '\n';
        return 0;
    }
    
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
    }

    fill(dp, dp + 1103, inf);
    dp[0] = 0;
    for(int i = 0; i < N; i += 1){
        if(dp[i] == -1) continue;
        for(int j = 1; j <= arr[i]; j += 1){
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }

    if(dp[N] == inf) cout << -1 << '\n';
    else cout << dp[N - 1] << '\n';

    return 0;
}