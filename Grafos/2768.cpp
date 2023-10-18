#include <bits/stdc++.h>
using namespace std;

#define MAX 123
#define INF 1e9

int n;
int dist[MAX][MAX][MAX];

void floydWarshall() {
    int i, j, k, l;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for(l = 0; l < n; l++) {
                    if (dist[i][j][l] > (dist[i][k][l] + dist[k][j][l])
                        && (dist[k][j][l] != INF
                            && dist[i][k][l] != INF) && k <= l)
                        dist[i][j][l] = dist[i][k][l] + dist[k][j][l];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, v1, v2, cost, q;
    while(cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    dist[i][j][k] = (i == j ? 0 : INF);
                }
            }
        }
        for(int i = 0; i < m; i++) {
            cin >> v1 >> v2 >> cost;
            v1--; v2--;
            for(int k = 0; k < n; k++) {
                dist[v1][v2][k] = dist[v2][v1][k] = cost;
            }
        }
        cin >> q;
        floydWarshall();
        for(int k = 0; k < q; k++) {
            cin >> v1 >> v2 >> cost;
            v1--; v2--; cost--;
            cout << (dist[v1][v2][cost] == INF ? -1 : dist[v1][v2][cost]) << "\n";
        }
    }
    return 0;
}
