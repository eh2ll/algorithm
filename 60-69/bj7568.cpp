#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, cnt[55];
pii arr[55];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        int a, b; cin >> arr[i].first >> arr[i].second;
    }

    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < N; j += 1){
            if(arr[i].first < arr[j].first && arr[i].second < arr[j].second){
                cnt[i] += 1;
            }
        }
    }

    for(int i = 0; i < N; i += 1){
        cout << cnt[i] + 1 << ' ';
    }
    cout << '\n';

    return 0;
}