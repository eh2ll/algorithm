#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using ld = long double;
using Point = pair<ld, ld>;

int chk(ld ret){
    return (ret > 0) - (ret < 0);
}

ld ccw(Point& a, Point&b, Point& c){
    ld ret = (b.X - a.X)*(c.Y - a.Y) - (b.Y - a.Y)*(c.X - a.X);
    return ret;
}

bool cross(Point& a, Point& b, Point& c, Point& d){
    int ab = chk(ccw(a, b, c)) * chk(ccw(a, b, d));
    int cd = chk(ccw(c, d, a)) * chk(ccw(c, d, b));
    if(ab == 0 && cd == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Point a, b; cin >> a.first >> a.second >> b.first >> b.second;
    Point c, d; cin >> c.first >> c.second >> d.first >> d.second;

    if(cross(a, b, c, d)){
        cout << 1 << '\n';
        ld ccwa = abs(ccw(c, d, a));
        ld ccwb = abs(ccw(c, d, b));
        // cout << ccwa << ' ' << ccwb << '\n';
        
        if(!(ccwa == 0 && ccwb == 0)){
            ld nx = (a.first * ccwb + b.first * ccwa) / (ccwa + ccwb);
            ld ny = (a.second * ccwb + b.second * ccwa) / (ccwa + ccwb);

            cout.precision(9);
            cout << fixed;
            cout << nx << ' ' << ny << '\n';
        }
        else{
            if(a > b) swap(a, b);
            if(c > d) swap(c, d);
            if(b == c) cout << c.first << ' ' << c.second << '\n';
            if(a == d) cout << a.first << ' ' << a.second << '\n';
        }
    }
    else cout << 0 << '\n';

    return 0;
}