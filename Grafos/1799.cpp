#include <bits/stdc++.h>
using namespace std;

#define MAX 4123
#define INF 112345678

int n, m, dist[MAX];
vector<vector<int>> graph(MAX);
unordered_map<string, int> vert;

int bfs(int src, int dest) {
    int u;
    queue<int> q;
    for(int i = 0; i < n; i++) dist[i] = INF;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()) {
        u = q.front();
        q.pop();
        if(u == dest) return dist[u];
        for(int &v : graph[u]) {
            if(dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return 0;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string u, v;
    int idx = 0;
    cin >> n >> m;
    cin.ignore();
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        if(vert.find(u) == vert.end()) vert[u] = idx++;
        if(vert.find(v) == vert.end()) vert[v] = idx++;
        graph[vert[u]].push_back(vert[v]);
        graph[vert[v]].push_back(vert[u]);
    }
    cout << bfs(vert["Entrada"], vert["*"]) + bfs(vert["*"], vert["Saida"]) << "\n";
    return 0;
}
