// so hard... jinhan814, jooddae, q&a

#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
int N, A[55];
int dp[55][250'005];

int solve(int idx, int diff){
    if(diff > 250'000) return -inf;
    if(idx == N){
        if(diff == 0) return 0;
        else return -inf;
    }

    int& ret = dp[idx][diff];
    if(ret != -1) return ret;
    
    ret = -inf;
    ret = max(ret, solve(idx + 1, diff));
    ret = max(ret, solve(idx + 1, diff + A[idx]));
    if(A[idx] < diff) ret = max(ret, solve(idx + 1, diff - A[idx]) + A[idx]);
    else ret = max(ret, solve(idx + 1, A[idx] - diff) + diff);

    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> A[i];
    }

    memset(dp, -1, sizeof(dp));
    int ans = solve(0, 0);

    cout << (ans ? ans : -1) << '\n';

    return 0;
}