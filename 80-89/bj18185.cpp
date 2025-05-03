#include <bits/stdc++.h>

using namespace std;

int N;
int A[10'004][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int pre1 = 0, pre2 = 0, pre3 = 0;
    for(int i = 0; i < N; i += 1){
        cin >> A[i][0];

        if(i - 1 >= 0){
            int mn = min(A[i - 1][0], A[i][0]);
            A[i - 1][0] -= mn;
            A[i][0] -= mn;
            A[i][1] += mn;
        }
        if(i - 1 >= 0){
            int mn = min(A[i - 1][1], A[i][0]);
            A[i - 1][1] -= mn;
            A[i][0] -= mn;
            A[i][2] += mn;
        }
    }

    // for(int i = 1; i < N; i += 1){
    //     if(i + 2 < N){
    //         int mn = min({A[i][1], A[i + 1][1], A[i + 2][1]});
    //         A[i][1] -= mn;
    //         A[i + 1][1] -= mn;
    //         A[i + 2][1] -= mn;
    //         A[i + 1][2] += mn;
    //         A[i + 2][2] += mn;
    //     }
    //     if(i + 1 < N){
    //         int mn = min(A[i][1], A[i + 1][0]);
    //         A[i][1] -= mn;
    //         A[i + 1][0] -= mn;
    //         A[i + 1][2] += mn;
    //     }
    // }

    long long tot = 0;
    for(int i = 0; i < N; i += 1){
        tot += A[i][0] * 3 + A[i][1] * 5 + A[i][2] * 7;
    }

    cout << tot << '\n';

    return 0;
}

// https://everenew.tistory.com/82
// https://www.acmicpc.net/blog/view/21