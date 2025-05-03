#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N, a, b, c, d, e, f;
    cin >> N >> a >> b >> c >> d >> e >> f;
    ll mn1 = 1'000'001;
    mn1 = min({a, b, c, d, e, f});
    ll mn2 = 2'000'001;
    mn2 = min({a + b, a + c, a + d, a + e, b + c, c + e, e + d, d + b, f + b, f + c, f + d, f + e});
    ll mn3 = 3'000'001;
    mn3 = min({a + b + c, a + c + e, a + e + d, a + d + b, f + b + c, f + c + e, f + e + d, f + d + b});
    
    long long sum = 0;
    sum += (4 * (N - 2) * (N - 1) + (N - 2) * (N - 2)) * mn1;
    sum += 4 * (N - 2 + N - 1) * mn2;
    sum += 4 * mn3;

    if(N == 1) cout << a + b + c + d + e + f - max({a, b, c, d, e, f}) << '\n';
    else cout << sum << '\n';

    return 0;
}