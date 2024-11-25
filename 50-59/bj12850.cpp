// jinhan814

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using mat = vector<vector<ll>>;

int N, D;
mat bor = {
    {0, 1, 0, 0, 1, 0 ,0, 0},
    {1, 0, 1, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 1, 0},
    {1, 1, 1, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 1},
    {0, 0, 1, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0}
};

mat operator * (const mat &a, const mat &b){
    mat ret(a.size(), vector<ll>(b[0].size()));
    for(int i = 0; i < a.size(); i += 1){
        for(int j = 0; j < b[0].size(); j += 1){
            for(int k = 0; k < b[0].size(); k += 1){
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= 1000000007;
            }
        }
    }
    return ret;
}

mat pow(mat a, int b){
    mat ret(a.size(), vector<ll>(a.size()));
    for(int i = 0; i < a.size(); i += 1) ret[i][i] = 1;
    while(b > 0){
        if(b & 1) ret = ret * a;
        b /= 2;
        a = a * a;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> D;
    bor = pow(bor, D);
    cout << bor[0][0] << '\n';

    return 0;
}