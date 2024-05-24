#include <bits/stdc++.h>
using namespace std;

#define MAX 1123

int n, m, vis[MAX], hasKey[MAX];
vector<vector<int>> graph(MAX);
vector<vector<int>> keys(MAX);

int bfs() {
    queue<int> q;
    int u, t = 0;
    memset(hasKey, 0, sizeof(hasKey));
    memset(vis, 0, sizeof(vis));
    vis[0] = hasKey[0] = 1;
    q.push(0);
    while(!q.empty()) {
        u = q.front();
        q.pop();
        vis[u] = 2;
        t++;
        for(int v : graph[u]) {
            if(vis[v] == 0) {
                vis[v] = 1;
                if(hasKey[v]) q.push(v);
            }
        }
        for(int v : keys[u]) {
            hasKey[v] = 1;
            if(vis[v] == 1) q.push(v);
        }
    }
    return t == n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v;
    while(cin >> n >> m) {
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i = 1; i < n; i++) {
            cin >> u;
            u--;
            keys[u].push_back(i);
        }
        cout << (bfs() ? "sim" : "nao") << "\n";
        for(int i = 0; i < n; i++) {
            graph[i].clear();
            keys[i].clear();
        }
    }
    return 0;
}
