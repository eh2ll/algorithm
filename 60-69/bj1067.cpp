// FFT. ibm2006, kks227

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lf = double;
using cd = complex<lf>;

const lf PI = acos(-1);
vector<cd> X, Y;

void fft(vector<cd> &a, bool invert){
    ll n = a.size();
    ll i, j;
    for(i = 1, j = 0; i < n; i += 1){
        ll bit = n >> 1;
        for(; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if(i < j) swap(a[i], a[j]);
    }
    for(ll len = 2; len <= n; len <<= 1){
        lf ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for(i = 0; i < n; i += len){
            cd w(1);
            for(j = 0; j < len / 2; j += 1){
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if(invert){
        for(auto &x : a) x /= n;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int need = 1;
    while(need < 2 * N) need <<= 1;
    X.resize(need);
    for(int i = 0; i < N; i += 1){
        int x; cin >> x;
        X[i] = x;
        X[i + N] = x;
    }
    Y.resize(need);
    for(int i = N - 1; i >= 0; i -= 1){
        int y; cin >> y;
        Y[i] = y;
    }

    fft(X, false);
    fft(Y, false);
    for(int i = 0; i < need; i += 1){
        X[i] *= Y[i];
    }
    fft(X, true);

    ll mx = -1;
    for(int i = N - 1; i <= 2 * N - 2; i += 1){
        mx = max(mx, (ll)(X[i].real() + 0.5));
        // cout << i << ' ' << (ll)(X[i].real() + 0.5) << '\n';
    }
    cout << mx << '\n';

    return 0;
}