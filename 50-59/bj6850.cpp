#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

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
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<Point> A;
    for(int i = 0; i < N; i += 1){
        ll x, y; cin >> x >> y;
        A.emplace_back(x, y, 1, 0);
    }
    sort(A.begin(), A.end());
    for(int i = 1; i < N; i += 1){
        A[i].p = A[i].x - A[0].x;
        A[i].q = A[i].y - A[0].y;
    }
    sort(A.begin() + 1, A.end());

    stack<int> st;
    st.push(0);
    st.push(1);
    for(int i = 2; i < N; i += 1){
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

    int base = st.top();
    ll ans = 0;
    while(st.size() > 1){
        int f = st.top(); st.pop();
        int s = st.top();
        ans += ccw(A[base], A[f], A[s]);
    }

    cout << abs(ans)/2/50 << '\n';

    return 0;
}