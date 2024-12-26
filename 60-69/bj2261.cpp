// kks227

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int inf = 0x3f3f3f3f;
int N;
vector<pii> V;
set<pii> S;

int dist(pii a, pii b){
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        int a, b; cin >> a >> b;
        V.push_back({a, b});
    }
    sort(V.begin(), V.end());

    S.insert({V[0].second, V[0].first});
    S.insert({V[1].second, V[1].first});
    int idx = 0, mn = dist(V[0], V[1]);
    for(int i = 2; i < N; i += 1){
        while(idx < i){
            if(pow(V[i].first - V[idx].first, 2) > mn){
                S.erase({V[idx].second, V[idx].first});
                idx += 1;
            }
            else break;
        }
       
        int d = (int)sqrt(mn) + 1;
        auto lo = S.lower_bound({V[i].second - d, -inf});
        auto hi = S.upper_bound({V[i].second + d, inf});
        
        for(auto k = lo; k != hi; k++){
            mn = min(mn, dist({V[i].second, V[i].first}, *k));
        }
        S.insert({V[i].second, V[i].first});
    }

    cout << mn << '\n';

    return 0;
}