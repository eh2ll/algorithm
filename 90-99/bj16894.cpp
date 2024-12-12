#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    ll rt = sqrt(N), tmp = N;
    int cnt = 0;
    for(int i = 2; i <= rt; i += 1){
        while(tmp % i == 0){
            cnt += 1;
            tmp /= i;
        }
    }
    if(tmp != 1) cnt += 1;

    if(N == 1 || cnt == 1) cout << "koosaga\n";
    else if(cnt == 2) cout << "cubelover\n";
    else cout << "koosaga\n";

    return 0;
}