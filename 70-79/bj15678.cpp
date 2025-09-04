#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, D; cin >> N >> D;
    vector<ll> A(N);
    for(auto &c : A) cin >> c;
    vector<ll> dp(N);
    deque<pll> dq;
    for(int i = 0; i < N; i += 1){
        dp[i] = A[i];
        while(!dq.empty() && i - dq.front().first > D) dq.pop_front();
        if(!dq.empty()) dp[i] = max(dp[i], dq.front().second + A[i]);
        while(!dq.empty() && dq.back().second < dp[i]) dq.pop_back();
        dq.push_back({i, dp[i]});
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}