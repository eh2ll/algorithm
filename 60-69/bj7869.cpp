#include <bits/stdc++.h>

using namespace std;
using ld = long double;

ld dist(ld x1, ld y1, ld x2, ld y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

ld cos2(ld r1, ld dis, ld r2){
    // theta = (a^2 + b^2 - c^2) / 2ab
    return 2 * acos( (pow(r1, 2) + pow(dis, 2) - pow(r2, 2)) / (2 * r1 * dis) );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ld x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    if(r1 > r2){
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }

    ld dis = dist(x1, y1, x2, y2);

    cout.precision(3);
    cout << fixed;

    if(dis >= r1 + r2){
        cout << 0.0 << '\n';
    }
    else if(dis + r1 > r2){
        ld a1 = cos2(r1, dis, r2);
        ld a2 = cos2(r2, dis, r1);
        ld area = 0.5 * (pow(r1, 2) * a1 - pow(r1, 2) * sin(a1) + pow(r2, 2) * a2 - pow(r2, 2) * sin(a2));
        
        cout << area << '\n';
    }
    else cout << r1 * r1 * M_PI << '\n';

    return 0;
}