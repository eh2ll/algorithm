#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll res = 1;
    int N; cin >> N;
    for(int i = 1; i <= N; i += 1){
        res *= i;
    }

    cout << res << '\n';

    return 0;
}