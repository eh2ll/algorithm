#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point{
    int x, y;
    Point(int x1, int y1) : x(x1), y(y1){}
    Point() : Point(0, 0){}
    bool operator<(const Point& O){
        if(y != O.y) return y < O.y;
        return x < O.x;
    }
};

Point arr[4];

ll ccw(Point& a, Point& b, Point& c){
    return 1LL*(b.x - a.x)*(c.y - a.y) - 1LL*(b.y - a.y)*(c.x - a.x);
}

bool cross(Point& a, Point& b, Point& c, Point& d){
    ll ab = ccw(a, b, c) * ccw(a, b, d);
    ll cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0){
        if(b < a) swap(a, b);
        if(d < c) swap(c, d);
        return !((b < c) || (d < a));
    }
    return ab < 0 && cd < 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 4; i += 1){
        int a, b; cin >> a >> b;
        arr[i] = Point(a, b);
    }

    if(cross(arr[0], arr[1], arr[2], arr[3])) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}