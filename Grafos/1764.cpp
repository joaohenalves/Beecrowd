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
    int u, v, mst = 0;
    for(int i = 0; i < n; i++) parent[i] = i;
    sort(edges.begin(), edges.end());
    for(auto ed : edges) {
        if(findSet(get<1>(ed)) != findSet(get<2>(ed))) {
            unionSets(get<1>(ed), get<2>(ed));
            mst += get<0>(ed);
        }
    }
    return mst;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v1, v2, cost;
    while(cin >> n >> m, n) {
        for(int i = 0; i < m; i++) {
            cin >> v1 >> v2 >> cost;
            edges.emplace_back(cost, v1, v2);
        }
        cout << kruskal() << "\n";
        edges.clear();
    }
    return 0;
}
