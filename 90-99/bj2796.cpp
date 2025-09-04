#include <bits/stdc++.h>

using namespace std;

struct rect{
    int l, r, b, t;
    rect(int x, int y, int p){
        l = x - p;
        r = x + p;
        b = y - p;
        t = y + p;
    }
    rect(int x1, int x2, int y1, int y2){
        l = x1;
        r = x2;
        b = y1;
        t = y2;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int x, y, p; cin >> x >> y >> p;
    rect R(x, y, p);

    long long res = 0;
    for(int i = 1; i < N; i += 1){
        cin >> x >> y >> p;
        rect A(x, y, p);
        int diff = max({A.l - R.r, R.l - A.r, A.b - R.t, R.b - A.t});
        if(diff < 0) diff = 0;
        res += diff;

        R.l -= diff;
        R.r += diff;
        R.b -= diff;
        R.t += diff;
        rect inter(max(R.l, A.l), min(R.r, A.r), max(R.b, A.b), min(R.t, A.t));

        R = inter;
    }
    cout << res << '\n';

    return 0;
}