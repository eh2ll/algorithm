#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;
bool isp[44'004];
vector<int> pr;

void sieve(){
    for(int i = 2; i <= 44'000; i += 1){
        if(!isp[i]) pr.push_back(i);
        for(auto j : pr){
            if(i * j > 44'000) break;
            isp[i * j] = 1;
            if(i % j == 0) break;
        }
    }
}

ll tot = 0, mid = 0;
void calc(int id, ll x, int pre){
    for(int i = id; i < pr.size(); i += 1){
        ll tmp = x * pr[i];
        if(tmp * tmp > mid) break;
        // cout << pre << ' ' << mid << ' ' << tmp * tmp << " -- " << pre * mid / (tmp * tmp) << '\n';
        tot += pre * mid / (tmp * tmp);
        calc(i + 1, tmp, -pre);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    // for(int i = 1; i <= 30; i += 1){
    //     cout << isp[i] << ' ';
    //     if(i % 10 == 0) cout << '\n';
    // }

    cin >> N;
    ll st = 0, en = 1e10;
    while(st + 1 < en){
        tot = 0;
        mid = (st + en) >> 1;
        calc(0, 1, 1);
        // cout << mid << ' ' << tot << '\n';
        if(N <= mid - tot) en = mid;
        else st = mid;
    }

    cout << en << '\n';

    return 0;
}