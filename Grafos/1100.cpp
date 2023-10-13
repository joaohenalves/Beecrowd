#include <bits/stdc++.h>
using namespace std;

#define MAX 64
#define INF 12345

int dist[MAX][MAX];
int mvx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int mvy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void floydWarshall() {
    int i, j, k;
    for (k = 0; k < MAX; k++) {
        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

void computeMoves() {
    int x1, y1;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            dist[i * 8 + j][i * 8 + j] = 0;
            for(int k = 0; k < 8; k++) {
                x1 = j + mvx[k];
                y1 = i + mvy[k];
                if(x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8) {
                    dist[i * 8 + j][y1 * 8 + x1] = 1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string src, dst;
    memset(dist, INF, sizeof(dist));
    computeMoves();
    floydWarshall();
    while(cin >> src >> dst) {
        int a = ((src[1] - '1') * 8) + src[0] - 'a';
        int b = ((dst[1] - '1') * 8) + dst[0] - 'a';
        cout << "To get from " << src << " to " << dst << " takes " << dist[a][b] << " knight moves.\n";
    }
    return 0;
}   