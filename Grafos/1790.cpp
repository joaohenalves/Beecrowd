#include <bits/stdc++.h>
using namespace std;

#define MAX 51

int n, m, ans, timer, vis[MAX], tin[MAX], low[MAX];
vector<vector<int>> graph(MAX);

void dfs(int u, int p) {
    vis[u] = 1;
    tin[u] = low[u] = timer++;
    for(int v : graph[u]) {
        if(v != p) {
            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] > tin[u]) ans++; //aqui é identificada a ponte u-v
            }
        }
    }
}

void findBridges() {
    timer = ans = 0;
    memset(vis, 0, sizeof(vis));
    memset(tin, -1, sizeof(tin));
    memset(low, -1, sizeof(low));
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) dfs(i, -1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, u, v;
    while(cin >> n >> m) {
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        findBridges();
        cout << ans << "\n";
        for(int i = 0; i < n; i++) graph[i].clear();
    }
    return 0;
}
