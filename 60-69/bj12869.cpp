#include <bits/stdc++.h>

using namespace std;

int N;
int dp[61][61][61];

int sol(int a, int b, int c){
    a = max(0, a);
    b = max(0, b);
    c = max(0, c);

    if(a == 0 && b == 0 && c == 0) return 0;

    int& ret = dp[a][b][c];
    if(ret != -1) return ret;

    ret = 0x3f3f3f3f;

    ret = min(ret, sol(a - 9, b - 3, c - 1) + 1);
    ret = min(ret, sol(a - 9, b - 1, c - 3) + 1);
    ret = min(ret, sol(a - 3, b - 9, c - 1) + 1);
    ret = min(ret, sol(a - 3, b - 1, c - 9) + 1);
    ret = min(ret, sol(a - 1, b - 9, c - 3) + 1);
    ret = min(ret, sol(a - 1, b - 3, c - 9) + 1);

    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int a = 0, b = 0, c = 0; 
    cin >> a;
    if(N >= 2) cin >> b;
    if(N >= 3) cin >> c;

    memset(dp, -1, sizeof(dp));
    
    cout << sol(a, b, c) << '\n';

    return 0;
}