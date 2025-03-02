#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, C;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    vector<ll> V1, V2;
    V1.push_back(0);
    V2.push_back(0);
    for(int i = 0; i < N / 2; i += 1){
        int x; cin >> x;
        int sz = V1.size();
        for(int k = 0; k < sz; k += 1){
            V1.push_back(V1[k] + x);
        }
    }
    for(int i = N / 2; i < N; i += 1){
        int x; cin >> x;
        int sz = V2.size();
        for(int k = 0; k < sz; k += 1){
            V2.push_back(V2[k] + x);
        }
    }

    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());

    ll cnt = 0;
    for(auto cur : V1){
        cnt += upper_bound(V2.begin(), V2.end(), C - cur) - V2.begin();
    }

    cout << cnt << '\n';

    return 0;
}