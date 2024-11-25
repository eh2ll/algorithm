#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
ll dp[33];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    dp[0] = 1;
    dp[2] = 3;
    
    if(N & 1){
        cout << 0 << '\n';
    }
    else{
        for(int i = 4; i <= 30; i += 2){
            dp[i] = dp[i - 2] * dp[2];
            for(int j = 4; j <= i; j += 2){
                dp[i] += dp[i - j] * 2;
            }
        }
        cout << dp[N] << '\n';
    }

    return 0;
}