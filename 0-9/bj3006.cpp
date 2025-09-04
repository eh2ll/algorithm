#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<ll> A;

void update(int idx, int val){
    while(idx <= A.size()){
        A[idx] += val;
        idx += (idx & -idx);
    }
}

ll sum(int idx){
    ll ret = 0;
    while(idx > 0){
        ret += A[idx];
        idx -= (idx & -idx);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    A.resize(222'222);
    map<int, int> mp;
    for(int i = 1; i <= N; i += 1){
        int x; cin >> x;
        mp[x] = i;
        update(i, 1);
    }

    int l = 1, r = N;
    while(l <= r){
        cout << sum(mp[l] - 1) << '\n';
        update(mp[l], -1);
        l += 1;

        if(l > r) break;
        cout << sum(N) - sum(mp[r]) << '\n';
        update(mp[r], - 1);
        r -= 1;
    }

    return 0;
}