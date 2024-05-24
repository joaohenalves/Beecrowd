#include <bits/stdc++.h>
using namespace std;

#define MAX 41
#define INF 112345678

vector<vector<int>> graph(MAX);
int n, cap[MAX][MAX], parent[MAX], dist[MAX];

int bfs(int s, int t) {
    int u, bneck = INF;
    queue<int> q;
    for(u = 0; u <= n + 7; u++) dist[u] = INF;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()) {
        u = q.front();
        q.pop();
        if(u == t) break;
        for(int &v : graph[u]) {
            if(cap[u][v] > 0 && dist[v] == INF) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    if(dist[t] == INF) return 0;
    for(u = t; u != s; u = parent[u]) {
        bneck = min(bneck, cap[parent[u]][u]);
    }
    return bneck;
}

int ffek(int s, int t) {
    int f = 0, bneck, u;
    while((bneck = bfs(s, t))) {
        for(u = t; u != s; u = parent[u]) {
            cap[parent[u]][u] -= bneck;
            cap[u][parent[u]] += bneck;
        }
        f += bneck;
    }
    return f;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<string, int> sh;
    string s1, s2;
    int i, c, m;
    sh["XXL"] = 1;
    sh["XL"] = 2;
    sh["L"] = 3;
    sh["M"] = 4;
    sh["S"] = 5;
    sh["XS"] = 6;
    cin >> c;
    while(c--) {
        memset(cap, 0, sizeof(cap));
        cin >> m >> n;
        for(i = 0; i < n; i++) {
            cin >> s1 >> s2;
            graph[i + 7].push_back(sh[s1]);
            graph[i + 7].push_back(sh[s2]);
            graph[sh[s1]].push_back(i + 7);
            graph[sh[s2]].push_back(i + 7);
            graph[n + 7].push_back(i + 7);
            graph[i + 7].push_back(n + 7);
            cap[sh[s1]][i + 7] = 1;
            cap[sh[s2]][i + 7] = 1;
            cap[i + 7][n + 7] = 1;
        }
        for(i = 1; i < 7; i++) {
            graph[0].push_back(i);
            graph[i].push_back(0);
            cap[0][i] = m / 6;
        }
        cout << (ffek(0, n + 7) == n ? "YES" : "NO") << "\n";
        for(i = 0; i <= n + 7; i++) graph[i].clear();
    }
    return 0;
}
