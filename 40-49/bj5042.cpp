#include <bits/stdc++.h>

using namespace std;
using ld = long double;

int N, L, W;
ld dp[1'003][1'003];
vector<ld> A, P;

ld dist(ld x1, ld x2, ld y){
    return sqrt((x1 - x2) * (x1 - x2) + y * y);
}

ld sol(int l, int r){
    int idx = l + r;
    if(idx == N) return 0;

    ld &ret = dp[l][r];
    if(ret > -1) return ret;

    ret = 1e18;
    if(l < N / 2){
        ret = min(ret, sol(l + 1, r) + abs(A[idx] - P[l]));
    }
    if(r < N / 2){
        ret = min(ret, sol(l, r + 1) + dist(A[idx], P[r], W));
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L >> W;
    A.resize(N);
    for(int i = 0; i < N; i += 1) cin >> A[i];
    sort(A.begin(), A.end());
    P.resize(N / 2);
    for(int i = 1; i < N / 2; i += 1) P[i] = P[i - 1] + 1.0 * L / (N / 2 - 1);

    memset(dp, -1, sizeof(dp));
    cout << fixed;
    cout.precision(7);

    cout << sol(0, 0) << '\n';

    return 0;
}