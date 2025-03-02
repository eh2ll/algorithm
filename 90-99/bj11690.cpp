#include <bits/stdc++.h>

using namespace std;

const long long MOD = pow(2, 32);
bool isp[100000008];
vector<int> p;

void sol(int x){
    for(int i = 2; i <= x; i += 1){
        if(!isp[i]) p.push_back(i);
        for(auto j : p){
            if(i * j > x) break;
            isp[i * j] = 1;
            if(i % j == 0) break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    sol(N);

    long long res = 1;
    for(auto c : p){
        if(log(N) / log(c) < 1) break; 
        res *= (long long)pow(c, floor(log(N) / log(c))) % MOD;
        res %= MOD;
    }

    cout << res << '\n';

    return 0;
}