#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll A, B;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> A >> B;
    B += 1;

    ll res = 0;
    for(ll cur = 1; cur <= B; cur *= 2){
        ll lo = A / cur;
        ll hi = B / cur;
        
        ll tmp = 0;
        if(((hi - lo) & 1) && (lo & 1)){
            tmp += (hi - lo) / 2 * cur + cur;
        }
        else{
            tmp += (hi - lo) / 2 * cur;
        }

        if(lo & 1) tmp -= A - lo * cur;
        if(hi & 1) tmp += B - hi * cur;

        res += tmp;

        // cout << cur << ' ' << tmp << '\n';
    }

    cout << res << '\n';

    return 0;
}


// 0010
// 0011
// 0100
// 0101
// 0110
// 0111
// 1000
// 1001
// 1010
// 1011
// 1100