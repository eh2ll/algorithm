#include <bits/stdc++.h>

using namespace std;

int W, N;
int arr[5003], tot[800005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> W >> N;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
    }

    for(int i = 0; i < N; i += 1){
        for(int j = i + 1; j < N; j += 1){
            int sum1 = arr[i] + arr[j];
            if(sum1 > W) continue;
            if(tot[W - sum1] > 0 && tot[W - sum1] < i){
                cout << "YES" << '\n';
                return 0;
            }

            tot[sum1] = j;
        }
    }

    cout << "NO\n";

    return 0;
}