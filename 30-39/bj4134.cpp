#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 40000000000;

ll chk(ll res){
    for(ll i = res; i < inf; i += 1){
        ll j;
        for(j = 2; j <= sqrt(i); j += 1){
            if(i % j == 0) break;
        }
        if(j > sqrt(i)) return i;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int TC; cin >> TC;
    while(TC--){
        ll x; cin >> x;
        cout << chk(max(ll(2), x)) << '\n';
    }

    return 0;
}