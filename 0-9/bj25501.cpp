#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

int sol(string& s, int l, int r){
    cnt += 1;
    if(l >= r) return 1;
    if(s[l] != s[r]) return 0;
    return sol(s, l + 1, r - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    while(N--){
        string s; cin >> s;
        int size = s.size();
        cnt = 0;
        cout << sol(s, 0, size - 1) << ' ' << cnt << '\n';
    }

    return 0;
}