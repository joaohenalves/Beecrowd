#include <bits/stdc++.h>
using namespace std;

#define INF 112345678
#define MAXV 16
#define MAXK 6
typedef pair<int, int> ii;
typedef tuple<int, int, int, int> iiii;

vector<vector<ii> > graph(16);
int n, m, k, marked[MAXV], dist[MAXV][MAXK][1 << MAXV];

void dfs(int u) {
    marked[u] = 1;
    for(auto &[v, cost] : graph[u]) {
        if(marked[v] == 0) dfs(v);
    }
}

int dijkstra() {
    priority_queue<iiii, vector<iiii>, greater<iiii>> pq;
    int i, j, l, u, v, d, kl, mask, dv;
    int target = pow(2, n) - 1;
    for(i = 0; i < n; i++) {
        for(j = 0; j <= k; j++) {
            for(l = 1; l <= target; l++) {
                dist[i][j][l] = (i == 0 && l == 1 ? 0 : INF);
            }
        }
    }
    pq.emplace(0, 0, k, 1);
    while(!pq.empty()) {
        auto [d, u, kl, mask] = pq.top();
        pq.pop();
        if(mask == target) return d;
        if(d > dist[u][kl][mask]) continue;
        for(auto &[v, dv] : graph[u]) {
            if(dist[v][kl][mask | 1 << v] > d + dv) {
                dist[v][kl][mask | 1 << v] = d + dv;
                pq.emplace(d + dv, v, kl, mask | 1 << v);
            }
        }
        if(kl > 0) {
            for(v = 0; v < n; v++) {
                if(dist[v][kl - 1][mask | 1 << v] > d && v != u) {
                    dist[v][kl - 1][mask | 1 << v] = d;
                    pq.emplace(d, v, kl - 1, mask | 1 << v);
                }
            }
        }
    }
    return INF;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, t, u, v, c, cost;
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        for(i = 0; i < m; i++) {
            cin >> u >> v >> cost;
            u--; v--;
            graph[u].emplace_back(v, cost);
            graph[v].emplace_back(u, cost);
        }
        memset(marked, 0, sizeof(marked));
        c = 0;
        for(i = 0; i < n; i++) {
            if(marked[i] == 0) {
                c++;
                dfs(i);
            }
        }
        if(c - 1 <= k) {
            cout << dijkstra() << "\n";
        } else cout << -1 << "\n";
        for(i = 0; i < n; i++) graph[i].clear();
    }
    return 0;
}
