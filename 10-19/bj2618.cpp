//kks227

#include <bits/stdc++.h>

using namespace std;

int N, M, posx[1001], posy[1001], dp[1001][1001], way[1001][1001];

int minsum(int s1, int s2){
    int cur = max(s1, s2);
    if(cur == M) return 0;
    
    int &ret = dp[s1][s2];
    if(ret != -1) return ret;
    
    int c1 = minsum(cur + 1, s2);
    if(s1 == 0) c1 += posx[cur] + posy[cur] - 2;
    else c1 += abs(posx[cur] - posx[s1 - 1]) + abs(posy[cur] - posy[s1 - 1]);

    int c2 = minsum(s1, cur + 1);
    if(s2 == 0) c2 += N * 2 - posx[cur] - posy[cur];
    else c2 += abs(posx[cur] - posx[s2 - 1]) + abs(posy[cur] - posy[s2 - 1]);

    way[s1][s2] = c1 > c2;

    return ret = min(c1, c2);
}

void pway(int s1, int s2){
    int cur = max(s1, s2);
    if(cur == M) return;

    cout << way[s1][s2] + 1 << '\n';

    if(way[s1][s2]) pway(s1, cur + 1);
    else pway(cur + 1, s2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i += 1){
        cin >> posx[i] >> posy[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << minsum(0, 0) << '\n';
    pway(0, 0);

    return 0;
}