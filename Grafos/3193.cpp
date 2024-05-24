#include <bits/stdc++.h>
using namespace std;


constexpr int INF = 112345678;
typedef pair<int, int> ii;
typedef tuple<int, int, int> t;


vector<vector<int> > graph(1123);
int n, m, c, s, e, price[1123], dist[1123][112], weight[1123][1123];

string dijkstra() {
    priority_queue<t, vector<t>, greater<t> > pq;
    int v, dv, tc, tu, tl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= c; j++) {
            dist[i][j] = INF;
        }
    }
    dist[s][0] = 0;
    pq.emplace(0, s, 0);
    while(!pq.empty()) {
        auto [tc, tu, tl] = pq.top();
        pq.pop();
        if(tu == e) return to_string(dist[tu][tl]) + "\n";
        if(tc > dist[tu][tl]) continue;
        if(tl < c && dist[tu][tl + 1] > dist[tu][tl] + price[tu]) {
            dist[tu][tl + 1] = dist[tu][tl] + price[tu];
            pq.emplace(dist[tu][tl + 1], tu, tl + 1);
        }
        for(const auto &v : graph[tu]) {
            dv = weight[tu][v];
            if(tl >= dv && dist[v][tl - dv] > dist[tu][tl]) {
                dist[v][tl - dv] = dist[tu][tl];
                pq.emplace(dist[tu][tl], v, tl - dv);
            }
        }
    }
    return "impossible\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, j, q, u, v, cost;
    while(cin >> n >> m) {
        for(i = 0; i < n; i++) {
            cin >> price[i];
            for(j = 0; j < n; j++) {
                weight[i][j] = INF;
            }
        }
        for(i = 0; i < m; i++) {
            cin >> u >> v >> cost;
            if(weight[u][v] == INF) {
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
            weight[u][v] = weight[v][u] = min(weight[u][v], cost);
        }
        cin >> q;
        while(q--) {
            cin >> c >> s >> e;
            cout << dijkstra();
        }
        for(i = 0; i < n; i++) graph[i].clear();
    }
    return 0;
}
