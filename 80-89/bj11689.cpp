#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> p;
bool isP[1000006];

void seive(ll x){
    memset(isP, 1, sizeof(isP));
    for(int i = 2; i <= x; i += 1){
        if(isP[i]) p.push_back(i);
        for(auto j : p){
            if(i * j > x) break;
            isP[i * j] = 0;
            if(i % j == 0) break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N; cin >> N;
    seive(1000006);
    vector<ll> sn;
    ll tt = N;
    for(auto num : p){
        if(tt == 1) break; 
        if(tt % num == 0){
            sn.push_back(num);
            while(tt % num == 0) tt /= num;
        }
    }
    if(tt > 1) sn.push_back(tt);
    // cout << "TT" << tt << '\n';

    long long res = 1, tmp = N;
    if(sn.size() > 0){
        for(auto num : sn){
            res *= num - 1;
            tmp /= num;
        }
        res *= tmp;
    }
    else if(N == 1){
        res = 1;
    }
    else{
        res = tmp - 1;
    }

    cout << res << '\n';

    return 0;
}