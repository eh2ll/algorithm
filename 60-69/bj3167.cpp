#include <bits/stdc++.h>

using namespace std;

int N, K, cntmx, cntmn;
int mx[2], mn[2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i += 1){
        int a, b; cin >> a >> b;
        if(i % K == 1){
            mx[0] += mx[1];
            mx[1] = 0;
            mn[0] += mn[1];
            mn[1] = 0;

            mx[0] -= a;
            mx[1] += b;
            mn[0] -= a;
            mn[1] += b;
        }
        else{
            int out1 = min(mx[1], a);
            cntmx += out1;
            mx[1] -= out1;
            mx[0] -= a - out1;
            mx[1] += b;

            int out2 = min(mn[0], a);
            cntmn += a - out2;
            mn[0] -= out2;
            mn[1] -= a - out2;
            mn[1] += b;
        }
        // cout << mx[0] << ' ' << mx[1] << ' ';
        // cout << mn[0] << ' ' << mn[1] << '\n';
    }

    if(K != 1) cout << cntmn << ' ' << cntmx << '\n';
    else cout << 0 << ' ' << 0 << '\n';
    
    return 0;
}