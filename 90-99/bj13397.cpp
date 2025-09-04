#include <bits/stdc++.h>

using namespace std;

int N, M, A[5'003];

bool check(int mid){
    int cnt = 0;
    int mn = A[0], mx = A[0];
    for(int i = 1; i < N; i += 1){
        mn = min(mn, A[i]);
        mx = max(mx, A[i]);
        if(mx - mn > mid){
            cnt += 1;
            mn = mx = A[i];
        }
    }
    // cout << mid << ' ' << cnt << '\n';

    return cnt + 1 <= M;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    bool flag = 1;
    for(int i = 0; i < N; i += 1){
        cin >> A[i];
        if(A[i] != A[0]) flag = 0;
    }

    int st = -1, en = 10'001;
    while(st + 1 < en){
        int mid = (st + en) / 2;
        if(check(mid)) en = mid;
        else st = mid;
    }

    cout << en << '\n';

    return 0;
}