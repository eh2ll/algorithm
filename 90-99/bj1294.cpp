#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> S;
vector<int> mem;

char findmin(){
    int ret = -1;
    char mn = 'Z' + 1;
    for(int i = 0; i < N; i += 1){
        if(S[i][mem[i]] < mn){
            mn = S[i][mem[i]];
            ret = i;
        }
        else if(S[i][mem[i]] == mn && S[i][mem[i]] != 'Z' + 1){
            int l = mem[ret], r = mem[i];
            while(S[ret][l] == S[i][r]){
                l += 1;
                r += 1;
                if(l >= S[ret].size() || r >= S[i].size()) break;
            }
            if(S[ret][l] > S[i][r]){
                ret = i;
            }
        }
    }
    mem[ret] += 1;
    return mn;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    S.resize(N);
    mem.assign(N, 0);
    int mxlen = 0, totlen = 0;
    for(int i = 0; i < N; i += 1){
        cin >> S[i];
        mxlen = max(mxlen, (int)S[i].size());
        totlen += S[i].size();
    }
    for(int i = 0; i < N; i += 1){
        while(S[i].size() <= mxlen){
            S[i] += 'Z' + 1;
        }
    }

    int t = 0;
    string ans = "";
    while(t < totlen){
        char c = findmin();
        // for(auto &x : mem) cout << x << " ";
        // cout << c << "\n";
        ans += c;
        t += 1;
    }

    cout << ans << "\n";

    return 0;
}