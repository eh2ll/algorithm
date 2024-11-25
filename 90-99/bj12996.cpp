#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1e9 + 7;
int S, d, k, h;
ll dp[55][55][55][55];

ll sol(int tot, int a, int b, int c){
    if(tot == S){
        if(a == d && b == k && c == h){
            return 1;
        }
        else return 0;
    }

    if(a < 0 || b < 0 || c < 0) return 0;
    
    ll& ret = dp[tot][a][b][c];
    if(ret != -1) return ret;

    ret = 0;
    ret += sol(tot + 1, a + 1, b, c);
    ret += sol(tot + 1, a, b + 1, c);
    ret += sol(tot + 1, a, b, c + 1);
    ret += sol(tot + 1, a + 1, b + 1, c);
    ret += sol(tot + 1, a, b + 1, c + 1);
    ret += sol(tot + 1, a + 1, b, c + 1);
    ret += sol(tot + 1, a + 1, b + 1, c + 1);
    ret %= inf;
    
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> d >> k >> h;
    memset(dp, -1, sizeof(dp));

    cout << sol(0, 0, 0, 0) << '\n';

    return 0;
}