#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[10004];

bool sol(int x){
    int ret = 0;
    for(int i = 0; i < N; i += 1){
        if(arr[i] <= x) ret += arr[i];
        else ret += x;
    }

    if(ret <= M) return 1;
    else return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int tot = 0;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
        tot += arr[i];
    }
    cin >> M;

    sort(arr, arr + N);

    if(tot <= M){
        cout << arr[N - 1] << '\n';
    }
    else{
        int st = 0, en = M;
        while(st + 1 < en){
            int mid = (st + en) / 2;
            if(sol(mid)) st = mid;
            else en = mid;
        }
        cout << st << '\n';
    }

    return 0;
}