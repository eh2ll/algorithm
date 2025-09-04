#include <bits/stdc++.h>

using namespace std;
using tii = tuple<int, int, int>;

int N, M;
int U[10'004], C[10'004];
set<int> T;

int pos(int x, int y){
    return x * M + y;
}

int dis(int x, int y){
    return (x / M - y / M) * (x / M - y / M) + (x % M - y % M) * (x % M - y % M);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    set<int> st1, st2;
    vector<tii> A;
    for(int i = 0; i < N; i += 1){
        string S; cin >> S;
        for(int j = 0; j < M; j += 1){
            if(S[j] == 'L'){
                st1.insert(pos(i, j));
                T.insert(pos(i, j));
            }
            else if(S[j] == 'X'){
                st2.insert(pos(i, j));
            }
        }
    }
    for(auto &x : st1){
        for(auto &y : st2){
            A.emplace_back(dis(x, y), x, y);
        }
    }
    sort(A.begin(), A.end());

    int cur = -1, cnt = 0;
    for(auto &[d, L, X] : A){
        if(cur != d){
            cur = d;
            for(int i = 0; i < N * M; i += 1){
                if(C[i] > 0) U[i] = 1;
                cnt += (C[i] > 1 && T.count(i)) ? 1 : 0;
            }
            memset(C, 0, sizeof(C));
        }
        if(U[L] || U[X]) continue;
        C[L] += 1;
        C[X] += 1;
    }
    for(int i = 0; i < N * M; i += 1){
        if(C[i] > 0) U[i] = 1;
        cnt += (C[i] > 1 && T.count(i)) ? 1 : 0;
    }

    cout << cnt << "\n";

    return 0;
}