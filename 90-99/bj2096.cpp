#include <bits/stdc++.h>

using namespace std;

int N, mx[3], mn[3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        int a, b, c; cin >> a >> b >> c;

        int l = max({mx[0] + a, mx[1] + b});
        int m = max({mx[0] + a, mx[1] + b, mx[2] + c});
        int r = max({mx[1] + b, mx[2] + c});

        mx[0] = l;
        mx[1] = m;
        mx[2] = r;

        l = min({mn[0] + a, mn[1] + b});
        m = min({mn[0] + a, mn[1] + b, mn[2] + c});
        r = min({mn[1] + b, mn[2] + c});

        mn[0] = l;
        mn[1] = m;
        mn[2] = r;
    }

    cout << max({mx[0], mx[1], mx[2]}) << ' ' << min({mn[0], mn[1], mn[2]});

    return 0;
}