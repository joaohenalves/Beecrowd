#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int> > graph(21);
int visited[21];
bool first;

void dfs(int s, int f, int v) {
    if(first) {
        for(int i = 0; i < s; i++) {
            cout << " ";
        }
        cout << f << "-" << v;
        if(!visited[v]) cout << " pathR(G," << v << ")\n";
        else {
            cout << "\n";
            return;
        }
    }
    first = true;
    visited[v] = 1;
    for(int i = 0; i < graph[v].size(); i++) {
        dfs(s + 2, v, graph[v][i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, v1, v2;
    cin >> c;
    for(int j = 1; j <= c; j++) {
        cin >> n >> m;
        for(int k = 0; k < 21; k++) graph[k].clear();
        memset(visited, 0, n * sizeof(visited[0]));
        for(int i = 0; i < m; i++) {
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
        }
        for(int l = 0; l < n; l++) sort(graph[l].begin(), graph[l].end());
        cout << "Caso " << j << ":\n";
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                first = false;
                if(graph[i].size() > 0) {
                    dfs(0, -1, i);
                    cout << "\n";
                }
            }
        }
    }
    return 0;
}