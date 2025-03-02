#include <bits/stdc++.h>

using namespace std;

int N, M;
int bor[502][502], dp[502][502];

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
        int mn1 = 0x3f3f3f3f, mn2 = 0x3f3f3f3f, id1, id2;
        for(int j = 1; j <= M; j += 1){
            if(mn1 >= dp[i - 1][j]){
                mn1 = dp[i - 1][j];
                id1 = j;
            }
        }
        for(int j = 1; j <= M; j += 1){
            if(mn2 >= dp[i - 1][j] && id1 != j){
                mn2 = dp[i - 1][j];
                id2 = j;
            }
        }

        for(int j = 1; j <= M; j += 1){
            if(j == id1){
                dp[i][j] = dp[i - 1][id2] + bor[i][j];
            }
            else{
                dp[i][j] = dp[i - 1][id1] + bor[i][j];
            }
        }
    }

    int mn = 0x3f3f3f3f;
    for(int j = 1; j <= M; j += 1){
        mn = min(mn, dp[N][j]);
    }

    cout << mn << '\n';

    return 0;
}