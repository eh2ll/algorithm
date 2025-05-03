#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i += 1){
        cin >> A[i];
    }

    vector<int> B;
    for(int i = 0; i < N; i += 1){
        if(B.empty() || B.back() < A[i]){
            B.push_back(A[i]);
        }
        else{
            auto it = lower_bound(B.begin(), B.end(), A[i]);
            *it = A[i];
        }
    }

    cout << B.size() << '\n';

    return 0;
}