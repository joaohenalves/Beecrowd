#include <bits/stdc++.h>
using namespace std;

#define MAX 112
#define INF 112345678

int n, dist[MAX][MAX], queries[MAX][MAX][MAX];

void floydWarshall() {
    int i, j, k;
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
		}
		queries[i][j][k] = dist[i][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, j, k, m, u, v, w, q;
    while(cin >> n >> m) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                dist[i][j] = (i == j ? 0 : INF);
            }
        }
        for(i = 0; i < m; i++) {
            cin >> u >> v >> w;
            u--; v--;
            dist[u][v] = dist[v][u] = w;
        }
        floydWarshall();
        cin >> q;
        while(q--) {
            cin >> u >> v >> w;
            u--; v--; w--;
            cout << (queries[u][v][w] == INF ? -1 : queries[u][v][w]) << "\n";
        }
    }
    return 0;
}
