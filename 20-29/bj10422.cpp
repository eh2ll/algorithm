#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
int T;
long long dp[5003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    
    dp[0] = 1;
    for(int i = 2; i <= 5000; i += 2){
        // int c = i / 2;
        // dp[i] = ((dp[i - 2] * (2 * c - 1) * (2 * c)) / (c * (c + 1))) % MOD;
        for (int j = 2; j <= i; j += 2){
			dp[i] += (dp[j - 2] * dp[i - j]) % MOD;
			dp[i] %= MOD;
		}
    }
    
    while(T--){
        int N; cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}