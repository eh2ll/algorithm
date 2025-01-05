#include <bits/stdc++.h>

using namespace std;

int N;
int bor[5003], dp[5003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> bor[i];
    }
    sort(bor, bor + N);

    fill(dp, dp + N, 1);
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < i; j += 1){
            if(bor[i] % bor[j] == 0) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int res = 0;
    for(int i = 0; i < N; i += 1) res = max(res, dp[i]);

    cout << N - res << '\n';

    return 0;
}