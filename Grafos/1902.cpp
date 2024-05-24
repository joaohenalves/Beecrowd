#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

int nxt[MAX], marked[MAX];

int dfs(int u, int id) {
    marked[u] = id;
    if(marked[nxt[u]] == id) return 1;
    else if(marked[nxt[u]] == -1) return dfs(nxt[u], id);
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<string, int> r;
    string a, b;
    int ans = 0, id = 0, idx = 0;
    while(cin >> a >> b) {
        if(r.find(a) == r.end()) r[a] = idx++;
        if(r.find(b) == r.end()) r[b] = idx++;
        nxt[r[a]] = r[b];
    }
    memset(marked, -1, sizeof(marked));
    for(int i = 0; i < idx; i++) {
        if(marked[i] == -1) {
            ans += dfs(i, id);
            id++;
        }
    }
    cout << ans << "\n";
    return 0;
}
