#include <bits/stdc++.h>

using namespace std;

int N, M;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    bool flag = 1;
    for(int i = 0; i < M; i += 1){
        int x; cin >> x;
        int pre = 200001;
        for(int i = 0; i < x; i += 1){
            int inp; cin >> inp;
            if(pre < inp) flag = 0;
            pre = inp;
        }
    }

    if(flag) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}