#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;

    if(M == 0){
        for(int i = 0; i < N; i += 1) cout << 0 << ' ';
        cout << '\n';
        return 0;
    }
    
    vector<int> res;
    int rt = sqrt(M);
    for(int i = 1; i <= rt; i += 1){
        res.push_back(1);
    }
    int sum = rt;
    while(sum + rt <= M){
        res.push_back(rt);
        sum += rt;
    }
    res.push_back(M - sum);

    if(rt == 1){
        res.clear();
        for(int i = 1; i <= M; i += 1) res.push_back(1);
    }

    int sz = res.size();
    for(int i = sz; i < N; i += 1){
        res.push_back(0);
    }

    sort(res.begin(), res.end());

    for(auto c : res) cout << c << ' ';
    cout << '\n';

    // int cnt = 0;
    // for(int i = 0; i < N; i += 1){
    //     cnt += res[i];
    // }
    // cout << cnt << '\n';

    return 0;
}

/*
0, 1, 2, 4, 6, 9, 12, 16, 20, 25, 30
1 1 1 1 4 4 4 4 0 4
*/