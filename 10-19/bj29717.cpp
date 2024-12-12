#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int TC;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    while(TC--){
        int N; cin >> N;
        ll exp = 1LL * N * (N + 1) / 2;
        int st = 1, en = 1e9 + 1;
        while(st + 1 < en){
            int mid = (st + en + 1) / 2;
            if(1LL * mid * (mid - 1) <= exp) st = mid;
            else en = mid;
        }
        cout << st << '\n';
    }

    return 0;
}