#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
int M;

tuple<ll, ll, ll> xgcd(ll a, ll b){
    if(b == 0) return {a, 1, 0};

    auto [g, x, y] = xgcd(b, a % b);

    return {g, y, x - (a / b) * y};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M;
    
    ll res = 0;
    for(int i = 0; i < M; i += 1){
        ll a, b; cin >> a >> b;
        auto [g, x, y] = xgcd(a, MOD);
        
        x = (x + MOD) % MOD;
        res += (x * b) % MOD;
        res %= MOD;
    }

    cout << res << '\n';

    return 0;
}