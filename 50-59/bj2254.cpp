#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

struct Point{
    ll x, y, p, q;
    Point(ll x, ll y, ll p, ll q) : x(x), y(y), p(p), q(q) {}
    bool operator<(const Point &O){
        if(q * O.p != p * O.q) return q * O.p < p * O.q;
        if(x != O.x) return x < O.x;
        return y < O.y;
    }
};

ll ccw(Point &a, Point &b, Point &c){
    ll ret = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return (ret > 0) - (ret < 0);
}

bool cross(Point &a, Point &b, Point &c, Point &d){
    ll ab = ccw(a, b, c) * ccw(a, b, d);
    ll cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0){
        if(a.x > b.x) swap(a, b);
        if(c.x > d.x) swap(c, d);
        return (c.x <= b.x && c.y <= b.y) && (a.x <= d.x && a.y <= d.y);
    }
    return ab <= 0 && cd <= 0;
}

bool laycast(vector<Point> &A, int x, int y){
    Point ct = Point(x, y, 1, 0);
    Point inf = Point(100'005, y + 1, 1, 0);
    int cnt = 0;
    for(int i = 0; i < A.size(); i += 1){
        Point a = A[i];
        Point b = A[(i + 1) % A.size()];
        if(cross(a, b, ct, inf)) cnt += 1;
        if(ccw(ct, a, b) == 0){
            if(a.x > b.x) swap(a, b);
            if(a.x <= x && x <= b.x && a.y <= y && y <= b.y){
                return 1;
            }
        }
    }
    if(cnt & 1) return 1;
    return 0;
}

int N, sx, sy;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> sx >> sy;
    vector<Point> A;
    for(int i = 0; i < N; i += 1){
        ll x, y; cin >> x >> y;
        A.emplace_back(x, y, 1, 0);
    }

    int ans = 0;
    while(A.size() >= 3){
        for(int i = 0; i < A.size(); i += 1){
            A[i].p = 1;
            A[i].q = 0;
        }
        sort(A.begin(), A.end());
        for(int i = 1; i < A.size(); i += 1){
            A[i].p = A[i].x - A[0].x;
            A[i].q = A[i].y - A[0].y;
        }
        sort(A.begin() + 1, A.end());

        stack<int> st;
        st.push(0);
        st.push(1);
        for(int i = 2; i < A.size(); i += 1){
            while(st.size() >= 2){
                int f = st.top(); st.pop();
                int s = st.top();
                if(ccw(A[s], A[f], A[i]) > 0){
                    st.push(f);
                    break;
                }
            }
            st.push(i);
        }

        vector<Point> B;
        set<int> unused;
        for(int i = 0; i < A.size(); i += 1) unused.insert(i);
        while(!st.empty()){
            B.push_back(A[st.top()]);
            unused.erase(st.top());
            st.pop();
        }
        reverse(B.begin(), B.end());

        if(!laycast(B, sx, sy)) break;
        ans += 1;

        vector<Point> C;
        for(auto &i : unused){
            C.push_back(A[i]);
        }
        A = move(C);
    }

    cout << ans << '\n';

    return 0;
}