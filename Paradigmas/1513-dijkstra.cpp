#include <bits/stdc++.h>
using namespace std;

#define MAX 112
#define INF 11234567
#define MAX_V 16
typedef pair<int, int> pi;
typedef tuple<int, int, int> iii;

int n, m, p, idx, dist[MAX][MAX], nodes[MAX_V][2], graph[MAX_V][MAX_V], djkDist[MAX_V][1 << MAX_V];
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

int dijkstra(int src) {
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    int x, y, v, target, aux;
    target = (1 << (p + 1)) - 1;
    for(x = 0; x < idx; x++) {
        for(y = 0; y <= target; y++) {
            djkDist[x][y] = INF;
        }
    }
    djkDist[src][1] = 0;
    pq.emplace(0, 0, 1);
    while(!pq.empty()) {
        auto [du, u, mask] = pq.top();
        pq.pop();
        if(u == 0 && mask == target) return du;
        if(djkDist[u][mask] < du) continue;
        for(v = 0; v < idx; v++) {
            aux = mask | (1 << v);
            if(djkDist[v][aux] > du + graph[u][v]) {
                djkDist[v][aux] = du + graph[u][v];
                pq.emplace(djkDist[v][aux], v, aux);
            }
        }
    }
    return 0;
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
        cout << dijkstra(0) << "\n";
    }
    return 0;
}
