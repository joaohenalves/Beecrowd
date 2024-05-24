#include <bits/stdc++.h>
using namespace std;

#define MAX 11234
#define INF 11234567
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

vector<vector<ii>> graph(MAX);
int n, m, dist[MAX][2];

int dijkstra() {
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    for(int i = 0; i < n; i++) {
        dist[i][0] = dist[i][1] = INF;
    }
    dist[0][0] = 0;
    pq.emplace(0, 0, 0);
    while(!pq.empty()) {
        auto [du, u, x] = pq.top();
        pq.pop();
        if(u == n - 1 && x == 0) return du;
        if(dist[u][x] < du) continue;
        for(auto &[v, dv] : graph[u]) {
            if(dist[v][x ^ 1] > du + dv) {
                dist[v][x ^ 1] = du + dv;
                pq.emplace(du + dv, v, x ^ 1);
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v, w;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--; v--;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    cout << dijkstra() << "\n";
    return 0;
}
