#include <bits/stdc++.h>

using namespace std;

int T;
int ncr[50][50];

void init(){
    for(int i = 0; i <= 30; i += 1) ncr[i][0] = ncr[i][i] = 1;
    for(int i = 1; i <= 30; i += 1){
        for(int j = 1; j <= 30; j += 1){
            ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();
    cin >> T;
    while(T--){
        int N, M; cin >> N >> M;
        cout << ncr[M][N] << '\n';
    }

    return 0;
}