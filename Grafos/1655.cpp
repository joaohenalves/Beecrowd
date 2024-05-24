#include <bits/stdc++.h>
using namespace std;

#define MAX 100
double dist[MAX][MAX];
int n;

void floydWarshall() {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][j] < (dist[i][k] * dist[k][j]))
                    dist[i][j] = dist[i][k] * dist[k][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, u, v;
    double cost;
    while(cin >> n, n) {
        cin >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = 0;
            }
        }
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> cost;
            u--; v--; cost *= 0.01;
            dist[u][v] = dist[v][u] = cost;
        }
        floydWarshall();
        double ans = dist[0][n - 1] * 100;
        cout << fixed;
        cout.precision(6);
        cout << ans << " percent\n";
    }
    return 0;
}
