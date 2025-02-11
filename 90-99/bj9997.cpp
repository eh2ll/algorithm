#include <bits/stdc++.h>

using namespace std;

int N, chk, cnt;
int bor[31];

void dfs(int cur, int tot){
    if(tot == chk && cur == N) cnt += 1;
    if(cur == N) return;

    dfs(cur + 1, tot);
    dfs(cur + 1, tot | bor[cur]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 26; i += 1) chk += (1 << i);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        string s; cin >> s;
        int tmp = 0;
        for(int j = 0; j < s.size(); j += 1){
            tmp |= (1 << (s[j] - 'a'));
        }
        bor[i] = tmp;
    }

    // for(int i = 0; i < (1 << N); i += 1){
    //     int tmp = 0;
    //     for(int k = 0; k < N; k += 1 ){
    //         if(i & (1 << k)){
    //             tmp |= bor[k];
    //         }
    //     }

    //     if(tmp == chk) cnt += 1;
    // }

    dfs(0, 0);

    cout << cnt << '\n';

    return 0;
}