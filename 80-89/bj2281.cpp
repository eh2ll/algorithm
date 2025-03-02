#include <bits/stdc++.h>

using namespace std;

int N, M;
int name[1003], dp[1003];

int sol(int idx){
    if(idx >= N) return 0;

    int& ret = dp[idx];
    if(ret != -1) return ret;

    ret = 0x3f3f3f3f;
    int r = M;
    for(int i = idx; i < N; i += 1){
        r -= name[i];
        if(r < 0) break;
        if(i == N - 1) ret = 0;
        ret = min(ret, r * r + sol(i + 1));
        r -= 1;
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i += 1){
        cin >> name[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << sol(0) << '\n';

    return 0;
}