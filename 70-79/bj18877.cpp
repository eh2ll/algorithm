#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll N, M;
pll A[100'005];

bool chk(ll x){
    ll cnt = 0;
    ll s = -2e18;
    for(int i = 0; i < M; i += 1){
        s = max(s + x, A[i].first);
        if(s > A[i].second){
            s -= x;
            continue;
        }
        ll d = (A[i].second - s) / x;
        for(ll t = 0; t <= d; t += 1){
        }
        cnt += d + 1;
        s += d * x;
    }

    if(cnt >= N) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i += 1){
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A + M);

    ll st = 1, en = 2e18;
    while(st + 1 < en){
        ll mid = (st + en + 1) / 2;
        if(chk(mid)) st = mid;
        else en = mid;
        // cout << mid << '\n';
    }
    
    cout << st << '\n';

    return 0;
}

// #include <bits/stdc++.h>
 
// using namespace std;
 
// typedef long long LL;
 
// #define INF 2000000000
// #define FF first
// #define SS second

// int n, m;
 
// vector<pair<LL,LL>> intervals;
// vector<LL> dp;
// bool ok(LL d) {
//     LL prev = -1LL * INF * INF;
    
//     int cnt = 0;
//     for (auto& i : intervals) {
//         while (max(prev + d, i.FF) <= i.SS) {
//             prev = max(prev + d, i.FF);
//             dp.push_back(prev);
//             cnt++;
//             if (cnt >= n) break;
//         }
//         if (cnt >= n) break;
//     }
 
//     return (cnt >= n);
// }
 
// int main() {
//     // freopen("socdist.in","r",stdin);
//     // freopen("socdist.out","w",stdout);
//     cin >> n >> m;

//     intervals.resize(m);
//     for (int i = 0; i < m; ++i) 
//         cin >> intervals[i].FF >> intervals[i].SS;
 
//     sort(intervals.begin(), intervals.end());
 
//     LL lo = 1;
//     LL hi = 1LL * INF * INF;
//     LL res = -1;
 
//     while (lo <= hi) {
//         dp.clear();
//         LL mid = (lo + hi) / 2;
 
//         if (ok(mid)) {
//             res = mid;
//             lo = mid + 1;
//         }
//         else {
//             hi = mid - 1;
//         }
//     }

//     for(auto c : dp) cout << c << ' ';
//     cout << '\n';
 
//     cout << res << "\n";
// }