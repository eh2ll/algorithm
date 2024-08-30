#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using ll = long double;
using Point = pair<ll, ll>;

ll N, res;
Point arr[10004];

ll ccw(Point a, Point b, Point c){
    ll ret = a.X * b.Y + b.X * c.Y + c.X * a.Y;
    ret -= a.Y * b.X + b.Y * c.X + c.Y * a.X;
    return ret / 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i].X >> arr[i].Y;
        if(!i) continue;
        res += ccw(arr[0], arr[i - 1], arr[i]);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(res) << '\n';

    return 0;
}