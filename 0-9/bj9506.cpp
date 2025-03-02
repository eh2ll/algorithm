#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        int x; cin >> x;
        if(x == -1) break;

        set<int> S;
        S.insert(1);
        int sum = 1;
        for(int i = 2; i * i <= x; i += 1){
            if(x % i == 0){
                S.insert(i);
                S.insert(x / i);
                if(i != (x / i)) sum += i + (x / i);
                else sum += i;
            }
        }

        if(sum == x){
            cout << x << " = ";
            for(auto it = S.begin(); it != S.end(); it++){
                if(it == S.begin()){
                    cout << *it;
                }
                else{
                    cout << " + " << *it;
                }
            }
            cout << '\n';
        }
        else{
            cout << x << " is NOT perfect.";
            cout << '\n';
        }
    }

    return 0;
}