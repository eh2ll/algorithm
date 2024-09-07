#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
int N, M;
bool isp[10004];
vector<int> p;

void solve(int x){
    memset(isp, 1, sizeof(isp));
    isp[1] = 0;
    for(int i = 2; i <= x; i += 1){
        if(isp[i]) p.push_back(i);
        for(auto j : p){
            if(i * j > x) break;
            isp[i * j] = 0;
            if(i % j == 0) break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve(10000);

    cin >> N >> M;
    
    int tot = 0, mn = inf;
    for(int i = N; i <= M; i += 1){
        if(isp[i]) tot += i, mn = min(mn, i);
    }

    if(mn == inf) cout << -1 << '\n';
    else cout << tot << '\n' << mn << '\n';

    return 0;
}