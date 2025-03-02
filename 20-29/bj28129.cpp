#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
int N, K;
int inp[3003][2];
long long bor[3003][3003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i = 1; i <= N; i += 1){
        int a, b; cin >> a >> b;
        inp[i][0] = a;
        inp[i][1] = b;

        if(i >= 2){
            for(int j = a; j <= b; j += 1){
                bor[i][j] = (bor[i][j - 1] + (bor[i - 1][min(3000, j + K)] - bor[i - 1][max(0, j - K - 1)] + MOD)) % MOD;
            }
            for(int j = b + 1; j <= 3000; j += 1){
                bor[i][j] = bor[i][b];
            }
        }
        else{
            int cnt = 1;
            for(int j = a; j <= b; j += 1){
                bor[i][j] = cnt++;
            }
            for(int j = b + 1; j <= 3000; j += 1){
                bor[i][j] = bor[i][b];
            }
        }
    }

    cout << (bor[N][inp[N][1]] - bor[N][inp[N][0] - 1]) % MOD << '\n';

    return 0;
}