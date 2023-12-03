#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

typedef pair<int, int> ii;
typedef vector<vector<ii> > vvii;

int dist[512][512];
bool country[512][512];
int n, m;

void dijkstra(int src, vvii &graph) {
    for(int i = 0; i < n; i++) dist[src][i] = INF;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    int u, v, du, dv;
    dist[src][src] = 0;
    pq.emplace(0, src);
    while(!pq.empty()) {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();
        if(du > dist[src][u]) continue;
        for(auto [v, dv] : graph[u]) {
            if(country[u][v] == 1 && country[v][u] == 1) dv = 0;
            if(dist[src][u] + dv < dist[src][v]) {
                dist[src][v] = dist[src][u] + dv;
                pq.emplace(dist[src][v], v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v, cost, q;
    while(cin >> n >> m, n) {
        vvii graph(n);
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                if(x != y) {
                    dist[x][y] = -1;
                    country[x][y] = 0;
                } else {
                    dist[x][y] = 0;
                    country[x][y] = 1;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> cost;
            u--; v--;
            graph[u].emplace_back(v, cost);
            country[u][v] = 1;
        }
        cin >> q;
        while(q--) {
            cin >> u >> v;
            u--; v--;
            if(country[u][v] == 1 && country[v][u] == 1) dist[u][v] = 0;
            else if(dist[u][v] == -1) dijkstra(u, graph);
            cout << (dist[u][v] == INF ? "Nao e possivel entregar a carta" : to_string(dist[u][v])) << "\n";
        }
        cout << "\n";
    }
    return 0;
}
