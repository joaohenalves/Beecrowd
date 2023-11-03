#include <bits/stdc++.h>
using namespace std;


#define INF 1e9

int dist[112][112];
int n, m;

void floydWarshall() {
    int i, j, k;
    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q, u, v, cost, ins = 1;
    while(cin >> n >> m, n) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dist[i][j] = (i == j ? 0 : INF);
        for(int k = 0; k < m; k++) {
            cin >> u >> v >> cost;
            u--; v--;
            dist[u][v] = dist[v][u] = cost;
        }
        floydWarshall();
        cout << "Instancia " << ins++ << "\n";
        cin >> q;
        while(q--) {
            cin >> u >> v;
            u--; v--;
            cout << (u == v ? 0 : dist[u][v]) << "\n";
        }
        cout << "\n";
    }
    return 0;
}
