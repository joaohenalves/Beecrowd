#include <bits/stdc++.h>
using namespace std;

#define MAX 1123
#define INFLL 1123456789123456
typedef long long ll;
typedef pair<ll, int> plli;

int val[MAX];
ll memo[MAX], dist[MAX], cost[MAX], weight[MAX];
vector<vector<int>> graph(MAX);
int n, m, g, k;

void dp() {
    fill(memo, memo + MAX, INFLL);
    memo[0] = 0;
    for(int i = 1; i < MAX; i++) {
        for(int j = 0; j < m; j++) {
            if(i >= val[j]) {
                memo[i] = min(memo[i], memo[i - val[j]] + weight[j]);
            } else {
                memo[i] = min(memo[i], weight[j]);
            }
        }
    }
}

ll dijkstra() {
    priority_queue<plli, vector<plli>, greater<plli>> pq;
    fill(dist, dist + n, INFLL);
    dist[0] = cost[0];
    pq.emplace(dist[0], 0);
    while(!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if(dist[u] < du) continue;
        if(u == n - 1) return du;
        for(auto &v : graph[u]) {
            if(dist[v] > du + cost[v]) {
                pq.emplace(du + cost[v], v);
                dist[v] = du + cost[v];
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v;
    while(cin >> m >> n >> g >> k, m) {
        for(int i = 0; i < m; i++) {
            cin >> weight[i] >> val[i];
        }
        dp();
        for(int i = 0; i < g; i++) {
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        memset(cost, 0, sizeof(cost));
        for(int i = 0; i < k; i++) {
            cin >> u >> v;
            u--;
            cost[u] += memo[v];
        }
        cout << dijkstra() << "\n";
        for(int i = 0; i < n; i++) graph[i].clear();
    }
    return 0;
}
