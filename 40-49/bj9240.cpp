// rotating_calipers. justicehui

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct Point{
    ll x, y, p, q;
    Point(ll x, ll y, ll p, ll q) : x(x), y(y), p(p), q(q) {}
    Point() : x(0), y(0), p(0), q(0) {}
    Point(ll x, ll y) : Point(x, y, 1, 0) {}
    bool operator <(const Point & O){
        if(q * O.p != p * O.q) return q * O.p < p * O.q;
        if(y != O.y) return y < O.y;
        return x < O.x;
    }
};

int N;
vector<Point> P;

ll ccw(Point &a, Point &b, Point &c){
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool check(Point &a, Point &b, Point &c, Point &d){
    Point zero = Point(0, 0);
    Point ba = Point(b.x - a.x, b.y - a.y);
    Point dc = Point(d.x - c.x, d.y - c.y);

    return ccw(zero, ba, dc) >= 0;
}

ll dist(Point &a, Point &b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ld rotating_calipers(){
    vector<Point> hull;
    for(auto &i : P){
        while(hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), i) <= 0){
            hull.pop_back();
        }
        hull.push_back(i);
    }

    int idx = 0;
    ll mx = 0;
    for(int i = 0; i < hull.size(); i += 1){
        while(idx + 1 < hull.size() && check(hull[i], hull[i + 1], hull[idx], hull[idx + 1])){
            mx = max(mx, dist(hull[i], hull[idx]));
            idx += 1;
        }
        mx = max(mx, dist(hull[i], hull[idx]));
    }

    return sqrt(mx);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    P.resize(N);
    for(int i = 0; i < N; i += 1){
        ll x, y; cin >> x >> y;
        P[i] = Point(x, y);
    }
    sort(P.begin(), P.end());
    for(int i = 1; i < N; i += 1){
        P[i].p = P[i].x - P[0].x;
        P[i].q = P[i].y - P[0].y;
    }
    sort(P.begin() + 1, P.end());

    cout << fixed;
    cout.precision(7);

    cout << rotating_calipers() << '\n';

    return 0;
}