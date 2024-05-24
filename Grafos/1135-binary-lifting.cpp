#include <bits/stdc++.h>
using namespace std;

#define MAXV 112345
#define LOG2_MAXV 18
typedef long long ll;

vector<vector<int> > graph(MAXV);
int n, l, timer, t[MAXV][2], up[MAXV][LOG2_MAXV];
ll dist[MAXV];

void dfsDist(int u, int p) {
    dist[u] += dist[p];
    for(int &v : graph[u]) {
        dfsDist(v, u);
    }
}

void dfs(int v, int p) {
    t[v][0] = ++timer;
    up[v][0] = p;
    for(int i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (int &u : graph[v]) {
        if (u != p) dfs(u, v);
    }
    t[v][1] = ++timer;
}

bool isAncestor(int u, int v) {
    return t[u][0] <= t[v][0] && t[u][1] >= t[v][1];
}

int lca(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;
    for (int i = l; i >= 0; --i) {
        if (!isAncestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

void preprocess(int root) {
    timer = 0;
    l = ceil(log2(n));
    dfs(root, root);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v, q;
    ll ans, cost;
    while(cin >> n, n) {
        for(int i = 1; i < n; i++) {
            cin >> u >> cost;
            graph[u].push_back(i);
            dist[i] = cost;
        }
        dist[0] = 0;
        dfsDist(0, 0);
        preprocess(0);
        cin >> q;
        while(q--) {
            cin >> u >> v;
            cout << dist[u] + dist[v] - (2 * dist[lca(u, v)]);
            cout << (q != 0 ? " " : "\n");
        }
        for(int i = 0; i < n; i++) graph[i].clear();
    }
    return 0;
}
