// justicehui github
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

using ll = long long;
using Point = pair<ll, ll>;

Point a, b, c, d;

int ccw(Point a, Point b, Point c){
    ll res = a.X * b.Y + b.X * c.Y + c.X * a.Y;
    res -= b.X * a.Y + c.X * b.Y + a.X * c.Y;
    return (res > 0) - (res < 0);
}

bool cross(Point a, Point b, Point c, Point d){
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a.X >> a.Y >> b.X >> b.Y;
    cin >> c.X >> c.Y >> d.X >> d.Y;

    if(cross(a, b, c, d)) cout << '1' << '\n';
    else cout << '0' << '\n';

    return 0;
}