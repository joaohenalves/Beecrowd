#include <bits/stdc++.h>
using namespace std;

#define to_i(ch) ((ch) - 'a')

int n, t;

struct node {
    int nxt[26], term = 0, occ = 0, l = 0;
    node() {memset(nxt, -1, sizeof(nxt));}
};

vector<node> trie;

void ins(string &s) {
    int c1, u = 0;
    for(auto c : s) {
        c1 = to_i(c);
        if(trie[u].nxt[c1] == -1) {
            trie[u].l++;
            trie[u].nxt[c1] = trie.size();
            trie.emplace_back();
        }
        u = trie[u].nxt[c1];
        trie[u].occ++;
    }
    trie[u].term = 1;
}

void search(int i, int p) {
    if(p == 0 || trie[p].term || trie[p].l > 1) {
        t += trie[i].occ;
    }
    for(int j = 0; j < 26; j++) {
        if(trie[i].nxt[j] != -1) search(trie[i].nxt[j], i);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n;
    while(cin >> n) {
        trie.clear();
        trie.emplace_back();
        for(int i = 0; i < n; i++) {
            cin >> s;
            ins(s);
        }
        t = 0;
        search(0, -1);
        cout << fixed;
        cout.precision(2);
        cout << (double) t / (double) n << "\n";
    }
    return 0;
}
