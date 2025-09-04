#include <bits/stdc++.h>    

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        int N; cin >> N;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int i = 0; i < N; i += 1){
            int x; cin >> x;
            pq.push(x);
        }
        
        ll ans = 0;
        while(pq.size() > 1){
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            pq.push(a + b);
            ans += a + b;
        }

        cout << ans << '\n';
    }

    return 0;
}