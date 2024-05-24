#include <bits/stdc++.h>
using namespace std;

#define MAX 11234
int n, m, q, parent[MAX], nodeRank[MAX];

int findSet(int u) {
    if(parent[u] == u) return u;
    else return parent[u] = findSet(parent[u]);
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, u, v, first = 0;
    while(cin >> n >> m >> q) {
        if(first) cout << "\n";
        first = 1;
        for(i = 0; i < n; i++) {
            nodeRank[i] = 0;
            parent[i] = i;
        }
        for(i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            unionSets(u, v);
        }
        while(q--) {
            cin >> u >> v;
            u--; v--;
            cout << (findSet(u) == findSet(v) ? "S" : "N") << "\n";
        }
    }
    return 0;
}
