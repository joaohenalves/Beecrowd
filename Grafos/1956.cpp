#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int MAX = 11234;
constexpr int MAX_EDGES = (MAX * (MAX - 1)) / 2;

vector<tuple<int, int, int> > edges;
int n, m, families, parent[MAX], nodeRank[MAX];

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

ll kruskal() {
    int u, v, cost;
    ll mst = 0;
    for(int i = 0; i < n; i++) parent[i] = i;
    sort(edges.begin(), edges.end());
    for(const auto &[cost, u, v] : edges) {
        if(findSet(u) != findSet(v)) {
            unionSets(u, v);
            mst += cost;
            families--;
        }
    }
    return mst;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int u, v, cost;
    ll total;
    cin >> n;
    families = n;
    edges.reserve(MAX_EDGES);
    for(int i = 0; i < n - 1; i++) {
        cin >> m;
        for(int j = 0; j < m; j++) {
            cin >> v >> cost;
            v--;
            edges.emplace_back(cost, i, v);
        }
    }
    total = kruskal();
    cout << families << " " << total << "\n";
    return 0;
}
