#include <bits/stdc++.h>
using namespace std;


#define INF 1e9

int dist[112][112];
int ai[] = {1, -1, 0, 0};
int aj[] = {0, 0, -1, 1};
int n, m;

void floydWarshall() {
    int i, j, k;
    for(k = 0; k < n * n; k++)
        for(i = 0; i < n * n; i++)
            for(j = 0; j < n * n; j++)
                if(dist[i][j] > (dist[i][k] + dist[k][j]) &&
                    dist[i][k] != INF && dist[k][j] != INF &&
                        i != j && i != k && j != k)
                            dist[i][j] = dist[i][k] + dist[k][j];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int dir, ii, jj, q, x1, y1, x2, y2, d;
    while(cin >> n, n) {
        for(int x = 0; x < n * n; x++) {
            for(int y = 0; y < n * n; y++) {
                dist[x][y] = (x == y ? 0 : INF);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < 4; k++) {
                    cin >> dir;
                    if(dir) {
                        ii = abs(i - (n - 1)) + ai[k];
                        jj = j + aj[k];
                        if(ii >= 0 && ii < n && jj >= 0 && jj < n) {
                            dist[abs(i - (n - 1)) * n + j][ii * n + jj] = 1;
                        }
                    }
                }
            }
        }
        floydWarshall();
        cin >> q;
        while(q--) {
            cin >> x1 >> y1 >> x2 >> y2;
            d = dist[y1 * n + x1][y2 * n + x2];
            cout << (d != INF ? to_string(d) : "Impossible") << "\n"; 
        }
        cout << "\n";
    }
    return 0;
}
