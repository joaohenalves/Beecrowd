#include <bits/stdc++.h>
using namespace std;

#define MAX 1123
#define MAX_E 1123456
typedef tuple<int, int, int> iii;

int n, m, nodeRank[MAX], parent[MAX];
vector<iii> edges(MAX_E);

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

int kruskal() {
    int u, v, w, ans = 0, t = n;
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        nodeRank[i] = 0;
    }
    sort(edges.begin(), edges.begin() + m);
    for(int i = 0; i < m; i++) {
        tie(w, u, v) = edges[i];
        if(findSet(u) != findSet(v)) {
            unionSets(u, v);
            t--;
            ans += w;
        }
    }
    return t == 1 ? ans : -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v, w, ans;
    while(cin >> n >> m) {
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            u--; v--;
            edges[i] = make_tuple(w, u, v);
        }
        ans = kruskal();
        cout << (ans == -1 ? "impossivel" : to_string(ans)) << "\n";
    }
    return 0;
}
