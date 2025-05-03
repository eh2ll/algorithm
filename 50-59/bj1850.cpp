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

    ll N, M; cin >> N >> M;
    if(N > M) swap(N, M);

    auto [g, x, y] = xgcd(N, M);

    for(int i = 0; i < g; i += 1) cout << 1;
    cout << '\n';

    return 0;
}