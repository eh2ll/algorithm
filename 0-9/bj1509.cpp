#include <bits/stdc++.h>

using namespace std;

int p[5050], dp[5050];

void sol(string s){
    int x = int(s.size());
    string tmp = "";
    for(int i = 0; i < x; i += 1){
        tmp += '#';
        tmp += s[i];
    }
    tmp += '#';
    x = 2 * x + 1;

    int r = -1, k = -1;
    for(int i = 0; i < x; i += 1){
        if(i <= r) p[i] = min(r - i, p[2 * k - i]);
        while(i - p[i] - 1 >= 0 && i + p[i] + 1 < x && tmp[i - p[i] - 1] == tmp[i + p[i] + 1]){
            p[i] += 1;
        }
        if(r < i + p[i]) r = i + p[i], k = i;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    sol(s);

    // for(int i = 0; i < 2 * s.size() + 1; i += 1) cout << p[i] << ' ';
    // cout << '\n';

    for(int i = 1; i < 2 * s.size() + 1; i += 2) dp[i] = (i + 1) / 2;

    for(int en = 1; en < 2 * s.size() + 1; en += 2){
        for(int st = 1; st <= en; st += 2){
            int mid = (st + en) / 2;
            // cout << "{ " << p[mid] << ' ' << (en - st) / 2 + 1 << ' ' << st - 2 << " }";
            if(p[mid] >= (en - st) / 2 + 1) dp[en] = min(dp[en], dp[max(0, st - 2)] + 1);
        }
        // cout << '\n';
    }

    // for(int i = 1; i < 2 * s.size() + 1; i += 2) cout << dp[i] << ' ';
    // cout << '\n';

    cout << dp[2 * s.size() - 1] << '\n';

    return 0;
}