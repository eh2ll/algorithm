#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> fail(vector<int> &A){
    int sz = A.size();
    vector<int> f(sz, 0);
    int j = 0;
    for(int i = 1; i < sz; i += 1){
        while(j > 0 && A[i] != A[j]) j = f[j - 1];
        if(A[i] == A[j]) f[i] = ++j;
    }
    return f;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> A(N), B(N), S, T;
    for(int i = 0; i < N; i += 1){
        cin >> A[i];
    }
    for(int i = 0; i < N; i += 1){
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i = 1; i < N; i += 1) S.push_back(A[i] - A[i - 1]);
    S.push_back(A[0] + 360'000 - A[N - 1]);
    for(int i = 0; i < N; i += 1) S.push_back(S[i]);
    for(int i = 1; i < N; i += 1) T.push_back(B[i] - B[i - 1]);

    vector<int> f = fail(T);
    int j = 0;
    bool ok = 0;
    for(int i = 0; i < S.size(); i += 1){
        while(j > 0 && S[i] != T[j]) j = f[j - 1];
        if(S[i] == T[j]){
            j += 1;
            if(j == N - 1){
                ok = 1;
                break;
            }
        }
    }

    if(ok) cout << "possible\n";
    else cout << "impossible\n";

    return 0;
}