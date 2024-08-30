#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
ll arr[4003][4];
vector<ll> V1, V2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }

    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < N; j += 1){
            V1.push_back(arr[i][0] + arr[j][1]);
            V2.push_back(arr[i][2] + arr[j][3]);
        }
    }

    sort(V2.begin(), V2.end());
    ll cnt = 0;
    for(auto c : V1){
        auto [l, r] = equal_range(V2.begin(), V2.end(), -c);
        cnt += (r - l);
    }

    cout << cnt << '\n';

    return 0;
}