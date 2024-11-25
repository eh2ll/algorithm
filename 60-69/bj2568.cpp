#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> V;
int ans[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        int a, b; cin >> a >> b;
        V.push_back({a, b});
    }

    sort(V.begin(), V.end());

    vector<int> res;
    for(int i = 0; i < N; i += 1){
        if(res.empty() || (res.back() < V[i].second)){
            res.push_back(V[i].second);
            ans[i] = (int)res.size() - 1;
        }
        else{
            auto idx = lower_bound(res.begin(), res.end(), V[i].second) - res.begin();
            res[idx] = V[i].second;
            ans[i] = idx;
        }
    }

    int sz = res.size() - 1;
    vector<int> ret;
    for(int i = N - 1; i >= 0; i -= 1){
        if(ans[i] != sz) ret.push_back(i);
        else sz -= 1;
    }

    reverse(ret.begin(), ret.end());

    cout << ret.size() << '\n';
    for(auto c : ret) cout << V[c].first << '\n';

    return 0;
}

// 8 2 9 1 4 6 7 10
// 1 1 2 1 2 3 4 5