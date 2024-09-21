#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9;
ll fac[20], facinv[20];

ll mpow(ll a, ll x){
    ll res = 1;
    while(x > 0){
        if(x % 2) res *= a;
        a *= a;
        x /= 2;
    }
    return res;
}

void fac_init(){
    fac[0] = 1;
    for(int i = 1; i <= 14; i += 1) fac[i] = fac[i - 1] * i % MOD;
    facinv[14] = mpow(fac[14], MOD - 2);
    for(int i = 13; i >= 0; i -= 1) facinv[i] = facinv[i + 1] * (i + 1) % MOD;
}

ll C(ll n, ll r){
    return (fac[n] * facinv[r] % MOD) * facinv[n - r] % MOD;
}

ll arr[20][20];

ll sol(ll k, ll n){
    for(int i = 1; i <= 14; i += 1) arr[0][i] = i, arr[i][1] = 1;
    for(int i = 1; i <= 14; i += 1){
        for(int j = 2; j <= 14; j += 1){
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    return arr[k][n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int TC; cin >> TC;
    while(TC--){
        int K, N; cin >> K >> N;
        cout << sol(K, N) << '\n';
    }

    return 0;
}