// kks227

#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[31][31][31][500];
char res[31];

int sol(int a, int b, int c, int k, int l){
    int& ret = dp[a][b][c][k];
    if(ret != -1) return ret;
    if(l == N) return ret = (k == K);

    if(sol(a + 1, b, c, k, l + 1)){
        res[l] = 'A';
        return ret = 1;
    }

    if(sol(a, b + 1, c, k + a, l + 1)){
        res[l] = 'B';
        return ret = 1;
    }

    if(sol(a, b, c + 1, k + a + b, l + 1)){
        res[l] = 'C';
        return ret = 1;
    }

    return ret = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    int cond = sol(0, 0, 0, 0, 0);

    if(cond){
        for(int i = 0; i < N; i += 1) cout << res[i];
        cout << '\n';
    }
    else cout << -1 << '\n';

    return 0;
}