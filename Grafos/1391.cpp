#include <bits/stdc++.h>
using namespace std;

#define MAX 512
#define INF 112345678
typedef pair<int, int> ii;

int n, m, s, d, graph[MAX][MAX], dist[MAX];
vector<vector<int>> parent(MAX);

int dijkstra(int op) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    int i, v;
    for(i = 0; i < n; i++) dist[i] = INF;
    dist[s] = 0;
    pq.emplace(0, s);
    while(!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if(u == d) return du;
        if(du > dist[u]) continue;
        for(v = 0; v < n; v++) {
            if(v != u) {
                if(dist[v] > du + graph[u][v]) {
                    dist[v] = du + graph[u][v];
                    if(op) {
                        parent[v].clear();
                        parent[v].push_back(u);
                    }
                    pq.emplace(dist[v], v);
                } else if(op && dist[v] == du + graph[u][v]) {
                    parent[v].push_back(u);
                }
            }
        }
    }
    return -1;
}

void removeEdges(int u) {
    for(auto it = parent[u].begin(); it != parent[u].end(); it++) {
        if(graph[*it][u] != INF) removeEdges(*it);
        graph[*it][u] = INF;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, j, u, v, w;
    while(cin >> n >> m, n) {
        cin >> s >> d;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                graph[i][j] = i == j ? 0 : INF;
            }
            parent[i].clear();
        }
        for(i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph[u][v] = w;
        }
        dijkstra(1);
        removeEdges(d);
        cout << dijkstra(0) << "\n";
    }
    return 0;
}
