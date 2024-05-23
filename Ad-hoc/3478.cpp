#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

int c, f, parent[MAX], nodeRank[MAX];

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
    int u, v, p;
    cin >> c >> f;
    p = c;
    for(int i = 1; i <= c; i++) {
        parent[i] = i;
        nodeRank[i] = 0;
    }
    for(int i = 0; i < f; i++) {
        cin >> u >> v;
        if(findSet(u) != findSet(v)) {
            unionSets(u, v);
            p--;
        }
    }
    cout << p << "\n";
    return 0;
}
