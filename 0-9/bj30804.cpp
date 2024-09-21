#include <bits/stdc++.h>

using namespace std;

int N, res, arr[200005], vis[10];

int chk(){
    int cnt = 0, ret = 0;
    for(int i = 0; i < 10; i += 1){
        cnt += (vis[i] != 0);
        ret += vis[i];
    }

    if(cnt > 2) return -1;
    else return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
    }

    int en = 0;
    vis[arr[en]] += 1;
    for(int st = 0; st < N; st += 1){
        int tmp = 0;
        while(en < N && (tmp = chk()) >= 0){
            res = max(res, tmp);
            en += 1;
            vis[arr[en]] += 1;
            // en += 1;
            // cout << st << ' ' << en << ": " << tmp << ' ' << res << '\n';
        }
        vis[arr[st]] -= 1;
        // cout << st << ' ' << en << ": " << tmp << ' ' << res << '\n';
    }

    cout << res << '\n';

    return 0;
}