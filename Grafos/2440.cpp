#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

int n, m, nodeRank[MAX], parent[MAX];

int findSet(int u) {
    if(parent[u] == u) return u;
    return parent[u] = findSet(parent[u]);
}

void unionSets(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if(nodeRank[u] > nodeRank[v]) {
        parent[v] = u;
    } else {
        parent[u] = v;
        if(nodeRank[u] == nodeRank[v]) nodeRank[v]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v, t;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        nodeRank[i] = 0;
    }
    t = n;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        if(findSet(u) != findSet(v)) {
            unionSets(u, v);
            t--;
        }
    }
    cout << t << "\n";
    return 0;
}
