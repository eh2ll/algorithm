#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
ll arr[100005];

ll sol(int l, int r){
    if(l >= r) return arr[r];

    int mid = (l + r + 1) / 2; 
    ll c1 = sol(l, mid - 1);
    ll c2 = sol(mid, r);

    ll h = min(arr[mid - 1], arr[mid]), tot = h * 2, tl = mid - 2, tr = mid + 1;

    while(l <= tl && tr <= r){
        if(arr[tl] > arr[tr]){
            h = min(h, arr[tl]);
            tot = max(tot, h * (tr - tl));
            tl -= 1;
        }
        else{
            h = min(h, arr[tr]);
            tot = max(tot, h * (tr - tl));
            tr += 1;
        }
        // cout << tl << ' ' << tr << ' ' << h << ' ' << tot << '\n';
    }
    while(l <= tl){
        h = min(h, arr[tl]);
        tot = max(tot, h * (r - tl + 1));
        tl -= 1;
    }
    while(tr <= r){
        h = min(h, arr[tr]);
        tot = max(tot, h * (tr - l + 1));
        tr += 1;
    }

    // cout << l << ' ' << r << ' ' << c1 << ' ' << tot << ' ' << c2 << '\n';
    return max({c1, tot, c2});
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin >> N;
        if(!N) break;

        memset(arr, 0, sizeof(arr));
        for(int i = 1; i <= N; i += 1){
            cin >> arr[i];
        }

        cout << sol(1, N) << '\n';
    }

    return 0;
}