#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M;
vector<pii> lim, spd;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int tmp = 0;
    for(int i = 0; i < N; i += 1){
        int a, b; cin >> a >> b;
        lim.push_back({tmp + a, b});
        tmp += a;
    }
    tmp = 0;
    for(int i = 0; i < M; i += 1){
        int a, b; cin >> a >> b;
        spd.push_back({tmp + a, b});
        tmp += a;
    }

    int l = 0, res = 0;
    for(int i = 0; i < (int)spd.size(); i += 1){
        int r = upper_bound(lim.begin(), lim.end(), pii{spd[i].first, -1}) - lim.begin();
        for(int k = l; k <= r; k += 1){
            res = max(res, spd[i].second - lim[k].second);
        }
        if(spd[i].first == lim[r].first) l = r + 1;
        else l = r;
    }

    cout << res << '\n';

    return 0;
}