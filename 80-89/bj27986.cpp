// #include <bits/stdc++.h>

// using namespace std;
// using pii = pair<int, int>;

// int N, M;

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> N >> M;

//     vector<pii> V(M);
//     int mn = 1e9;
//     for(int i = 0; i < M; i++){
//         cin >> V[i].first >> V[i].second;
//         mn = min(mn, V[i].second - V[i].first + 1);
//     }

//     vector<int> ans(N);
//     int val = 1;
//     for(int i = 0; i < N; i += 1){
//         ans[i] = val;
//         if(val == mn) val = 1;
//         else val += 1;
//     }
//     for(auto &x : ans) cout << x << ' ';
//     cout << '\n';

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    string s; cin >> s;
    if(s[0] == 'B' || s[N - 1] == 'A') cout << "No\n";
    else cout << "Yes\n";

    return 0;
}