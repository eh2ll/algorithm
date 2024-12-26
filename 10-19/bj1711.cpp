#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int N;
pll arr[1503];

ll dot(pll& a, pll& b, pll& c){
    ll ret = 1LL*(b.first - a.first)*(c.first - a.first);
    ret += 1LL*(b.second - a.second)*(c.second - a.second);
    // cout << ": " << ret << '\n';
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i].first >> arr[i].second;
    }

    vector<int> V;
    for(int i = 0; i < N - 3; i += 1) V.push_back(0);
    for(int i = 0; i < 3; i += 1) V.push_back(1);

    ll cnt = 0;
    for(int i = 0; i < N; i += 1){
        for(int j = i + 1; j < N; j += 1){
            for(int k = j + 1; k < N; k += 1){
                if(i == j || j == k || k == i) continue;
                // cout << i << ' ' << j << ' ' << k << ' ';
                if(dot(arr[i], arr[j], arr[k]) == 0) cnt += 1;
                if(dot(arr[j], arr[i], arr[k]) == 0) cnt += 1;
                if(dot(arr[k], arr[i], arr[j]) == 0) cnt += 1;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}