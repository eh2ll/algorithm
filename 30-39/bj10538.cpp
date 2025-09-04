#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int H1, W1, H2, W2;
int p1 = 293, p2 = 307, m1 = 1000000007, m2 = 1000000009;
string S1[2'003], S2[2'003];
int d1[2'003][2'003], d2[2'003][2'003];

ll mod(ll a, ll m){
    return (a % m + m) % m;
}

vector<ll> fail(vector<ll> &cp){
    int N = cp.size();
    vector<ll> f(N, 0);
    int j = 0;
    for(int i = 1; i < N; i += 1){
        while(j > 0 && cp[i] != cp[j]) j = f[j - 1];
        if(cp[i] == cp[j]) f[i] = ++j;
    }
    return f;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> H1 >> W1 >> H2 >> W2;
    for(int i = 0; i < H1; i += 1){
        cin >> S1[i];
        for(int j = 0; j < W1; j += 1){
            if(S1[i][j] == 'o') d1[i][j] = 1;
            else d1[i][j] = 2;
        }
    }
    for(int i = 0; i < H2; i += 1){
        cin >> S2[i];
        for(int j = 0; j < W2; j += 1){
            if(S2[i][j] == 'o') d2[i][j] = 1;
            else d2[i][j] = 2;
        }
    }

    vector<ll> cp1(W1), cp2(W1);
    for(int j = 0; j < W1; j += 1){
        ll tmp1 = 0, tmp2 = 0;
        for(int i = 0; i < H1; i += 1){
            tmp1 = (tmp1 * p1 + d1[i][j]) % m1;
            tmp2 = (tmp2 * p2 + d1[i][j]) % m2;
        }
        cp1[j] = tmp1;
        cp2[j] = tmp2;
    }

    ll of1 = 1, of2 = 1;
    for(int i = 0; i < H1; i += 1){
        of1 = (of1 * p1) % m1;
        of2 = (of2 * p2) % m2;
    }

    vector<vector<ll>> br1(H2 - H1 + 1, vector<ll>(W2, 0)), br2(H2 - H1 + 1, vector<ll>(W2, 0));
    for(int j = 0; j < W2; j += 1){
        ll tmp1 = 0, tmp2 = 0;
        for(int i = 0; i < H2; i += 1){
            tmp1 = (tmp1 * p1 + d2[i][j]) % m1;
            tmp2 = (tmp2 * p2 + d2[i][j]) % m2;

            if(i >= H1){
                tmp1 = mod(tmp1 - (d2[i - H1][j] * of1) % m1, m1);
                tmp2 = mod(tmp2 - (d2[i - H1][j] * of2) % m2, m2);
            }

            if(i >= H1 - 1){
                br1[i - H1 + 1][j] = tmp1;
                br2[i - H1 + 1][j] = tmp2;
            }
        }
    }

    vector<ll> f1 = fail(cp1);
    vector<ll> f2 = fail(cp2);
    ll cnt = 0;
    for(int i = 0; i < H2 - H1 + 1; i += 1){
        vector<ll> tmp(W2, 0);
        int j = 0;
        for(int k = 0; k < W2; k += 1){
            while(j > 0 && br1[i][k] != cp1[j] && br2[i][k] != cp2[j]) j = f1[j - 1];
            if(br1[i][k] == cp1[j] && br2[i][k] == cp2[j]) tmp[k] = ++j;
            if(tmp[k] == W1){
                cnt += 1;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}