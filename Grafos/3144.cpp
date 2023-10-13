#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 512;

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
    for(auto &[cost, u, v] : edges) {
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
    int whatever, u, v, cost;
    cin >> n >> m;
    cin >> whatever;
    edges.reserve(m);
    while(m--) {
        cin >> u >> v >> cost;
        u--; v--;
        edges.emplace_back(cost, u, v);
    }
    cout << kruskal() * 2 << "\n";
    return 0;
}