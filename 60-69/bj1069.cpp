#include <bits/stdc++.h>

using namespace std;
using ll = long double;

ll N, M, D, T;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> D >> T;
    cout.precision(9);
    cout << fixed;
    
    ll tot = sqrt(pow(N, 2) + pow(M, 2));
    if(D <= T){
        cout << tot << '\n';
        return 0;
    }

    ll cnt = tot / D;
    if(cnt == (int)cnt){
        cout << cnt * T << '\n';
        return 0;
    }

    ll mx = ceil(cnt);
    ll two = 2;
    ll tri = max(mx, two);
    ll mn = min({mx * T + abs(tot - D * mx), tri * T, floor(cnt) * T + tot - D * floor(cnt)});

    cout << mn << '\n';

    return 0;
}