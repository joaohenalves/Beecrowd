#include <bits/stdc++.h>
using namespace std;

int ans;

#define to_i(ch) ((ch) - 'a')

struct node {
    int nxt[26], term = 0;
    node() {memset(nxt, -1, sizeof(nxt));}
};

vector<node> trie;

void ins(string s) {
    int c, u = 0, flag = 0;
    for(int i = 0; i < s.size(); i++) {
        c = to_i(s[i]);
        if(trie[u].nxt[c] == -1) {
            trie[u].nxt[c] = trie.size();
            trie.emplace_back();
            flag = 1;
        }
        ans &= !trie[u].term;
        u = trie[u].nxt[c];
    }
    trie[u].term = 1;
    ans &= flag;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    while(cin >> n, n) {
        trie.clear();
        trie.emplace_back();
        ans = 1;
        while(n--) {
            cin >> s;
            if(ans) ins(s);
        }
        cout << "Conjunto " << (ans ? "Bom\n" : "Ruim\n");
    }

    return 0;
}