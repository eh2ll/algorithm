// #include <bits/stdc++.h>

// using namespace std;

// int N, M;
// int arr[1000006];
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> N >> M;
//     for(int i = 0; i < N; i += 1){
//         cin >> arr[i];
//     }

//     int en = 0, cnt = 0, res = 1000006;
//     for(int st = 0; st < N; st += 1){
//         while(cnt < M && en < N){
//             if(arr[en] == 1) cnt += 1;
//             en += 1;
//         }
//         if(cnt == M) res = min(res, en - st);
//         // cout << st << ' ' << en << '\n';
//         if(arr[st] == 1) cnt -= 1;
//     }

//     cout << res << '\n';

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[1000006];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
    }

    int en = 0, cnt = 0, res = INT_MAX;
    for(int st = 0; st < N; st += 1){
        while(en < N && cnt < K){
            if(arr[en] == 1) cnt += 1;
            en += 1;
        }
        if(cnt >= K){
            res = min(res, en - st);
        }
        if(arr[st] == 1) cnt -= 1;
    }

    if(res == INT_MAX) cout << -1 << '\n';
    else cout << res << '\n';

    return 0;
}
