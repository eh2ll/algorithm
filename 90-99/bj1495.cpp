#include <bits/stdc++.h>

using namespace std;

int N, S, M;
bool dp[51][55004];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S >>  M;
    dp[0][S] = 1;
    for(int i = 1; i <= N; i += 1){
        int x; cin >> x;
        for(int j = 0; j <= M; j += 1){
            if(dp[i - 1][j]){
                if(j - x >= 0) dp[i][j - x] = 1;
                if(j + x <= M) dp[i][j + x] = 1;
            }
        }
    }

    int res = -1;
    for(int i = M; i >= 0; i -= 1){
        if(dp[N][i]){
            res = i;
            break;
        }
    }

    if(res >= 0) cout << res << '\n';
    else cout << -1 << '\n';
    
    return 0;
}