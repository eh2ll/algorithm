#include <bits/stdc++.h>

using namespace std;

int N, K;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    queue<int> Q;
    for(int i = 1; i <= N; i += 1) Q.push(i);

    cout << "<";
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < K - 1; j += 1){
            Q.push(Q.front());
            Q.pop();
        }
        if(i < N - 1) cout << Q.front() << ", ";
        else cout << Q.front();
        Q.pop();
    }
    cout << ">\n";

    return 0;
}