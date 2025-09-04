#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int mapping(char c){
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    if(c == 'T') return 3;
}

struct Node{
    Node* child[4];
    int terminal;
    Node(){
        fill(child, child + 4, nullptr);
        terminal = -1;
    }
    ~Node(){
        for(int i = 0; i < 4; i += 1){
            if(child[i]) delete child[i];
        }
    }
    void insert(const char *key, int num){
        if(*key == 0){
            terminal = num;
            return;
        }
        int cur = mapping(*key);
        if(!child[cur]) child[cur] = new Node();
        child[cur]->insert(key + 1, num);
    }
    Node* fail;
    vector<int> output;
};

Node *root = new Node();

void aho_fail(Node *root){
    queue<Node*> Q;
    root->fail = root;
    Q.push(root);
    while(!Q.empty()){
        Node *cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i += 1){
            Node *nxt = cur->child[i];
            if(!nxt) continue;
            if(cur == root) nxt->fail = root;
            else{
                Node* t = cur->fail;
                while(t != root && !t->child[i]) t = t->fail;
                if(t->child[i]) t = t->child[i];
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

vector<pii> aho_search(const char *s, int len, Node *root){
    vector<pii> ret;
    auto state = root;
    for(int i = 0; i < len; i += 1){
        int c = mapping(s[i]);
        while(state != root && !state->child[c]) state = state->fail;
        if(state->child[c]) state = state->child[c];
        for(int j = 0; j < state->output.size(); j += 1){
            ret.emplace_back(i, state->output[j]);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        delete root;
        root = new Node();
        int N, M; cin >> N >> M;
        char s1[1'000'006], s2[102];
        cin >> s1 >> s2;
        int cnt = 0;
        root->insert(s2, cnt++);
        for(int p1 = 0; p1 < M; p1 += 1){
            for(int p2 = p1 + 1; p2 < M; p2 += 1){
                char tmp[102] = {0};
                int idx = 0;
                for(int i = 0; i < p1; i += 1) tmp[idx++] += s2[i];
                for(int i = p2; i >= p1; i -= 1) tmp[idx++] += s2[i];
                for(int i = p2 + 1; i < M; i += 1) tmp[idx++] += s2[i];
                root->insert(tmp, cnt++);
            }
        }
        aho_fail(root);
        auto ans = aho_search(s1, N, root);
        cout << ans.size() << '\n';
    }

    return 0;
}