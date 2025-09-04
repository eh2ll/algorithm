// mobius function - rkm0959, gratus

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1'000'005;
bool isp[inf];
int mu[inf];
void mobius(){
    fill(isp, isp + inf, 1);
    fill(mu, mu + inf, 1);
    for(ll i = 2; i < inf; i += 1){
        if(!isp[i]) continue;
        mu[i] = -mu[i];
        for(ll j = 2 * i; j < inf; j += i){
            isp[j] = 0;
            mu[j] = -mu[j];
            if((j / i) % i == 0) mu[j] = 0;
        }
    }
}

ll calc(ll x){
    ll ret = 0;
    for(ll i = 1; i * i <= x; i += 1){
        ret += 1LL * mu[i] * (x / (i * i));
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    mobius();

    ll N; cin >> N;
    ll st = 0, en = 1e12 + 1;
    while(st + 1 < en){
        ll mid = (st + en) >> 1;
        if(mid - calc(mid) < N) st = mid;
        else en = mid;
    }

    cout << en << '\n';

    return 0;
}