#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1123;
constexpr int MAX_EDGES = MAX * (MAX - 1) / 2;

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
    for(const auto &[cost, u, v] : edges) {
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
    int u, v, cost, total, flag;
    edges.reserve(MAX_EDGES);
    while(cin >> n >> m) {
        flag = 0;
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> cost;
            u--; v--; 
            edges.emplace_back(cost, u, v);
        }
        total = kruskal();
        for(int j = 1; j < n; j++) {
            if(parent[j] != parent[0]) {
                flag = 1;
                break;
            }
        }
        cout << (flag ? "impossivel" : to_string(total)) << "\n";
        edges.clear();
    }
    return 0;
}