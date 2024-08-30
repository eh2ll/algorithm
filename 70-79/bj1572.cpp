// justicehui, codeforces blog ..

#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update>

int N, K;
ordered_set S;
ll ans;
vector<ll> V;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    V.resize(N + 1);
    for(int i = 1; i <= N; i += 1){
        cin >> V[i];
    }
    for(int i = 1; i <= K; i += 1){
        S.insert({V[i], i});
    }

    ans += (*S.find_by_order((K + 1) / 2 - 1)).first;
    for(int i = K + 1; i <= N; i += 1){
        S.erase({V[i - K], i - K});
        S.insert({V[i], i});
        ans += (*S.find_by_order((K + 1) / 2 - 1)).first;
    }

    cout << ans << '\n';

    return 0;
}