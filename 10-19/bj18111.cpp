#include <bits/stdc++.h>

using namespace std;

int N, M, B;
pair<int, int> arr[502][502][260];
int bor[502][502];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> B;
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < M; j += 1){
            int x; cin >> x;
            bor[i][j] = x;
            arr[i][j][x] = {0, 0};
            for(int k = x - 1; k >= 0; k -= 1){
                arr[i][j][k] = {(x - k) * 2, -1 * (x - k)};
            }
            for(int k = x + 1; k <= 256; k += 1){
                arr[i][j][k] = {(k - x), (k - x)};
            }
        }
    }

    int mn = 512 * 250000 + 10, lev = -1;
    for(int k = 256; k >= 0; k -= 1){
        int tot = 0, blks = 0;
        for(int i = 0; i < N; i += 1){
            for(int j = 0; j < M; j += 1){
                tot += arr[i][j][k].first;
                blks += arr[i][j][k].second;
            }
        }
        // cout << k << ' ' << mn << ' ' << tot << ' ' << blks << '\n';
        if(mn > tot && blks <= B){
            mn = tot;
            lev = k;
        }
    }

    cout << mn << ' ' << lev << '\n';

    return 0;
}
