#include <bits/stdc++.h>

using namespace std;
using ll = long double;

int T;

ll angle(int a1, int b1, int a2, int b2){
    ll A = (pow(a1, 2) + pow(b1, 2));
    ll B = (pow(a2, 2) + pow(b2, 2));
    ll C = (pow(a2 - a1, 2) + pow(b2 - b1, 2));

    ll res = acos((A + B - C) / (2 * sqrt(A * B)));
    
    return res / (2 * M_PI);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    cout.precision(5);
    cout << fixed;

    while(T--){
        int N; cin >> N;
        ll ret = 0;
        for(int i = 0; i < N; i += 1){
            int a1, b1, a2, b2;
            cin >> a1 >> b1 >> a2 >> b2;
            ret += angle(a1, b1, a2, b2);
            // cout << angle(a1, b1, a2, b2) << '\n';
        }
    
        cout << ret << '\n';
    }

    return 0;
}