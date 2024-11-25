#include <bits/stdc++.h>

using namespace std;

int N, M;
int bor[1003][1003], dp[1003][1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= M; j += 1){
            cin >> bor[i][j];
        }
    }

    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= M; j += 1){
            dp[i][j] = max({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + bor[i][j];
        }
    }

    cout << dp[N][M] << '\n';

    return 0;
}