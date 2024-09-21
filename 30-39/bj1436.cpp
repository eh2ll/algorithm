#include <bits/stdc++.h>

using namespace std;

int N;
int arr[10004];

int chk(int x){
    int cnt = 0;
    while(x){
        if(x % 1000 == 666) cnt += 1;
        x /= 10;
    }

    if(cnt >= 1) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int idx = 1;
    for(int i = 666; i <= 6660006; i += 1){
        if(!chk(i)) continue;
        arr[idx++] = i;
        if(idx > 10000) break;
    }

    cout << arr[N] << '\n';

    return 0;
}