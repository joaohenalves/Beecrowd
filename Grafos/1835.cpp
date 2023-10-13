#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
int visited[123];

void dfs(int v) {
    visited[v] = 1;
    for(int i = 0; i < graph[v].size(); i++) {
        if(!visited[graph[v][i]]) dfs(graph[v][i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i, t, v, e, v1, v2, counter;
    cin >> t;
    for(int j = 1; j <= t; j++) {
        cin >> v >> e;
        graph.resize(v);
        memset(visited, 0, v * sizeof(visited[0]));
        counter = 0;
        for(i = 0; i < e; i++) {
            cin >> v1 >> v2;
            v1--; v2--;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        for(i = 0; i < v; i++) {
            if(!visited[i]) {
                dfs(i);
                counter++;
            }
        }
        cout << "Caso #" << j << ": " << (counter - 1 ? "ainda falta(m) " +  to_string(counter - 1) + " estrada(s)\n" : "a promessa foi cumprida\n");
        for(i = 0; i < v; i++) {
            graph[i].clear();
        }
        graph.clear();
    }
    return 0;
}