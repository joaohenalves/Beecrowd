#include <bits/stdc++.h>
using namespace std;

#define MAX 1123

int parent[MAX], nodeRank[MAX];

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
        if(nodeRank[u] == nodeRank[v]) {
            nodeRank[v]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v, a, counter;
    while(cin >> n >> m) {
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            nodeRank[i] = 0;
        }
        while(m--) {
            cin >> u >> v;
            if(findSet(u) != findSet(v)) {
                unionSets(u, v);
            }
        }
        cin >> a;
        counter = 0;
        for(int i = 1; i <= n; i++) {
            if(findSet(i) == findSet(a)) {
                counter++;
            }
        }
        cout << counter << "\n";
    }
    return 0;
}
