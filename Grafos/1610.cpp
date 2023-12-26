#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int> > graph(11234);
int n, color[11234];

bool dfs(int v) {
    for(const auto &u : graph[v]) {
        if(color[u] == 2) continue;
        if(color[u] == 1) return true;
        color[u] = 1;
        if(dfs(u)) return true;
    }
    color[v] = 2;
    return false;
}

bool findCycle() {
    for(int i = 0; i < n; i++) {
        if(color[i] == 2) continue;
        color[i] = 1;
        if(dfs(i)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, m, u, v;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        memset(color, 0, (n + 1) * sizeof(color[0]));
        for(int i = 0; i < n; i++) graph[i].clear();
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            graph[u].insert(v);
        }
        cout << (findCycle() ? "SIM" : "NAO") << "\n";
    }
    return 0;
}
