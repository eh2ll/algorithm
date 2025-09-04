#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll cnt[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N; cin >> N;
    for(int digit = 1; digit <= 9; digit += 1){
        for(ll idx = 10; idx / 10 <= N; idx *= 10){
            ll num = N / idx;
            if((N % idx) >= digit * (idx / 10)){
                // cnt[digit] += (num + 1) * (idx / 10);
                cnt[digit] += (num + 1) * (idx / 10);
                if(idx >= 100 && (N % idx) / (idx / 10) == digit){
                    cnt[digit] -= (idx / 10);
                    cnt[digit] += (N % (idx / 10) + 1);
                }
                else if(idx > N){
                    cnt[digit] -= (num + 1) * (idx / 10);
                    cnt[digit] += idx / 10;
                }
            }
            else{
                cnt[digit] += num * (idx / 10);
            }
            // cout << "cnt[" << digit << "] = " << cnt[digit] << ' ' << (num + 1) * (idx / 10) << "\n";
        }
    }
    int digit = 0;
    for(ll idx = 10; idx <= N; idx *= 10){
        if(idx > N) break;
        cnt[digit] += (N / idx) * (idx / 10);
        if(idx >= 100 && (N % idx) / (idx / 10) == digit){
            cnt[digit] -= (idx / 10);
            cnt[digit] += (N % (idx / 10) + 1);
        }
    }

    for(int digit = 0; digit <= 9; digit += 1){
        cout << cnt[digit] << " ";
    }
    cout << "\n";

    return 0;
}