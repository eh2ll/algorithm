#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
string s;
const int MOD = 1234567891;
ll pow31[55];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> s;

    pow31[0] = 1;
    for(int i = 1; i <= 50; i += 1){
        pow31[i] = (pow31[i - 1] * 31) % MOD;
    }

    ll res = 0;
    for(int i = 0; i < N; i += 1){
        res += (s[i] - 'a' + 1) * pow31[i];
        res %= MOD;
    }

    cout << res << '\n';

    return 0;
}