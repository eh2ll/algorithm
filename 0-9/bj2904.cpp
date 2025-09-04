#include <bits/stdc++.h>

using namespace std;

int A[1'003];
int isp[1'000'001];
vector<int> pr;

void sieve(){
    for(int i = 2; i <= 1'000'000; i += 1){
        if(!isp[i]) pr.push_back(i), isp[i] = i;
        for(auto j : pr){
            if(i * j > 1'000'000) break;
            isp[i * j] = j;
            if(i % j == 0) break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    int N; cin >> N;
    map<int, int> cnt;
    for(int i = 0; i < N; i += 1){
        cin >> A[i];

        int x = A[i];
        while(x > 1){
            cnt[isp[x]] += 1;
            x /= isp[x];
        }
    }

    vector<int> scores;
    int mx = 1;
    for(auto &[k, v] : cnt){
        if(v >= N){
            for(int i = 0; i < v / N; i += 1){
                scores.push_back(k);
                mx *= k;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < N; i += 1){
        for(auto &x : scores){
            if(A[i] % x == 0){
                A[i] /= x;
            }
            else{
                sum += 1;
            }
        }
    }

    cout << mx << ' ' << sum << '\n';

    return 0;
}