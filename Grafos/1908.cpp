#include <bits/stdc++.h>
using namespace std;

int n, counter = 0;
bitset<10000> visited;

void bfs(vector<vector<int> > &graph, vector<int> &dist) {
    queue<int> qu;
    visited[0] = 1;
    dist[0] = 0;
    qu.emplace(0);
    while(!qu.empty()) {
        int temp = qu.front();
        qu.pop();
        for(auto v : graph[temp]) {
            if(visited[v] == 0) {
                qu.emplace(v);
                visited[v] = 1;
                dist[v] = dist[temp] + 1;
                if(v == n - 1) return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, n1, n2;
    cin >> n >> k;
    vector<vector<int> > graph;
    vector<int> emptyList;
    vector<int> dist (n);
    graph.reserve(n);
    for(int i = 0; i <= n; i++) {
        graph.emplace_back(emptyList);
    }
    vector<int> tempList;
    for(int j = 0; j < k; j++) {
        cin >> n1;
        for(int l = 0; l < n1; l++) {
            cin >> n2;
            tempList.emplace_back(n2 - 1);
        }
        for(int v = 0; v < n1; v++) {
            for(int b = 0; b < n1; b++) {
                if(tempList[b] != tempList[v]) {
                    graph[tempList[v]].emplace_back(tempList[b]);
                }
            }
        }
        tempList.clear();
    }
    bfs(graph, dist);
    cout << dist[n - 1] << "\n";
    return 0;
}