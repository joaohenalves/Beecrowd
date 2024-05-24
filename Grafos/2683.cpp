#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 41234;


vector<tuple<int, int, int> > edges;
int n, parent[MAX], nodeRank[MAX];

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
    for(int i = 0; i < 1000; i++) parent[i] = i;
    sort(edges.begin(), edges.end());
    for(const auto &[cost, u, v] : edges) {
        if(findSet(u) != findSet(v)) {
            unionSets(u, v);
            mst += cost;
        }
    }
    return mst;
}

int invKruskal() {
    int u, v, cost, mst = 0;
    for(int i = 0; i < 1000; i++) { 
        parent[i] = i;
        nodeRank[i] = 0;
    }
    for(int j = edges.size() - 1; j >= 0; j--) {
        tie(cost, u, v) = edges[j];
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
    int u, v, cost, total = 0;
    cin >> n;
    edges.reserve(n);
    for(int i = 0; i < n; i++) {
        cin >> u >> v >> cost;
        u--; v--; total += cost;
        edges.emplace_back(cost, u, v);
    }
    int krs = kruskal();
    int invKrs = invKruskal();
    cout << invKrs << "\n" << krs << "\n";
    return 0;
}
