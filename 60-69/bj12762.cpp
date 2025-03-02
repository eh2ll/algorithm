#include <bits/stdc++.h>

using namespace std;

int N, dp[1003][3];
vector<int> a1, a2, s1, s2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        int x; cin >> x;
        a1.push_back(-x);
        a2.push_back(-x);
    }
    reverse(a2.begin(), a2.end());

    int idx = 1;
    for(auto c : a1){
        if(s1.empty() || s1.back() < c){
            s1.push_back(c);
        }
        else{
            auto it = lower_bound(s1.begin(), s1.end(), c);
            *it = c;
        }
        dp[idx++][1] = s1.size();
    }
    idx = 1;
    for(auto c : a2){
        if(s2.empty() || s2.back() < c){
            s2.push_back(c);
        }
        else{
            auto it = lower_bound(s2.begin(), s2.end(), c);
            *it = c;
        }
        dp[idx++][2] = s2.size();
    }

    int mx = 0;
    for(int i = 1; i <= N; i += 1) mx = max(mx, dp[i][1] + dp[N - i + 1][2] - 1);

    cout << mx << '\n';

    return 0;
}