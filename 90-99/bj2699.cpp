#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
using ll = long long;

struct Point{
    ll x, y, p, q;
    Point(int x1, int y1, int p1, int q1) : x(x1), y(y1), p(p1), q(q1){}
    Point() : Point(0, 0, 1, 0){}
    Point(int x1, int y1) : Point(x1, y1, 1, 0){}
    bool operator <(const Point& O){
        if(q * O.p != p * O.q) return q * O.p > p * O.q;
        if(y != O.y) return y > O.y;
        return x < O.x;
    }
};

ll ccw(Point& a, Point&b, Point& c){
    return 1LL*(b.x - a.x)*(c.y - a.y) - 1LL*(b.y - a.y)*(c.x - a.x);
}

int TC;
Point p[55];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    while(TC--){
        int N; cin >> N;
        memset(p, 0, sizeof(p));
        for(int i = 0; i < N; i += 1){
            int a, b; cin >> a >> b;
            p[i] = Point(a, b);
        }
        sort(p, p + N);

        for(int i = 1; i < N; i += 1){
            p[i].p = p[i].x - p[0].x;
            p[i].q = p[i].y - p[0].y;
        }
        sort(p + 1, p + N);

        stack<int> S;
        S.push(0);
        S.push(1);
        int nxt = 2;
        while(nxt < N){
            while(S.size() >= 2){
                int fi, se;
                fi = S.top(); S.pop();
                se = S.top();
                if(ccw(p[se], p[fi], p[nxt]) < 0){
                    S.push(fi);
                    break;
                }
            }
            S.push(nxt++);
        }

        vector<Point> V;
        while(!S.empty()){
            auto cur = S.top(); S.pop();
            V.push_back(p[cur]);
        }
        
        reverse(V.begin(), V.end());

        cout << V.size() << '\n';
        for(auto& i : V){
            cout << i.x << ' ' << i.y << '\n';
        }
    }

    return 0;
}