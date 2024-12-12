#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr[1003];
int chk[102][1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        int a, b; cin >> a >> b;
        arr[i].push_back(a);
        arr[i].push_back(b);
    }

    chk[0][1] = 1;
    for(int i = 0; i < 100; i += 1){
        for(int j = 1; j <= N; j += 1){
            if(!chk[i][j]) continue;
            for(auto c : arr[j]) chk[i + 1][c] = 1;
        }
    }

    int ret = -1;
    for(int i = 10; i < 100; i += 1){
        if(!chk[i][1]){
            ret = i;
            break;
        }
    }

    cout << ret << '\n';

    return 0;
}