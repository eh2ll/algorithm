#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
int N, Q, U, V;
int arr[1003], dp[1003];

int sol(int x, int y){
    int mn = inf, mx = -1 * inf;
    for(int i = x; i <= y; i += 1){
        mn = min(mn, dp[i - 1]);
        mx = max(mx, dp[i] - mn);
    }

    return mx - V;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q >> U >> V;
    for(int i = 1; i <= N; i += 1){
        int x; cin >> x;
        arr[i] = arr[i - 1] + x;
        dp[i] = U * arr[i] + V * i;
    }

    for(int i = 0; i < Q; i += 1){
        int op, a, b; cin >> op >> a >> b;
        if(op != 0){
            int tmp = arr[a] - arr[a - 1];
            for(int k = a; k <= N; k += 1) arr[k] += b - tmp;
            for(int k = a; k <= N; k += 1) dp[k] += U * (b - tmp);
        }
        else{
            cout << sol(a, b) << '\n';
        }
    }

    return 0;
}