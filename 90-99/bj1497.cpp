//basic algo lecture
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M;
ll state[10];

int btcnt(ll num){
    int ret = 0;
    for(int i = 0; i < max(N, M); i += 1){
        ret += ((num >> i) & 1);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i += 1){
        string a, b; cin >> a >> b;
        for(int j = M - 1; j >= 0; j -= 1){
            state[i] = (state[i] << 1) | (b[j] == 'Y');
        }
    }

    pair<int, int> ans = {0, -1};
    for(int bit = 0; bit < (1 << N); bit += 1){
        ll comb = 0;
        for(int i = 0; i < N; i += 1){
            if((bit & (1LL << i)) == 0) continue;
            comb |= state[i];
        }
        int song = btcnt(comb);
        int guit = btcnt(bit);

        if(ans.first < song){
            ans = {song, guit};
        }
        else if(ans.first == song && ans.second > guit){
            ans = {song, guit};
        }
    }

    cout << ans.second << '\n';

    return 0;
}