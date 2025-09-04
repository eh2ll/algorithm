#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S, T;
    cin >> S >> T;
    int sz = S.size();
    deque<char> L, R;
    int lx = 0, rx = T.size() - 1;
    while(lx <= rx){
        bool chk = 0;
        while(lx <= rx){
            L.push_back(T[lx++]);
            bool ok = 0;
            if(L.size() >= sz){
                int j = 0;
                ok = 1;
                for(int i = L.size() - sz; i < L.size(); i += 1){
                    if(L[i] != S[j++]){
                        ok = 0;
                        break;
                    }
                }
            }

            if(ok){
                for(int i = 0; i < sz; i += 1){
                    L.pop_back();
                }
                chk = 1;
                break;
            }
        }
        if(!chk) break;

        while(lx <= rx){
            R.push_front(T[rx--]);
            bool ok = 0;
            if(R.size() >= sz){
                int j = 0;
                ok = 1;
                for(int i = 0; i < sz; i += 1){
                    if(R[i] != S[j++]){
                        ok = 0;
                        break;
                    }
                }
            }

            if(ok){
                for(int i = 0; i < sz; i += 1){
                    R.pop_front();
                }
                chk = 1;
                break;
            }
        }
        if(!chk) break;
    }

    while(!R.empty()){
        L.push_back(R.front()); R.pop_front();
        if(L.size() < sz) continue;
        bool ok = 1;
        int j = 0;
        for(int i = L.size() - sz; i < L.size(); i += 1){
            if(L[i] != S[j++]){
                ok = 0;
                break;
            }
        }
        if(ok){
            for(int i = 0; i < sz; i += 1){
                L.pop_back();
            }
        }
    }

    string ans(L.begin(), L.end());
    cout << ans << '\n';

    return 0;
}