#include <bits/stdc++.h>
using namespace std;
 
#define MAX 112
typedef pair<int, int> ii;

int n, m, grid[MAX][MAX], dist[MAX][MAX];
int ai[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int aj[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int bfs(int x, int y) {
    queue<ii> q;
    int ii, jj, mx = 0;
    memset(dist, -1, sizeof(dist));
    dist[x][y] = 0;
    q.emplace(x, y);
    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for(int k = 0; k < 8; k++) {
            ii = i + ai[k];
            jj = j + aj[k];
            if(ii >= 0 && ii < n && jj >= 0 && jj < m && grid[ii][jj] && dist[ii][jj] == -1) {
                q.emplace(ii, jj);
                dist[ii][jj] = dist[i][j] + 1;
                mx = max(mx, dist[ii][jj]);
            }
        }
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, a, b;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        cin >> a >> b;
        a--; b--;
        cout << bfs(a, b) << "\n";
    }
    return 0;
}

