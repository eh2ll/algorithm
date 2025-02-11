#include <bits/stdc++.h>

using namespace std;

int N;
int arr[21];
map<int, int> mp;

void sol(int cur, int sum){
    if(cur == 20){
        if(sum > 0) mp[sum] = 1;
        return;
    }
    sol(cur + 1, sum);
    sol(cur + 1, sum + arr[cur]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= 1048576; i += 1) mp[i] = 0;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
    }

    sol(0, 0);

    int res = 0;
    for(auto [k, v] : mp){
        if(v == 0){
            res = k;
            break;    
        }
    }

    // for(auto [k, v] : mp){
    //     if(v == 1) cout << k << ' ';
    // }
    // cout << '\n';

    cout << res << '\n';

    return 0;
}