#include <bits/stdc++.h>
using namespace std;

#define INF 1123456789789
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> li;

vector<vector<ii> > graph(11234);
ll dist[11234];
int c, t;

ll dijkstra(int src, int dest) {
    fill(dist, dist + c, INF);
    priority_queue<li, vector<li>, greater<li> > pq;
    int u, v, dv;
    ll du;
    dist[src] = 0;
    pq.emplace(0, src);
    while(!pq.empty()) {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();
        if(u == dest) return dist[dest];
        if(du > dist[u]) continue;
        for(const auto &[v, dv] : graph[u]) {
            if(du + dv < dist[v]) {
                dist[v] = du + dv;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist[dest];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int f, u, v, cost;
    ll ans = 0;
    cin >> f;
    while(f--) {
        cin >> c >> t;
        for(int i = 0; i < t; i++) {
            cin >> u >> v >> cost;
            u--; v--;
            graph[u].emplace_back(v, cost);
        }
        ans += dijkstra(0, c - 1);
        for(int i = 0; i < c; i++) graph[i].clear();
    }
    cout << ans << "\n";
    return 0;
}
