#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    string a, b; cin >> a >> b;
    string a1 = a;
    string a2 = "";
    for(int i = 0; i < a.size(); i += 1){
        if(i < 2) a2 += (1 - (a[i] - '0')) + '0';
        else a2 += a[i];
    }

    int cnt1 = 0;
    for(int i = 1; i < a1.size(); i += 1){
        if(a1[i - 1] != b[i - 1]){
            cnt1 += 1;
            a1[i - 1] = (1 - (a1[i - 1] - '0')) + '0';
            a1[i] = (1 - (a1[i] - '0')) + '0';
            if(i + 1 < a1.size()) a1[i + 1] = (1 - (a1[i + 1] - '0')) + '0';
        }
    }

    int cnt2 = 1;
    for(int i = 1; i < a2.size(); i += 1){
        if(a2[i - 1] != b[i - 1]){
            cnt2 += 1;
            a2[i - 1] = (1 - (a2[i - 1] - '0')) + '0';
            a2[i] = (1 - (a2[i] - '0')) + '0';
            if(i + 1 < a2.size()) a2[i + 1] = (1 - (a2[i + 1] - '0')) + '0';
        }
    }

    int mn = 100001;
    bool flag = 1;
    for(int i = 0; i < a1.size(); i += 1){
        if(a1[i] != b[i]) flag = 0;
    }
    if(flag) mn = min(mn, cnt1);

    flag = 1;
    for(int i = 0; i < a2.size(); i += 1){
        if(a2[i] != b[i]) flag = 0;
    }
    if(flag) mn = min(mn, cnt2);

    if(mn < 100001) cout << mn << '\n';
    else cout << -1 << '\n';

    return 0;
}