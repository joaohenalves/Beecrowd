#include <bits/stdc++.h>
using namespace std;

int n, m, dist[412][412];

void floydWarshall() {
    int i, j, k;
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                dist[i][j] |= (dist[i][k] & dist[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, j, q, u, v;
    cin >> n >> m >> q;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            dist[i][j] = i == j;
        }
    }
    for(i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        dist[u][v] = dist[v][u] = 1;
    }
    floydWarshall();
    while(q--) {
        cin >> u >> v;
        u--; v--;
        cout << (dist[u][v] == 1 ? "Lets que lets" : "Deu ruim") << "\n";
    }
    return 0;
}
