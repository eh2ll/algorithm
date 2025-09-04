#include <bits/stdc++.h>

using namespace std;

int A[10'004][2], dp[10'004][4];

int calc(int& a, int& b, int& w){
    if(a + b <= w) return 1;
    else return 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int TC; cin >> TC;
    while(TC--){
        memset(A, 0, sizeof(A));
        int N, W; cin >> N >> W;
        for(int k = 0; k < 2; k += 1){
            for(int i = 0; i < N; i += 1){
                cin >> A[i][k];
            }
        }
        A[N][0] = A[0][0];
        A[N][1] = A[0][1];

        int res = 0x3f3f3f3f;

        dp[0][0] = calc(A[0][0], A[0][1], W);
        dp[0][1] = calc(A[0][0], A[1][0], W) + 1;
        dp[0][2] = calc(A[0][1], A[1][1], W) + 1;
        dp[0][3] = calc(A[0][0], A[1][0], W) + calc(A[0][1], A[1][1], W);
        for(int i = 1; i < N; i += 1){
            int mgs = calc(A[i][0], A[i][1], W);
            int ups = calc(A[i][0], A[i + 1][0], W);
            int dns = calc(A[i][1], A[i + 1][1], W);
            dp[i][0] = min({dp[i - 1][0] + mgs, dp[i - 1][1] + 1, dp[i - 1][2] + 1, dp[i - 1][3]});
            dp[i][1] = min({dp[i - 1][0] + ups + 1, dp[i - 1][1] + 2, dp[i - 1][2] + ups, dp[i - 1][3] + 1});
            dp[i][2] = min({dp[i - 1][0] + dns + 1, dp[i - 1][1] + dns, dp[i - 1][2] + 2, dp[i - 1][3] + 1});
            dp[i][3] = min({dp[i - 1][0] + ups + dns, dp[i - 1][1] + dns + 1, dp[i - 1][2] + ups + 1, dp[i - 1][3] + 2});
        }

        res = min(res, dp[N - 1][0]);
        // cout << res << '\n';

        dp[0][0] = 1;
        dp[0][1] = 2;
        dp[0][2] = calc(A[0][1], A[1][1], W);
        dp[0][3] = calc(A[0][1], A[1][1], W) + 1;
        for(int i = 1; i < N; i += 1){
            int mgs = calc(A[i][0], A[i][1], W);
            int ups = calc(A[i][0], A[i + 1][0], W);
            int dns = calc(A[i][1], A[i + 1][1], W);
            dp[i][0] = min({dp[i - 1][0] + mgs, dp[i - 1][1] + 1, dp[i - 1][2] + 1, dp[i - 1][3]});
            dp[i][1] = min({dp[i - 1][0] + ups + 1, dp[i - 1][1] + 2, dp[i - 1][2] + ups, dp[i - 1][3] + 1});
            dp[i][2] = min({dp[i - 1][0] + dns + 1, dp[i - 1][1] + dns, dp[i - 1][2] + 2, dp[i - 1][3] + 1});
            dp[i][3] = min({dp[i - 1][0] + ups + dns, dp[i - 1][1] + dns + 1, dp[i - 1][2] + ups + 1, dp[i - 1][3] + 2});
        }
        
        res = min(res, dp[N - 1][1]);
        // cout << res << '\n';

        dp[0][0] = 1;
        dp[0][1] = calc(A[0][0], A[1][0], W);
        dp[0][2] = 2;
        dp[0][3] = calc(A[0][0], A[1][0], W) + 1;
        for(int i = 1; i < N; i += 1){
            int mgs = calc(A[i][0], A[i][1], W);
            int ups = calc(A[i][0], A[i + 1][0], W);
            int dns = calc(A[i][1], A[i + 1][1], W);
            dp[i][0] = min({dp[i - 1][0] + mgs, dp[i - 1][1] + 1, dp[i - 1][2] + 1, dp[i - 1][3]});
            dp[i][1] = min({dp[i - 1][0] + ups + 1, dp[i - 1][1] + 2, dp[i - 1][2] + ups, dp[i - 1][3] + 1});
            dp[i][2] = min({dp[i - 1][0] + dns + 1, dp[i - 1][1] + dns, dp[i - 1][2] + 2, dp[i - 1][3] + 1});
            dp[i][3] = min({dp[i - 1][0] + ups + dns, dp[i - 1][1] + dns + 1, dp[i - 1][2] + ups + 1, dp[i - 1][3] + 2});
        }

        res = min(res, dp[N - 1][2]);
        // cout << res << '\n';

        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[0][2] = 1;
        dp[0][3] = 2;
        for(int i = 1; i < N; i += 1){
            int mgs = calc(A[i][0], A[i][1], W);
            int ups = calc(A[i][0], A[i + 1][0], W);
            int dns = calc(A[i][1], A[i + 1][1], W);
            dp[i][0] = min({dp[i - 1][0] + mgs, dp[i - 1][1] + 1, dp[i - 1][2] + 1, dp[i - 1][3]});
            dp[i][1] = min({dp[i - 1][0] + ups + 1, dp[i - 1][1] + 2, dp[i - 1][2] + ups, dp[i - 1][3] + 1});
            dp[i][2] = min({dp[i - 1][0] + dns + 1, dp[i - 1][1] + dns, dp[i - 1][2] + 2, dp[i - 1][3] + 1});
            dp[i][3] = min({dp[i - 1][0] + ups + dns, dp[i - 1][1] + dns + 1, dp[i - 1][2] + ups + 1, dp[i - 1][3] + 2});
        }

        res = min(res, dp[N - 1][3]);
        // cout << res << '\n';

        cout << res << '\n';
    }

    return 0;
}