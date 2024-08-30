#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[1000006];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(arr, arr + 1000001, 1);

    cin >> N >> K;
    int tot = N;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
        if(arr[i] & 1) arr[i] = 1;
        else arr[i] = 0;
        tot -= arr[i];
    }

    int cnt0 = max(N - K, tot);
    K = N - cnt0;

    int st = 0, en = 0;
    for(int i = 0; i < N; i += 1){
        if(!arr[i]){
            st = i;
            en = i;
            break;
        }
    }

    int cnt = 0, res = 0;
    for(int i = st; i < N; i += 1){
        if(arr[i]){
            cnt -= 1;
            cnt = max(cnt, 0);    
            continue;
        }

        while(cnt <= K && en < N){
            en += 1;
            if(arr[en]) cnt += 1;
        }
        res = max(res, en - i - cnt + 1);
    }

    cout << res << '\n';

    return 0;
}