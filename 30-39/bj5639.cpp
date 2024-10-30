#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int x, idx;
int arr[10004];

void sol(int st, int en){
    int cur = arr[st];

    if(st >= en){
        return;
    }

    int mid = st + 1;
    for(; mid < en; mid += 1){
        if(cur < arr[mid]) break;
    }

    // cout << st + 1 << ' ' << mid << ' ' << en << '\n';

    sol(st + 1, mid);
    sol(mid, en);
    cout << cur << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> x){
        arr[idx++] = x;
    }

    sol(0, idx);

    return 0;
}