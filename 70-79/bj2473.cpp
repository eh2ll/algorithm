#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<ll> arr;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        ll x; cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    
    ll mn = LLONG_MAX;
    tuple<ll, ll, ll> res;
    for(int i = 0; i < N; i += 1){
        for(int j = i + 1; j < N; j += 1){
            ll tmp = arr[i] + arr[j];
            ll lowid = lower_bound(arr.begin() + j + 1, arr.end(), -tmp) - arr.begin() - 1;
            ll highid = lowid + 1;
            if(j < lowid && abs(tmp + arr[lowid]) < mn){
                mn = abs(tmp + arr[lowid]);
                res = tie(i, j, lowid);
            }
            if(highid < N && abs(tmp + arr[highid]) < mn){
                mn = abs(tmp + arr[highid]);
                res = tie(i, j, highid);
            }
        }
    }

    auto [a, b, c] = res;
    cout << arr[a] << ' ' << arr[b] << ' ' << arr[c] << '\n';

    return 0;
}