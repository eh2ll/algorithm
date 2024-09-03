#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using ll = long long;
using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

ordered_set S;
int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        int x; cin >> x;
        S.insert(x);
        cout << i - S.order_of_key(x) << '\n';
    }

    return 0;
}