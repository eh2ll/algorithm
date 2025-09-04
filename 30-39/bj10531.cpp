// FFT. koosaga, cubelover, ibm2006, jinhan814, justicehui, kks227, casterian

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lf = long double;
using cd = complex<lf>;

const lf PI = acos(-1);
int N, M, cnt;
vector<cd> K;

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

    cin >> N;
    K.resize(524'288);
    for(int i = 0; i < N; i += 1){
        int k; cin >> k;
        K[k] = 1;
    }
    K[0] = 1;

    fft(K, false);
    for(int i = 0; i < 524'288; i += 1) K[i] *= K[i];
    fft(K, true);

    cin >> M;
    for(int i = 0; i < M; i += 1){
        int d; cin >> d;
        if(int(K[d].real() + (K[d].real() > 0 ? 0.5 : -0.5)) != 0) cnt += 1;
    }

    cout << cnt << '\n';

    return 0;
}