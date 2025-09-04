#include <bits/stdc++.h>

using namespace std;

vector<int> g[100'005];
int col[100'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for(int i = 1; i <= N; i += 1){
        int M; cin >> M;
        for(int j = 0; j < M; j += 1){
            int x; cin >> x;
            g[i].push_back(x);
        }
    }

    while(1){
        bool ok = 1;
        for(int i = 1; i <= N; i += 1){
            int cur = col[i], cnt = 0;
            for(auto &x : g[i]){
                if(col[x] == cur) cnt += 1;
            }
            if(cnt > 1){
                col[i] ^= 1;
                ok = 0;
            }
        }

        if(ok) break;
    }

    vector<int> cnt0, cnt1;
    for(int i = 1; i <= N; i += 1){
        if(col[i] == 0) cnt0.push_back(i);
        else cnt1.push_back(i);
    }

    cout << cnt0.size() << ' ';
    for(auto &x : cnt0) cout << x << ' ';
    cout << '\n';
    cout << cnt1.size() << ' ';
    for(auto &x : cnt1) cout << x << ' ';
    cout << '\n';

    return 0;
}