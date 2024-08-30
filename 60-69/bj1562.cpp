#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, arr[102][10][1<<10];
const int mod = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 1; i <= 9; i += 1) arr[1][i][1 << i] = 1;
    
    for(int i = 2; i <= N; i += 1){
        for(int j = 0; j < 10; j += 1){
            for(int bit = 0; bit < (1 << 10); bit += 1){
                if(j == 0){
                    arr[i][j][bit | (1 << j)] += arr[i - 1][j + 1][bit] % mod;
                }
                else if(j == 9){
                    arr[i][j][bit | (1 << j)] += arr[i - 1][j - 1][bit] % mod;
                }
                else{
                    arr[i][j][bit | (1 << j)] += arr[i - 1][j + 1][bit] % mod;
                    arr[i][j][bit | (1 << j)] += arr[i - 1][j - 1][bit] % mod;
                }
            }
        }
    }

    ll res = 0;
    for(int i = 0; i <= 9; i += 1){
        res = (res + arr[N][i][(1 << 10) - 1]) % mod;
    }

    cout << res << '\n';

    return 0;
}