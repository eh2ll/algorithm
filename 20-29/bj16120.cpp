#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string inp; cin >> inp;
    stack<char> S;
    for(int i = 0; i < inp.size(); i += 1){
        if(S.empty() || S.top() == 'P'){
            S.push(inp[i]);
        }
        else{
            if(S.top() == 'A' && inp[i] == 'P' && S.size() >= 3){
                S.pop();
                char c2 = S.top(); S.pop();
                char c1 = S.top(); S.pop();
                if(c1 == 'P' && c2 == 'P') S.push('P');
                else{
                    S.push(c1);
                    S.push(c2);
                    S.push('A');
                    S.push(inp[i]);
                }
            }
            else{
                S.push(inp[i]);
            }
        }
    }

    if(!S.empty() && S.top() == 'P' && S.size() == 1){
        cout << "PPAP\n";
    }
    else cout << "NP\n";

    return 0;
}