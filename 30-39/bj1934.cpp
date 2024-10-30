#include <bits/stdc++.h>

using namespace std;
using ll = long long;

tuple<ll, ll, ll> xgcd(ll a, ll b){
    if(b == 0) return {a, 1, 0};

    auto [g, x, y] = xgcd(b, a % b);

    return {g, y, x - (a / b) * y};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int TC; cin >> TC;
    while(TC--){
        ll a, b; cin >> a >> b;
        auto [g, x, y] = xgcd(a, b);
        cout << a / g *  b << '\n';
    }

    return 0;
}