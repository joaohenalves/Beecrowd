#include <bits/stdc++.h>
using namespace std;

#define MAX 112
#define INF 112345678

int n, m, dist[MAX][MAX];

void floydWarshall() {
    int i, j, k;
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v, w, c, mx;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dist[i][j] = i == j ? 0 : INF;
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    floydWarshall();
    mx = INF;
    for(int i = 0; i < n; i++) {
        c = 0;
        for(int j = 0; j < n; j++) {
            c = max(c, dist[i][j]);
        }
        mx = min(mx, c);
    }
    cout << mx << "\n";
    return 0;
}
