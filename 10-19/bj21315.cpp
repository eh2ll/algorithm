#include <bits/stdc++.h>

using namespace std;

int N, arr[1003];

// 1 2 3 4 5 / 2 3 4 5 1 / 4 5 2 3 1 / 5 4 2 3 1

vector<int> sol(vector<int>& tmp, int k){
    vector<int> ret;
    int sz = (int)tmp.size();
    int cur = sz;
    for(int i = 0; i <= k; i += 1){
        int twos = pow(2, i);
        for(int j = sz - twos; j < cur; j += 1){
            ret.push_back(tmp[j]);
        }
        cur = sz - twos;
    }
    for(int i = 0; i < cur; i += 1){
        ret.push_back(tmp[i]);
    }
    return ret;
}

bool chk(vector<int>& tmp){
    for(int i = 0; i < N; i += 1){
        if(arr[i] != tmp[i]) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
    }

    int mx = (int)floor(log2(N - 1));
    for(int i = 0; i <= mx; i += 1){
        for(int j = 0; j <= mx; j += 1){
            vector<int> tmp;
            tmp.resize(N);
            iota(tmp.begin(), tmp.end(), 1);
            vector<int> sol1 = sol(tmp, i);
            vector<int> sol2 = sol(sol1, j);

            if(chk(sol2)) cout << i << ' ' << j << '\n';
        }
    }

    return 0;
}