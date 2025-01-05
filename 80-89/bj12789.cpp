#include <bits/stdc++.h>

using namespace std;

int N;
int bor[1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> bor[i];
    }

    stack<int> S;
    int tmp = 1;
    for(int i = 0; i < N; i += 1){
        if(bor[i] == tmp){
            bor[i] = 0;
            tmp += 1;
        }
        else{
            S.push(bor[i]);
        }

        while(!S.empty() && S.top() == tmp){
            S.pop();
            tmp += 1;
        }
    }

    if(!S.empty()) cout << "Sad\n";
    else cout << "Nice\n";

    return 0;
}