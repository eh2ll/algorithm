#include <bits/stdc++.h>

using namespace std;

int opcnt = 0;
string s;
vector<char> V;

map<char, int> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    mp['+'] = 2;
    mp['-'] = 2;
    mp['*'] = 1;
    mp['/'] = 1;
    mp['('] = 0;

    cin >> s;

    stack<char> op;
    int len = s.size();
    for(int i = 0; i < len; i += 1){
        if(s[i] == '('){
            op.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!op.empty() && op.top() != '('){
                V.push_back(op.top());
                op.pop();
            }
            op.pop();
        }
        else if('A' <= s[i] && s[i] <= 'Z'){
            V.push_back(s[i]);
        }
        else{
            if(op.empty()){
                op.push(s[i]);
                continue;
            }

            if(mp[op.top()] == 0) op.push(s[i]);
            else if(mp[op.top()] == mp[s[i]]){
                V.push_back(op.top());
                op.pop();
                op.push(s[i]);
            }
            else if(mp[op.top()] > mp[s[i]]){
                op.push(s[i]);
            }
            else if(mp[op.top()] < mp[s[i]]){
                while(!op.empty() && op.top() != '('){
                    V.push_back(op.top());
                    op.pop();
                }
                op.push(s[i]);
            }
        }
    }

    while(!op.empty()){
        V.push_back(op.top());
        op.pop();
    }

    for(auto c : V) cout << c;
    cout << '\n';

    return 0;
}