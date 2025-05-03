#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[1'003];

int chk(int x){
    if(x == 0) return 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < A[i] / x; j += 1){
            pq.push(x);
        }
        if(A[i] % x != 0) pq.push(A[i] % x);
    }

    int cnt = pq.size();
    // cout << "x, cnt : " << x << ' ' << cnt << '\n';
    if(cnt < K) return 0;

    while(pq.size() > K) pq.pop();
    int res = 0;
    while(pq.size() > K / 2){
        res += pq.top();
        pq.pop();
    }

    // cout << "res : " << res << '\n';
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i += 1){
        cin >> A[i];
    }

    // int mn = 0, mx = 1'000'001;
    // while(mn + 1 < mx){
    //     int med = (mn + mx) / 2;
    //     int st = 0, en = 1001;
    //     bool flag = 0;
    //     while(st <= 1000){
    //         if(chk(st, med)){
    //             flag = 1;
    //             break;
    //         }
    //         st += 1;
    //     }
    //     if(flag) mn = med;
    //     else mx = med;
    //     // while(st + 1 < en){
    //     //     int mid = (st + en + 1) / 2;
    //     //     if(chk(mid, med)) st = mid;
    //     //     else en = mid;
    //     // }
    //     // if(chk(st, med)) mn = med;
    //     // else mx = med;
    //     // cout << med << ' ' << st << ' ' << mn << ' ' << mx << '\n';
    // }

    int st = 0, mx = 0;
    bool flag = 0;
    while(st <= 1000){
        mx = max(mx, chk(st));
        st += 1;
    }

    cout << mx << '\n';

    return 0;
}