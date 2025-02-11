#include <bits/stdc++.h>

using namespace std;

int N, cnt;

struct sets{
    int p1, p2;

    bool operator<(const sets& O){
        return p1 < O.p1;
    }
};

int toPoint(int a, int b){
    int ret = 0;
    if(a == 1){
        ret = 4 * 50 + (50 - b);
    }
    else if(a == 2){
        ret = 2 * 50 + b;
    }
    else if(a == 3){
        ret = 1 * 50 + b;
    }
    else if(a == 4){
        ret = 3 * 50 + (50 - b);
    }

    return ret;
}

bool comp(int l, int r, int x1, int x2){
    bool flag = 1;
    if(l < x1 && x1 < r && l < x2 && x2 < r){
        flag = 0;
    }
    else if(x1 < l && r < x2){
        flag = 0;
    }
    else if(x1 < l && x2 < l){
        flag = 0;
    }
    else if(r < x1 && r < x2){
        flag = 0;
    }
    return flag;
}

sets bor[102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N / 2; i += 1){
        int a, b, c, d; cin >> a >> b >> c >> d;
        int p1 = toPoint(a, b);
        int p2 = toPoint(c, d);
        bor[i] = {min(p1, p2), max(p1, p2)};
    }

    sort(bor, bor + N / 2);
    
    // for(int i = 0; i < N / 2; i += 1){
    //     cout << bor[i].p1 << ' ' << bor[i].p2 << '\n';
    // }

    int mx = 0, tot = 0;
    for(int i = 0; i < N / 2; i += 1){
        int cnt1 = 0, cnt2 = 0;
        for(int j = 0; j < i; j += 1){
            if(comp(bor[i].p1, bor[i].p2, bor[j].p1, bor[j].p2)){
                cnt1 += 1;
            }
        }
        for(int j = i + 1; j < N / 2; j += 1){
            if(comp(bor[i].p1, bor[i].p2, bor[j].p1, bor[j].p2)){
                cnt2 += 1;
            }
        }
        mx = max(mx, cnt1 + cnt2);
        tot += cnt2;
        // cout << i << ' ' << cnt1 << ' ' << cnt2 << '\n';
    }

    cout << tot << '\n' << mx << '\n';

    return 0;
}