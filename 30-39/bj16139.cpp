#include <bits/stdc++.h>

using namespace std;

int N, arr[200003][26];
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    s = '0' + s;
    int len = s.size();
    for(int i = 1; i < len; i += 1){
        arr[i][s[i] - 'a'] += 1;
        for(int j = 0; j < 26; j += 1){
            arr[i][j] += arr[i - 1][j];
        }
    }

    cin >> N;
    for(int i = 0; i < N; i += 1){
        string tmp; cin >> tmp;
        int a, b; cin >> a >> b;
        int res = arr[b + 1][tmp[0] - 'a'] - arr[a][tmp[0] - 'a'];
        cout << res << '\n';
    }

    return 0;
}