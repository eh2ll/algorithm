#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000;
int N;
vector<vector<int>> pr(INF + 1);

void cp(){
    for(int i = 1; i <= INF; i += 1){
        int num = i;
        vector<int> tmp;
        for(int k = 2; k * k <= i; k += 1){
            while(num % k == 0){
                num /= k;
                tmp.push_back(k);
            }
        }
        if(num > 1) tmp.push_back(num);

        pr[i] = tmp;
    }
}

vector<int> p;
int isp[1000006];

void sieve(){
    for(int i = 2; i <= INF; i += 1){
        if(!isp[i]) p.push_back(i);
        for(int j : p){
            if(i * j > INF) break;
            isp[i * j] = j;
            if(i % j == 0) break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cp();
    sieve();

    cin >> N;
    map<int, int> mp;
    for(int i = 0; i < N; i += 1){
        int x; cin >> x;
        // for(auto c : pr[x]){
        //     if((mp[c] + 1) % 2 == 0) mp.erase(c);
        //     else mp[c] = 1;
        // }
        // if(mp.empty()) cout << "DA\n";
        // else cout << "NE\n";
        int cur = x;
        while(isp[cur] > 0){
            int c = isp[cur];
            if((mp[c] + 1) % 2 == 0) mp.erase(c);
            else mp[c] = 1;
            cur /= c;
        }
        if(cur != 1){
            if((mp[cur] + 1) % 2 == 0) mp.erase(cur);
            else mp[cur] = 1;
        }

        if(mp.empty()) cout << "DA\n";
        else cout << "NE\n";
    }

    return 0;
}