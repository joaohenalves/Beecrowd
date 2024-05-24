#include <bits/stdc++.h>
using namespace std;

#define MAX 112
typedef tuple<int, int, int> iii;

int n, m, parent[MAX], nodeRank[MAX];
vector<iii> edges;

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
        if(nodeRank[v] == nodeRank[u]) nodeRank[v]++;
    }
}

void kruskal() {
    sort(edges.begin(), edges.end());
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        nodeRank[i] = 0;
    }
    for(auto &[w, u, v] : edges) {
        if(findSet(u) != findSet(v)) {
            cout << u + 1 << " " << v + 1 << "\n";
            unionSets(u, v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v, w, c = 1;
    while(cin >> n >> m, n) {
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            u--; v--;
            edges.emplace_back(w, u, v);
            edges.emplace_back(w, v, u);
        }
        cout << "Teste " << c << "\n";
        kruskal();
        cout << "\n";
        edges.clear();
        c++;
    }
    return 0;
}
