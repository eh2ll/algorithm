#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

struct Point{
    ll x, y, p, q;
    Point(ll x1, ll y1, ll p1, ll q1) : x(x1), y(y1), p(p1), q(q1){}
    Point() : Point(0, 0, 1, 0){}
    Point(ll x1, ll y1) : Point(x1, y1, 1, 0){}
    bool operator<(const Point& O){
        if(q*O.p != p*O.q) return q*O.p < p*O.q;
        if(y != O.y) return y < O.y;
        return x < O.x;
    }
};

ll dis(Point& a, Point& b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

ll dot(Point& a, Point& b, Point& c){
    ll ret = 1LL*(b.x - a.x)*(c.x - a.x);
    ret += 1LL*(b.y - a.y)*(c.y - a.y);
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    Point arr[4];
    while(T--){
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < 4; i += 1){
            int a, b; cin >> a >> b;
            arr[i] = Point(a, b);
        }
        sort(arr, arr + 4);
        for(int i = 0; i < 4; i += 1){
            arr[i].p = arr[i].x - arr[0].x;
            arr[i].q = arr[i].y - arr[0].y;
        }
        sort(arr + 1, arr + 4);

        ll ab = dis(arr[0], arr[1]);
        ll bc = dis(arr[1], arr[2]);
        ll cd = dis(arr[2], arr[3]);
        ll da = dis(arr[3], arr[0]);
        ll ret = dot(arr[1], arr[0], arr[2]);
        // cout << ab << ' ' << bc << ' ' << cd << ' ' << da << ' ' << ret << '\n';
        if((ab == bc && bc == cd && cd == da && da == ab) && (ret == 0)){
            cout << 1 << '\n';
        }
        else{
            cout << 0 << '\n';
        }
    }

    return 0;
}