#include <bits/stdc++.h>

using namespace std;

int N;
string s;
int dp[1003];

void sol(string& s, int idx){
    if(idx == s.size()) return;

    if(s[idx] == 'B'){
        for(int i = 0; i < idx; i += 1){
            if(s[i] != 'J') continue;
            dp[idx] = min(dp[idx], dp[i] + (idx - i) * (idx - i));
        }
    }
    else if(s[idx] == 'O'){
        for(int i = 0; i < idx; i += 1){
            if(s[i] != 'B') continue;
            dp[idx] = min(dp[idx], dp[i] + (idx - i) * (idx - i));
        }
    }
    else{
        for(int i = 0; i < idx; i += 1){
            if(s[i] != 'O') continue;
            dp[idx] = min(dp[idx], dp[i] + (idx - i) * (idx - i));
        }
    }

    sol(s, idx + 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> s;

    fill(dp, dp + 1003, 1048576);
    dp[0] = 0;
    sol(s, 0);

    if(dp[N - 1] == 1048576) cout << "-1\n";
    else cout << dp[N - 1] << '\n';

    return 0;
}