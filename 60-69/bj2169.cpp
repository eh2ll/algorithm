// justicehui

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int N, M, arr[1003][1003], dp[1003][1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= M; j += 1){
            cin >> arr[i][j];
        }
    }

    for(int j = 1; j <= M; j += 1) dp[1][j] = dp[1][j - 1] + arr[1][j];
    for(int i = 2; i <= N; i += 1){
        int L[1003], R[1003];
        L[1] = dp[i - 1][1] + arr[i][1];
        R[M] = dp[i - 1][M] + arr[i][M];
        for(int j = 2; j <= M; j += 1) L[j] = max(L[j - 1], dp[i - 1][j]) + arr[i][j];
        for(int j = M - 1; j >= 1; j -= 1) R[j] = max(R[j + 1], dp[i - 1][j]) + arr[i][j];
        for(int j = 1; j <= M; j += 1) dp[i][j] = max(L[j], R[j]);
    }

    cout << dp[N][M] << '\n';

    return 0;
}