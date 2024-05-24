#include <bits/stdc++.h>
using namespace std;

#define MAX 112
#define INF 11234567
#define MAX_V 16
typedef pair<int, int> pi;

int n, m, p, idx, dist[MAX][MAX], nodes[MAX_V][2], graph[MAX_V][MAX_V], dp[MAX_V][1 << MAX_V];
int ai[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int aj[] = {-2, -2, -1, -1, 1, 1, 2, 2};
char grid[MAX][MAX];

void bfs(int i, int j) {
    int qi, qj, ii, jj, k, x, y;
    queue<pi> q;
    for(x = 0; x < n; x++) {
        for(y = 0; y < m; y++) {
            dist[x][y] = INF;
        }
    }
    dist[i][j] = 0;
    q.emplace(i, j);
    while(!q.empty()) {
        auto [qi, qj] = q.front();
        q.pop();
        for(k = 0; k < 8; k++) {
            ii = qi + ai[k];
            jj = qj + aj[k];
            if(ii >= 0 && ii < n && jj >= 0 && jj < m && grid[ii][jj] != '#' && dist[ii][jj] == INF) {
                dist[ii][jj] = dist[qi][qj] + 1;
                q.emplace(ii, jj);
                if(grid[ii][jj] >= 'a' && grid[ii][jj] <= 'z') {
                    graph[grid[i][j] - 'a'][grid[ii][jj] - 'a'] = dist[ii][jj]; 
                }
            }
        }
    }
}

int heldKarp() {
    int i, j, mask, ans = INF;
    for(mask = 0; mask < (1 << idx); mask++) {
        for(i = 0; i < idx; i++) {
            dp[i][mask] = INF;
        }
    }
    dp[0][1] = 0;
    for(mask = 1; mask < (1 << idx); mask++) {
        for(i = 0; i < idx; i++) {
            if((mask >> i) & 1) {
                for(j = 0; j < idx; j++) {
                    if(i != j && (mask >> j) & 1) {
                        dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + graph[j][i]);
                    }
                }
            }
        }
    }
    for(i = 1; i < idx; i++) {
        ans = min(ans, dp[i][(1 << idx) - 1] + graph[i][0]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, j;
    while(cin >> n >> m >> p, n) {
        idx = 1;
        char aux = 'b';
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == 'C') {
                    grid[i][j] = 'a';
                    nodes[0][0] = i;
                    nodes[0][1] = j;
                } else if(grid[i][j] == 'P') {
                    grid[i][j] = aux++;
                    nodes[idx][0] = i;
                    nodes[idx][1] = j;
                    idx++;
                }
            }
        }
        memset(graph, 0, sizeof(graph));
        for(i = 0; i < idx; i++) {
            bfs(nodes[i][0], nodes[i][1]);
        }
        cout << heldKarp() << "\n";
    }
    return 0;
}
