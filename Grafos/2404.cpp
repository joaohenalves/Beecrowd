#include <bits/stdc++.h>
using namespace std;

#define MAX 41234


vector<tuple<int, int, int> > edges;
int n, m, parent[MAX], nodeRank[MAX];

int findSet(int u) {
    return parent[u] == u ? u : (parent[u] = findSet(parent[u]));
}

void unionSets(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if(nodeRank[u] < nodeRank[v]) parent[u] = v;
    else {
        parent[v] = u;
        if(nodeRank[u] == nodeRank[v]) nodeRank[u]++;
    }
}

int kruskal() {
    int u, v, cost, mst = 0;
    for(int i = 0; i < n; i++) parent[i] = i;
    sort(edges.begin(), edges.end());
    for(const auto &ed : edges) {
        tie(cost, u, v) = ed;
        if(findSet(u) != findSet(v)) {
            unionSets(u, v);
            mst += cost;
        }
    }
    return mst;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int u, v, cost;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> cost;
        u--; v--;
        edges.emplace_back(cost, u, v);
    }
    cout << kruskal() << "\n";
    return 0;
}
