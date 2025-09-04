#include <bits/stdc++.h>

using namespace std;
using tii = tuple<int, int, int>;

int A[502][502], D[502][502];
set<tii> S;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= N; j += 1){
            cin >> A[i][j];
            S.insert({A[i][j], i, j});
        }
    }
    for(int i = 0; i <= N; i += 1){
        A[i][0] = A[i][N + 1] = 0x3f3f3f3f;
        A[0][i] = A[N + 1][i] = 0x3f3f3f3f;
    }

    int mx = 0;
    for(auto [v, i, j] : S){
        if(A[i][j] > A[i - 1][j]){
            D[i][j] = max(D[i][j], D[i - 1][j] + 1);
        }
        if(A[i][j] > A[i + 1][j]){
            D[i][j] = max(D[i][j], D[i + 1][j] + 1);
        }
        if(A[i][j] > A[i][j - 1]){
            D[i][j] = max(D[i][j], D[i][j - 1] + 1);
        }
        if(A[i][j] > A[i][j + 1]){
            D[i][j] = max(D[i][j], D[i][j + 1] + 1);
        }
        mx = max(mx, D[i][j]);
    }

    cout << mx + 1 << '\n';

    return 0;
}