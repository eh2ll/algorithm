// eine.tistory (dp bitmask) can be done with bipartite matching

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int TC, N, M;
string s[15];
int dp[15][1025];

bool adjchk(int bit){
    for(int i = 0; i < M - 1; i += 1){
        int val = (3 << i);
        if((bit & val) == val) return false;
    }
    return true;
}

bool seatchk(string seat, int bit){
    for(int i = 0; i < M; i += 1){
        if(seat[i] == 'x' && (bit & (1 << i))) return false;
    }
    return true;
}

bool bitschk(int cbit, int pbit){
    for(int i = 0; i < M; i += 1){
        if((1 << i) & pbit){
            if(i > 0 && ((1 << (i - 1)) & cbit)) return false;
            if(i + 1 < M && (1 << (i + 1) & cbit)) return false;
        }
    }
    return true;
}

int sol(){
    int ans = 0;
    vector<pii> bitsset;
    for(int bit = 0; bit < (1 << M); bit += 1){
        if(adjchk(bit)){
            int cnt = 0;
            for(int i = 0; i < M; i += 1){
                if((1 << i) & bit) cnt += 1;
            }
            bitsset.push_back({bit, cnt});
        }
    }

    for(int i = 1; i <= N; i += 1){
        for(auto [cbit, ccnt] : bitsset){
            if(!seatchk(s[i], cbit)) continue;
            for(auto [pbit, pcnt] : bitsset){
                if(bitschk(cbit, pbit)){
                    dp[i][cbit] = max(dp[i][cbit], dp[i - 1][pbit] + ccnt);
                    ans = max(ans, dp[i][cbit]);
                }
            }
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    while(TC--){
        cin >> N >> M;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= N; i += 1) cin >> s[i];

        cout << sol() << '\n';
    }

    return 0;
}