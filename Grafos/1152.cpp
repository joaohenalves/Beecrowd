#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 212345;

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
    for(const auto &[cost, u, v] : edges) { //this line only works on c++17 or newer
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
    int u, v, cost, total;
    edges.reserve(MAX);
    while(cin >> n >> m, n) {
        total = 0;
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> cost;
            total += cost;
            edges.emplace_back(cost, u, v);
        }
        cout << total - kruskal() << "\n";
        edges.clear();
    }
    return 0;
}
