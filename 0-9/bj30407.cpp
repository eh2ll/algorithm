#include <bits/stdc++.h>

using namespace std;

int N, H, D, K, mx;
int arr[21];

void sol(int n, int d, int s, int tot){
    if(n == N){
        mx = max(mx, tot);
        return;
    }

    if(s == 2) sol(n + 1, d, 1, tot);
    else sol(n + 1, d, s, tot - max(0, arr[n] - d) / 2);

    if(s == 2) sol(n + 1, d + K, 1, tot);
    else sol(n + 1, d + K, s, tot - max(0, arr[n] - (d + K)));

    if(s < 1 && n < N - 1){
        sol(n + 1, d, 2, tot - max(0, arr[n] - d));
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> H >> D >> K;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
    }

    sol(0, D, 0, H);

    if(mx > 0) cout << mx << '\n';
    else cout << -1 << '\n';

    return 0;
}