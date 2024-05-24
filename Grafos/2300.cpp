#include <bits/stdc++.h>
using namespace std;

#define MAX 112

int n, m, parent[MAX], nodeRank[MAX];

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
    int u, v, c = 1, flag;
    while(cin >> n >> m, n) {
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            nodeRank[i] = 0;
        }
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            if(findSet(u) != findSet(v)) {
                unionSets(u, v);
            }
        }
        flag = 1;
        for(int i = 2; i <= n; i++) {
            if(findSet(i) != findSet(i - 1)) {
                flag = 0;
                break;
            }
        }
        cout << "Teste " << c << "\n";
        cout << (flag ? "normal" : "falha") << "\n\n";
        c++;
    }
    return 0;
}
