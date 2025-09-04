#include <bits/stdc++.h>

using namespace std;

int A[1'000'006], L[1'000'006], R[1'000'006];

int xgcd(int a, int b){
    if(b == 0) return a;
    return xgcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for(int i = 1; i <= N; i += 1){
        cin >> A[i];
    }
    for(int i = 1; i <= N; i += 1){
        L[i] = xgcd(L[i - 1], A[i]);
        R[N - i + 1] = xgcd(R[N - i + 2], A[N - i + 1]);
    }

    int g = 0, mx = 0, mxidx = 0;
    for(int i = 1; i <= N; i += 1){
        g = xgcd(L[i - 1], R[i + 1]);
        if(g % A[i] != 0 && g > mx){
            mx = g;
            mxidx = A[i];
        }
    }

    if(mx <= L[N]) cout << -1 << '\n';
    else cout << mx << ' ' << mxidx << '\n';

    return 0;
}