#include <bits/stdc++.h>
using namespace std;

#define INF 112345678
typedef tuple<int, int, int, int> t;
typedef pair<int, int> ii;

vector<vector<ii> > graph(112);
int a, b, m, l, k, dist[112][11][512];

int dijkstra() {
    priority_queue<t, vector<t>, greater<t> > pq;
    int v, dv, td, tu, tk, tr;
    for(int i = 0; i < a + b; i++) {
        for(int j = 0; j <= k; j++) {
            for(int x = 0; x <= l; x++) {
                dist[i][j][x] = (i == a + b - 1 ? 0 : INF);
            }
        }
    }
    pq.emplace(0, a + b - 1, k, 0);
    while(!pq.empty()) {
        auto [td, tu, tk, tr] = pq.top();
        pq.pop();
        if(tu == 0) return td;
        for(const auto &[v, dv] : graph[tu]) {
            int d1 = td + (tr >= dv ? 0 : dv);
            int d2 = td + (tk >= 1 && dv <= l ? 0 : dv);
            if(dist[v][tk][max(tr - dv, 0)] > d1) {
                pq.emplace(d1, v, tk, (v < a ? tr - dv : 0));
                dist[v][tk][max(tr - dv, 0)] = d1;
            }
            if(tk >= 1 && dv <= l) {
                if(dist[v][tk - 1][(v < a ? l - dv : 0)] > d2) {
                    pq.emplace(d2, v, tk - 1, (v < a ? l - dv : 0));
                    dist[v][tk - 1][(v < a ? l - dv : 0)] = d2;
                }
            }
        }
    }
    return INF;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases, u, v, cost;
    cin >> cases;
    while(cases--) {
        cin >> a >> b >> m >> l >> k;
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> cost;
            u--; v--;
            graph[u].emplace_back(v, cost);
            graph[v].emplace_back(u, cost);
        }
        cout << dijkstra() << "\n";
        for(int i = 0; i < a + b; i++) graph[i].clear();
    }
    return 0;
}
