#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

bool cmp(const pii &A, const pii &B){
    if(A.Y * B.X != A.X * B.Y) return A.Y * B.X > A.X * B.Y;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<pair<pii, pii>> A(N);
    for(int i = 0; i < N; i += 1){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        A[i] = {{a, b}, {c, d}};
    }
    int Q; cin >> Q;
    vector<pii> B(Q);
    for(int i = 0; i < Q; i += 1){
        ll a, b; cin >> a >> b;
        B[i] = {a, b};
    }
    sort(B.begin(), B.end(), cmp);

    int cnt = 0;
    for(int i = 0; i < N; i += 1){
        auto [l, r] = A[i];
        if(!cmp(l, r)) swap(l, r);
        if(upper_bound(B.begin(), B.end(), r, cmp) - lower_bound(B.begin(), B.end(), l, cmp) > 0){
            cnt += 1;
        }
    }

    cout << N - cnt << '\n';

    return 0;
}