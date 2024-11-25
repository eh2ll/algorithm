#include <bits/stdc++.h>

using namespace std;

string s;
char res[51];
int dp[51][51][51][3][3];
map<char, int> mp;

int sol(int a, int b, int c, int p, int pp){
    // cout << a << ' ' << b << ' ' << c << ' ' << p << ' ' << pp << '\n';
    // cout << dp[a][b][c][p][pp] << '\n';

    int pos = a + b + c;
    int& ret = dp[a][b][c][p][pp];
    if(ret != -1) return ret;
    if(pos == (int)s.size()) return ret = 1;


    if(a < mp['A']){
        res[pos] = 'A';
        if(sol(a + 1, b, c, 0, p)) return ret = 1;
    }

    if(b < mp['B']){
        res[pos] = 'B';
        if(p != 1 && sol(a, b + 1, c, 1, p)) return ret = 1;
    }

    if(c < mp['C']){
        res[pos] = 'C';
        if(p != 2 && pp != 2 && sol(a, b, c + 1, 2, p)) return ret = 1;
    }

    return ret = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for(int i = 0; i < (int)s.size(); i += 1){
        mp[s[i]] += 1;        
    }

    // cout << mp['A'] << ' ' << mp['B'] << ' ' << mp['C'] << '\n';

    memset(dp, -1, sizeof(dp));

    if(sol(0, 0, 0, 0, 0)){
        for(int i = 0; i < (int)s.size(); i += 1) cout << res[i];
        cout << '\n';
    }
    else cout << -1 << '\n';

    return 0;
}