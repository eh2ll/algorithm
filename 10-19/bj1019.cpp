#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll bor[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string N; cin >> N;

    int sz = N.size();
    for(int i = 1; i < 10; i += 1){
        cout << i << '\n' << "+ ";
        for(int j = sz - 1; j >= 0; j -= 1){
            if(N[j] - '0' < i && j == 0) continue;
            ll cnt = 1;
            if(N[j] - '0' >= i){
                for(int k = sz - 1; k >= 0; k -= 1){
                    if(j == k) continue;
                    cnt *= N[k] - '0' + 1;
                }
            }
            else{
                for(int k = sz - 1; k >= 0; k -= 1){
                    if(j == k) continue;
                    if(k == j - 1){
                        cnt *= N[k] - '0' + 1 - 1;
                        continue;
                    }
                    cnt *= N[k] - '0' + 1;
                }
            }
            bor[i] += cnt;
            cout << cnt << ' ';
        }
        cout << '\n';
    }

    for(int j = sz - 1; j >= 0; j -= 1){
        ll cnt = 1;
        ll tmp = 0;
        for(int k = sz - 1; k >= 0; k -= 1){
            if(j == k){
                tmp = cnt;
                continue;
            }
            cnt *= N[k] - '0' + 1;
        }
        bor[0] += cnt - tmp;
    }
    

    for(int i = 0; i < 10; i += 1) cout << bor[i] << ' ';
    bor[0] = -1;

    return 0;
}
/*
499999999
539999999
542999999
543199999
543209999
543211999
543212299
543212339
543212345

자릿수
*/