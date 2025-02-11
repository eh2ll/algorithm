#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<int, int> bor[300005];
int res[300005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= M; i += 1){
        int x; cin >> x;
        bor[i] = {x, i};
    }
    sort(bor + 1, bor + 1 + M, greater<pair<int, int>>());
    
    if(bor[1].first <= (N + 1) / 2){
        int idx = 1;
        for(int i = 1; i <= M; i += 1){
            auto [cnt, num] = bor[i];
            while(cnt--){
                res[idx] = num;
                idx += 2;
                if(idx > N){
                    idx = 2;
                }
            }
        }

        for(int i = 1; i <= N; i += 1){
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}