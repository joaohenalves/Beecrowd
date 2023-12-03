#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<int, int> > tree(112345, make_pair(-1, 0));
int n, depth[112345];

int findDepth(int node) {
    if(depth[node] != -1) return depth[node];
    return depth[node] = 1 + findDepth(tree[node].first);
}

ll lca(int u, int v) {
    ll ans = 0;
    if(depth[u] > depth[v]) swap(u, v);
    while(u != v) {
        if(depth[v] == depth[u]) {
            ans += tree[u].second;
            u = tree[u].first;
        }
        ans += tree[v].second;
        v = tree[v].first;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v, q, cost;
    while(cin >> n, n) {
        for(int i = 1; i < n; i++) depth[i] = -1;
        depth[0] = 0;
        for(int i = 1; i < n; i++) {
            cin >> v >> cost;
            tree[i] = make_pair(v, cost);
        }
        for(int i = 1; i < n; i++) findDepth(i);
        cin >> q;
        while(q--) {
            cin >> u >> v;
            cout << lca(u, v) << (q != 0 ? " " : "\n");
        }
    }
    return 0;
}
