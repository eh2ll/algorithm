// jinhan814

#include <bits/stdc++.h>

using namespace std;
using matrix = vector<vector<long long>>;

const int MOD = 1e9 + 7;
int N, K;

matrix operator*(const matrix& a, const matrix& b){
    matrix ret(a.size(), vector<long long>(b[0].size()));
    for(int i = 0; i < a.size(); i += 1){
        for(int j = 0; j < a[0].size(); j += 1){
            for(int k = 0; k < b[0].size(); k += 1){
                ret[i][k] = (ret[i][k] + a[i][j] * b[j][k]) % MOD;
            }
        }
    }
    return ret;
}

matrix sol(matrix A, int k){
    matrix ret(N, vector<long long>(N));
    for(int i = 0; i < N; i += 1) ret[i][i] = 1;
    while(k > 0){
        if(k & 1){
            ret = ret * A;
        }
        k >>= 1;
        A = A * A;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    matrix A(N, vector<long long>(N));
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < N; j += 1){
            cin >> A[i][j];
        }
    }

    A = sol(A, K);
    int cnt = 0;
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < N; j += 1){
            cnt = (cnt + A[i][j]) % MOD;
        }
    }

    cout << cnt << '\n';

    return 0;
}