#include <bits/stdc++.h>
using namespace std;

#define MAXV 51234
#define LOG2_MAXV 20
typedef long long ll;

vector<vector<int> > graph(MAXV);
int n, l, timer, depth[MAXV], vertices[MAXV], occ[MAXV], t[MAXV][2], up[MAXV][LOG2_MAXV];

void dfsDepth(int u, int p, int d) {
    depth[u] = d;
    for(int &v : graph[u]) {
        if(v != p) dfsDepth(v, u, d + 1);
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
    int half, u, v, ancestor;
    ll ans = 0;
    cin >> n;
    half = n / 2;
    memset(occ, 0, (n + 1) * sizeof(int));
    for(int i = 0; i < n; i++) {
        cin >> vertices[i];
        vertices[i]--;
        if(occ[vertices[i]] == 0) occ[vertices[i]]++;
        else vertices[i] += half;
    }
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        graph[vertices[u]].push_back(vertices[v]);
        graph[vertices[v]].push_back(vertices[u]);
    }
    dfsDepth(0, 0, 0);
    preprocess(0);
    for(int i = 0; i < half; i++) {
        ancestor = lca(i, i + half);
        ans += depth[i] + depth[i + half] - (2 * depth[ancestor]);
    }
    cout << ans << "\n";
    return 0;
}
