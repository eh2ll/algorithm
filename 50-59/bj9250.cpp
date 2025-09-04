// aho-corasick. justicehui

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, Q;

struct Node{
    map<char, Node*> child;
    int terminal;
    Node() : terminal(-1) {};
    ~Node(){
        for(auto &i : child) delete i.second;
        child.clear();
    }
    void insert(const char *key, int num){
        if(*key == 0){
            terminal = num;
            return;
        }
        if(!child[*key]) child[*key] = new Node();
        child[*key]->insert(key + 1, num);
    }
    Node* fail;
    vector<int> output;
};

Node *root = new Node();

void aho_fail(Node * root){
    queue<Node*> Q;
    root->fail = root;
    Q.push(root);
    while(!Q.empty()){
        Node *cur = Q.front(); Q.pop();
        for(auto &i : cur->child){
            Node *nxt = i.second;
            if(!nxt) continue;
            if(cur == root) nxt->fail = root;
            else{
                Node* t = cur->fail;
                while(t != root && !t->child[i.first]) t = t->fail;
                if(t->child[i.first]) t = t->child[i.first];
                nxt->fail = t;
            }
            nxt->output = nxt->fail->output;
            if(nxt->terminal != -1){
                nxt->output.push_back(nxt->terminal);
            }
            Q.push(nxt);
        }
    }
}

vector<pii> aho_search(string &s, Node *root){
    vector<pii> ret;
    auto state = root;
    for(int i = 0; i < s.size(); i += 1){
        while(state != root && !state->child[s[i]]) state = state->fail;
        if(state->child[s[i]]) state = state->child[s[i]];
        for(int j = 0; j < state->output.size(); j += 1){
            ret.push_back({i, state->output[j]});
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        string s; cin >> s;
        root->insert(s.c_str(), i);
    }
    aho_fail(root);
    cin >> Q;
    for(int i = 0; i < Q; i += 1){
        string s; cin >> s;
        auto res = aho_search(s, root);
        if(!res.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}