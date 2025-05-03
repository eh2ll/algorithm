#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1'000'000'007;
vector<ll> A, B;

void update(int i, int diff){
    while(i < A.size()){
        A[i] += diff;
        B[i] += 1;
        i += (i & -i);
    }
}

ll sum(int i){
    ll ret = 0;
    while(i > 0){
        ret += A[i];
        i -= (i & -i);
    }
    return ret;
}

ll cnt(int i){
    ll ret = 0;
    while(i > 0){
        ret += B[i];
        i -= (i & -i);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    A.resize(200'001);
    B.resize(200'001);
    ll res = 1;
    for(int i = 1; i <= N; i += 1){
        ll x; cin >> x;
        x += 1;
        if(i > 1){
            ll tmp = 0;
            tmp += (x * cnt(x - 1) - sum(x - 1));
            tmp += ((sum(200'000) - sum(x)) - x * (cnt(200'000) - cnt(x)));
            res *= tmp % MOD;
        }
        res %= MOD;
        // cout << res << '\n';
        update(x, x);
    }

    cout << res << '\n';

    return 0;
}