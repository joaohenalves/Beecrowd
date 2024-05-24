#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph(20);
int n, m, marked[20];

void dfs(int u) {
    marked[u]++;
    for(auto &v : graph[u]) {
        if(marked[v] == 0) dfs(v);
        else if(marked[v] == 1) {
            marked[v]++;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q, id, flag;
    string s1, s2, s3;
    unordered_map<string, int> h;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++) {
        cin >> s1 >> s2 >> s3;
        if(h[s1] == 0) h[s1] = ++id;
        if(h[s2] == 0) h[s2] = ++id;
        if(h[s3] == 0) h[s3] = ++id;
        graph[h[s3]].push_back(h[s1]);
        graph[h[s3]].push_back(h[s2]);
    }
    while(q--) {
        memset(marked, 0, sizeof(marked));
        flag = 0;
        cin >> s1 >> s2;
        dfs(h[s1]);
        dfs(h[s2]);
        for(int i = 0; i < n; i++) if(marked[i] == 2) flag = 1;
        cout << (flag ? "verdadeiro" : "falso") << "\n";
    }
    return 0;
}
