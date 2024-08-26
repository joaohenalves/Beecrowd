#include <bits/stdc++.h>
using namespace std;

#define MAX 11234
#define MAXG 112
#define MOD 1000000007
#define INF 1123456789
#define EPS 1e-9
typedef long long ll;
typedef pair<int, int> ii;
 
int n, m, ans, timer, vis[MAX], tin[MAX], low[MAX], bridges[MAX];
vector<vector<int>> graph(MAX);
vector<vector<int>> bridgeGraph(MAX);

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
                if(low[v] > tin[u]) {
                    bridgeGraph[u].push_back(v);
                    bridgeGraph[v].push_back(u);
                }
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

void dfsBridges(int u, int b) {
    bridges[u] = b;
    for(int v : bridgeGraph[u]) {
        if(bridges[v] == -1) {
            dfsBridges(v, b);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, u, v, q;
    while(cin >> n >> m >> q, n) {
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        findBridges();
        memset(bridges, -1, sizeof(bridges));
        for(int i = 0; i < n; i++) {
            if(bridges[i] == -1) {
                dfsBridges(i, i);
            }
        }
        while(q--) {
            cin >> u >> v;
            u--; v--;
            cout << (bridges[u] == bridges[v] ? 'Y' : 'N') << "\n";
        }
        cout << "-\n";
        for(int i = 0; i < n; i++) {
            graph[i].clear();
            bridgeGraph[i].clear();
        }
    }
    return 0;
}
