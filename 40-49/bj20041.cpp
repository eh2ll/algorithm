#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

pll en;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<pll> A(N);
    for(int i = 0; i < N; i += 1){
        cin >> A[i].X >> A[i].Y;
    }
    cin >> en.X >> en.Y;

    int u, d, l, r;
    u = d = l = r = 0;
    for(int i = 0; i < N; i += 1){
        int dx = en.X - A[i].X;
        int dy = en.Y - A[i].Y;

        if(abs(dx) > abs(dy)){
            if(dx > 0) r = 1;
            else l = 1;
        }
        else if(abs(dx) < abs(dy)){
            if(dy > 0) u = 1;
            else d = 1;
        }
        else{
            if(dx > 0) r = 1;
            else if(dx < 0) l = 1;
            if(dy > 0) u = 1;
            else if(dy < 0) d = 1;
        }
    }

    if(u + d + l + r == 4) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}