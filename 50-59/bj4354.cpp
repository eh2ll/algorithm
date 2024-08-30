// barkingdog
#include <bits/stdc++.h>

using namespace std;

vector<int> fail(string &s){
	vector<int> f(s.size());
	int j = 0;
	for(int i = 1; i < s.size(); i += 1){
		while(j > 0 && s[i] != s[j]) j = f[j - 1];
		if(s[i] == s[j]) f[i] = ++j;
	}
	return f;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while(1){
        cin >> s;
        if(s == ".") return 0;

        int N = s.size();
        vector<int> f = fail(s);

        if(f[N - 1] == 0) cout << "1\n";
        else if(N % (N - f[N - 1]) == 0){
            cout << N / (N - f[N - 1]) << '\n';
        }
        else cout << "1\n";
    }

    return 0;
}