#include <bits/stdc++.h>

using namespace std;

long double A, B, C;
long double num = M_PI;

bool chk(long double x){
    if(C - A * x > B * sin(x)){
        return true;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;

    cout << fixed;
    cout.precision(10);
    
    long double st = 0, en = 100001;
    int it = 1000;
    while(en - st > 1e-10){
        long double mid = (st + en) / 2;
        // cout << mid << '\n';
        if(chk(mid)) st = mid;
        else en = mid;
    }

    cout << en << '\n';

    return 0;
}