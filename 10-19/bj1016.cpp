#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int mu[1'001'005];
bool isp[1'001'005];

void mobius(){
    fill(mu, mu + 1'001'005, 1);
    fill(isp, isp + 1'001'005, 1);
    for(int i = 2; i < 1'001'005; i += 1){
        if(!isp[i]) continue;
        mu[i] = -mu[i];
        for(int j = 2 * i; j < 1'001'005; j += i){
            isp[j] = 0;
            mu[j] = -mu[j];
            if((j / i) % i == 0) mu[j] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    mobius();

    ll mini, maxi; cin >> mini >> maxi;
    ll tot = 0;
    for(ll i = 1; i * i <= maxi; i += 1){
        tot += mu[i] * (maxi / (i * i) - (mini - 1) / (i * i));
    }

    cout << tot << '\n';

    return 0;
}