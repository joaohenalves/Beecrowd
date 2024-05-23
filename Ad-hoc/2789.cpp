#include <bits/stdc++.h>
using namespace std;

#define MAXV 5123
#define MAXD 1123
#define LOG2_MAXV 15
typedef long long ll;

vector<vector<int> > graph(MAXV);
int n, d, m, l, timer, w[MAXV], val[MAXV], upd[MAXV], t[MAXV][2], up[MAXV][LOG2_MAXV];
ll dp[MAXD];

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

int dfsSum(int u, int p) {
    int s = upd[u];
    for(int &v : graph[u]) {
        if(v != p) s += dfsSum(v, u);
    }
    return val[u] = s;
}

ll knapsack() {
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= n; i++) {
        if(w[i]) {
            for(int j = d; j >= w[i]; j--) {
                dp[j] = max(dp[j], dp[j - w[i]] + val[i]);
            }
        }
    }
    return dp[d];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v, q, cost, temp;
    cin >> n >> d;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    graph[0].push_back(1);
    graph[1].push_back(0);
    cin >> m;
    memset(w, 0, sizeof(w));
    memset(val, 0, sizeof(val));
    for(int i = 0; i < m; i++) {
        cin >> u >> cost;
        w[u] = cost;
    }
    cin >> q;
    memset(upd, 0, sizeof(upd));
    preprocess(0);
    while(q--) {
        cin >> u >> v >> cost;
        temp = lca(u, v);
        upd[u] += cost;
        upd[v] += cost;
        upd[temp] -= cost;
        upd[up[temp][0]] -= cost;
    }
    dfsSum(0, 0);
    cout << knapsack() << "\n";
    return 0;
}
