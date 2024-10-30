#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[100005];

int sol(int x){
    int cnt = 0, tmp = 0;
    for(int i = 0; i < N; i += 1){
        if(tmp + arr[i] <= x){
            tmp += arr[i];
        }
        else{
            tmp = arr[i];
            cnt += 1;
        }
    }
    if(tmp > 0) cnt += 1;
    
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int mx = 0;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    int st = mx - 1, en = 0x3f3f3f3f;
    while(st + 1 < en){
        int mid = (st + en + 1) / 2;
        // cout << st << ' ' << en << "// " << sol(st) << ' ' << sol(mid) << ' ' << sol(en) << '\n';
        if(sol(mid) <= M) en = mid;
        else st = mid; 
    }

    cout << en << '\n';

    return 0;
}