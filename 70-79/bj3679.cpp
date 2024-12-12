#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point{
    int x, y, p, q, idx;
    Point(): Point(0, 0, 1, 0, 0){}
    Point(int x1, int y1, int i1): Point(x1, y1, 1, 0, i1){}
    Point(int x1, int y1, int p1, int q1, int i1): x(x1), y(y1), p(p1), q(q1), idx(i1){}
    bool operator <(const Point& O){
        if(1LL*q*O.p != 1LL*p*O.q) return 1LL*q*O.p < 1LL*p*O.q;
        if(y != O.y) return y < O.y;
        return x < O.x;
    }
};

int TC, N;
Point p[2003];

ll ccw(Point& a, Point& b, Point& c){
    return 1LL*(b.x - a.x)*(c.y - a.y) - 1LL*(b.y - a.y)*(c.x - a.x);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    while(TC--){
        cin >> N;
        for(int i = 0; i < N; i += 1){
            int a, b; cin >> a >> b;
            p[i] = Point(a, b, i);
        }
        sort(p, p + N);

        for(int i = 1; i < N; i += 1){
            p[i].p = p[i].x - p[0].x;
            p[i].q = p[i].y - p[0].y;
        }
        sort(p + 1, p + N);

        int j = N - 1;
        while(!ccw(p[0], p[j - 1], p[j])) j -= 1;

        for(int i = 0; i < j; i += 1) cout << p[i].idx << ' ';
        for(int i = N - 1; i >= j; i -= 1) cout << p[i].idx << ' ';
        cout << '\n';
    }

    return 0;
}