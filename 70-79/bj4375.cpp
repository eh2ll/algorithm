#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; 
    while(cin >> N){
        int num = 0;
        for(int i = 1; i <= N; i += 1){
            num *= 10, num += 1;
            num %= N;
            if(num == 0){
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}