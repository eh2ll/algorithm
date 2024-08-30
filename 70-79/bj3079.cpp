#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll N, M;
ll T[100005];

ll chk(ll x){
    ll tot = 0;
    for(int i = 0; i < N; i += 1){
        tot += x / T[i];
        if(tot >= M) return 1;
    }
    return tot >= M;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i += 1) cin >> T[i];

    ll st = 1, en = 1e18;
    while(st != en){
        ll mid = (st + en) / 2;
        if(chk(mid)) en = mid;
        else st = mid + 1;
    }

    cout << st << '\n';

    return 0;
}