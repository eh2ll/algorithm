#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tmp = 3;
    while(tmp--){
        string s; cin >> s;
        ll a = 0;
        if(isdigit(s[0])){
            a = stol(s);
            ll ret = a + tmp + 1;
            if(ret % 3 == 0 && ret % 5 == 0) cout << "FizzBuzz\n";
            else if(ret % 3 == 0) cout << "Fizz\n";
            else if(ret % 5 == 0) cout << "Buzz\n";
            else cout << ret << '\n';

            return 0;
        }
    }

    return 0;
}