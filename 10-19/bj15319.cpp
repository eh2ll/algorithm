#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1e9 + 7;
int N;
ll res;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i += 1){
        int a, b; cin >> a >> b;
        ll tmp = 0, mul = 1;
        while(b > 0){
            if(b & 1){
                tmp += mul;
            }
            mul *= a;
            b >>= 1;
            
            tmp %= inf;
            mul %= inf;
        }
        res = (res + tmp) % inf;
    }

    cout << res << '\n';
    
    return 0;
}