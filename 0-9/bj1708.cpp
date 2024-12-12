// kks227

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using ll = long long;

struct Point{
    int x, y, p, q;
    Point(): Point(0, 0, 1, 0){}
    Point(int x1, int y1): Point(x1, y1, 1, 0){}
    Point(int x1, int y1, int p1, int q1): x(x1), y(y1), p(p1), q(q1){}
    bool operator <(const Point& O){
        if(1LL * q * O.p != 1LL * p * O.q) return 1LL * q * O.p < 1LL * p * O.q;
        if(y != O.y) return y < O.y;
        return x < O.x;
    }
};

int N;
Point P[100005];

int ccw(Point& a, Point& b, Point& c){
    return 1LL*(b.x - a.x)*(c.y - a.y) - 1LL*(b.y - a.y)*(c.x - a.x);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        int a, b; cin >> a >> b;
        P[i] = {a, b, 1, 0};
    }
    sort(P, P + N);

    for(int i = 1; i < N; i += 1){
        P[i].p = P[i].x - P[0].x;
        P[i].q = P[i].y - P[0].y;
    }
    sort(P + 1, P + N);

    stack<int> S;
    S.push(0);
    S.push(1);
    int nxt = 2;
    while(nxt < N){
        while(S.size() >= 2){
            int first, second;
            first = S.top(); S.pop();
            second = S.top();
            if(ccw(P[second], P[first], P[nxt]) > 0){
                S.push(first);
                break;
            }
        }
        S.push(nxt++);
    }

    cout << S.size() << '\n';

    return 0;
}