#include <bits/stdc++.h>

using namespace std;

int N, Q, arr[500005];
int dp[500005][30];

void make_table(){
    for(int i = 1; i <= N; i += 1) dp[i][0] = arr[i];

    for(int j = 1; j < 30; j += 1){
        for(int i = 1; i <= N; i += 1){
            dp[i][j] = dp[ dp[i][j - 1] ][j - 1];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        cin >> arr[i];
    }

    make_table();

    cin >> Q;
    for(int i = 0; i < Q; i += 1){
        int a, b; cin >> a >> b;
        for(int k = 0; (1 << k) <= a; k += 1){
            if(a & (1 << k)){
                b = dp[b][k];
            }
        }
        cout << b << '\n';
    }

    return 0;
}