// trie. justicehui.

#include <bits/stdc++.h>

using namespace std;

char tmp[33];

struct trie{
    trie *child[2];
    trie(){
        child[0] = child[1] = 0;
    }
    ~trie(){
        if(child[0]) delete child[0];
        if(child[1]) delete child[1];
    }
    void insert(char *s){
        if(*s == 0) return;
        int k = *s - '0';
        if(child[k] == 0) child[k] = new trie();
        child[k]->insert(s + 1);
    }
    void query(char *s){
        if(*s == 0) return;
        int k = *s - '0'; k ^= 1;
        if(child[k]){
            *s = '1';
            child[k]->query(s + 1);
        }
        else{
            *s = '0';
            child[k^1]->query(s + 1);
        }
    }
};

void tostr(int x){
    for(int i = 31; i >= 0; i -= 1){
        tmp[i] = (x & 1) ? '1' : '0';
        x >>= 1;
    }
    tmp[32] = 0;
}

int toint(){
    int ret = 0;
    for(int i = 0; i < 32; i += 1){
        ret <<= 1;
        if(tmp[i] == '1') ret |= 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    trie *root = new trie();

    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i += 1){
        cin >> A[i];
        tostr(A[i]);
        root->insert(tmp);
    }
    int ans = 0;
    for(int i = 0; i < N; i += 1){
        tostr(A[i]);
        root->query(tmp);
        ans = max(ans, toint());
    }

    cout << ans << "\n";

    return 0;
}