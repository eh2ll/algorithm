#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using ll = long long;
using Point = pair<ll, ll>;

Point a, b, c;

int ccw(Point a, Point b, Point c){
    ll res = a.X * b.Y + b.X * c.Y + c.X * a.Y;
    res -= a.Y * b.X + b.Y * c.X + c.Y * a.X;
    return (res > 0) - (res < 0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y;

    cout << ccw(a, b, c) << '\n';

    return 0;
}