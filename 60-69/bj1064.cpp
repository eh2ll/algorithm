#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using ll = long double;
using Point = pair<ll, ll>;

ll dist(Point a, Point b){
    return sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
}

bool ccw(Point a, Point b, Point c){
    ll res = a.X * b.Y + b.X * c.Y + c.X * a.Y;
    res -= a.Y * b.X + b.Y * c.X + c.Y * a.X;
    return (res > 0) - (res < 0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Point a, b, c;
    cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y;
    ll distab = dist(a, b);
    ll distbc = dist(b, c);
    ll distca = dist(c, a);

    ll mn = min({distab, distbc, distca});
    ll mx = max({distab, distbc, distca});

    cout << fixed;
    cout.precision(9);
    if(ccw(a, b, c) == 0) cout << "-1\n";
    else cout << 2 * (mx - mn) << '\n';

    return 0;
}