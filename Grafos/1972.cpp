#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define INF 1e9

int n, m;
int ai[] = {-1, 1, 0, 0};
int aj[] = {0, 0, 1, -1};
char grid[512][512];

int dijkstra(int start, int target) {
    vector<int> dist(n * m, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int ii, jj, x, y, v, weight, t;
    dist[start] = 0;
    pq.push({0, start});
 
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
 
        if (d > dist[u]) {
            continue;
        }
        y = u / m;
        x = u % m;
        for(int i = 0; i < 4; i++) {
            ii = y + ai[i];
            jj = x + aj[i];
            if(ii >= 0 && ii < n && jj >= 0 && jj < m && grid[ii][jj] != '#') {
                if(grid[ii][jj] >= 65 || grid[ii][jj] == '.') {
                    weight = 0;
                } else {
                    weight = grid[ii][jj] - '0';
                }
            } else continue;
            v = ii * m + jj;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[target];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string row;
    char ch;
    int herc, eut, result;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> row;
        for(int j = 0; j < m; j++) {
            grid[i][j] = row[j];
            if(grid[i][j] == 'H') herc = i * m + j;
            if(grid[i][j] == 'E') eut = i * m + j;
        }
    }
    result = dijkstra(herc, eut);
    cout << (result == INF ? "ARTSKJID" : to_string(result)) << "\n";
    return 0;
}
