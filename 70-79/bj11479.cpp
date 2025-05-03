// cp-algorithm

#include <bits/stdc++.h>

using namespace std;

string inp;

vector<int> sort_cyclic(const string& s){
    int n = s.size();
    const int alp = 256;

    vector<int> p(n), c(n), cnt(max(n, alp), 0);
    for(int i = 0; i < n; i += 1) cnt[s[i]] += 1;
    for(int i = 1; i < alp; i += 1) cnt[i] += cnt[i - 1];
    for(int i = 0; i < n; i += 1) p[--cnt[s[i]]] = i;

    c[p[0]] = 0;
    int classes = 1;
    for(int i = 1; i < n; i += 1){
        if(s[p[i]] != s[p[i - 1]]) classes += 1;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for(int h = 0; (1 << h) < n; h += 1){
        for(int i = 0; i < n; i += 1){
            pn[i] = p[i] - (1 << h);
            if(pn[i] < 0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for(int i = 0; i < n; i += 1) cnt[c[pn[i]]] += 1;
        for(int i = 1; i < classes; i += 1) cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i -= 1) p[--cnt[c[pn[i]]]] = pn[i];

        cn[p[0]] = 0;
        classes = 1;
        for(int i = 1; i < n; i += 1){
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if(cur != prev) classes += 1;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array(string s){
    s += '$';
    vector<int> sorted_shifts = sort_cyclic(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> lcp(const string& s, const vector<int>& p){
    int n = s.size();
    vector<int> rank(n, 0);
    for(int i = 0; i < n; i += 1) rank[p[i]] = i;
    
    int k = 0;
    vector<int> lcp(n - 1, 0);
    for(int i = 0; i < n; i += 1){
        if(rank[i] == n - 1){
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while(i + k < n && j + k < n && s[i + k] == s[j + k]) k += 1;
        lcp[rank[i]] = k;
        if(k) k -= 1;
    }
    return lcp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> inp;
    vector<int> p = suffix_array(inp);
    vector<int> r = lcp(inp, p);
    
    // for(int i = 0; i < inp.size(); i += 1){
    //     if(i == inp.size() - 1) cout << p[i] << ' ' << -1 << '\n';
    //     else cout << p[i] << ' ' << r[i] << '\n';
    // }

    long long ans = inp.size();
    ans = ans * (ans + 1) / 2;
    for(int i = 0; i < r.size(); i += 1){
        ans -= r[i];
    }

    cout << ans << '\n';

    return 0;
}