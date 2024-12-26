#include <bits/stdc++.h>

using namespace std;

int N, sum;
int bor[100005];
long double one = 1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> bor[i];
        sum += bor[i];
    }
    sort(bor, bor + N);

    cout.precision(9);
    cout << fixed;
    
    if(N == 1) cout << bor[0] << '\n';
    else cout << max(one * sum / N, one * bor[N - 2]) << '\n';

    return 0;
}