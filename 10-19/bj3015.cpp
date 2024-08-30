#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    stack<pii> S;

    long long tot = 0;
    for(int i = 0; i < N; i += 1){
        int x; cin >> x;
        int cnt = 1;
        while(!S.empty() && S.top().first <= x){
            if(S.top().first == x){
                tot += S.top().second;
                cnt = S.top().second + 1;
                S.pop();
            }
            else{
                tot += S.top().second;
                S.pop();
                cnt = 1;
            }
        }

        if(!S.empty()) tot += 1;
        S.push({x, cnt});
    }

    cout << tot << '\n';

    return 0;
}