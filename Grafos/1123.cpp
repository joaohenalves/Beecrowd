#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;
constexpr int MAX_EDGES = 300 * 300 / 2;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<vector<pair<int, int > > > graph(250);
vector<int> dist(250);
int n;

int dijkstra(int start, int target) {
    fill(dist.begin(), dist.begin() + n, INF);
    dist[start] = 0;
    pq.emplace(0, start);
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto &edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist[target];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, c, k, v1, v2, cost, aux1, aux2;
    while(cin >> n >> m >> c >> k, n) {
        for(int i = 0; i < m; i++) {
            cin >> v1 >> v2 >> cost;
            aux1 = min(v1, v2);
            aux2 = max(v1, v2);
            if(aux2 < c) {
                if(aux2 - aux1 == 1) graph[aux1].emplace_back(aux2, cost);
            } else {
                if(aux1 >= c) graph[aux1].emplace_back(aux2, cost);
                graph[aux2].emplace_back(aux1, cost);
            }
        }
        cout << dijkstra(k, c - 1) << "\n";
        for(int i = 0; i < n; i++) graph[i].clear();
    }
    return 0;
}