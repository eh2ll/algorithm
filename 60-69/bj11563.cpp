//kks227

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using ll = long double;
using Point = pair<ll, ll>;

int N, M;
pair<Point, Point> arr1[2003], arr2[2003];

ll disPo(Point a, Point b){
    return sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
}

ll dot(ll a1, ll a2, ll b1, ll b2){
    return a1 * b1 + a2 * b2;
}

ll cross(ll a1, ll a2, ll b1, ll b2){
    return a1 * b2 - b1 * a2;
}

ll perpen(Point a, Point b, Point c){
    ll dot1 = dot(b.X - a.X, b.Y - a.Y, c.X - a.X, c.Y - a.Y);
    ll dot2 = dot(a.X - b.X, a.Y - b.Y, c.X - b.X, c.Y - b.Y);

    if(dot1 * dot2 >= 0){
        return abs(cross(b.X - a.X, b.Y - a.Y, c.X - a.X, c.Y - a.Y) / disPo(a, b));
    }
    return -1;
}

ll sol(){
    ll res = 1e9;
    ll tmp = 0;
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < M; j += 1){
            auto [c1, c2] = arr1[i];
            auto [c3, c4] = arr2[j];

            ll dist = min({disPo(c1, c3), disPo(c1, c4), disPo(c2, c3), disPo(c2, c4)});
            res = min(res, dist);

            tmp = perpen(c1, c2, c3);
            if(tmp >= 0) res = min(res, tmp);

            tmp = perpen(c1, c2, c4);
            if(tmp >= 0) res = min(res, tmp);

            tmp = perpen(c3, c4, c1);
            if(tmp >= 0) res = min(res, tmp);

            tmp = perpen(c3, c4, c2);
            if(tmp >= 0) res = min(res, tmp);
        }
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i += 1){
        cin >> arr1[i].X.X >> arr1[i].X.Y >> arr1[i].Y.X >> arr1[i].Y.Y;
    }
    for(int i = 0; i < M; i += 1){
        cin >> arr2[i].X.X >> arr2[i].X.Y >> arr2[i].Y.X >> arr2[i].Y.Y;
    }

    ll res = sol();

    cout << fixed;
    cout.precision(7);
    cout << res << '\n';

    return 0;
}